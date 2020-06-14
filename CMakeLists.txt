cmake_minimum_required(VERSION 3.5)

message("BEFORE CMAKE_CXX_FLAGS=${CMAKE_CXX_FLAGS}")

if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
set(CMAKE_CXX_FLAGS "-Wall -g")
endif()

message("AFTER  CMAKE_CXX_FLAGS=${CMAKE_CXX_FLAGS}")

add_subdirectory(src)
