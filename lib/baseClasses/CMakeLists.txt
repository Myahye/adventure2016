cmake_minimum_required(VERSION 3.2.2)
project (BaseClass)

add_library(BaseClass 
	Room.cpp
	Door.cpp)
target_link_libraries(BaseClass)

install(TARGETS BaseClass DESTINATION lib)

set_property(TARGET BaseClass PROPERTY CXX_STANDARD 14)
