add_library(yamlParser YamlParser.cpp)
target_link_libraries(yamlParser baseClasses)
target_link_libraries(yamlParser ${CMAKE_SOURCE_DIR}/lib/yaml/libyaml-cpp.a)
install(TARGETS yamlParser DESTINATION lib)
set_property(TARGET yamlParser PROPERTY CXX_STANDARD 14)

