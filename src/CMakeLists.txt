set(SOURCES ${SOURCES}
    ${CMAKE_CURRENT_SOURCE_DIR}/linkedlist.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/rpn.cpp
)

add_library(${CMAKE_PROJECT_NAME}_lib STATIC ${SOURCES})