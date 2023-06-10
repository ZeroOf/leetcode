cmake_minimum_required(VERSION 3.25)
project(leetcode)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_SOURCE_DIR})

file(GLOB_RECURSE SRCS leetcode/editor/en/*.cpp)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/e2239ee6043f73722e7aa812a459f54a28552929.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)


enable_testing()

link_libraries(gtest_main gtest)

add_executable(${PROJECT_NAME} ${SRCS})
include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME})
