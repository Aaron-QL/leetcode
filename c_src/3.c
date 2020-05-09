int isContain(char *substr, int length, char c) {
    int i = 0;
    for (; i < length; i++) {
        if (substr[i] == c) {
            return 1;
        }
    }
    return 0;
}

int lengthOfLongestSubstring(char *s) {
    int strLength = (int) strlen(s);
    if (strLength == 0) {
        return 0;
    }
    if (strLength == 1) {
        return 1;
    }
    int i = 0, maxLength = 1;
    for (; i < strLength - maxLength; i++) {
        int j = 1;
        for (; j < strLength - i; j++) {
            if (isContain(s+i, j, s[i + j]) == 1) {
                break;
            } else {
                if ((j + 1) > maxLength) {
                    maxLength = j + 1;
                }
            }
        }
    }
    return maxLength;
}
