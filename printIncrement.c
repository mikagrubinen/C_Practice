/*
Write a loop statement that will show the following output:
1
12
123
1234
12345
*/

#include "stdlib.h"
#include "stdio.h"



int main()
{
	for (int i = 1; i <= 5; ++i)
	{
		for (int j = 1; j <= i; ++j)
		{
			printf("%d", j);
		}
		printf("\n");
	}
	
	return 0;
}