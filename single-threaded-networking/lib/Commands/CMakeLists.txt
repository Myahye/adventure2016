add_library(Commands Commands.cpp)
set_target_properties(Commands
                      PROPERTIES
                      LINKER_LANGUAGE CXX
                      CXX_STANDARD 14
)
target_link_libraries(Commands BaseClass)
install(TARGETS Commands DESTINATION lib)
set_property(TARGET Commands PROPERTY CXX_STANDARD 14)