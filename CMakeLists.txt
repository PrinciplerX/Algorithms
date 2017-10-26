cmake_minimum_required(VERSION 2.8)

project(Algorithms)

set(LIBRARY_OUTPUT_PATH    ${PROJECT_SOURCE_DIR}/build/${CMAKE_BUILD_TYPE}/lib)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build/${CMAKE_BUILD_TYPE}/bin)

message("+------------------------------------------------------------------------")
message("| PROJECT_SOURCE_DIR     = " ${PROJECT_SOURCE_DIR})
message("| PROJECT_BINARY_DIR     = " ${PROJECT_BINARY_DIR})
message("| LIBRARY_OUTPUT_PATH    = " ${LIBRARY_OUTPUT_PATH})
message("| EXECUTABLE_OUTPUT_PATH = " ${EXECUTABLE_OUTPUT_PATH})
message("| CMAKE_BUILD_TYPE       = " ${CMAKE_BUILD_TYPE})
message("+------------------------------------------------------------------------")

add_subdirectory(src)
