int check(struct TreeNode* node)
{
    if (node == NULL) {
        return 0;
    }

    if (node->left == NULL && node->right == NULL) {
        return 1;
    }

    if (node->left == NULL) {
        return check(node->right) + 1;
    }

    if (node->right == NULL) {
        return check(node->left) + 1;
    }

    int left = check(node->left);
    int right = check(node->right);

    printf("left:%d,right:%d\n", left, right);

    if (left < right) {
        return left + 1;
    } else {
        return right + 1;
    }
}

int minDepth(struct TreeNode* root)
{
    return check(root);
}