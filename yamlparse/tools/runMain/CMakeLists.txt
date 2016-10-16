add_executable(adventure main.cpp)

target_link_libraries(adventure model)
set_property(TARGET adventure PROPERTY CXX_STANDARD 14)

install(TARGETS adventure DESTINATION bin)
