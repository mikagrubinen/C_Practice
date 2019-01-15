/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Note that an empty string is also considered valid.

Example 1:

Input: "()"
Output: true
Example 2:

Input: "()[]{}"
Output: true
Example 3:

Input: "(]"
Output: false
Example 4:

Input: "([)]"
Output: false
Example 5:

Input: "{[]}"
Output: true
*/

#include<stdio.h> 
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>


bool isValid(char* s) {

    if(s[0] == '\0')
        return true;

    int length = strlen(s);
    char stack[length];

    stack[0] = s[0];
    int count = 1;

    for (int i = 1; i < length; ++i)
    {
        switch(s[i])
        {
            case ')':
                if(count != 0 && stack[count-1] == '(')
                {
                    stack[count-1] = '\0';
                    count--;
                }
                else
                    return false;
                break;

            case ']':
                if(count != 0 && stack[count-1] == '[')
                {
                    stack[count-1] = '\0';
                    count--;
                }
                else
                    return false;
                break;

            case '}':
                if(count != 0 && stack[count-1] == '{')
                {
                    stack[count-1] = '\0';
                    count--;
                }
                else
                    return false;
                break;

            case '(':
                stack[count] = s[i];
                count++;
                break;

            case '[':
                stack[count] = s[i];
                count++;
                break;

            case '{':
                stack[count] = s[i];
                count++;
                break;
        }
    }

    if(count != 0)
        return false;
    else
        return true;
}


int main(void) 
{
    char input[] = { '(', '[', ']', ')'};
    printf("%d\n", isValid(input));
    return 0;    
} 
