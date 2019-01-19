/*
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
You may assume no duplicates in the array.

Example 1:
Input: [1,3,5,6], 5
Output: 2

Example 2:
Input: [1,3,5,6], 2
Output: 1

Example 3:
Input: [1,3,5,6], 7
Output: 4

Example 4:
Input: [1,3,5,6], 0
Output: 0
*/

#include <stdlib.h>
#include <stdio.h>

int searchInsert(int* nums, int numsSize, int target) 
{   
	int count = 0;
	
	if(numsSize == 0)
		return 0;
	
	for(int i = 0; i < numsSize; i++)
	{
		if(target == nums[i])
			return i;
		else if(target < nums[i])
			return i;
		else if(target > nums[i])
			count++;
	}
	
	return count;
}

int main(){
	int nums[] = {1,3,5,6};
	int len = sizeof(nums)/sizeof(nums[0]);
	
	int index = searchInsert(nums, len, 0);

	printf("%d", index);
	
	return 0;
}