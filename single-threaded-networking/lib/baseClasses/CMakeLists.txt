cmake_minimum_required(VERSION 3.2.2)

add_library(BaseClass
	Character.cpp
	Npc.cpp
	Room.cpp
	Door.cpp
	Player.cpp
	Object.cpp
	Spells.cpp
	Context.cpp)
	set_target_properties(networking
	                      PROPERTIES
	                      LINKER_LANGUAGE CXX
	                      CXX_STANDARD 14
	)

install(TARGETS BaseClass DESTINATION lib)

set_property(TARGET BaseClass PROPERTY CXX_STANDARD 14)