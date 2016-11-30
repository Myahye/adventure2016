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
   yamlParseAndBuildExistingPlayers(paths[2]);
   std::cout << "gei " << std::endl;
   this->context = Context{&this->rooms,&this->npcs,&this->objects,&this->players,&this->playerLocation};
   std::cout << "goi " << std::endl;
   this->reset();
 }

void Model::yamlParseAndBuild(const std::string& pathToFile){
  std::cout << "DIFFERENT FILE\n\n\n\n\n\n\n";
  yamlparse.loadFile(pathToFile);
  yamlparse.buildNpcs(this->npcs);
  yamlparse.buildObjects(this->objects);
  yamlparse.buildResets(this->resets);
  std::cout << "wwww " << std::endl;
  yamlparse.buildRooms(this->rooms);
      // printAll();
  //this->resets = yamlparse.parseBuildResets(pathToFile);
  //not yet implemented
  // this->allPlayers = yamlParse.parseBuildPlayers(pathToFile);

}

void Model::yamlParseAndBuildExistingPlayers(const std::string& pathToFile){
  std::cout << "existing players\n\n\n\n\n\n\n";
  yamlparse.loadFile(pathToFile);
  std::cout << "aa11a" << std::endl;
  yamlparse.buildPlayers(this->players);
  std::cout << "aaa" << std::endl;
  //yamlparse.buildResets(this->resets);
}

void Model::printAll(){
  // std::cout << "Printing map contents \n";
   int count = 1;
  // for ( auto it = npcs.begin(); it != npcs.end(); ++it ){
  //   std::cout << "Map 1\nid:" << it->first << "\n";
  //   std::cout << it->first  << std::endl;
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
  for ( auto it = rooms.begin(); it != rooms.end(); ++it ){
     std::cout << "Map 1\nid:" << it->first << "\n";
     (it->second).printClass(count);
     std::cout << std::endl;
     count++;
  }
   // for ( auto it = resets.begin(); it != resets.end(); ++it ){
   //   std::cout << "Map 3\nid:" << "\n";

   //    (*it)->printClass(count);
   //   std::cout << std::endl;
   //   count++;
   // }
}

int
Model::createPlayer(const std::string& username, const std::string& password){

  // players[assignedIds] = Player {14441
  //     assignedIds, username, password,
  // };

  Player newPlayer{this->assignedIds, username, password};
  players.insert({this->assignedIds, newPlayer});
  playerLocation[assignedIds] = 3007;
  assignedIds++;
  for (auto & player: players) {
      std::cout << "Player Id: " << player.second.playerCharacter.getId() << ", username: " << player.second.getUsername() << ", password: " << player.second.getPassword() << "\n";
  }
  return assignedIds - 1;
}

std::vector<std::tuple<int,std::string,std::string>>
Model::getPlayerCredentialsVector() const {

  std::vector<std::tuple<int,std::string,std::string>> vector;

  for(auto player: players) {
    vector.push_back(std::make_tuple(player.second.playerCharacter.getId(),player.second.getUsername(),player.second.getPassword()));
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

void Model::reset(){
    //  std::cout << "gerooooi " << std::endl;
  for(auto& reset : resets) {
  //      std::cout << "pppp " << std::endl;
    if(reset != NULL) {
           //reset->printClass(1);
      reset->execute(this->context);
   //     std::cout << "lll " << std::endl;
      this->context.setCurrentlySelectedNpc(reset->getCurrentlySelectedNpc());
  //  std::cout << "geroi " << std::endl;
    }
  }
   //   std::cout << "roi " << std::endl;
  this->context.setCurrentlySelectedNpc(NULL);
    //  std::cout << "oi " << std::endl;
}

Context Model::getContext() const {
  return this->context;
}


void Model::playerDisconnected(const int playerId) {
  players[playerId].setStatus("Offline");
  this->rooms[playerLocation[playerId]].removePlayer(playerId);
}

void Model::playerConnect(const int playerId) {
  std::cout << "s " << playerLocation[playerId] << std::endl;
  players[playerId].setStatus("Online");
  this->rooms[playerLocation[playerId]].addPlayer(playerId, players[playerId].getUsername());
