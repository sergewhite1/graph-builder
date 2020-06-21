cmake_minimum_required(VERSION 3.5)

set(PROJECT_NAME graph-builder-solution)

project(${PROJECT_NAME})

#set(CMAKE_VERBOSE_MAKEFILE TRUE)

message("project: ${PROJECT_NAME}")

message("BEFORE CMAKE_CXX_FLAGS=${CMAKE_CXX_FLAGS}")

if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
set(CMAKE_CXX_FLAGS "-Wall")
endif()

message("AFTER  CMAKE_CXX_FLAGS=${CMAKE_CXX_FLAGS}")

add_subdirectory(src)
