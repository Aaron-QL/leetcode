#include "../include/my.h"

struct ListNode* newNode()
{
    return (struct ListNode*) malloc(sizeof(struct ListNode));
}

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    struct ListNode* oriNode = newNode();
    struct ListNode* tempNode = oriNode;

    while (l1 != NULL && l2 != NULL) {
        if (l1->val < l2->val) {
            tempNode->val = l1->val;
            l1 = l1->next;
        } else {
            tempNode->val = l2->val;
            l2 = l2->next;
        }
        tempNode->next = newNode();
        tempNode = tempNode->next;
    }

    if (l1 != NULL) {
        tempNode->val = l1->val;
        tempNode->next = l1->next;
    }

    if (l2 != NULL) {
        tempNode->val = l2->val;
        tempNode->next = l2->next;
    }

    return oriNode;
}
