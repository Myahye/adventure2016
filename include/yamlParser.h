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

	void push (const int& index);
	int findIndexById(const int& id);

	int getArmor_P (const int& index);
	string getDamage_P (const int& index);
	int getGold_P (const int& index);
	string getHit_P (const int& index);
	int getId_P (const int& index);
	int getLevel_P (const int& index);
	int getThac0_P (const int& index);

	void showDesc (const int& index);
	void showKeywords (const int& index);
	void showLongDesc (const int& index);
	void showShortDesc (const int& index);
}
#endif