add_library(model Model.cpp)
target_link_libraries(model yamlParser )
install(TARGETS model DESTINATION lib)
set_property(TARGET model PROPERTY CXX_STANDARD 14)

