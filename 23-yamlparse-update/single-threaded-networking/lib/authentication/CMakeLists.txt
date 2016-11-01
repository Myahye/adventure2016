
add_library(authentication
  Authentication.cpp
)

set_target_properties(authentication
                      PROPERTIES
                      LINKER_LANGUAGE CXX
                      CXX_STANDARD 14
)

install(TARGETS authentication
  ARCHIVE DESTINATION lib
)
set_property(TARGET authentication PROPERTY CXX_STANDARD 14)
