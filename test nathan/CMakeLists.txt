cmake_minimum_required(VERSION 3.20)
project(test_nathan C)

set(CMAKE_C_STANDARD 99)

add_executable(test_nathan main.c functions.c functions.h)
