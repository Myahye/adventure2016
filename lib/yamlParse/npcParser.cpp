#include "yaml-cpp/yaml.h"
#include "NPC.h"
#include "yamlParser.h"

#include <fstream>
#include <string>
#include <vector>

using namespace std;

void npcParser::push (const int& index){
	npcVector.push_back(
	NPC(npcNode[index]["id"].as<int>(),
		npcNode[index]["shortdesc"].as<string>())
	);
}

int npcParser::findIndexById (const int& id){
	auto it = find(
		npcVector.begin().getId(), 
		npcVector.end().getId(), 
		id
	);
	if (it == npcVector.end())
		return -1;
	return distance(npcVector.begin(), it);
}

int npcParser::getArmor_P (const int& index){
	return npcVector[index].getArmor();
}

string npcParser::getDamage_P (const int& index){
	return npcVector[index].getDamage();
}

int npcParser::getGold_P (const int& index){
	return npcVector[index].getGold();
}

string npcParser::getHit_P (const int& index){
	return npcVector[index].getHit();
}

int npcParser::getId_P (const int& index){
	return npcVector[index].getId();
}

int npcParser::getLevel_P (const int& index){
	return npcVector[index].getLevel();
}

int npcParser::getThac0_P (const int& index){
	return npcVector[index].getThac0();
}

void npcParser::showDesc (const int& index){
	vector<string> desc = npcVector[index].getDesc();
	for (auto d : desc)
		cout << d << endl;
}

void npcParser::showKeywords (const int& index){
	vector<string> keywords = npcVector[index].getKeywords();
	for (auto word : keywords)
		cout << word << endl;
}

void npcParser::showLongDesc (const int& index){
	cout << npcVector[index].getLongDesc() << endl;
}

void npcParser::showShortDesc (const int& index){
	cout << npcVector[index].getShortDesc() << endl;
}