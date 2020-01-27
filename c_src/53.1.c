#include "../include/my.h"

int maxSubArray(int* nums, int numsSize){
    int temp[numsSize];
    int max = temp[0] = nums[0];
    for (int i = 1; i < numsSize; i++) {
        temp[i] = nums[i] + (temp[i-1] > 0 ? temp[i-1] : 0);
    }
    for (int i = 1; i < numsSize; i++) {
        max = max < temp[i] ? temp[i] : max;
    }

    return max;
}

