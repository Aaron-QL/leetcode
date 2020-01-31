#include "../include/my.h"

int mySqrt(int x)
{
    int low = 0, high = x;
    int mid, pow;

    while (low <= high) {
        mid = (low + high) / 2;
        pow = mid * mid;
        if (pow == x) {
            return mid;
        } else if (pow < x) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return high;
}
