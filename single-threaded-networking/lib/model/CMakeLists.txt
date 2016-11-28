
add_library(model
							Combatant.cpp
							Fight.cpp
							CombatManager.cpp
            	ModelInterface.cpp
            	Model.cpp)

set_target_properties(networking
                      PROPERTIES
                      LINKER_LANGUAGE CXX
                      CXX_STANDARD 14
)

install(TARGETS model
  ARCHIVE DESTINATION lib
)


set_property(TARGET model PROPERTY CXX_STANDARD 14)

target_link_libraries(model yamlParser)
target_link_libraries(model Resets)
target_link_libraries(model Commands)
