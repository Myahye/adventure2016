#include "Model.h"

// Model::Model(){
//   Door door1("south", {"south door"}, 2);
//   Door door2("north", {"north door"}, 1);
//   Door door3("north");
//   vector<Door> doors1;
//   vector<Door> doors2;
//   doors1.push_back(door1);
//   doors2.push_back(door2);

//   string desc1 ="A room with a passage to the south";
//   string ext_desc1 = " ";
//   string name_room1 = "Room 1";
//   int id_room1 = 1;
//   Room room1(desc1, ext_desc1, name_room1, id_room1, doors1);

//   string desc2 ="A room with a passage to the north";
//   string ext_desc2 = " ";
//   string name_room2 = "Room 2";
//   int id_room2 = 2;
//   Room room2(desc2, ext_desc2, name_room2, id_room2, doors2);

//   this->rooms.insert({2, room2});

//   this->rooms.insert({1, room1});

//   Room roomtmp = this->rooms[1];
//   std::cout << "Room 1 description: " << roomtmp.getDesc() << endl;

//   for (auto & room: this->rooms) {
//       std::cout << "Room Id: " << room.second.getRoomId() <<endl;
//       vector<Door> tmp = room.second.getDoors();
//       std::cout << "Number of doors in room: " << tmp.size() << endl;
//       for(Door door: tmp){
//         std::cout << door.getDir() << endl;
//       }
//   }

// }

//This is what construction will look like
 Model::Model(const std::vector<std::string>& paths){
    for_each(paths.begin(), paths.end(), [this](const std::string& pathToFile){this->yamlParseAndBuild(pathToFile);} );  
    //for_each(paths.begin(), paths.end(), this->yamlParseAndBuild);  

    //yamlParseAndBuild(path);
    this->context = Context{&this->rooms,&this->npcs,&this->objects};
 }

//use subclass to build objects
//each subclass method returns an unordered_map?
void Model::yamlParseAndBuild(const std::string& pathToFile){
  std::cout << "DIFFERENT FILE\n\n\n\n\n\n\n";
  yamlparse.loadFile(pathToFile);
  yamlparse.buildNpcs(this->npcs);
  yamlparse.buildObjects(this->objects);
  yamlparse.buildRooms(this->rooms);
  yamlparse.buildSpells(this->spellsDefenseV);
  //yamlparse.buildResets(this->resets);


  //this->rooms = yamlparse.parseBuildRooms(pathToFile);
  //this->resets = yamlparse.parseBuildResets(pathToFile);
  //not yet implemented
  // this->allPlayers = yamlParse.parseBuildPlayers(pathToFile);

}

void Model::printAll(){
  /*std::cout << "Printing NPC map contents \n";
  int count = 1;
  for ( auto& it : npcs ){
    (it->second).printClass(count);
    count++;
  }
  count =1;
  std::cout << "=============================" << std::endl;
  std::cout << "Printing OBJECT map contents" << std::endl;
  objects[3031].printClass(count);*/

  // for ( auto it = objects.begin(); it != objects.end(); ++it ){
  //   (it->second).printClass(count);
  //   std::cout << std::endl;
  //   count++;
  // }
  // for ( auto it = rooms.begin(); it != rooms.end(); ++it ){
  //    std::cout << "Map 1\nid:" << it->first << "\n";
  //    (it->second).printClass(count);
  //    std::cout << std::endl;
  //    count++;
  // }
  // std::cout << "\n\n\n";
  // count =1;
  // std::cout << "Printing RESET vector contents" << std::endl;
  // for ( auto it = resets.begin(); it != resets.end(); ++it ){
  //     auto r = *it;
  //     r->printClass(count);
  //     std::cout << std::endl;
  //     count++;
  // }
  int count = 1;
  for (auto& it : rooms){
    it.second.printClass(count);
    count++;
  }
  std::cout << rooms.size() << " rooms printed" << std::endl;

  count = 1;
  for (auto& it : spellsDefenseV){
    it.printClass();
    count++;
  }
  std::cout << spellsDefenseV.size() << " defense spells printed" << std::endl;
}

int
Model::createPlayer(const std::string& username, const std::string& password){

  // players[assignedIds] = Player {14441
  //     assignedIds, username, password,
  // };

  Player newPlayer{this->assignedIds, username, password};
  players.insert({this->assignedIds, newPlayer});
  playerLocation[assignedIds] = 1100;
  assignedIds++;
  for (auto & player: players) {
      std::cout << "Player Id: " << player.second.getId() << ", username: " << player.second.getUsername() << ", password: " << player.second.getPassword() << "\n";
  }
  return assignedIds - 1;
}

std::vector<std::tuple<int,std::string,std::string>>
Model::getPlayerCredentialsVector() const {

  std::vector<std::tuple<int,std::string,std::string>> vector;

  for(auto player: players) {
    vector.push_back(std::make_tuple(player.second.getId(),player.second.getUsername(),player.second.getPassword()));
  }

  return vector;
}

std::string
Model::getCurrentRoomDescription(const int& playerId) {

  int currentRoomId = this->playerLocation[playerId];
  std::string response = "\n\n" + this->rooms[currentRoomId].getFullRoomDesc();

  return response;
}

std::string
Model::movePlayer(const int& playerId, const std::string& destDirection){
  std::cout << "Player wants to go " << destDirection << std::endl;
  int currentRoomId  = this->playerLocation[playerId];
  std::cout << "Current room Id: " << currentRoomId << std::endl;
  Room currentRoom = this->rooms[currentRoomId];
  std::vector<Door> currentRoomDoors = currentRoom.getDoors();
  std::cout << "number of doors in room: " << currentRoomDoors.size() << std::endl;

  // for(Door door : currentRoomDoors){
  //   std::cout << "Dir: " << door.getDir() << endl;
  // }

  int destRoomId = currentRoom.getRoomInDir(destDirection);

  if(destRoomId != -1) {
    std::cout << "Destination room Id:: " << currentRoom.getRoomInDir(destDirection) << std::endl;
    //throw custom_errors::NoSuchDoorException();
    this->playerLocation[playerId] = destRoomId;
    return this->players[playerId].getUsername() + "> " + destDirection + getCurrentRoomDescription(playerId);
  } else {
    return this->players[playerId].getUsername() + "> " + "There is no door in the " + destDirection + " direction." + "\n\n";
  }
}
//---------------------------------------------------lawrence Yu
std::string
Model::dummySayCommand(const int& playerId, const std::string& message){
  return this->players[playerId].getUsername() + "> " + message.substr(4) + "\n\n";
}

std::string
Model::lookCommand(const int& playerId, const std::string& command){
  std::string response = this->players[playerId].getUsername() + "> " + command;
  std::string message = command.substr(5);
  std::transform(message.begin(), message.end(), message.begin(), ::tolower);

  int currentRoomId = this->playerLocation[playerId];

  if(message == "room") {
    return response + getCurrentRoomDescription(playerId);
  }

  //-------------------------------------------------look "cardinal direction"

  //will move this to room class later as if isDirection return door.getDesc()
  auto doorsInRoom = this->rooms[currentRoomId].getDoors();

  for(auto& currentDoor : doorsInRoom) {
    if(message == currentDoor.getDir()) {

      response += "\n\n";
      for (auto& each_desc : currentDoor.getDesc()){
        response += each_desc;
      }
      response += "\n";

      return response;
    }
  }

  //-------------------------------------------------look "Npc keyword"

  //will move this to room class later as if isNpc return npc.getfulldesc()
  auto npcsInRoom = this->rooms[currentRoomId].getNpcsInRoom();
  for(auto currentNpc : npcsInRoom) {
    if(checkNpcKeywords(message, currentNpc)) {

      //change for look toddler 1 look toddler 2 look toddler 3 later since it only checks the description of the first duplicate npc?
      response += "\n\n" + currentNpc.second[0].getDesc();
      response += "\n     Wearing: "  + currentNpc.second[0].getNpcEquipmentDesc();
      response += "\n     Carrying: " + currentNpc.second[0].getNpcInventoryDesc() + "\n\n";

      return response;
    }
  }

  //-------------------------------------------------look "Object keyword"

  //will move this to room class later as if isobject return object.getfulldesc()
  /*for(auto objectIdVectorPair : this->rooms[currentRoomId].getObjectsInRoom()) {
    if(checkObjectKeywords(message, objectIdVectorPair)) {
    response += "\n";
      //change for look object 1 look object 2 look object 3 later since it only checks the description of the first duplicate object?
      for(auto descriptionText : objectIdVectorPair.second[0].getExtra().first) {
        response += descriptionText + "\n";
      }
      return response;
    }
  }*/

  return this->players[playerId].getUsername() + "> " + "Cannot find " + message + ", no match. \n\n";
}

//----------------------Lawrence Yu
void Model::reset(){
  for(auto& reset : resets) {
    reset->execute(this->context);
    this->context.setCurrentlySelectedNpc(reset->getCurrentlySelectedNpc());
  }
}

bool Model::checkObjectKeywords(const std::string& message, std::pair<const int,std::vector<Object>>& objectIdVectorPair) {
  // return std::any_of(objectIdVectorPair.second[0].getKeywords().begin(), objectIdVectorPair.second[0].getKeywords().end(), 
  // [&message] (const std::string& keyword) { return message == keyword;});
  for(auto& keyword : objectIdVectorPair.second[0].getKeywords()) {
    if(message == keyword) {
      return true;
    }
  }
  return false;
}
bool Model::checkNpcKeywords(const std::string& message, std::pair<const int,std::vector<Npc>>& npcIdVectorPair) {
  // return std::any_of(npcIdVectorPair.second[0].getKeywords().begin(), npcIdVectorPair.second[0].getKeywords().end(), 
  // [&message] (const std::string& keyword) { return message == keyword;});
  for(auto& keyword : npcIdVectorPair.second[0].getKeywords()) {
    if(message == keyword) {
      return true;
    }
  }
  return false;
}
