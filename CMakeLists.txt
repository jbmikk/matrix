cmake_minimum_required (VERSION 2.8.0)
project (matrix)

include(ExternalProject)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall")


# Include externals
# -----------------

include_directories("${CMAKE_BINARY_DIR}/ctest-prefix/src/ctest/src")

externalproject_add(
        ctest
        GIT_REPOSITORY git@github.com:jbmikk/ctest.git
        DOWNLOAD_NAME ctest
        DOWNLOAD_DIR ctest
        INSTALL_COMMAND ""
        UPDATE_DISCONNECTED 1
)


# Matrix
# ------

file(GLOB SOURCES src/*.c)

add_library(matrix ${SOURCES})

target_link_libraries(matrix m)

set_target_properties(matrix PROPERTIES COMPILE_FLAGS "-DLIBRARY")


# Tests
# -----

include_directories("${PROJECT_SOURCE_DIR}/src")

add_executable(matrix_test test/matrix_test.c)

add_dependencies(matrix_test ctest)

target_link_libraries(matrix_test matrix)
