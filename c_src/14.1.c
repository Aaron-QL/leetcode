
//Approach 1: Horizontal scanning

void compare(char *dest, char *src)
{
    int i;
    for (i = 0; (dest[i] == src[i]) && dest[i] != '\0'; i++) {

    }
    dest[i] = '\0';
}


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
