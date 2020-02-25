

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getRow(int rowIndex, int* returnSize){
    int len = rowIndex + 1;
    *returnSize = len;
    int** arr = malloc(sizeof(int*) * len);

    if (rowIndex < 0) {
        return arr;
    }

    for (int i = 1; i <= len; i++) {
        arr[i - 1] = malloc(sizeof(int) * i);
        arr[i - 1][0] = 1;
        arr[i - 1][i - 1] = 1;
        if (i > 2) {
            for (int j = 1; j < i - 1; j++) {
                arr[i - 1][j] = arr[i - 2][j - 1] + arr[i - 2][j];
            }
        }
    }

    int* ret = malloc(sizeof(int) * len);
    for (int k = 0; k < len; k++) {
        ret[k] = arr[len - 1][k];
    }

    return ret;
}

