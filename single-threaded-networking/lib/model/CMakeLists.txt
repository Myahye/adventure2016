
add_library(model
  CommandParse.cpp
)

set_target_properties(networking
                      PROPERTIES
                      LINKER_LANGUAGE CXX
                      CXX_STANDARD 14
)

install(TARGETS model
  ARCHIVE DESTINATION lib
)


#set_property(TARGET model PROPERTY CXX_STANDARD 14)
