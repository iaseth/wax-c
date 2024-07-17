cmake_minimum_required(VERSION 3.0)
project(waxc)

file(GLOB_RECURSE sources src/*.c include/*.h)
add_executable(waxc ${sources})

target_compile_options(waxc PUBLIC -std=c99 -Wall)
target_include_directories(waxc PUBLIC include)
