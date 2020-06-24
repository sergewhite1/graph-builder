cmake_minimum_required(VERSION 3.10)

set(PROJECT_NAME wht)

project(${PROJECT_NAME})

add_library(${PROJECT_NAME} OBJECT
  listener/listenable.cpp
  listener/listenable.h
  same_value.h
  same_value.cpp)

message("project: ${PROJECT_NAME}")
message("CMAKE_CURRENT_SOURCE_DIR=${CMAKE_CURRENT_SOURCE_DIR}")

target_include_directories(${PROJECT_NAME} INTERFACE 
  ${CMAKE_CURRENT_SOURCE_DIR}/..)
