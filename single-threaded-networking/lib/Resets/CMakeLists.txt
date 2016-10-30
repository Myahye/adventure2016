add_library(Resets Resets.cpp)
set_target_properties(Resets
                      PROPERTIES
                      LINKER_LANGUAGE CXX
                      CXX_STANDARD 14
)
target_link_libraries(Resets BaseClass)
install(TARGETS Resets DESTINATION lib)
set_property(TARGET Resets PROPERTY CXX_STANDARD 14)