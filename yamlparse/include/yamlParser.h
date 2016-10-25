#ifndef YAMLPARSER_H
#define YAMLPARSER_H

#include "NPC.h"
#include "Object.h"
#include "Room.h"
#include "yaml-cpp/yaml.h"
#include <unordered_map>


class yamlParser{
public:
	yamlParser();
	std::unordered_map<int,NPC> parseBuildNpcs(const std::string& pathToFile);
	std::unordered_map<int,Object> parseBuildObjects(const std::string& pathToFile);
	std::unordered_map<int,Room> parseBuildRooms(const std::string& pathToFile);

	//helper methods - maybe seperate this into another class?
	std::vector<std::string> setStringVectorHelper( const YAML::Node& descNode);
	
};

#endif