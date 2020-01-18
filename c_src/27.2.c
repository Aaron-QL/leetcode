#include "../include/my.h"

int removeElement(int* nums, int numsSize, int val){
    int i = 0;
    while (i < numsSize) {
        if (nums[i] == val) {
            nums[i] = nums[--numsSize];
        } else {
            i++;
        }
    }
    return i;
}