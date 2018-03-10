/*
We have two special characters. The first character can be represented by one bit 0. 
The second character can be represented by two bits (10 or 11).

Now given a string represented by several bits. Return whether the last character must be a one-bit character or not. 
The given string will always end with a zero.

Example 1
Input: 
bits = [1, 0, 0]
Output: True
Explanation: 
The only way to decode it is two-bit character and one-bit character. So the last character is one-bit character.

Example 2
Input: 
bits = [1, 1, 1, 0]
Output: False
Explanation: 
The only way to decode it is two-bit character and two-bit character. So the last character is NOT one-bit character.
*/

#include "stdio.h"
#include <stdbool.h>

bool isOneBitCharacter(int* bits, int bitsSize) {

    bool result;

    for (int i = 0; i < bitsSize;)
    {
        if (bits[i] == 1)
        {
            i+=2;
            result = false;
        }
        else
        {
            i++;
            result = true;
        }
    }

    return result;
}

int main(){

    int bits[] = {1,0,0};

    printf("%s\n", isOneBitCharacter(bits, 3) ? "True" : "False");

	return 0;
}