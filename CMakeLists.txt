cmake_minimum_required(VERSION 3.0)
project(waxc)

add_library(waxclib SHARED)
file(GLOB_RECURSE sources lib/*.c include/*.h)
target_sources(waxclib PUBLIC ${sources})
set_target_properties(waxclib PROPERTIES LINKER_LANGUAGE C)

target_compile_options(waxclib PUBLIC -std=c99 -Wall)
target_include_directories(waxclib PUBLIC include)


add_executable(waxc src/waxc.c)
add_dependencies(waxc waxclib)

target_link_libraries(waxc LINK_PUBLIC waxclib)
target_compile_options(waxc PUBLIC -std=c99 -Wall)
target_include_directories(waxc PUBLIC include)
