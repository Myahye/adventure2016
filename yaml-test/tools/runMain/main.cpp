#include "yaml-cpp/yaml.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main() {
	YAML::Node test = YAML::LoadFile("test.yml");
	if (test["username"]) {
		std::cout << test["username"].as<std::string>() << "\n";
		std::cout << test["password"].as<std::string>() << "\n";
	}
	return 0;
}