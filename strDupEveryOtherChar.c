/*
Interview question for Intern - Software Engineer position at Astranis:
Implement a C function that takes a null-terminated string and returns a new heap-allocated 
null-terminated string containing every other character from original string (e.g., “house” -> “hue”). 
*/

#include "stdlib.h"
#include "stdio.h"
#include <string.h>

char* strDupEveryOtherChar(const char* s) 
{
	// initalize helper variables
	int i = 0;
	int j = 0;
	int k = 0;
	int count = 0;

	// find length of the string
	while('\0' != s[i])
	{
		if (0 == i%2)
		{
			++count;
		}
		i++;
	}

	// allocate memory with one extra space for null-terminating character
	count = count +1;
	char* return_str = (char *)malloc(count * sizeof(char));

	// populate allocated memory space with every other character from original string
	while('\0' != s[j])
	{
		if (0 == j%2)
		{
			return_str[k] = s[j];
			k++;
		}
		j++;
	}
	return_str[k] = '\0';
	
	return return_str;
}

int main()
{
	char str[] = "1y2u3i4h5b6l7r";
	printf("%s\n", strDupEveryOtherChar(str));
	
	return 0;
}