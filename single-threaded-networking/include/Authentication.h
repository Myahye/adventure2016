#ifndef authentication_h
#define authentication_h

#include "Server.h"
#include "ModelInterface.h"

using namespace networking;

namespace Authentication {

	int findExistingPlayer(const std::string& username, const std::vector<std::tuple<int,std::string,std::string>>& players);

	bool currentlyLoggedIn(int playerID, const std::vector<Connection>& clients);

	bool correctPassword(int playerID, const std::string& password, const std::vector<std::tuple<int,std::string,std::string>>& players);

	std::string authorizeClient(Message& message, Server& server, std::vector <Connection>& clients, ModelInterface& modelInterface);

	std::string handleLogin(Message& message, Server& server, std::vector <Connection>& clients, const std::vector<std::tuple<int,std::string,std::string>>& players, ModelInterface& modelInterface);

	std::string handleRegistration(Message& message, Server& server, std::vector <Connection>& clients, const std::vector<std::tuple<int,std::string,std::string>>& players, ModelInterface& modelInterface);

}

#endif
