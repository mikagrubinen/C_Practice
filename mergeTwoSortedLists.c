/*
Given a sorted array nums, remove the duplicates in-place such that each element appear only once and return the new length.
Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

Example 1:
Given nums = [1,1,2],
Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.
It doesn't matter what you leave beyond the returned length.

Example 2:
Given nums = [0,0,1,1,1,2,2,3,3,4],
Your function should return length = 5, with the first five elements of nums being modified to 0, 1, 2, 3, and 4 respectively.
It doesn't matter what values are set beyond the returned length.
*/

#include<stdio.h> 
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

struct ListNode{
    int val;
    struct ListNode *next;
};

void addNode(struct ListNode **head_ref, int value){
    struct ListNode *node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = value;

    if(*head_ref == NULL){
        *head_ref = node;
        node->next = NULL;
    }
    else{
        node->next = *head_ref;
        *head_ref = node;
    }
}

void printList(struct ListNode *list){
    if(list == NULL)
        printf("List is empty!\n");
    else{
        struct ListNode *temp = list;
        while(temp != NULL){
            printf("%d\t", temp->val);
            temp = temp->next;
        }
    }
    printf("\n");
}


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *result = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *current = result;
    result->next = NULL;
    result->val = 0;

    if(l1 == NULL && l2 == NULL)
        return NULL;
    
    while(l1 != NULL || l2 != NULL){

        
        if(l1 != NULL && l2 != NULL){
            if(l1->val < l2->val){
                current->next = l1;
                current = current->next;
                l1 = l1->next;
            }
            else{
                current->next = l2;
                current = current->next;
                l2 = l2->next;
            }
        } 
        else if(l1 != NULL && l2 == NULL){
            current->next = l1;
            result = result->next;
            return result;
        }
        else if(l1 == NULL && l2 != NULL){
            current->next = l2;
            result = result->next;
            return result;
        }       
    }

    return result;
}



int main(void) 
{
    struct ListNode *l1 = NULL;
    struct ListNode *l2 = NULL;
    addNode(&l1, 4);
    addNode(&l1, 2);
    addNode(&l1, 1);
    addNode(&l2, 4);
    addNode(&l2, 3);
    addNode(&l2, 1);

    printList(l1);
    printList(l2);

    struct ListNode *result = mergeTwoLists(l1, l2);
    printList(result);
    return 0;    
} 
