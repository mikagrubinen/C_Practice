/*
Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.

For example:
Given num = 38, the process is like: 3 + 8 = 11, 1 + 1 = 2. Since 2 has only one digit, return it.
*/

#include "stdlib.h"
#include "stdio.h"

int addDigits(int num) 
{
    return (num-9*((num-1)/9));
}

int main()
{
	printf("%d\n", addDigits(38));
	return 0;
}