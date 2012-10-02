project(qt-webitemview)
cmake_minimum_required(VERSION 2.8)

find_package(Qt4 REQUIRED)
set(QT_USE_QTWEBKIT TRUE)
include(${QT_USE_FILE})

set(CMAKE_AUTOMOC TRUE)

add_subdirectory(src)
add_subdirectory(examples)
