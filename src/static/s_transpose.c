#include "static/s_transpose.h"
#include "defines.h"

#include <stdlib.h>

int transpose(double *** matrix, int *rows, int *cols) {
    if (!rows) return ERROR_NULL_POINTER;
    if (!cols) return ERROR_NULL_POINTER;
    if (!matrix) return ERROR_NULL_POINTER;

    double ** current = *matrix;
    double ** temp = (double**)malloc(*cols * sizeof(double*));
    if (!temp) return ERROR_ALLOCATION_MEMORY;

    for (int i = 0; i < *cols; i++) {
        temp[i] = (double*)malloc(*rows * sizeof(double));
        if (!temp[i]) return ERROR_ALLOCATION_MEMORY;
    }

    for (int i = 0; i < *rows; i++) {
        if (!current[i]) return ERROR_NULL_POINTER;
        for (int j = 0; j < *cols; j++) {
            temp[j][i] = current[i][j];
        }
    }

    for (int i = 0; i < *rows; i++) {
        free(current[i]);
    }
    free(current);

    int temp_r = *rows;
    *rows = *cols;
    *cols = temp_r;

    *matrix = temp;
    return SUCCESS;
}


