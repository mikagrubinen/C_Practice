/*
Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.

For example, given the range [5, 7], you should return 4.
*/

#include "stdlib.h"
#include "stdio.h"


int rangeBitwiseAnd(int m, int n)
{
   while(m < n)
   {
      n &= n - 1;
   }
   return n;
}


int main()
{
   printf("%d\n", rangeBitwiseAnd(0, 7));

	return 0;
}