cmake_minimum_required(VERSION 3.9)
set(PROJECT_NAME C-Threads)
project(${PROJECT_NAME})

set(CMAKE_C_STANDARD 11)
# TODO add flags for coveralls
set(CMAKE_C_FLAGS  "-lm")

include_directories(include)

add_executable(${PROJECT_NAME} src/main.c)
target_link_libraries(${PROJECT_NAME} m)

