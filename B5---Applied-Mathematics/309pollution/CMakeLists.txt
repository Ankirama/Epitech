cmake_minimum_required(VERSION 3.3)
project(309pollution)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(includes)

set(SOURCE_FILES src/main.cpp src/Parsing.cpp)
add_executable(309pollution ${SOURCE_FILES})