#include "../include/my.h"

//动态规划（Kadane 算法）
int maxSubArray(int* nums, int numsSize){
    int maxSum= nums[0];
    for (int i = 1; i < numsSize; i++) {
        if (nums[i-1] > 0) {
            nums[i] += nums[i-1];
        }
        maxSum = MAX(nums[i], maxSum);
    }

    return maxSum;
}

