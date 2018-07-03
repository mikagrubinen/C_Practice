#include "stdio.h"
#include "stdint.h"


#define BIT(n)                  ( 1<<(n) )

#define BIT_SET(y, mask)        ( y |=  (mask) )
#define BIT_CLEAR(y, mask)      ( y &= ~(mask) )
#define BIT_FLIP(y, mask)       ( y ^=  (mask) )



void print_bit_by_bit(uint8_t c)
{
	for(int i=7; i>=0; i--){
		printf("%i", c & (1 << i) ? 1 : 0);
	}
	printf("\n");
}

int main()
{
	uint8_t mask = BIT(0) | BIT(2);
	uint8_t y = 128;

	BIT_SET(y, mask);
	print_bit_by_bit(y);

	BIT_CLEAR(y, mask);
	print_bit_by_bit(y);

	BIT_FLIP(y, mask);
	print_bit_by_bit(y);

	return 0;
}