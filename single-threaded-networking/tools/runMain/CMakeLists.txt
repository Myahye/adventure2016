add_executable(adventure main.cpp)

#SET(CURSES_USE_NCURSES TRUE)

#find_package(Curses)
#include_directories(${CURSES_INCLUDE_DIR})
#target_link_libraries(cursesexample ${CURSES_LIBRARIES})
target_link_libraries(adventure BaseClass
                                ${CMAKE_SOURCE_DIR}/lib/yaml/libyaml-cpp.a)

set_property(TARGET adventure PROPERTY CXX_STANDARD 14)

install(TARGETS adventure DESTINATION bin)