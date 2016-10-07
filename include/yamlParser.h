#ifndef YAMLPARSER_H
#define YAMLPARSER_H

#include <vector>
#include <string>

#include "yaml-cpp/yaml.h"
#include "NPC.h"

using namespace std;

class yamlParser {
public:

};

class npcParser : public yamlParser{
private:
	vector<NPC> npcVector;
	YAML::Node mainNode;
	YAML::Node npcNode;

public:
	npcParser(string& file) : 
	mainNode(YAML::LoadFile(file)),
	npcNode(mainNode["NPCS"]){}

	~npcParser(){}
}
