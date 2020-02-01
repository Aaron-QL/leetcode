#include "../include/my.h"

int bruteForce(int i, int n, int memo[])
{
    if (i > n) {
        return 0;
    }

    if (i == n) {
        return 1;
    }

    if (memo[i] > 0) {
        return memo[i];
    }

    memo[i] = bruteForce(i + 1, n, memo) + bruteForce(i + 2, n, memo);
    return memo[i];
}

int climbStairs(int n){
    int memo[n+1];
    for (int i = 0; i<= n; i++) {
        memo[i] = 0;
    }
    return bruteForce(0, n, memo);
}