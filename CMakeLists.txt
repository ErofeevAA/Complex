cmake_minimum_required(VERSION 3.13)
project(complex)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(googletest)

include_directories(googletest/include)

add_executable(complex main.cpp complex.h complex.cpp)

target_link_libraries(complex gtest gtest_main)




