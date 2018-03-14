/*
 *
 *  Created on: Sep 7, 2017
 *      Author: mgrubic
 *
 *  Printing uint8_t bit by bit
 */

#include "stdio.h"
#include "stdint.h"

int main(){
	uint8_t a = 5;

	for(int i=7; i>=0; i--){
		printf("%i", c & (1 << i) ? 1 : 0);
	}

	return 0;
}
