#include "../include/my.h"

int bruteForce(int i, int n)
{
    if (i > n) {
        return 0;
    }

    if (i == n) {
        return 1;
    }

    return bruteForce(i + 1, n) + bruteForce(i + 2, n);
}

int climbStairs(int n){
    return bruteForce(0, n);
}