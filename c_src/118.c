

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int* returnSize, int** returnColumnSizes){

    *returnSize = numRows;
    int** arr = malloc(sizeof(int*) * numRows);
    *returnColumnSizes = malloc(sizeof(int) * numRows);

    if (numRows <= 0) {
        return arr;
    }

    for (int i = 1; i <= numRows; i++) {
        (*returnColumnSizes)[i - 1] = i;
        arr[i - 1] = malloc(sizeof(int) * i);
        arr[i - 1][0] = 1;
        arr[i - 1][i - 1] = 1;
        if (i > 2) {
            for (int j = 1; j < i - 1; j++) {
                arr[i - 1][j] = arr[i - 2][j - 1] + arr[i - 2][j];
            }
        }
    }

    return arr;
}

