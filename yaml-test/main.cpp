#include "yaml-cpp/yaml.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

struct NPC {
  int id;
  int armor;
}

void operator >> (const YAML::Node& node, NPC& npc){
  node["id"] >> npc.id;
  node["armor"] >> npc.armor;
}

int main()
{
  std::ifstream fin("shire.yml");
  YAML::Parser parser(fin);
  YAML::Node doc;
  parser.GetNextDocument(doc);
  for(unsigned i=0;i<doc.size();i++) {
    NPC npc;
    doc[i] >> npc;
    std::cout << npc.id << " " << npc.armor << "\n";
  }
  return 0;
}
