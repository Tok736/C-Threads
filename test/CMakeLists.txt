cmake_minimum_required(VERSION 3.9)
project(tests)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(../include)


file(GLOB_RECURSE TEST_CPPS "*/*.cpp")

add_executable(runTest ${TEST_CPPS} test.cpp)

# TODO add lib to further test
target_link_libraries(runTest gtest gtest_main)

add_test(
        NAME runTest
        COMMAND runTest
)


