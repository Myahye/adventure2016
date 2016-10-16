#ifndef model_h
#define model_h

#include <string>
#include <unordered_map>
#include <tuple>
#include <boost/algorithm/string/predicate.hpp>
#include "Player.h"

class Model {

private:
std::unordered_map<int,Player> players;
int assignedIDs = 1;
//need to change these to temlpate values
//std::unordered_map<PlayerId,RoomId> playerLocation;

public:

  //CommandParse(pathtoyaml);
  Model();
  //Model(const std::string& path);

  int createPlayer(const std::string& username, const std::string& password);
  std::vector<std::tuple<int,std::string,std::string>> getPlayerCredentialsVector() const;

  //map<int, Players>
  //map<int, rooms>
  //map<int, npcs>
  //map<int, objects>


  //builds above member variables
  //Model::yamlParse

  //Methods for players to interact with room
  //These are inorder of importance and what needs to be implemented first
  //string movePlayer(const int& playerId, const string& direction);
  //Model::getAvailableDoors
  //Model::getAvailableRoomCommands
  //

};
#endif /* commandparse_h */
