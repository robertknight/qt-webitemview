include_directories(../src)

add_executable(filesystem filesystem.cpp)
target_link_libraries(filesystem qtwebitemview)
