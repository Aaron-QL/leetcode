#include "../include/my.h"

int lengthOfLastWord(char * s){
    int len = strlen(s);
    int lastLen = 0;

    while (len > 0 && (s[len - 1] == ' ')) {
        len--;
    }


    while (len-- > 0) {
        if (s[len] == ' ') {
            break;
        } else {
            lastLen++;
        }
    }

    return lastLen;
}

