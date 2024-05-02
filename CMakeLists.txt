cmake_minimum_required(VERSION 3.28)
project(eis)

set(CMAKE_CXX_STANDARD 17)

add_executable(eis main.cpp
        eis_lib/eis.cpp
        eis_lib/eis.h)
