#include "../include/my.h"

struct ListNode* deleteDuplicates(struct ListNode* head){
    struct ListNode *current = head;
    while (current != NULL && current->next != NULL) {
        if (current->val == current->next->val) {
            current->next = current->next->next;
        } else {
            current = current->next;
        }
    }
    return head;
}