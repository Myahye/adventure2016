#include "yaml-cpp/yaml.h"
#include "Helper.h"
#include "Npc.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>

void yamlParse() {
	Helper helper();
	Boolean return;
	YAML::Node test = YAML::LoadFile("../data/test.yml");
	if (test["username"]) {
		std::cout << test["username"].as<std::string>() << "\n";
		std::cout << test["password"].as<std::string>() << "\n";
	}
	YAML::Node config = YAML::LoadFile("../data/shire.yml");
	const YAML::Node&  NPC_node= config["NPCS"];
	for (auto it = NPC_node.begin(); it != NPC_node.end(); ++it) {
		const YAML::Node& element = *it;
		//std::cout << "Armor: " << element["armor"].as<std::string>() << "\n\n";
		int id = element["id"].as<int>();
		string shortdesc = element["shortdesc"].as<std::string>();
		return = helper.createNpc(id,shortdesc);
		std::cout << "Create Npc with ID: " + id + " = " + return << "\n\n";
		//helper.getNpc
		// for (auto el : element["description"]){
		// 	//std::cout << el.as<std::string>() << "\n";
		// }

		//std::cout << "Damage: " << element["damage"].as<std::string>() << "\n\n";
	}
}
