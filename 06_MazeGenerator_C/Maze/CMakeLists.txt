cmake_minimum_required(VERSION 3.24)
project(untitled C)

set(CMAKE_C_STANDARD 11)

add_executable(untitled cmake-build-debug/src/main.c cmake-build-debug/src/stack.h cmake-build-debug/src/stack.c cmake-build-debug/src/types.h)
