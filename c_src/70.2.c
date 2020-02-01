#include "../include/my.h"


int climbStairs(int n){
    if (n <= 2) {
        return n;
    }
    int buf[n + 1];
    buf[1] = 1;
    buf[2] = 2;
    for (int i = 3; i <= n; i++) {
        buf[i] = buf[i - 1] + buf[i - 2];
    }

    return buf[n];
}