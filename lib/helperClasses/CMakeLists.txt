cmake_minimum_required(VERSION 3.2.2)
project (Helper)

add_library(Helper Helper.cpp)
target_link_libraries(Helper BaseClass)

install(TARGETS Helper DESTINATION lib)

set_property(TARGET Helper PROPERTY CXX_STANDARD 14)
