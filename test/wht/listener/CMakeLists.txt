cmake_minimum_required(VERSION 3.10)

set(PROJECT_NAME test-wht-listener)

project(${PROJECT_NAME})

add_executable(${PROJECT_NAME} main.cpp)

add_test(${PROJECT_NAME}_1 ${PROJECT_NAME} 1)
