#include "lib/stack.c"

typedef struct {
    struct TreeNode* node;
    int depth;
} Pair;

Pair* createPair(struct TreeNode* node, int depth) {
    Pair* p = (Pair*) malloc(sizeof(Pair));
    p->node = node;
    p->depth = depth;

    return p;
}

int maxDepth(struct TreeNode* root)
{
    int maxDepth = 0, curDepth = 0;
    if (root == NULL) {
        return maxDepth;
    }

    Stack* s = createStack(10);
    push(s, createPair(root, curDepth + 1));
    while (!isEmpty(s)) {
        Pair* p = pop(s);
        if (p->node != NULL) {
            if (p->depth > maxDepth) {
                maxDepth = p->depth;
            }
            push(s, createPair(p->node->left, p->depth + 1));
            push(s, createPair(p->node->right, p->depth + 1));
        }
    }

    return maxDepth;
}