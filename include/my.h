#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>
#include <limits.h>
#include <sys/param.h>
#include <stdbool.h>


char *addBinary(char *, char*);

struct ListNode {
    int val;
    struct ListNode *next;
};


struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct ListNode* deleteDuplicates(struct ListNode* head);

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n);