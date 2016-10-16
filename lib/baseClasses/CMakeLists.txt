cmake_minimum_required(VERSION 3.2.2)

add_library(Player_Class
  Player.cpp
)
add_library(NPC_Class
  NPC.cpp
)

set_property(TARGET Player_Classes PROPERTY CXX_STANDARD 14)
