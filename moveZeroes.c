/*
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].

Note:
You must do this in-place without making a copy of the array.
Minimize the total number of operations.
*/

#include "stdio.h"
#include <stdbool.h>

void moveZeroes(int* nums, int numsSize) 
{
    int count = 0;

    for (int i = 0; i < numsSize; ++i)
    {
        if (nums[i] == 0) count++;
        else nums[i - count] = nums[i];
    }

    for (int i = numsSize - count; i < numsSize; ++i)
    {
        nums[i] = 0;
    }
}

int main(){

    int nums[] = {0, 1, 0, 3, 12};

    moveZeroes(nums, 5);

    for (int i = 0; i < 5; ++i)
    {
        printf("%d\n", nums[i]);
    }
    

	return 0;
}