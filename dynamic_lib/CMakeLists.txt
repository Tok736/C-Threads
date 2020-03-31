cmake_minimum_required(VERSION 3.9)

project(transpose_dynamic)

add_library(transpose_dynamic SHARED transpose_thread.c transpose_thread.h)

