
add_executable(chatserver
  chatserver.cpp
)

target_link_libraries(chatserver
  networking
  model
  authentication
  BaseClass
)

set_target_properties(chatserver
                      PROPERTIES
                      LINKER_LANGUAGE CXX
                      CXX_STANDARD 14
                      PREFIX ""
)

# This program requires boost
find_package(Boost 1.54 COMPONENTS system REQUIRED)
include_directories(${Boost_INCLUDE_DIR})
target_link_libraries(chatserver ${Boost_LIBRARIES})

install(TARGETS chatserver
  RUNTIME DESTINATION bin
)
set_property(TARGET chatserver PROPERTY CXX_STANDARD 14)
