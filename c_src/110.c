/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int getHeight(struct TreeNode* node)
{
    if (node == NULL) {
        return 0;
    }
    
    int leftHeight = getHeight(node->left);
    int rightHeight = getHeight(node->right);
    
    if (leftHeight > rightHeight) {
        return leftHeight + 1;
    } else {
        return rightHeight + 1;
    }
}

bool isBalanced(struct TreeNode* root){
    if (root == NULL) {
        return true;
    }
    
    int l = getHeight(root->left);
    int r = getHeight(root->right);
    
    int c = l - r;
    if (c < -1 || c > 1) {
        return false;
    }
    
    return isBalanced(root->left) && isBalanced(root->right);
}

