cmake_minimum_required(VERSION 3.2.2)

add_library(helper
  Helper.cpp
)
set_property(TARGET baseClasses PROPERTY CXX_STANDARD 14)
