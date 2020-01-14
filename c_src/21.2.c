#include "../include/my.h"

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    struct ListNode* prehead = (struct ListNode*) malloc(sizeof(struct ListNode));

    struct ListNode* prev = prehead;

    while (l1 != NULL && l2 != NULL) {
        if (l1->val < l2->val) {
            prev->next = l1;
            l1 = l1->next;
        } else {
            prev->next = l2;
            l2 = l2->next;
        }
        prev = prev->next;
    }

    if (l1 != NULL) {
        prev->next = l1;
    }
    if (l2 != NULL) {
        prev->next = l2;
    }

    return prehead->next;
}

