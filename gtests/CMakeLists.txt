# 'Google_test' is the subproject name
project(Google_tests)

# 'python_tests' is the folder with Google Test sources
add_subdirectory(googletest)
include_directories(./googletest/googletest/include ./googletest/googletest)

add_executable(eis_tests

        tests/eis_general.cpp
        functions/functions.h
)

target_link_libraries(eis_tests eis_lib)
target_link_libraries(eis_tests gtest gtest_main)