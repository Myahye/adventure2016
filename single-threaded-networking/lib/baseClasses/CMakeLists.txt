cmake_minimum_required(VERSION 3.2.2)

add_library(BaseClass
	CharacterImp.cpp
	Character.cpp
	Room.cpp
	Door.cpp
	Player.cpp
	Object.cpp Context.cpp)
	set_target_properties(networking
	                      PROPERTIES
	                      LINKER_LANGUAGE CXX
	                      CXX_STANDARD 14
	)
#target_link_libraries(BaseClass)

install(TARGETS BaseClass DESTINATION lib)

set_property(TARGET BaseClass PROPERTY CXX_STANDARD 14)
