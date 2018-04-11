/**
 * C Pointer Basics Test from www.geeksforgeeks.org
 * Question 11
 * Try to figure out the result, then uncomment printf() to check result
 */

#include "stdio.h"


int f(int x, int *py, int **ppz) 
{ 
	int y, z; 
  	**ppz += 1; 
   	z  = **ppz; 
  	*py += 2; 
   	y = *py; 
   	x += 3; 
   	return x + y + z; 
} 
  
int main() 
{ 
    int c, *b, **a; 
   	c = 4; 
   	b = &c; 
   	a = &b; 
   	// printf("%d ", f(c, b, a)); 
   	return 0;
}