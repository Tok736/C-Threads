cmake_minimum_required(VERSION 3.9)
set(PROJECT_NAME C-Threads)
project(${PROJECT_NAME})


# ==== Flags and C standard  ==== #
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS  "-lm -Wall -Wextra -Werror -Wpedantic -fprofile-arcs -ftest-coverage -lgcov")
set(CMAKE_EXE_LINKER_FLAGS "-lgcov --coverage")

include_directories(include)

file(GLOB_RECURSE SOURCE "src/*.c")
#add_executable(${PROJECT_NAME} main.c ${SOURCE})

# ==== Need for debugging tests ==== #
file(GLOB_RECURSE TEST_CPPS "test/*/*.cpp")
add_executable(${PROJECT_NAME} ${SOURCE} ${TEST_CPPS} test/test.cpp)

# ==== Linking with static and dynamic libs ==== #
target_include_directories(${PROJECT_NAME} PUBLIC static_lib)
add_subdirectory(static_lib)

target_include_directories(${PROJECT_NAME} PUBLIC dynamic_lib)
add_subdirectory(dynamic_lib)

target_link_libraries(${PROJECT_NAME} m transpose_static transpose_dynamic)

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