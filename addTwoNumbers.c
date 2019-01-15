/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. 
Add the two numbers and return it as a linked list. You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
*/

#include<stdio.h> 
#include<stdlib.h>

struct ListNode{
    int val;
    struct ListNode *next;
};

void addNode(int val, struct ListNode** head_ref)
{
    if(*head_ref == NULL){
        struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
        head->val = val;
        head->next = NULL;
        *head_ref = head;
    }
    else{
        struct ListNode* temp = (struct ListNode*)malloc(sizeof(struct ListNode));
        temp->val = val;
        temp->next = *head_ref;
        *head_ref = temp;
    }
}

void printList(struct ListNode* head){
    struct ListNode *temp = head;
    while(temp != NULL){
        printf("%d\t", temp->val);
        temp = temp->next;
    }
}

int makeNum(struct ListNode* list){

    struct ListNode *temp = list;
    int result = 0;
    int i = 1;

    while(temp != NULL){
        result += i * temp->val;    
        temp = temp->next;
        i = i*10;
    }
    return result;
}

void reverse(struct ListNode** list){
    struct ListNode* prev = NULL;
    struct ListNode* cur = *list;
    struct ListNode* next = NULL;

    while(cur != NULL){
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    *list = prev;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {

    struct ListNode* final = NULL;

    int num1 = makeNum(l1);
    int num2 = makeNum(l2);

    int result = num1 + num2;

    printf("num1: %d\n", num1);
    printf("num2: %d\n", num2);
    printf("result: %d\n", result);
    

    int digit;
    if(result == 0){
        addNode(0, &final);
    }
    else{
        while(result > 0){
            digit = result % 10;
            result /= 10;
            addNode(digit, &final);
        }        
    }

    reverse(&final);
    printList(final);

    return final;
}

int main(void) 
{ 
    struct ListNode* l1 = NULL;
    struct ListNode* l2 = NULL;
    
    addNode(3, &l1);
    addNode(4, &l1);
    addNode(2, &l1);

    addNode(4, &l2);
    addNode(6, &l2);
    addNode(5, &l2);

    // printList(l1);
    // printList(l2);

    addTwoNumbers(l1, l2);

    return 0;    
} 
