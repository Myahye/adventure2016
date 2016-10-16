#include "Model.h"

Model::Model(){}

int
Model::createPlayer(const std::string& username, const std::string& password){

  // players[assignedIDs] = Player {
  //     assignedIDs, username, password,
  // };


  Player mapPlayer{this->assignedIDs, username, password};
  players.insert({this->assignedIDs, mapPlayer});

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


// string Model::move

//(const int& playerId, const string& direction){
//   int roomId  = this->playerLocation[playerId];
//   Room currentRoom = this->rooms[roomId];
//   try{
//     int destRoomId = currentRoom.getRoomInDir(direction);
//
//   }catch (CustErrors::noSuchDoorException){
//
//     return
//   }
//
//
//   if(direction)
// }

// Model::yamlParse(){
//   this->players = YamlParse.parseBuildPlayers;
//   this->rooms = YamlParse.parseBuildRooms;
//   this->npcs = YamlParse.parseBuildNpcs;
//   this->objects = YamlParse.parseBuildObjects;
// }
