cmake_minimum_required(VERSION 3.2.2)
project (BaseClass)

add_library(BaseClass Npc.cpp)
target_link_libraries(BaseClass Helper)

install(TARGETS BaseClass DESTINATION lib)

set_property(TARGET BaseClass PROPERTY CXX_STANDARD 14)
