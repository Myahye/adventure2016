#ifndef YAMLPARSER_H
#define YAMLPARSER_H

#include "NPC.h"
#include "Object.h"
#include "yaml-cpp/yaml.h"
#include <unordered_map>


class yamlParser{
public:
	yamlParser();
	std::unordered_map<int,NPC> parseBuildNpcs(const std::string& pathToFile);
	std::unordered_map<int,Object> parseBuildObjects(const std::string& pathToFile);
	//helper methods - maybe seperate this into another class?
	std::vector<std::string> setDescHelper( const YAML::Node& descNode);
	std::vector<std::string> setKeywordsHelper( const YAML::Node& keywordsNode);
	std::vector<std::string> setLongDescHelper( const YAML::Node& longDescNode);
};

#endif