#include "gtest/gtest.h"

extern "C" {
#include "matrix.h"
#include "transpose.h"
}

#define SUCCESS 0

TEST(timeTest, testNoThread) {
    int rows = 10000, cols = 5000;
    double ** matrix;

    generate(&matrix, rows, cols, -10, 30);
    int status = transpose(&matrix, &rows, &cols);
    EXPECT_EQ(status, SUCCESS);
}
