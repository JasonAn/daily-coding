cmake_minimum_required(VERSION 3.5)
project(check_brackets)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -static ")

set(SOURCE_FILES main.cpp)
add_executable(check_brackets ${SOURCE_FILES})