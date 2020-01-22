#include "../include/my.h"

char* change(char* ret) {
    char* ret_temp = (char *) malloc(sizeof(char) * 1000);
    int count = 1,  j = 0;
    char flag = ret[0];
    for (int i = 1; i < strlen(ret); ++i) {
        if (ret[i] == flag) {
            count++;
        } else {
            j += sprintf(ret_temp + j, "%d%c", count, flag);
            flag = ret[i];
            count = 1;
        }
    }
    sprintf(ret_temp + j, "%d%c", count, flag);
    free(ret);
    return ret_temp;
}

char * countAndSay(int n){
    char* p = (char *) malloc(sizeof(char) * 1000);
    p[0] = '1';
    p[1] = '\0';
    for (int i = 1; i <= n; i++) {
        p = change(p);
    }

    return p;
}
