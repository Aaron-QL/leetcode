//Approach 3: Divide and conquer
char *divideAndConquer(char **, int, int);
char *compare(char *, char *);

char * longestCommonPrefix(char ** strs, int strsSize){
    if (strsSize == 0) {
        return "";
    }

    return divideAndConquer(strs, 0, strsSize - 1);
}

char *divideAndConquer(char **strs, int left, int right)
{
    if (left == right) {
        return strs[left];
    }
    int mid = (left + right) / 2;
    char *leftElite = divideAndConquer(strs, left, mid);
    char *rightElite = divideAndConquer(strs, mid + 1, right);
    return compare(leftElite, rightElite);
}

char *compare(char *s1, char *s2)
{
    int len = strlen(s1) < strlen(s2) ? strlen(s1) : strlen(s2);
    char *p = malloc((len + 1) * sizeof(char));
    char *pp = p;
    while (*s1 == *s2) {
        if (*s1 != '\0') {
            *pp++ = *s1;
        } else {
            break;
        }
        s1++;
        s2++;
    }
    *pp = '\0';
    return p;
}