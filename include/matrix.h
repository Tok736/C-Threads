#ifndef C_THREADS_MATRIX_H
#define C_THREADS_MATRIX_H

#include "stdlib.h"
#include "stdio.h"

void generate(double *** matrix, int rows, int cols, int down, int up);
void printMatrix(double ** matrix, int rows, int cols);
void freeMatrix(double *** matrix, int rows);



#endif //C_THREADS_MATRIX_H
