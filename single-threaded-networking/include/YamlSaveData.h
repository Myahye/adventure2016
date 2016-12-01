#ifndef YamlSaveData_H
#define YamlSaveData_H

#include "yaml-cpp/yaml.h"
#include "Model.h"
#include <iostream>
#include <fstream>
#include <string>

class YamlSaveData{

public:
	void saveUserData(const std::unordered_map<int,Player>& players);
	void emitVectorStrings(std::string name, YAML::Emitter& emitter, std::vector<std::string>& stringV);
	void emitVectorObjects(YAML::Emitter& emitter, std::vector<Object>& objectV);
	void emitMapObjects(YAML::Emitter& emitter, std::unordered_map<int, Object>& objectM);
	void emitObjectExtra(std::string pair_one, std::string pair_two, YAML::Emitter& emitter, std::vector< std::pair< std::vector<std::string>, std::vector<std::string> > >& extraV);
	void updateOrAddPlayer(std::unordered_map<int,Player>& players, Player& player);
	void deletePlayer(std::unordered_map<int,Player>& players, Player& player);
};	

#endif