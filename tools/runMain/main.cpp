#include "yaml-cpp/yaml.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main() {
	YAML::Node test = YAML::LoadFile("../data/test.yml");
	if (test["username"]) {
		std::cout << test["username"].as<std::string>() << "\n";
		std::cout << test["password"].as<std::string>() << "\n";
	}
	YAML::Node config = YAML::LoadFile("../data/shire.yml");
	const YAML::Node&  NPC_node= config["NPCS"];
	for (auto it = NPC_node.begin(); it != NPC_node.end(); ++it) {
		const YAML::Node& element = *it;
		std::cout << " aaa " << std::endl;
		std::cout << "Armor: " << element["armor"].as<std::string>() << "\n\n";

		for (auto el : element["description"]){
			std::cout << el.as<std::string>() << "\n";
		}
		// const YAML::Node& desc = element["description"];
		
		// for (auto it = desc.begin(); it != desc.end(); ++it) {
		// 	std::cout << it.as<std::string>() << "\n\n";
		// }

		std::cout << "Damage: " << element["damage"].as<std::string>() << "\n\n";
	}
	return 0;
}