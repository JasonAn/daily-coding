cmake_minimum_required(VERSION 3.5)
project(Preprocessor_Solution)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(Preprocessor_Solution ${SOURCE_FILES})