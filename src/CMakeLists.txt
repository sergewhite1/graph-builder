cmake_minimum_required(VERSION 3.5)

message("ENV Qt5_DIR= $ENV{Qt5_DIR}")

project(graph-builder LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check http://doc.qt.io/qt-5/deployment-android.html for more information.
# They need to be set before the find_package(Qt5 ...) call.

#if(ANDROID)
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    if (ANDROID_ABI STREQUAL "armeabi-v7a")
#        set(ANDROID_EXTRA_LIBS
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libcrypto.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libssl.so)
#    endif()
#endif()

find_package(Qt5 COMPONENTS Charts Widgets REQUIRED)

if(ANDROID)
#  add_library(graph-builder SHARED
#    main.cpp
#    mainwindow.cpp
#    mainwindow.h
#    mainwindow.ui
#  )
else()
  add_executable(graph-builder
    model/graph_model.cpp
    model/graph_model.h
    view/mainwindow.cpp
    view/mainwindow.h
    view/mainwindow.ui
    view_model/graph_view_model.cpp
    view_model/graph_view_model.h
    main.cpp
    $<TARGET_OBJECTS:wht>
  )
endif()

target_link_libraries(graph-builder PRIVATE stdc++ Qt5::Charts Qt5::Widgets)

add_subdirectory(wht)
