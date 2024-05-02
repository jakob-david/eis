
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
set(SOURCE_FILES main.cpp)
add_executable(eis_main ${SOURCE_FILES})
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
target_link_libraries(eis_main eis_lib)
######################################

# Google Tests
######################################
add_subdirectory(gtests)
######################################
