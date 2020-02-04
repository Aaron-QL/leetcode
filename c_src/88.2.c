#include "../include/my.h"

//双指针-从后往前
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    int p = nums1Size - 1, p1 = m - 1, p2 = n - 1;

    while (p1 >= 0 && p2 >= 0) {
        if (nums1[p1] > nums2[p2]) {
            nums1[p--] = nums1[p1--];
        } else {
            nums1[p--] = nums2[p2--];
        }
    }

    while (p2 >= 0) {
        nums1[p--] = nums2[p2--];
    }
}