#include "gtest/gtest.h"
#include "matrix.h"
#include "dynamic/d_transpose.h"
#include "static/s_transpose.h"
#include "defines.h"

TEST(testStartTest, simple) {
    int rows = 10000, cols = 5000;
    double ** matrix;

    generate(&matrix, rows, cols, -10, 30);
    printMatrix(matrix, rows, cols);
    int status = transpose_thread(&matrix, &rows, &cols);
    EXPECT_EQ(status, SUCCESS);
}
