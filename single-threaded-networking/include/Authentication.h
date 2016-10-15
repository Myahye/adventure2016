#ifndef authentication_h
#define authentication_h

#include "Server.h"

using namespace networking;

namespace Authentication {

	bool findExistingUsername(const std::string& username);

	bool currentlyLoggedIn(const std::string& username);

	std::string authorizeClient(Message& message, Server& server, std::vector<Connection>& clients, std::unordered_map<std::string, Player>& players);

	std::string handleLogin(Message& message, Server& server, std::vector<Connection>& clients, std::unordered_map<std::string, Player>& players);

	std::string handleRegistration(Message& message, Server& server, std::vector<Connection>& clients, std::unordered_map<std::string, Player>& players);

}

#endif