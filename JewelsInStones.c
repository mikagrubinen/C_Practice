/*
You're given strings J representing the types of stones that are jewels, and S representing the stones you have.  
Each character in S is a type of stone you have.  You want to know how many of the stones you have are also jewels.

The letters in J are guaranteed distinct, and all characters in J and S are letters. Letters are case sensitive, 
so "a" is considered a different type of stone from "A".
*/

#include "stdio.h"
#include "string.h"

int numJewelsInStones(char* J, char* S) {

    int ret = 0;

    int j = strlen(J);
    int s = strlen(S);

    for (int a = 0; a < j; ++a)
    {
    	for (int b = 0; b < s; ++b)
    	{
    		if (J[a] == S[b])
    		{
    			ret++;
    		}
    	}
    }

    return ret;
}

int main(){

	char* J = "aA";
	char* S = "aAbbb";

	printf("%c \n", numJewelsInStones(J, S));

	return 0;
}

