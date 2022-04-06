cmake_minimum_required(VERSION 3.5)
project(brick VERSION 0.1)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED True)
add_compile_options(-Wall -I include)

add_executable(brick main.c usage.c)

