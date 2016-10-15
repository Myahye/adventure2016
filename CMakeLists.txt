cmake_minimum_required(VERSION 3.2)
project(Player)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib")

include_directories(include)
install (DIRECTORY include/ DESTINATION include/ FILES_MATCHING PATTERN "*.h")

add_subdirectory(lib)
add_subdirectory(tools)