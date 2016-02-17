cmake_minimum_required(VERSION 3.3)
project(ucd_csci2421_hw4)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp
    node1.cpp
    node1.h)

add_executable(ucd_csci2421_hw4 ${SOURCE_FILES})