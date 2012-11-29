include_directories(../src)

add_executable(filesystem filesystem.cpp)
target_link_libraries(filesystem qtwebitemview)

add_executable(simplelistview simplelistview.cpp)
target_link_libraries(simplelistview qtwebitemview)
