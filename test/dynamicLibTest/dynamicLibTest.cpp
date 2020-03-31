#include "gtest/gtest.h"

extern "C" {
#include "matrix.h"
#include "transpose_thread.h"
}

#define SUCCESS 0

TEST(timeTest, testThread) {
    int rows = 10000, cols = 5000;
    double ** matrix;

    generate(&matrix, rows, cols, -10, 30);
    int status = transpose_thread(&matrix, &rows, &cols);
    EXPECT_EQ(status, SUCCESS);
}
