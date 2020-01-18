#include "../include/my.h"

int removeElement(int* nums, int numsSize, int val){
    int i = 0, j = 0;
    for (; i < numsSize; i++) {
        if (nums[i] != val) {
            nums[j++] = nums[i];
        }
    }
    return j;
}