#include "lib/stack.c"

bool check(struct TreeNode* p, struct TreeNode* q)
{
    if (p == NULL && q == NULL) {
        return true;
    }
    if (p == NULL || q == NULL) {
        return false;
    }

    return p->val == q->val;
}

bool isSameTree(struct TreeNode* p, struct TreeNode* q)
{
    Stack* s = createStack(sizeof(struct TreeNode));
    push(s, p);
    push(s, q);
    while (!isEmpty(s)) {
        p = (struct TreeNode*) pop(s);
        q = (struct TreeNode*) pop(s);
        if (!check(p, q)) {
            return false;
        }
        if (p != NULL) {
            push(s, p->left);
            push(s, q->left);
            push(s, p->right);
            push(s, q->right);
        }
    }

    return true;
}