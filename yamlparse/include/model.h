#ifndef MODEL_H
#define MODEL_H

#include "yamlParser.h"

class model{

private:
	std::unordered_map<int,NPC> allNPC;
	std::unordered_map<int,Object> allObjects;
public:
	model();
	void yamlParseAndBuild(const std::string& pathToFile);
	void printAll();
	yamlParser yamlparse;
	// void yamlParseNPC(std::string pathToFile);
	// std::vector<std::string> setDescHelper( const YAML::Node& descNode);
	// std::vector<std::string> setKeywordsHelper( const YAML::Node& keywordsNode);
	// std::vector<std::string> setLongDescHelper( const YAML::Node& longDescNode);

};

#endif
