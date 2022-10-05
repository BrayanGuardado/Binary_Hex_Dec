cmake_minimum_required(VERSION 3.23)
project(Binary_Hex_Deci)

set(CMAKE_CXX_STANDARD 14)

include_directories(Binary_Hex_Deci)

add_executable(Binary_Hex_Deci
        Binary_Hex_Deci/Binary_Hex_Deci.cpp
        Binary_Hex_Deci/Convert.cpp
        Binary_Hex_Deci/Convert.h)
