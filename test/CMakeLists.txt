cmake_minimum_required(VERSION 3.9)
project(tests)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(../include ../dynamic_lib ../static_lib)


file(GLOB_RECURSE TEST_CPPS "*/*.cpp")
add_executable(runTest test.cpp ${TEST_CPPS})

# TODO add lib to further test
target_link_libraries(runTest gtest gtest_main transpose_dynamic transpose_static)

add_test(
        NAME runTest
        COMMAND runTest
)


