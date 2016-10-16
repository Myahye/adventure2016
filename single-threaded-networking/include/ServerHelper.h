#ifndef serverhelper_h
#define serverhelper_h
//include "model.h"
#include <boost/algorithm/string/predicate.hpp>

#include "Server.h"
#include "Model.h"


class ServerHelper {

private:
	Model model;


public:
/*********************Modified by Lawrence***********************************************************************/
	// int assignedIDs = 1;
	//
  // struct Player {
	// Player() : username("peasant"), password(""), level(0), inventory(""), playerID(0) {}
	//
	// Player(std::string player, std::string pass, int lvl, std::string inv, int ID)
	// : username(player), password(pass), level(lvl), inventory(inv), playerID(ID) {}
	//
	// std::string username;
	// std::string password;
	// int level;
	// std::string inventory;
	// int playerID;
  // };
	//
  // std::unordered_map<int,Player> playersCreated;
/*********************Modified by Lawrence***********************************************************************/
  //ServerHelper(pathtoyaml);
  ServerHelper();

  std::deque<networking::Message>  parseCommands(const std::deque<networking::Message>& clientMessageQueue,  std::vector<networking::Connection>& clients);

/*********************Modified by Lawrence***********************************************************************/
  int createPlayer(const std::string& username, const std::string& password);
  std::vector<std::tuple<int,std::string,std::string>> getPlayerCredentialsVector() const;
/*********************Modified by Lawrence***********************************************************************/
};


#endif /* serverhelper_h */
