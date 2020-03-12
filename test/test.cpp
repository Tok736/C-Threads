#include "gtest/gtest.h"

extern "C" {

}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(test, small) {
    EXPECT_EQ(4,4);
}
