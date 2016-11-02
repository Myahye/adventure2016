add_library(Spells Spells.cpp)
set_target_properties(Spells
                      PROPERTIES
                      LINKER_LANGUAGE CXX
                      CXX_STANDARD 14
)
target_link_libraries(Spells BaseClass)
install(TARGETS Spells DESTINATION lib)
set_property(TARGET Spells PROPERTY CXX_STANDARD 14)
