#include "../include/my.h"


int check(char* s1, char* s2, int len)
{
    for (int i = 0; i < len; i++) {
        if (s1[i] != s2[i]) {
            return 0;
        }
    }
    return 1;
}

int myStrStr(char * haystack, char * needle)
{
    int len1 = strlen(haystack);
    int len2 = strlen(needle);
    if (len2 == 0) {
        return 0;
    }
    if (len1 < len2) {
        return -1;
    }
    for (int i = 0; i <= len1 - len2; i++) {
        if (check(haystack + i, needle, len2)) {
            return i;
        }
    }
    return -1;
}
