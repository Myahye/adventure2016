#ifndef YAMLPARSER_H
#define YAMLPARSER_H

#include "NPC.h"
#include "Object.h"
#include "Room.h"
#include "Door.h"
#include "Reset.h"
#include "yaml-cpp/yaml.h"
#include <unordered_map>


class YamlParser{
public:
	YamlParser();
	std::unordered_map<int,NPC> parseBuildNpcs(const std::string& pathToFile);
	std::unordered_map<int,Object> parseBuildObjects(const std::string& pathToFile);
	std::unordered_map<int,Room> parseBuildRooms(const std::string& pathToFile);
	std::vector<Reset> parseBuildResets(const std::string& pathToFile);

	//helper methods - maybe seperate this into another class?
	std::vector<std::string> setStringVectorHelper( const YAML::Node& descNode);
	
};

#endif