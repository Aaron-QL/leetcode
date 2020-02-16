#include "../include/my.h"

//保存单个节点的值的链表
struct LinkedIntNode {
    int val;
    struct LinkedIntNode *next;
};

//保存树中每一层的信息
struct LinkedInts {
    int count;
    struct LinkedIntNode *head;
};

//保存遍历后的总信息
struct TreeTraversalResult {
    int levelLimit;
    struct LinkedInts *levels;
};

/**
 * 初始化result结构
 * @param level 最大层数
 * @return
 */
struct TreeTraversalResult *initTreeTraversalResult(int level) {
    struct TreeTraversalResult *r = (struct TreeTraversalResult *) calloc(1, sizeof(struct TreeTraversalResult));
    r->levelLimit = level;
    r->levels = (struct LinkedInts *) calloc(level, sizeof(struct LinkedInts));

    return r;
}

/**
 * 递归遍历树，保存每个节点的值
 * @param node 当前节点
 * @param currentLevel 当前层
 * @param r
 */
void traversal(struct TreeNode *node, int currentLevel, struct TreeTraversalResult *r) {
    if (node == NULL) {
        return;
    }

    //溢出时重新分配内存
    if (currentLevel >= r->levelLimit) {
        printf("memory overflow");

        struct LinkedInts *newLevels = calloc(r->levelLimit * 2, sizeof(struct TreeTraversalResult));
        memmove(newLevels, r->levels, sizeof(struct LinkedInts) * r->levelLimit);
        r->levelLimit *= 2;
        r->levels = newLevels;
    }

    struct LinkedIntNode *newNode = malloc(sizeof(struct LinkedIntNode));
    newNode->val = node->val;
    newNode->next = r->levels[currentLevel].head;
    r->levels[currentLevel].head = newNode;
    r->levels[currentLevel].count++;

    traversal(node->left, currentLevel + 1, r);
    traversal(node->right, currentLevel + 1, r);
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 * returnSize 是返回的二维数组层数（行数）
 * returnColumnSizes是个二维数组，保存每一行的列数
 */
int **levelOrderBottom(struct TreeNode *root, int *returnSize, int **returnColumnSizes) {
    //初始化数据结构
    struct TreeTraversalResult *result = initTreeTraversalResult(100);
    //遍历二叉树，把树中的值保存成我们方便处理的高级数据结构
    traversal(root, 0, result);

    //判断二维数组的层数（行数）
    for (*returnSize = 0; result->levels[*returnSize].count != 0; (*returnSize)++) {

    }

    //为二维数组分配空间
    int **resultArray = malloc(sizeof(int *) * *returnSize);
    *returnColumnSizes = malloc(sizeof(int) * *returnSize);

    //遍历我们的数据结构，生成二维数组
    int tmp, j;
    struct LinkedIntNode *tmpNode;
    for (int i = *returnSize - 1; i >= 0; i--) {
        tmp = *returnSize - 1 - i;
        j = result->levels[i].count;
        (*returnColumnSizes)[tmp] = j;
        resultArray[tmp] = malloc(sizeof(int) * j);
        tmpNode = result->levels[i].head;

        while (tmpNode != NULL) {
            resultArray[tmp][--j] = tmpNode->val;
            tmpNode = tmpNode->next;
        }
    }

    return resultArray;
}
