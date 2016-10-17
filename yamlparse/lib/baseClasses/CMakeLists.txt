add_library(baseClasses NPC.cpp Object.cpp)
install(TARGETS baseClasses DESTINATION lib)
set_property(TARGET baseClasses PROPERTY CXX_STANDARD 14)

