#ifndef model_h
#define model_h
//#include "CustomError.h"
#include <string>
#include <unordered_map>
#include <tuple>
#include <boost/algorithm/string/predicate.hpp>
#include "Player.h"
#include "Room.h"
#include "Door.h"
#include "CustomError.h"

//using namespace custom_errors;

class Model {

private:
  std::unordered_map<int,Player> players;
  int assignedIDs = 1;
  //need to change these to temlpate values
  std::unordered_map<int,int> playerLocation;
  std::unordered_map<int,Room> rooms;

  //Still need to be implemented
  //map<int, Players>
  //map<int, rooms>
  //map<int, npcs>
  //map<int, objects>

public:
  Model();

  int createPlayer(const std::string& username, const std::string& password);
  std::vector<std::tuple<int,std::string,std::string>> getPlayerCredentialsVector() const;

  //Model(const std::string& pathToYamlFile/s);
  //Populates member variables
  //Model::yamlParse()

  //Methods for players to interact with world
  std::string movePlayer(const int& playerID, const std::string& direction);

  //These still need to be implemented
  //Model::getAvailableDoors
  //Model::getAvailableRoomCommands

  std::string getCurrentRoomDescription(const int& playerID);

  std::string dummySayCommand(const int& playerID, const std::string& message);

  std::string lookCommand(const int& playerID, const std::string& destDirection);

};
#endif /* commandparse_h */
