//  Условие ИЗ №2:
//  В вашем распоряжении — прямоугольная матрица из 10 000 x 5000
//  вещественных чисел двойной точности. Составьте наивный алгоритм
//  транспонирования матрицы, а затем реализуйте параллельный
//  алгоритм с использованием нескольких потоков решения этой
//  задачи с учетом оптимизации работы с кэш-памятью.

#include "matrix.h"
#include "transpose.h"
#include "transpose_thread.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SUCCESS 0

int userTest() {
    int rows, cols;
    double ** matrix;

    printf("Enter amount of rows and cols: ");
    scanf("%d %d", &rows, &cols);

    generate(&matrix, rows, cols, -10, 30);
    printMatrix(matrix, rows, cols);
    int status = transpose(&matrix, &rows, &cols);
    if (status != SUCCESS) return status;

    printMatrix(matrix, rows, cols);

    status = transpose_thread(&matrix, &rows, &cols);
    if (status != SUCCESS) return status;

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


