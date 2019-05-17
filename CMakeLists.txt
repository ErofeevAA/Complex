cmake_minimum_required(VERSION 3.13)
project(complex)

set(CMAKE_CXX_STANDARD 14)

find_package(GTest REQUIRED)
find_package(Threads REQUIRED)

include_directories(${gtest_SOURCE_DIR}/include${gtest_SOURCE_DIR})

enable_testing()


add_executable(complex main.cpp complex.h complex.cpp)

