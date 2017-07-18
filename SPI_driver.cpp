#include <stdio.h>
#include "utilities.h"
#include <FreeRTOS.h>
#include "task.h"
#include "queue.h"
#include "io.hpp"
#include "gpio.hpp"
#include "tasks.hpp"
#include "examples/examples.hpp"

#include "LPC17xx.h"

const int flash_cs = 6;

void cs(void){
    LPC_GPIO0->FIOCLR = (1 << flash_cs);
}

void ds(void){
    LPC_GPIO0->FIOSET = (1 << flash_cs);
}

inline char spi1_exchange_byte(char out){
	LPC_SSP1->DR = out;
	while(LPC_SSP1->SR & (1 << 4));
	return LPC_SSP1->DR;
}

void print_flash_signature (char c[]){
	printf("Manufacturer ID: 0x%02x \n", c[1]);
	printf("Device ID (Byte 1): 0x%02x \n", c[2]);
	printf("Device ID (Byte 2): 0x%02x \n", c[3]);
	printf("\n");
}

void print_status_register (char c[]){
	for(int i=1; i<=2; i++){
		for(int j=7; j>=0; --j){
			printf("Byte %d - Bit %d: %c \n", i, j, (c[i] & (1 << j) ? '1' : '0'));
		}
		printf("\n");
	}
}


class spi_driver : public scheduler_task
{
public:
	spi_driver(uint8_t priority) : scheduler_task("task", 2000, priority)
    {
        /* Nothing to init */
    }

    bool init(void)
    {
        LPC_SC->PCONP |= (1 << 10);		// Setting bit 10 to enable power PCSSP1
        LPC_SC->PCLKSEL0 &= ~(3 << 20);	// Reseting bits 21 & 20 to 00
        LPC_SC->PCLKSEL0 |= (1 << 20);	// Setting bit 20 so finally bits 21 & 20 are 01 meaning PCLK_peripheral = CCLK

        LPC_PINCON->PINSEL0 &= ~((3 << 14) | (3 << 16) | (3 << 18));	// reset to 00
        LPC_PINCON->PINSEL0 |= ((1 << 15) | (1 << 17) | (1 << 19));		// getting 10 on bits 15:14 17:16 19:18

        LPC_PINCON->PINSEL0 &= ~(3 << 12);		//making P0.6 GPIO by resetting bits to 00
        LPC_GPIO0->FIODIR |= (1 << flash_cs);	//making P0.6 output direction (Chip Select)

        LPC_SSP1->CR0 = 7;
        LPC_SSP1->CR1 = (1 << 1);
        LPC_SSP1->CPSR = 8;         // SCK speed = CPU / 8

        return true;
    }

    bool run(void *p)
    {
    	cs();
    	{
    		char flash_signature[4];
    		for(int i=0; i<4; ++i){
    			flash_signature[i] = spi1_exchange_byte(0x9F);
    		}
    		print_flash_signature(flash_signature);
    	}
    	ds();

    	cs();
    	{
        	char status_register[3];
        	for(int i=0; i<3; ++i){
        		status_register[i] = spi1_exchange_byte(0xD7);
        	}
        	print_status_register(status_register);
    	}
    	ds();

        vTaskDelay(1000);
        return true;
    }
};

int main(void)
{
    scheduler_add_task(new spi_driver(PRIORITY_LOW));
    scheduler_start();
    return -1;
}
