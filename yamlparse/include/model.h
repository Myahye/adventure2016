#ifndef MODEL_H
#define MODEL_H

#include <iostream>
#include "yaml-cpp/yaml.h"
#include "NPC.h"
#include <unordered_map>
#include <fstream>
#include <string>
#include <vector>


class model{

private:
	//std::unordered_map<int,NPC> allNPC;

public:
	model();
	void yamlParseNPC(std::string pathToFile);
	std::vector<std::string> setDescHelper( const YAML::Node& descNode);
	std::vector<std::string> setKeywordsHelper( const YAML::Node& keywordsNode);
	std::vector<std::string> setLongDescHelper( const YAML::Node& longDescNode);

};

#endif
