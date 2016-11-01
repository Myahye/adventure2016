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
   yamlParseAndBuild(paths[0]);
   yamlParseAndBuild(paths[1]);
   std::cout << "gei " << std::endl;
   this->context = Context{&this->rooms,&this->npcs,&this->objects,&this->players,&this->playerLocation};
   std::cout << "goi " << std::endl;
 }

void Model::yamlParseAndBuild(const std::string& pathToFile){
  std::cout << "DIFFERENT FILE\n\n\n\n\n\n\n";
  yamlparse.loadFile(pathToFile);
  yamlparse.buildNpcs(this->npcs);
  yamlparse.buildObjects(this->objects);
  yamlparse.buildResets(this->resets);
  std::cout << "wwww " << std::endl;
    //printAll();
  yamlparse.parseBuildRooms(this->rooms);
  //this->resets = yamlparse.parseBuildResets(pathToFile);
  //not yet implemented
  // this->allPlayers = yamlParse.parseBuildPlayers(pathToFile);

}

void Model::printAll(){
  std::cout << "Printing map contents \n";
  int count = 1;
  // for ( auto it = npcs.begin(); it != npcs.end(); ++it ){
  //   std::cout << "Map 1\nid:" << it->first << "\n";
  //   std::cout << (it->second).printClass(count);  << std::endl;
  //   count++;
  // }
  // count =1;
  // std::cout << "=============================" << std::endl;
  // for ( auto it = objects.begin(); it != objects.end(); ++it ){
  //   std::cout << "Map 1\nid:" << it->first << "\n";
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
   for ( auto it = resets.begin(); it != resets.end(); ++it ){
     std::cout << "Map 3\nid:" << "\n";

      (*it)->printClass(count);
     std::cout << std::endl;
     count++;
  }
}

int
Model::createPlayer(const std::string& username, const std::string& password){

  // players[assignedIds] = Player {14441
  //     assignedIds, username, password,
  // };

  Player newPlayer{this->assignedIds, username, password};
  players.insert({this->assignedIds, newPlayer});
  playerLocation[assignedIds] = 1137;
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

// std::string
// Model::movePlayer(const int& playerId, const std::string& destDirection){
//   std::cout << "Player wants to go " << destDirection << std::endl;
//   int currentRoomId  = this->playerLocation[playerId];
//   std::cout << "Current room Id: " << currentRoomId << std::endl;
//   Room currentRoom = this->rooms[currentRoomId];
//   std::vector<Door> currentRoomDoors = currentRoom.getDoors();
//   std::cout << "number of doors in room: " << currentRoomDoors.size() << std::endl;

//   // for(Door door : currentRoomDoors){
//   //   std::cout << "Dir: " << door.getDir() << endl;
//   // }

//   int destRoomId = currentRoom.getRoomInDir(destDirection);

//   if(destRoomId != -1) {
//     std::cout << "Destination room Id:: " << currentRoom.getRoomInDir(destDirection) << std::endl;
//     //throw custom_errors::NoSuchDoorException();
//     this->playerLocation[playerId] = destRoomId;
//     return this->players[playerId].getUsername() + "> " + destDirection + getCurrentRoomDescription(playerId);
//   } else {
//     return this->players[playerId].getUsername() + "> " + "There is no door in the " + destDirection + " direction." + "\n\n";
//   }
// }
//---------------------------------------------------lawrence Yu
std::string
Model::dummySayCommand(const int& playerId, const std::string& message){
  return this->players[playerId].getUsername() + "> " + message.substr(4) + "\n\n";
}

// std::string
// Model::lookCommand(const int& playerId, const std::string& command){
//   std::string response = this->players[playerId].getUsername() + "> " + command;
//   std::string message = command.substr(5);
//   std::transform(message.begin(), message.end(), message.begin(), ::tolower);

//   int currentRoomId = this->playerLocation[playerId];
//   Room currentRoom = this->rooms[currentRoomId];

//   if(message == "room") {
//     return response + getCurrentRoomDescription(playerId);
//   }

//   //-------------------------------------------------look "cardinal direction"

//   //will move this to room class later as if isDirection return door.getDesc()
//   auto doorsInRoom = currentRoom.getDoors();

//   for(auto currentDoor : doorsInRoom) {
//     if(message == currentDoor.getDir()) {
//       response += "\n\n" + currentDoor.getDesc() += "\n";

//       return response;
//     }
//   }

//   //-------------------------------------------------look "Npc keyword"

//   //will move this to room class later as if isNpc return npc.getfulldesc()
//   Npc currentNpc = currentRoom.findNpc(message);

//   if(currentNpc.getId() != 0) {

//     //change for look toddler 1 look toddler 2 look toddler 3 later since it only checks the description of the first duplicate npc?
//     response += "\n\n" + currentNpc.getDesc();
//     response += "\n     Wearing: "  + currentNpc.getNpcEquipmentDesc();
//     response += "\n     Carrying: " + currentNpc.getNpcInventoryDesc() + "\n\n";

//     return response;
//   }

//   //-------------------------------------------------look "Object keyword"

//   //will move this to room class later as if isobject return object.getfulldesc()
//   Object currentObject = currentRoom.findObject(message);

//   if(currentObject.getId() != 0) {

//     response += "\n";
//     //change for look object 1 look object 2 look object 3 later since it only checks the description of the first duplicate object?
//     for(auto descriptionText : currentObject.getExtra().first) {
//       response += descriptionText + "\n";
//     }
//     return response;
//   }

//   return this->players[playerId].getUsername() + "> " + "Cannot find " + message + ", no match. \n\n";
// }

//----------------------Lawrence Yu
void Model::reset(){
      std::cout << "gerooooi " << std::endl;
  for(auto& reset : resets) {
        std::cout << "pppp " << std::endl;
    if(reset != NULL) {
          std::cout << "nnnn " << std::endl;
      reset->execute(this->context);
        std::cout << "lll " << std::endl;
      this->context.setCurrentlySelectedNpc(reset->getCurrentlySelectedNpc());
    std::cout << "geroi " << std::endl;
    }
  }
      std::cout << "roi " << std::endl;
  this->context.setCurrentlySelectedNpc(NULL);
      std::cout << "oi " << std::endl;
}

Context Model::getContext() const {
  return this->context;
}


std::string
Model::stealCommand(const int& playerId, const std::string& command){
  // std::string response = this->players[playerId].getUsername() + "> " + command;
  // std::string message = command.substr(6);
  // std::transform(message.begin(), message.end(), message.begin(), ::tolower);

  // int currentRoomId = this->playerLocation[playerId];
  // Room currentRoom = this->rooms[currentRoomId];


  // //will move this to room class later as if isDirection return door.getDesc()

  // Npc* currentNpc = currentRoom.findNpc(message);

  // if(currentNpc != NULL) {

  //   //change for look toddler 1 look toddler 2 look toddler 3 later since it only checks the description of the first duplicate npc?
  //   response += "\n\n" + currentNpc->getDesc();
  //   response += "\n     Wearing: "  + currentNpc->getNpcEquipmentDesc();
  //   response += "\n     Carrying: " + currentNpc->getNpcInventoryDesc() + "\n\n";

  //   return response;
  // }

  // //-------------------------------------------------look "Object keyword"

  // //will move this to room class later as if isobject return object.getfulldesc()

  // Object* currentObject = currentRoom.findObject(message);

  // if(currentObject != NULL) {

  //   response += "\n";
  //   //change for look object 1 look object 2 look object 3 later since it only checks the description of the first duplicate object?
  //   for(auto descriptionText : objectIdVectorPair.second[0].getExtra().first) {
  //     response += descriptionText + "\n";
  //   }
  //   return response;
  // }

  // return this->players[playerId].getUsername() + "> " + "Cannot find " + message + ", no match. \n\n";
}

/*delete command to check if delete works on npc from npcs and npcs from room {
  

//////////////////IMPORTANT CHECK IF GAME WORKS EVEN AFTER DELETING OBJECTS/ NPCS//////////////////

}

*/
