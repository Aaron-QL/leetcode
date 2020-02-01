#include "../include/my.h"


int climbStairs(int n){
    if (n < 3) {
        return n;
    }

    int first = 1, second = 2, third;
    for (int i = 3; i <= n; i++) {
        third = first + second;
        first = second;
        second = third;
    }

    return third;
}