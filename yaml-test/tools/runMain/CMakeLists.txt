add_executable(test_yaml main.cpp)

#SET(CURSES_USE_NCURSES TRUE)

#find_package(Curses)
#include_directories(${CURSES_INCLUDE_DIR})
#target_link_libraries(cursesexample ${CURSES_LIBRARIES})

set_property(TARGET test_yaml PROPERTY CXX_STANDARD 14)

install(TARGETS test_yaml DESTINATION bin)
