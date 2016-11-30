#ifndef model_h
#define model_h
//#include "CustomError.h"
#include <string>
#include <unordered_map>
#include <tuple>
#include <boost/algorithm/string/predicate.hpp>
#include "Room.h"
#include "Door.h"
#include "CustomError.h"
#include "YamlParseBuild.h"
#include "Resets.h"
#include "Player.h"
#include "Npc.h"
#include "Context.h"

//using namespace custom_errors;

class Model {

private:
  std::unordered_map<int,Player> players;
  std::unordered_map<int,Room> rooms;
  std::unordered_map<int,Npc> npcs;
  std::unordered_map<int,Object> objects;
  std::vector<std::unique_ptr<Reset>> resets;

  int assignedIds = 1;
  //need to change these to temlpate values
  std::unordered_map<int,int> playerLocation;

  YamlParseBuild yamlparse;
  void yamlParseAndBuild(const std::string& pathToFile);
  //void yamlParseAndBuildExistingPlayers(const std::string& pathToFile);
  void printAll();


  Context context;
public:
  //Model(); //temp
  void yamlParseAndBuildExistingPlayers(const std::string& pathToFile);
  Model(const std::vector<std::string>& paths);

  int createPlayer(const std::string& username, const std::string& password);
  std::vector<std::tuple<int,std::string,std::string>> getPlayerCredentialsVector() const;

  //Methods for players to interact with world
  std::string movePlayer(const int& playerId, const std::string& direction);

  //These still need to be implemented
  //Model::getAvailableDoors
  //Model::getAvailableRoomCommands

  std::string getCurrentRoomDescription(const int& playerId);

  std::string dummySayCommand(const int& playerId, const std::string& message);

  std::string lookCommand(const int& playerId, const std::string& destDirection);

  std::string stealCommand(const int& playerId, const std::string& command);

  Context getContext() const;

  //-----------------------------Lawrence YU
  void reset();

  void playerDisconnected(const int playerId);
  void playerConnect(const int playerId);

};
#endif /* commandparse_h */
