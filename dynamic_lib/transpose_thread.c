#include "transpose_thread.h"

#include <pthread.h>
#include <stdlib.h>
#include <sys/sysinfo.h>
#include <stdio.h>

#define ERROR_NULL_POINTER        -14
#define ERROR_ALLOCATION_MEMORY   -13
#define ERROR_CREATE_THREAD       -11
#define ERROR_JOIN_THREAD         -12
#define SUCCESS                    0

typedef struct {
    double** current;
    double** temp;
    int col_start;
    int col_end;
    int rows;
} Matrix;

void * parted_transpose(void * args) {
    Matrix * matrix = (Matrix*)args;
    for (int i = matrix->col_start; i < matrix->col_end; i++) {
        matrix->temp[i] = (double*)malloc(matrix->rows * sizeof(double));
    }
    for (int i = matrix->col_start; i < matrix->col_end; i++) {
        for (int j = 0; j < matrix->rows; j++) {
            matrix->temp[i][j] = matrix->current[j][i];
        }
    }
    return SUCCESS;
}

int transpose_thread(double*** matrix, int* rows, int* cols) {
    if (!rows) return ERROR_NULL_POINTER;
    if (!cols) return ERROR_NULL_POINTER;
    if (!matrix) return ERROR_NULL_POINTER;

    int temp_rows = *rows, temp_cols = *cols;
    int threads_amount = get_nprocs();

    double ** current = *matrix;
    double ** temp = (double**)malloc(*cols * sizeof(double*));
    if (!temp) return ERROR_ALLOCATION_MEMORY;


    Matrix * matrixes = (Matrix*)malloc(threads_amount * sizeof(Matrix));
    if (!matrixes) return ERROR_ALLOCATION_MEMORY;
    int d_col = temp_cols / threads_amount;
    for (int i = 0; i < threads_amount; i++) {
        matrixes[i].rows = temp_rows;
        matrixes[i].current = current;
        matrixes[i].temp = temp;
        matrixes[i].col_start = d_col * i;
        matrixes[i].col_end = d_col * (i + 1);
    }
    matrixes[threads_amount - 1].col_end = temp_cols;

    int status_addr;
    pthread_t * thread_id = (pthread_t*)malloc(threads_amount * sizeof(pthread_t));

    for (int i = 0; i < threads_amount; i++) {
        int status;
        status = pthread_create(&(thread_id[i]), NULL, parted_transpose, &matrixes[i]);
        if (status != SUCCESS) {
            return ERROR_CREATE_THREAD;
        }
    }

    for (int i = 0; i < threads_amount; i++) {
        int status;
        status = pthread_join(thread_id[i], (void**)&status_addr);
        if (status != SUCCESS) {
            return ERROR_JOIN_THREAD;
        }
    }

    for (int i = 0; i < *rows; i++) {
        free(current[i]);
    }
    free(current);

    *cols = temp_rows;
    *rows = temp_cols;

    *matrix = temp;
    return 0;
}


