struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2) {
    struct ListNode *dummyHead = (struct ListNode*)calloc(1, sizeof(struct ListNode));
    dummyHead->val = 0;
    int carry = 0, x, y, sum;
    struct ListNode *p = l1, *q = l2, *curr = dummyHead;
    while (p || q) {
        x = p ? p->val : 0;
        y = q ? q->val : 0;
        sum = x + y + carry;
        carry = sum / 10;
        struct ListNode *next = (struct ListNode*)calloc(1, sizeof(struct ListNode));
        next->val = sum % 10;
        curr->next = next;
        curr = curr->next;
        if (p) {
            p = p->next;
        }
        if (q) {
            q = q->next;
        }
    }
    if (carry > 0) {
        struct ListNode *next = (struct ListNode*)calloc(1, sizeof(struct ListNode));;
        next->val = carry;
        curr->next = next;
    }
    return dummyHead->next;
}
