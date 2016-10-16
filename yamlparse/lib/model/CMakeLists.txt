add_library(model model.cpp)
target_link_libraries(model NPC )
install(TARGETS model DESTINATION lib)
set_property(TARGET model PROPERTY CXX_STANDARD 14)

