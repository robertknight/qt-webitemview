project(qt-webitemview)
cmake_minimum_required(VERSION 2.8)

option(QTWEBITEMVIEW_BUILD_EXAMPLES OFF)

find_package(Qt4 REQUIRED)
set(QT_USE_QTWEBKIT TRUE)
include(${QT_USE_FILE})

set(CMAKE_AUTOMOC TRUE)

add_subdirectory(src)

if (QTWEBITEMVIEW_BUILD_EXAMPLES)
  add_subdirectory(examples)
endif()
