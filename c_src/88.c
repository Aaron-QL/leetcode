#include "../include/my.h"

//双指针-从前往后
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    int buf[m + 1];//+1是为了防止m=0的情况

    memcpy(buf, nums1, sizeof(int) * m);

    int i = 0, j = 0, k = 0;
    while (i < m && j < n) {
        if (buf[i] < nums2[j]) {
            nums1[k++] = buf[i++];
        } else {
            nums1[k++] = nums2[j++];
        }
    }
    while (i < m) {
        nums1[k++] = buf[i++];
    }
    while (j < n) {
        nums1[k++] = nums2[j++];
    }

}