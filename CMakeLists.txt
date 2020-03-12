cmake_minimum_required(VERSION 3.9)
set(PROJECT_NAME C-Threads)
project(${PROJECT_NAME})

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS  "-lm -fprofile-arcs -ftest-coverage -lgcov")
set(CMAKE_EXE_LINKER_FLAGS "-lgcov --coverage")

include_directories(include)

add_executable(${PROJECT_NAME} src/main.c)

# ==== Need for debugging tests ==== #
#file(GLOB_RECURSE TEST_CPPS "test/*/*.cpp")
#add_executable(${PROJECT_NAME} ${TEST_CPPS} test/test.cpp)

target_link_libraries(${PROJECT_NAME} m)


# ==== Linking with Google test ==== #
enable_testing()

add_subdirectory(googletest)
add_subdirectory(test)
#include googletest/include dir
include_directories(googletest/googletest/include)

#include the googlemock/include dir
include_directories(googletest/googlemock/include)

#Link with GoogleTest
target_link_libraries(${PROJECT_NAME} gtest gtest_main)

#Link with GoogleMock
target_link_libraries(${PROJECT_NAME} gmock gmock_main)