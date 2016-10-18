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

//This is what construction will look like
// Model::Model(const std::string& path){
//   yamlParse(path);
// }

//Representation of what yamlParse will do
// Model::yamlParse(){
//   this->players = YamlParse.parseBuildPlayers;
//   this->rooms = YamlParse.parseBuildRooms;
//   this->npcs = YamlParse.parseBuildNpcs;
//   this->objects = YamlParse.parseBuildObjects;
// }

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

std::string
Model::getCurrentRoomDescription(const int& playerID) {
  int currentRoomID = this->playerLocation[playerID];
  std::string currentRoomDescription = this->rooms[currentRoomID].getDesc();
  currentRoomDescription[0] = std::tolower(currentRoomDescription[0]);
  return currentRoomDescription;
}

std::string
Model::movePlayer(const int& playerID, const std::string& destDirection){
  std::cout << "Player wants to go " << destDirection <<endl;
  int currentRoomID  = this->playerLocation[playerID];
  std::cout << "Current room ID: " << currentRoomID << endl;
  Room currentRoom = this->rooms[currentRoomID];
  vector<Door> currentRoomDoors = currentRoom.getDoors();
  std::cout << "number of doors in room: " << currentRoomDoors.size() << endl;

  for(Door door : currentRoomDoors){
    std::cout << "Dir: " << door.getDir() << endl;
  }

  try{
    int destRoomID = currentRoom.getRoomInDir(destDirection);
    //throw custom_errors::NoSuchDoorException();
    this->playerLocation[playerID] = destRoomID;
    std::string currentRoomDescription = this->rooms[currentRoomID].getDesc();
    currentRoomDescription[0] = std::tolower(currentRoomDescription[0]);
    return this->players[playerID].getUsername() + "> " + "You are now in " + currentRoomDescription + "\n";

  } catch (custom_errors::NoSuchDoorException& e){
    return this->players[playerID].getUsername() + "> " + e.what() + "\n";
  }
}

std::string
Model::dummySayCommand(const int& playerID, const std::string& message){
    return this->players[playerID].getUsername() + "> " + message.substr(4) + "\n";
}

std::string
Model::lookCommand(const int& playerID, const std::string& command){
  std::string message = command.substr(5);
  std::transform(message.begin(), message.end(), message.begin(), ::tolower);
  if(message == "around room") {
    int currentRoomID = this->playerLocation[playerID];
    vector<Door> currentRoomDoors = this->rooms[currentRoomID].getDoors();

    if(currentRoomDoors.size() == 1) {
      return this->players[playerID].getUsername() + ">\n     " + this->rooms[currentRoomID].getDesc() + ".\n\n" +
                "     There is 1 obvious exit: " + currentRoomDoors[0].getDir() + ".\n";
    }

    std::string response = this->players[playerID].getUsername() + ">\n     " + this->rooms[currentRoomID].getDesc() + ".\n\n" +
                              "     There are " + to_string(currentRoomDoors.size()) + " obvious exits: ";

    for(auto it = currentRoomDoors.begin(); it != currentRoomDoors.end()-1;  ++it ){
      response += it->getDir() + ", ";
    }

     response += "and " + currentRoomDoors[currentRoomDoors.size()-1].getDir() + ".\n";

    return response;
  }
  return this->players[playerID].getUsername() + "> " + "Cannot find " + message + ", no match. \n";
}
