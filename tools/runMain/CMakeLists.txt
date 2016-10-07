cmake_minimum_required(VERSION 3.2.2)

add_executable(adventure main.cpp)

#SET(CURSES_USE_NCURSES TRUE)

#find_package(Curses)
#include_directories(${CURSES_INCLUDE_DIR})
#target_link_libraries(cursesexample ${CURSES_LIBRARIES})
target_link_libraries(adventure baseClasses)


set_property(TARGET adventure PROPERTY CXX_STANDARD 14)

install(TARGETS adventure DESTINATION bin)
