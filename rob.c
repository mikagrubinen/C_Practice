/*
You are a professional robber planning to rob houses along a street. 
Each house has a certain amount of money stashed, the only constraint 
stopping you from robbing each of them is that adjacent houses have 
security system connected and it will automatically contact the police 
if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money 
of each house, determine the maximum amount of money you can rob tonight 
without alerting the police.
*/

#include "stdlib.h"
#include "stdio.h"

int max(int a, int b)
{
	return a > b ? a : b;
}

int rob(int* nums, int numsSize)
{
	int cur	= 0;
	int pre = 0;

	for (int i = 0; i < numsSize; ++i)
	{
		int temp = max((pre + nums[i]), cur);
		pre = cur;
		cur = temp;
	}
	return cur;
}

int main()
{
	int nums[] = {1,3,1};
	int numsSize = sizeof(nums)/sizeof(nums[0]);
	printf("%d\n", rob(nums, numsSize));
	return 0;
}