cmake_minimum_required(VERSION 3.2.2)

add_library(BaseClass
	Room.cpp
	Door.cpp
	Player.cpp
	Npc.cpp
	Object.cpp
	Context.cpp
	Spells.cpp)
	set_target_properties(networking
	                      PROPERTIES
	                      LINKER_LANGUAGE CXX
	                      CXX_STANDARD 14
	)
#target_link_libraries(BaseClass)

install(TARGETS BaseClass DESTINATION lib)

set_property(TARGET BaseClass PROPERTY CXX_STANDARD 14)
