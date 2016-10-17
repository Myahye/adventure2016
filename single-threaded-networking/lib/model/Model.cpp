#include "Model.h"

Model::Model(){
  Door door1("south", "south", 2);
  Door door2("north", "north", 1);
  Door door3("north");
  vector<Door> doors1;
  vector<Door> doors2;
  doors1.push_back(door1);
  doors2.push_back(door2);

  string desc1 ="A room with a passage to the south";
  string ext_desc1 = " ";
  string name_room1 = "Room 1";
  int id_room1 = 1;
  Room room1(desc1, ext_desc1, name_room1, id_room1, doors1);

  string desc2 ="A room with a passage to the north";
  string ext_desc2 = " ";
  string name_room2 = "Room 2";
  int id_room2 = 2;
  Room room2(desc2, ext_desc2, name_room2, id_room2, doors2);

  this->rooms.insert({2, room2});

  this->rooms.insert({1, room1});

  Room roomtmp = this->rooms[1];
  std::cout << "Room 1 description: " << roomtmp.getDesc() << endl;

  for (auto & room: this->rooms) {
      std::cout << "Room ID: " << room.second.getRoomId() <<endl;
      vector<Door> tmp = room.second.getDoors();
      std::cout << "Number of doors in room: " << tmp.size() << endl;
      for(Door door: tmp){
        std::cout << door.getDir() << endl;
      }
  }

}

int
Model::createPlayer(const std::string& username, const std::string& password){

  // players[assignedIDs] = Player {14441
  //     assignedIDs, username, password,
  // };

  Player newPlayer{this->assignedIDs, username, password};
  players.insert({this->assignedIDs, newPlayer});
  playerLocation[assignedIDs] = 1;
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

// Model::Model(const std::string& path){
//   yamlParse(path);
// }
std::string
Model::getCurrentRoomDescription(const int& playerId) const{
  int currentRoomId  = this->playerLocation[playerId];
  return this->rooms[currentRoomId].getDesc();
}

std::string
Model::movePlayer(const int& playerId, const std::string& destDirection){
  std::cout << "Player wants to go " << destDirection <<endl;
  int currentRoomId  = this->playerLocation[playerId];
  std::cout << "Current room ID: " << currentRoomId << endl;
  Room currentRoom = this->rooms[currentRoomId];
  vector<Door> currentRoomDoors = currentRoom.getDoors();
  std::cout << "number of doors in room: " << currentRoomDoors.size() << endl;

  for(Door door : currentRoomDoors){
    std::cout << "Dir: " << door.getDir() << endl;
  }

  try{
    int destRoomId = currentRoom.getRoomInDir(destDirection);
    //throw custom_errors::NoSuchDoorException();
    this->playerLocation[playerId] = destRoomId;
    return "You are now in " + this->rooms[destRoomId].getDesc();

  }catch (custom_errors::NoSuchDoorException& e){
      return e.what();
  }
}

// Model::yamlParse(){
//   this->players = YamlParse.parseBuildPlayers;
//   this->rooms = YamlParse.parseBuildRooms;
//   this->npcs = YamlParse.parseBuildNpcs;
//   this->objects = YamlParse.parseBuildObjects;
// }
