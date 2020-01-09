#include "../include/my.h"


//Approach 4: Binary search
int isCommonPrefix(char **, int, int);

char *longestCommonPrefix(char ** strs, int strsSize){
    if (strsSize == 0) {
        return "";
    }

    int minLen = INT_MAX;
    for (int i = 0; i < strsSize; i++) {
        minLen = MIN(minLen, strlen(strs[i]));
    }

    int low = 0, high = minLen;
    while (low <= high) {
        int middle = (low + high) / 2;
        if (isCommonPrefix(strs, middle, strsSize)) {
            low = middle + 1;
        } else {
            high = middle - 1;
        }
    }
    minLen = MIN(low, high);

    char *p = malloc((minLen + 1) * sizeof(char));
    strncpy(p, strs[0], minLen);
    printf("%s\n", p);
    return p;
}

int isCommonPrefix(char **strs, int len, int strsSize)
{
    if (strsSize < 2) {
        return 1;
    }
    char *first = strs[0];
    char *tmp;
    for (int i = 1; i < strsSize; i++) {
        tmp = strs[i];
        for (int j = 0; j < len; j++) {
            if (first[j] != strs[i][j]) {
                return 0;
            }
        }
    }
    return 1;
}