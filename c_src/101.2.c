#include "lib/stack.c"


bool check(struct TreeNode *t1, struct TreeNode *t2)
{
    if (t1 == NULL && t2 == NULL) {
        return true;
    }
    if (t1 == NULL || t2 == NULL) {
        return false;
    }

    return t1->val == t2->val;
}

bool isSymmetric(struct TreeNode* root)
{
    if (root == NULL) {
        return true;
    }
    Stack* s = createStack(10);
    push(s, root->left);
    push(s, root->right);

    while (!isEmpty(s)) {
        struct TreeNode* a = pop(s);
        struct TreeNode* b = pop(s);
        if (!check(a, b)) {
            return false;
        }
        if (a != NULL) {
            push(s, a->left);
            push(s, b->right);
            push(s, a->right);
            push(s, b->left);
        }
    }

    return true;
}