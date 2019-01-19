/*
Given an array nums and a value val, remove all instances of that value in-place and return the new length.
Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
The order of elements can be changed. It doesn't matter what you leave beyond the new length.

Example 1
Given nums = [3,2,2,3], val = 3,
Your function should return length = 2, with the first two elements of nums being 2.
It doesn't matter what you leave beyond the returned length.

Example 2:
Given nums = [0,1,2,2,3,0,4,2], val = 2,
Your function should return length = 5, with the first five elements of nums containing 0, 1, 3, 0, and 4.
Note that the order of those five elements can be arbitrary.
It doesn't matter what values are set beyond the returned length.
*/

#include <stdlib.h>
#include <stdio.h>

int removeElement(int* nums, int numsSize, int val) 
{
    
	if(numsSize <= 0)
		return 0;
	
	int count = numsSize;
	
	for(int i = numsSize-1; i >= 0; i--)
	{
		if(val == nums[i])
		{
			count--;
			if(i == numsSize-1)
				;
			else
			{
				for(int j = i; j < numsSize-1; j++)	
					nums[j] = nums[j+1];
			}
		}
	}
	
	return count;
}

int main(){
	int nums[] = {0,1,2,2,3,0,4,2};
	int len = sizeof(nums)/sizeof(nums[0]);
	
	int count = removeElement(nums, len, 2);
	
	for(int i = 0; i < count; i++)
		printf("%d", nums[i]);
	
	return 0;
}