//  Условие ИЗ №2:
//  В вашем распоряжении — прямоугольная матрица из 10 000 x 5000
//  вещественных чисел двойной точности. Составьте наивный алгоритм
//  транспонирования матрицы, а затем реализуйте параллельный
//  алгоритм с использованием нескольких потоков решения этой
//  задачи с учетом оптимизации работы с кэш-памятью.

#include "static/s_transpose.h"
#include "dynamic/d_transpose.h"
#include "defines.h"
#include "matrix.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int userTest() {
    int rows, cols;
    double ** matrix;

    printf("Enter amount of rows and cols: ");
    scanf("%d %d", &rows, &cols);

    generate(&matrix, rows, cols, -10, 30);
    printMatrix(matrix, rows, cols);
    int status = transpose_thread(&matrix, &rows, &cols);
    if (status != SUCCESS) return status;
    printf("\n");
    printMatrix(matrix, rows, cols);
    freeMatrix(&matrix, rows);
    return SUCCESS;
}

int main() {
    srand(time(0));

    int status = userTest();
    if (status != SUCCESS) return status;

    return 0;
}


