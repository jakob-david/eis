project(eis)

set(HEADER_FILES eis.h)
set(SOURCE_FILES eis.cpp)

add_library(eis_lib ${SOURCE_FILES} ${HEADER_FILES})