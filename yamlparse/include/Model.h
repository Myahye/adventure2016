#ifndef MODEL_H
#define MODEL_H

#include "YamlParser.h"

class Model{

private:
	std::unordered_map<int,NPC> allNPC;
	std::unordered_map<int,Object> allObjects;
	std::unordered_map<int,Room> allRooms;
	std::vector<Reset> allResets;
	//std::unordered_map<int,Player> allPlayers
public:
	Model();
	void yamlParseAndBuild(const std::string& pathToFile);
	void printAll();
	YamlParser yamlparse;
	// void yamlParseNPC(std::string pathToFile);
	// std::vector<std::string> setDescHelper( const YAML::Node& descNode);
	// std::vector<std::string> setKeywordsHelper( const YAML::Node& keywordsNode);
	// std::vector<std::string> setLongDescHelper( const YAML::Node& longDescNode);

};

#endif