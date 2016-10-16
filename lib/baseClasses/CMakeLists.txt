cmake_minimum_required(VERSION 3.2.2)

add_library(Player Player.cpp)
add_library(NPC NPC.cpp)

set_property(TARGET Player PROPERTY CXX_STANDARD 14)
set_property(TARGET NPC PROPERTY CXX_STANDARD 14)