cmake_minimum_required (VERSION 2.8.0)
project (matrix)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall")


# Matrix
# ------

file(GLOB SOURCES src/*.c)

add_library(matrix ${SOURCES})

set_target_properties(matrix PROPERTIES COMPILE_FLAGS "-DLIBRARY")

