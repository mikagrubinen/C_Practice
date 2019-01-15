/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:
Given nums = [2, 7, 11, 15], target = 9,
Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/

#include<stdio.h> 
#include<stdlib.h>

int* twoSum(int* nums, int numsSize, int target) {
    
    int * result = (int*)malloc(2*sizeof(int));
        
    for(int i=1; i<numsSize; i++)
    {        
        for(int j=i; j<numsSize; j++)
        {
            if((nums[i-1]+nums[j]) == target){
                result[0] = i-1;
                result[1] = j; 
            }           
        }                   
    }
    return result;
}

int main(void) 
{ 
    int a[] = {3,2,3};

    int * res = twoSum(a, 3, 6);

    printf("%d", res[0]);
    printf("%d", res[1]);

    return 0;    
} 
