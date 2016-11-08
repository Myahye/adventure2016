#include "Model.h"


//This is what construction will look like
 Model::Model(const std::vector<std::string>& paths){
   yamlParseAndBuild(paths[0]);
   yamlParseAndBuild(paths[1]);
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
  yamlparse.parseBuildRooms(this->rooms);

}

void Model::printAll(){
   int count = 1;
  for ( auto it = rooms.begin(); it != rooms.end(); ++it ){
     std::cout << "Map 1\nid:" << it->first << "\n";
     (it->second).printClass(count);
     std::cout << std::endl;
     count++;
  }
}

int
Model::createPlayer(const std::string& username, const std::string& password){


  Player newPlayer{this->assignedIds, username, password};
  players.insert({this->assignedIds, newPlayer});
  playerLocation[assignedIds] = 3007;
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
Model::dummySayCommand(const int& playerId, const std::string& message){
  return this->players[playerId].getUsername() + "> " + message.substr(4) + "\n\n";
}

void Model::reset(){
  for(auto& reset : resets) {
    if(reset != NULL) {
      reset->execute(this->context);
      this->context.setCurrentlySelectedNpc(reset->getCurrentlySelectedNpc());
    }
  }
  this->context.setCurrentlySelectedNpc(NULL);
}

Context Model::getContext() const {
  return this->context;
}


void Model::playerDisconnected(const int playerId) {
  this->rooms[playerLocation[playerId]].removePlayer(playerId);
}

void Model::playerConnect(const int playerId) {
  std::cout << "s " << playerLocation[playerId] << std::endl;
  this->rooms[playerLocation[playerId]].addPlayer(playerId, players[playerId].getUsername());
}
