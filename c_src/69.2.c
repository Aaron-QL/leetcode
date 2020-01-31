#include "../include/my.h"

int mySqrt(int x)
{
    if (x == 1) {
        return 1;
    }
    int a = x / 2;
    while (a * a > x) {
        a = (a + x / a) / 2;
    }

    return a;
}
