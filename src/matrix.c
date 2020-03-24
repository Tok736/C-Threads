#include "matrix.h"
#include "stdlib.h"
#include "stdio.h"

void generate(double *** matrix, int rows, int cols, int down, int up) {
    double ** current = *matrix;
    current = (double**)malloc(rows * sizeof(double*));
    for (int i = 0; i < rows; i++) {
        current[i] = (double*)malloc(cols * sizeof(double));
        for (int j = 0; j < cols; j++) {
            current[i][j] = rand() % (up - down) + down;
        }
    }
    *matrix = current;
}

void printMatrix(double ** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%8.2lf", matrix[i][j]);
        }
        printf("\n");
    }
}

void freeMatrix(double *** matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free((*matrix)[i]);
    }
    free(*matrix);
}