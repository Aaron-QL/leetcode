#include "../include/my.h"

char * addBinary(char * a, char * b)
{
    int carry = 0;
    int lenA, lenB, lenS;
    lenA = strlen(a);
    lenB = strlen(b);
    lenS = MAX(lenA, lenB);
    char *sum = (char *) calloc((lenS + 2), sizeof(char));
    sum[lenS + 1] = '\0';

    while (lenA > 0 || lenB > 0) {
        if (lenA > 0) {
            carry += a[--lenA] - '0';
        }
        if (lenB > 0) {
            carry += b[--lenB] - '0';
        }
        sum[lenS--] = carry % 2 + '0';
        carry /= 2;
    }

    if (carry > 0) {
        sum[0] = '1';
        return sum;
    } else {
        return sum + 1;
    }
}

