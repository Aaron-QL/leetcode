//Approach 1: Horizontal scanning
char * longestCommonPrefix(char ** strs, int strsSize){
    if (strsSize == 0) {
        return "";
    }
    char *prefix = malloc((strlen(strs[0]) + 1) * sizeof(char));
    strcpy(prefix, strs[0]);
    for (int i = 1; i < strsSize; i++) {
        compare(prefix, strs[i]);
    }
    return prefix;
}

void compare(char *dest, char *src)
{
    int i;
    for (i = 0; (dest[i] == src[i]) && dest[i] != '\0'; i++) {

    }
    dest[i] = '\0';
}

//Approach 2: Vertical scanning
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