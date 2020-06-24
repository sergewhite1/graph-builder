cmake_minimum_required(VERSION 3.10)

set(PROJECT_NAME test-wht-listener)

project(${PROJECT_NAME})

add_executable(${PROJECT_NAME} main.cpp $<TARGET_OBJECTS:wht>)

target_include_directories(${PROJECT_NAME} PRIVATE
$<TARGET_PROPERTY:wht,INTERFACE_INCLUDE_DIRECTORIES>)

foreach(i RANGE 1 4)
  add_test(${PROJECT_NAME}_${i} ${PROJECT_NAME} ${i})
endforeach()
