cmake_minimum_required(VERSION 3.5)
project(3_way_partition)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(3_way_partition ${SOURCE_FILES})