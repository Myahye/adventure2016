#ifndef MODEL_H
#define MODEL_H

#include "yamlParser.h"

class model{

private:
	std::unordered_map<int,NPC> allNPC;

public:
	model();
	void printallNPCmap();
	void yamlParseAndBuild(const std::string& pathToFile);
	yamlParser yamlparse;
	// void yamlParseNPC(std::string pathToFile);
	// std::vector<std::string> setDescHelper( const YAML::Node& descNode);
	// std::vector<std::string> setKeywordsHelper( const YAML::Node& keywordsNode);
	// std::vector<std::string> setLongDescHelper( const YAML::Node& longDescNode);

};

#endif
