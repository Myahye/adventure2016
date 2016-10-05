cmake_minimum_required(VERSION 3.2.2)
project (yamlParse)

add_library(yamlParse yamlParse.cpp)
install(TARGETS yamlParse DESTINATION lib)

set_property(TARGET yamlParse PROPERTY CXX_STANDARD 14)
