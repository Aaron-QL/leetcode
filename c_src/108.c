/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* recursion(int* nums, int low, int high, struct TreeNode* node)
{
    if (low > high) {
        return node;
    }
    
    int mid = (low + high) / 2;
    node = calloc(1, sizeof(struct TreeNode));
    node->val = nums[mid];
    node->left = recursion(nums, low, mid - 1, node->left);
    node->right = recursion(nums, mid + 1, high, node->right);
    
    return node;
}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize){    
    struct TreeNode* root = NULL;
    if (numsSize <= 0) {
        return root;
    }
    
    return recursion(nums, 0, numsSize - 1, root);
}

