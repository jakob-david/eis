
# General
######################################
#cmake_minimum_required(VERSION 3.26)
cmake_minimum_required(VERSION 3.22.1)
project(eis)
set(CMAKE_CXX_STANDARD 17)
######################################

# Compiler Flags
######################################
set(CMAKE_BUILD_TYPE Release)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wshadow -Wconversion -Wpedantic -Werror")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O2")
######################################

# main.cpp
######################################
set(SOURCE_FILES main.cpp python_exporter.cpp)
# add_executable(eis_main ${SOURCE_FILES})              # uncomment to use main.cpp file
######################################

# find main Python file
######################################
find_package(Python3 COMPONENTS Interpreter)
include_directories(${PYTHON_INCLUDE_DIRS})
######################################

# Includes
######################################
include_directories(eis_lib)
add_subdirectory(eis_lib)
# target_link_libraries(eis_main eis_lib)               # uncomment to use main.cpp file
######################################

# Google Tests
######################################
add_subdirectory(gtests)
######################################

# Pybind11
######################################
add_subdirectory(pybind11)
pybind11_add_module(eis_library python_exporter.cpp eis_lib/eis.cpp)
######################################