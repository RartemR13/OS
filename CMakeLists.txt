cmake_minimum_required(VERSION 3.10)

project(OS)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-O3 -Wall -Wextra")

add_library(OS OS.cpp)