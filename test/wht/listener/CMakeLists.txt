cmake_minimum_required(VERSION 3.10)

set(PROJECT_NAME test-wht-listener)

project(${PROJECT_NAME})

add_executable(${PROJECT_NAME} main.cpp)

foreach(i RANGE 1 2)
  add_test(${PROJECT_NAME}_${i} ${PROJECT_NAME} ${i})
endforeach()
