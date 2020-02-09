#include "../include/my.h"

int maxDepth(struct TreeNode* root)
{
    if (node == NULL) {
        return 0;
    } else {
        return MAX(maxDepth(node->left), maxDepth(node->right)) + 1;
    }
}

