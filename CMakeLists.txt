cmake_minimum_required(VERSION 3.16)
project(leetcode)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_SOURCE_DIR})

file(GLOB_RECURSE SRCS leetcode/editor/en/*.cpp)

add_executable(${PROJECT_NAME} ${SRCS} main.cpp)
add_subdirectory(test)