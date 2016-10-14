#ifndef model_h
#define model_h

#include <string>
#include <map>

class Model {

private:

//need to change these to temlpate values
std::map<PlayerId,RoomId> playerLocation;


public:

  //CommandParse(pathtoyaml);
  Model();
  //map<int, Players>
  //map<int, rooms>
  //map<int, npcs>
  //map<int, objects>


  //builds above member variables
  //Model::yamlParse

  //Methods for players to interact with room
  //These are inorder of importance and what needs to be implemented first
  string movePlayer(const int& playerId, const string& direction);
  //Model::getAvailableDoors
  //Model::getAvailableRoomCommands
  //

};
#endif /* commandparse_h */
