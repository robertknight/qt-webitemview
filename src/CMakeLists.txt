set(SRCS
  WebItemDelegate.cpp
)

add_library(qtwebitemview ${SRCS})
target_link_libraries(qtwebitemview ${QT_LIBRARIES})

