/*
Good to have this in mind when thinking how stack works
*/

#include "stdio.h"

int main()
{
	int a = 5;
	char b = 'c';
	int d = 8;
	
	int *ptri = &a;
	char *ptrc = &b;
	int *ptri2 = &d;

	printf("%p \n", ptri);	// 0x7ffee25bcaf8
	printf("%p \n", ptrc);	// 0x7ffee25bcaf7
	printf("%p \n", ptri2);	// 0x7ffee25bcaf0
    return 0;
}