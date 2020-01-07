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
    char *p = s1;
    while (*s1 == *s2) {
        if (*s1 == '\0') {
            break;
        }
        s1++;
        s2++;
    }
    *s1 = '\0';
    return p;
}