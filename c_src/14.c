
char * longestCommonPrefix(char ** strs, int strsSize){
    char *first = strs[0];
    char item;
    int i, j;
    for (i = 0; i < strlen(first); i++) {
        item = first[i];
        if (!item) {
            break;
        }
        for (j = 1; j < strsSize; j++) {
            if (strs[j][i] != item) {
                goto END;
            }
        }
    }
    END:
    first[i] = '\0';
    return first;
}