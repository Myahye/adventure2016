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
 }

//use subclass to build objects
//each subclass method returns an unordered_map?
void Model::yamlParseAndBuild(const std::string& pathToFile){
  this->NPCs = yamlparse.parseBuildNpcs(pathToFile);
  this->objects = yamlparse.parseBuildObjects(pathToFile);
  this->rooms = yamlparse.parseBuildRooms(pathToFile);
  this->resets = yamlparse.parseBuildResets(pathToFile);

  printAll();
  //not yet implemented
  // this->allPlayers = yamlParse.parseBuildPlayers(pathToFile);

}

void Model::printAll(){
  std::cout << "Prining map contents \n";
  int count = 1;
  // for ( auto it = NPCs.begin(); it != NPCs.end(); ++it ){
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
  //    std::cout << "Map 2\nid:" << it->getId() << "\n";
  //    it->printClass(count);
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
  std::vector<Door> currentRoomDoors = this->rooms[currentRoomID].getDoors();
  std::string currentRoomDescription = "";
  std::string response = "";

  //------------------------------------------------------------------room description
  for(auto descriptionText : this->rooms[currentRoomID].getDesc()) {
    currentRoomDescription += descriptionText + "\n";
  }
  response = this->players[playerID].getUsername() + ">\n" + currentRoomDescription +
  
  //------------------------------------------------------------------npc descriptions
  response += "\n";
  for(auto npcIDVectorPair : this->rooms[currentRoomID].getNPCsInRoom()) {
    // response += std::to_string(npc.second.size()) + " " + npc.second[0].getKeywords()[0] + ", ";
    for(auto npc : npcIDVectorPair.second) {
      response += "     " + npc.getLongDesc()[0] + "\n";
    }
  }
  response += "\n";

  //------------------------------------------------------------------Object descriptions
  for(auto objectIDVectorPair : this->rooms[currentRoomID].getObjectsInRoom()) {
    // response += std::to_string(npc.second.size()) + " " + npc.second[0].getKeywords()[0] + ", ";
    for(auto object : objectIDVectorPair.second) {
      response += "     " + object.getLongDesc()[0] + "\n";
    }
  }
  response += "\n";

  //-----------------------------------------------------------------available doors/exits
  // if(currentRoomDoors.size() == 1) {
  //   return this->players[playerID].getUsername() + ">\n     " + currentRoomDescription + "\n\n" +
  //               "     There is 1 obvious exit: " + currentRoomDoors[0].getDir() + ".\n\n";
  // }

  response += "     There are " + std::to_string(currentRoomDoors.size()) + " obvious exits: ";
  for(auto currentDoor = currentRoomDoors.begin(); currentDoor != currentRoomDoors.end()-1;  ++currentDoor ){
    response += currentDoor->getDir() + ", ";
  }
  response += /*"and "*/ currentRoomDoors[currentRoomDoors.size()-1].getDir() + ".\n\n";

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
  
    //currentRoomDescription[0] = std::tolower(currentRoomDescription[0]);
    return getCurrentRoomDescription(playerID);
  } else {
    return this->players[playerID].getUsername() + "> " + "There is no door in that direction." + "\n\n";
  }
}
//-------------------lawrence Yu
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
  for(auto currentDoor : this->rooms[currentRoomID].getDoors()) {
    if(message == currentDoor.getDir()) {
      for(auto descriptionText : currentDoor.getDesc()) {
        response += descriptionText + "\n";
      }
      response += "\n";
      return response;
    }
  }

  //-------------------------------------------------look "NPC keyword"
  response += "\n";
  for(auto npcIDVectorPair : this->rooms[currentRoomID].getNPCsInRoom()) {
    if(message == npcIDVectorPair.second[0].getKeywords()[0]) {
      for(auto descriptionText : npcIDVectorPair.second[0].getDesc()) {
        response += descriptionText + "\n";
      }
      response += "\n";
      return response;
    }
  }
  std::cout << objects[1102].getExtra().first.size() << std::endl;
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

  return this->players[playerID].getUsername() + "> " + "Cannot find " + message + ", no match. \n\n";
}

//----------------------Lawrence Yu
void Model::reset(){
  for(auto reset : resets) {
    if(reset.getAction() == "npc") {
      resetNPC(reset);
    } else if(reset.getAction() == "object") {
      resetObject(reset);
    } /*else if(reset.getAction() == "give") {
      resetEquip(reset);
    } else if(reset.getAction() == "equip") {
      resetGive(reset);
    }*/
  }
}

void Model::resetNPC(const Reset& reset) {
  int limit = reset.getLimit();
  NPC npc = NPCs[reset.getId()];
  // NPC npcClone = clone(npc); 
  rooms[reset.getRoom()].addNPC(npc, limit);
}

void Model::resetObject(const Reset& reset) {
  int limit = reset.getLimit();
  Object object = objects[reset.getId()];
  // NPC npcClone = clone(npc); 
  rooms[reset.getRoom()].addObject(object, limit);
}

/*
reset(){
  for(auto reset : resets) {
    Command* command = handlereset(reset);
    
      command->execute(*this,reset);
  }
}

Command* handlereset(reset) {
  if(reset == npc) return new Commands::resetNPC();
  if(reset == object) return resetobject;
}
/*

class resetnpc : Command{
  resetnpc
}

Command* command = resetnpc();
*/