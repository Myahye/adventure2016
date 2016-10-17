#ifndef authentication_h
#define authentication_h

#include "Server.h"
#include "ServerHelper.h"

using namespace networking;

namespace Authentication {

	int findExistingPlayer(const std::string& username, const std::vector<std::tuple<int,std::string,std::string>>& players);

	bool currentlyLoggedIn(int playerID, const std::vector<Connection>& clients);

	bool correctPassword(int playerID, const std::string& password, const std::vector<std::tuple<int,std::string,std::string>>& players);

	std::string authorizeClient(Message& message, Server& server, std::vector <Connection>& clients, ServerHelper& serverHelper);

	std::string handleLogin(Message& message, Server& server, std::vector <Connection>& clients, const std::vector<std::tuple<int,std::string,std::string>>& players, ServerHelper& serverHelper);

	std::string handleRegistration(Message& message, Server& server, std::vector <Connection>& clients, const std::vector<std::tuple<int,std::string,std::string>>& players, ServerHelper& serverHelper);

}

#endif
