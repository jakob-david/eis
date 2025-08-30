add_library(eis eis.cpp)

target_include_directories(eis
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)

target_compile_features(eis PUBLIC cxx_std_17)