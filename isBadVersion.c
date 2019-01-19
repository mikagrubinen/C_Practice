/*

*/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>



bool isBadVersion(int version)
{
	if(4 <= version)
		return true;
	else
		return false;
}

int firstBadVersion(int n) 
{
	int ver = n;
	bool result = isBadVersion(n);
	
	while(result)
	{
		ver = ver - 1;
		result = isBadVersion(ver);
	}
			
	return ver + 1;
}

int main(){

	
	int index = firstBadVersion(100);

	printf("%d\n", index);
	
	return 0;
}