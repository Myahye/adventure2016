cmake_minimum_required(VERSION 3.2.2)

add_library(baseClasses
  room.cpp door.cpp
)
set_property(TARGET baseClasses PROPERTY CXX_STANDARD 14)
