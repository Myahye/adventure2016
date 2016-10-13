add_subdirectory(yamlParse)
add_library(room
  room.cpp
  door.cpp
)
set_property(TARGET room PROPERTY CXX_STANDARD 14)
