


# General
######################################
cmake_minimum_required(VERSION 3.22.1)
project(eis)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
######################################

# add subdirectories
######################################
add_subdirectory(eis)
######################################

# main.cpp
######################################
add_executable(eis_run main.cpp)
target_link_libraries(eis_run PRIVATE eis) 
set_target_properties(eis_run PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})
######################################

# Compiler Flags
######################################
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release CACHE STRING "Build type" FORCE)
endif()

target_compile_options(eis_run PRIVATE $<$<CONFIG:Debug>:-g> $<$<CONFIG:Release>:-O3>)
######################################

# Unit Tests
######################################
include(FetchContent)

# Download GoogleTest automatically if not found
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.15.2.zip
  DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)
FetchContent_MakeAvailable(googletest)

enable_testing()

file(GLOB TEST_SOURCES unit_tests/*.cpp)

add_executable(eis_test ${TEST_SOURCES})

# Add unit_tests/ as an include directory
target_include_directories(eis_test PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/unit_tests)

# Place test binary in project root
set_target_properties(eis_test PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}
)

target_link_libraries(eis_test PRIVATE eis GTest::gtest_main)

if(UNIX)
    target_link_libraries(eis_test PRIVATE pthread)
endif()

add_test(NAME eis_test COMMAND eis_test)
######################################

# Pybind 11
######################################
include(FetchContent)

FetchContent_Declare(
  pybind11
  GIT_REPOSITORY https://github.com/pybind/pybind11.git
  GIT_TAG v2.11.0 # or latest stable version
)
FetchContent_MakeAvailable(pybind11)

# Bindings
add_library(eis_lib MODULE ./python_bindings.cpp)
target_link_libraries(eis_lib PRIVATE eis pybind11::module)
set_target_properties(eis_lib PROPERTIES PREFIX "") 

target_include_directories(eis_lib PRIVATE eis_lib/include)

target_compile_features(eis_lib PRIVATE cxx_std_17)

# Optional: make sure you use PIC for shared libs
set_target_properties(eis_lib PROPERTIES POSITION_INDEPENDENT_CODE ON)

# Save the library in the root directory
set_target_properties(eis_lib PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}"
)
######################################





















# General
######################################
#cmake_minimum_required(VERSION 3.26)
#cmake_minimum_required(VERSION 3.22.1)
#project(eis)
#set(CMAKE_CXX_STANDARD 17)
######################################

# Compiler Flags
######################################
#set(CMAKE_BUILD_TYPE Release)
#set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wshadow -Wconversion -Wpedantic -Werror")
#set(CMAKE_CXX_FLAGS_DEBUG "-g")
#set(CMAKE_CXX_FLAGS_RELEASE "-O2")
######################################

# main.cpp
######################################
#set(SOURCE_FILES main.cpp python_exporter.cpp)
#add_executable(eis_main ${SOURCE_FILES})              # uncomment to use main.cpp file
######################################

# find main Python file
######################################
#find_package(Python3 COMPONENTS Interpreter)
#include_directories(${PYTHON_INCLUDE_DIRS})
######################################

# Includes
######################################
#include_directories(eis_lib)
#add_subdirectory(eis_lib)
# target_link_libraries(eis_main eis_lib)               # uncomment to use main.cpp file
######################################

# Google Tests
######################################
#add_subdirectory(gtests)
######################################

# Pybind11
######################################
#add_subdirectory(pybind11)
#pybind11_add_module(eis_library python_exporter.cpp eis_lib/eis.cpp)
######################################