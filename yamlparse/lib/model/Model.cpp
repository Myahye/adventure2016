#include "Model.h"
//#include "NPC.h"

Model::Model() {};

//use subclass to build objects
//each subclass method returns an unordered_map?
void Model::yamlParseAndBuild(const std::string& pathToFile){
  this->allNPC = yamlparse.parseBuildNpcs(pathToFile);
  this->allObjects = yamlparse.parseBuildObjects(pathToFile);
  this->allRooms = yamlparse.parseBuildRooms(pathToFile);
  this->allResets = yamlparse.parseBuildResets(pathToFile);
  //not yet implemented
  // this->allPlayers = yamlParse.parseBuildPlayers(pathToFile);

}


void Model::printAll(){
  std::cout << "Prining map contents \n";
  int count = 1;
  // for ( auto it = allNPC.begin(); it != allNPC.end(); ++it ){
  //   std::cout << "Map 1\nid:" << it->first << "\n";
  //   (it->second).printClass(count);
  //   std::cout << std::endl;
  //   count++;
  // }
  // count =1;
  // std::cout << "=============================" << std::endl;
  // for ( auto it = allObjects.begin(); it != allObjects.end(); ++it ){
  //   std::cout << "Map 1\nid:" << it->first << "\n";
  //   (it->second).printClass(count);
  //   std::cout << std::endl;
  //   count++;
  // }
  for ( auto& it : allRooms ){
     std::cout << "Map 1\nid:" << it.first << "\n";
     (it.second).printClass(count);
     std::cout << std::endl;
     count++;
  }

  count = 1;
  for ( auto& it : allResets ){
     std::cout << "Vec 1\n";
     (it).printClass(count);
     std::cout << std::endl;
     count++;
  }
}