#include "../include/my.h"

//贪心算法
int maxSubArray(int* nums, int numsSize){
    int maxSum= nums[0], curSum = nums[0];
    for (int i = 1; i < numsSize; i++) {
        curSum = MAX(nums[i], curSum + nums[i]);
        maxSum = MAX(curSum, maxSum);
    }

    return maxSum;
}

