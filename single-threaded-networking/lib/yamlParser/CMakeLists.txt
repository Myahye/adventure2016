add_library(yamlParser yamlParser.cpp)
target_link_libraries(yamlParser BaseClass)
target_link_libraries(yamlParser ${CMAKE_SOURCE_DIR}/lib/yaml/libyaml-cpp.a)
install(TARGETS yamlParser DESTINATION lib)
set_property(TARGET yamlParser PROPERTY CXX_STANDARD 14)

