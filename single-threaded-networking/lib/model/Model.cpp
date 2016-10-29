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
//       std::cout << "Room ID: " << room.second.getRoomId() <<endl;
//       vector<Door> tmp = room.second.getDoors();
//       std::cout << "Number of doors in room: " << tmp.size() << endl;
//       for(Door door: tmp){
//         std::cout << door.getDir() << endl;
//       }
//   }

// }

//This is what construction will look like
 Model::Model(const std::string& path){
   yamlParseAndBuild(path);
   this->context = Context{&this->rooms,&this->npcs,&this->objects};
 }

//use subclass to build objects
//each subclass method returns an unordered_map?
void Model::yamlParseAndBuild(const std::string& pathToFile){
  this->npcs = yamlparse.parseBuildNpcs(pathToFile);
  this->objects = yamlparse.parseBuildObjects(pathToFile);
  this->rooms = yamlparse.parseBuildRooms(pathToFile);
  this->resets = yamlparse.parseBuildResets(pathToFile);

  printAll();
  //not yet implemented
  // this->allPlayers = yamlParse.parseBuildPlayers(pathToFile);

}

void Model::printAll(){
  std::cout << "Printing map contents \n";
  int count = 1;
  // for ( auto it = npcs.begin(); it != npcs.end(); ++it ){
  //   std::cout << "Map 1\nid:" << it->first << "\n";
  //   (it->second).printClass(count);
  //   std::cout << std::endl;
  //   count++;
  // }
  count =1;
  std::cout << "=============================" << std::endl;
  for ( auto it = objects.begin(); it != objects.end(); ++it ){
    std::cout << "Map 1\nid:" << it->first << "\n";
    (it->second).printClass(count);
    std::cout << std::endl;
    count++;
  }
  // for ( auto it = rooms.begin(); it != rooms.end(); ++it ){
  //    std::cout << "Map 1\nid:" << it->first << "\n";
  //    (it->second).printClass(count);
  //    std::cout << std::endl;
  //    count++;
  // }
  //  for ( auto it = resets.begin(); it != resets.end(); ++it ){
  //    std::cout << "Map 3\nid:" << "\n";
  //      auto r = *it;
  //      r->printClass(count);
  //    std::cout << std::endl;
  //    count++;
  // }
}

int
Model::createPlayer(const std::string& username, const std::string& password){

  // players[assignedIDs] = Player {14441
  //     assignedIDs, username, password,
  // };

  Player newPlayer{this->assignedIDs, username, password};
  players.insert({this->assignedIDs, newPlayer});
  playerLocation[assignedIDs] = 1100;
  assignedIDs++;
  for (auto & player: players) {
      std::cout << "Player ID: " << player.second.getId() << ", username: " << player.second.getUsername() << ", password: " << player.second.getPassword() << "\n";
  }
  return assignedIDs - 1;
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
Model::getCurrentRoomDescription(const int& playerID) {

  int currentRoomID = this->playerLocation[playerID];
  std::string response = this->players[playerID].getUsername() + ">\n";

  response += this->rooms[currentRoomID].getFullRoomDesc();

  return response;
}

std::string
Model::movePlayer(const int& playerID, const std::string& destDirection){
  std::cout << "Player wants to go " << destDirection << std::endl;
  int currentRoomID  = this->playerLocation[playerID];
  std::cout << "Current room ID: " << currentRoomID << std::endl;
  Room currentRoom = this->rooms[currentRoomID];
  std::vector<Door> currentRoomDoors = currentRoom.getDoors();
  std::cout << "number of doors in room: " << currentRoomDoors.size() << std::endl;

  // for(Door door : currentRoomDoors){
  //   std::cout << "Dir: " << door.getDir() << endl;
  // }

  int destRoomID = currentRoom.getRoomInDir(destDirection);

  if(destRoomID != -1) {
    std::cout << "Destination room ID:: " << currentRoom.getRoomInDir(destDirection) << std::endl;
    //throw custom_errors::NoSuchDoorException();
    this->playerLocation[playerID] = destRoomID;
    return getCurrentRoomDescription(playerID);
  } else {
    return this->players[playerID].getUsername() + "> " + "There is no door in that direction." + "\n\n";
  }
}
//---------------------------------------------------lawrence Yu
std::string
Model::dummySayCommand(const int& playerID, const std::string& message){
  return this->players[playerID].getUsername() + "> " + message.substr(4) + "\n\n";
}

std::string
Model::lookCommand(const int& playerID, const std::string& command){
  std::string message = command.substr(5);
  std::transform(message.begin(), message.end(), message.begin(), ::tolower);

  if(message == "room") {
    return getCurrentRoomDescription(playerID);
  }

  int currentRoomID = this->playerLocation[playerID];
  std::string response = this->players[playerID].getUsername() + "> ";

  //-------------------------------------------------look "cardinal direction"

  auto doorsInRoom = this->rooms[currentRoomID].getDoors();
  for(auto currentDoor : doorsInRoom) {
    if(message == currentDoor.getDir()) {
      response += currentDoor.getDesc() += "\n";

      return response;
    }
  }

  //-------------------------------------------------look "NPC keyword"

  auto npcsInRoom = this->rooms[currentRoomID].getNpcsInRoom();
  for(auto currentNpc : npcsInRoom) {
    if(/*checkNpcKeywords(message, currentNpc)*/message == currentNpc.second[0].getKeywords()[0]) {

      //change for look toddler 1 look toddler 2 look toddler 3 later?
      response += "\n" + currentNpc.second[0].getDesc();
      response += "\n     Wearing: "  + currentNpc.second[0].getNpcEquipmentDesc();
      response += "\n     Carrying: " + currentNpc.second[0].getNpcInventoryDesc() + "\n\n";

      return response;
    }
  }

  //-------------------------------------------------look "Object keyword"

  response += "\n";
  for(auto objectIDVectorPair : this->rooms[currentRoomID].getObjectsInRoom()) {
    if(message == objectIDVectorPair.second[0].getKeywords()[0]) {
      for(auto descriptionText : objectIDVectorPair.second[0].getExtra().first) {
        response += descriptionText + "\n";
      }
      response += "\n";
      return response;
    }
  }

  std::cout << "OIGJWEIOGJWO: " << objects[1102].getExtra().first.size() << std::endl;

  return this->players[playerID].getUsername() + "> " + "Cannot find " + message + ", no match. \n\n";
}

//----------------------Lawrence Yu
void Model::reset(){
  for(auto& reset : resets) {
    reset->execute(this->context);
    this->context.setCurrentlySelectedNPC(reset->getCurrentlySelectedNPC());
  }
}

bool Model::checkObjectKeywords(const std::string& message, std::pair<const int,std::vector<Object>>& objectIDVectorPair) {
  // return std::any_of(objectIDVectorPair.second[0].getKeywords().begin(), objectIDVectorPair.second[0].getKeywords().end(), 
  // [&message] (const std::string& keyword) { return message == keyword;});
  for(auto& keyword : objectIDVectorPair.second[0].getKeywords()) {
    if(message == keyword) {
      return true;
    }
  }
  return false;
}
bool Model::checkNpcKeywords(const std::string& message, std::pair<const int,std::vector<NPC>>& npcIDVectorPair) {
  // return std::any_of(npcIDVectorPair.second[0].getKeywords().begin(), npcIDVectorPair.second[0].getKeywords().end(), 
  // [&message] (const std::string& keyword) { return message == keyword;});
  for(auto& keyword : npcIDVectorPair.second[0].getKeywords()) {
    if(message == keyword) {
      return true;
    }
  }
  return false;
}

// std::string Model::getObjectExtraDesc(std::pair<const int,std::vector<Object>>& objectIDVectorPair) {
//   std::string response = "";
//   for(auto descriptionText : objectIDVectorPair.second[0].getExtra().first) {
//         response += descriptionText + "\n";
//   }
//   return response;
// }

