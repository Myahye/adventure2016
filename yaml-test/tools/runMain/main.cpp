#include <iostream>
#include <fstream>
#include "yaml-cpp/yaml.h"

int main()
{
  YAML::Node test = YAML::LoadFile("shire.yml");
  if (test["name"]) {
    std::cout << "Name is: " << test["name"].as<std::string>() << "\n";
  }
  std::ofstream fout("shire.yml");
  fout << test;
}
