#include "model.h"
//#include "NPC.h"

model::model() {};

//use subclass to build objects
//each subclass method returns an unordered_map?
void model::yamlParseAndBuild(const std::string& pathToFile){
  this->allNPC = yamlparse.parseBuildNpcs(pathToFile);
  this->allObjects = yamlparse.parseBuildObjects(pathToFile);
  //not yet implemented
  // this->players = YamlParse.parseBuildPlayers(pathtoyml);
  // this->rooms = YamlParse.parseBuildRooms(pathtoyml);
  // this->objects = YamlParse.parseBuildObjects(pathtoyml);
}


void model::printAll(){
	std::cout << "Prining map contents \n";
	int count = 1;
	for ( auto& it : allNPC ){
    std::cout << "Map 1\nid:" << it.first << "\n";
    (it.second).printClass(count);
  	std::cout << std::endl;
  	count++;
  }
  count =1;
  std::cout << "=============================" << std::endl;
  for ( auto& it : allObjects ){
    std::cout << "Map 1\nid:" << it.first << "\n";
    (it.second).printClass(count);
    std::cout << std::endl;
    count++;
  }
}