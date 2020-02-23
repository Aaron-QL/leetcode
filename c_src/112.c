bool check(struct TreeNode* node, int cur, int sum)
{
    cur += node->val;

    if (node->left == NULL && node->right == NULL) {
        return cur == sum;
    }

    if (node->left == NULL) {
        return check(node->right, cur, sum);
    }

    if (node->right == NULL) {
        return check(node->left, cur, sum);
    }

    return check(node->left, cur, sum) || check(node->right, cur, sum);

}

bool hasPathSum(struct TreeNode* root, int sum){
    if (root == NULL) {
        return false;
    }
    return check(root, 0, sum);
}
