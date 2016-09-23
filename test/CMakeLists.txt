cmake_minimum_required(VERSION 3.2)
project(hello)


include_directories(include)

add_executable(hello hello.cpp test.cpp)

set_property(TARGET hello PROPERTY CXX_STANDARD 14)
