#include "Model.h"

Model::Model(std::string path){
  yamlParse(path);
}


string Model::movePlayer(const int& playerId, const string& direction){
  int roomId  = this->playerLocation[playerId];
  Room currentRoom = this->rooms[roomId];
  try{
    int destRoomId = currentRoom.getRoomInDir(direction);

  }catch (CustErrors::noSuchDoorException){

    return
  }


  if(direction)
}

// Model::yamlParse(){
//   this->players = YamlParse.parseBuildPlayers;
//   this->rooms = YamlParse.parseBuildRooms;
//   this->npcs = YamlParse.parseBuildNpcs;
//   this->objects = YamlParse.parseBuildObjects;
// }
