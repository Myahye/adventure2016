#ifndef authentication_h
#define authentication_h

#include "Server.h"
#include "ModelInterface.h"

using namespace networking;

/*  @class Authentication 
*   @breif helper clas for the server handeling Player login's
*		   helps check existing players and login status. 
*		   also helps in managing registration of new players	 	
*/

namespace Authentication {

	int findExistingPlayer(const std::string& username, const std::vector<std::tuple<int,std::string,std::string>>& players);

	bool currentlyLoggedIn(int playerId, const std::vector<Connection>& clients);

	bool correctPassword(int playerId, const std::string& password, const std::vector<std::tuple<int,std::string,std::string>>& players);

	std::string authorizeClient(Message& message, Server& server, std::vector <Connection>& clients, ModelInterface& modelInterface);

	std::string handleLogin(Message& message, Server& server, std::vector <Connection>& clients, const std::vector<std::tuple<int,std::string,std::string>>& players, ModelInterface& modelInterface);

	std::string handleRegistration(Message& message, Server& server, std::vector <Connection>& clients, const std::vector<std::tuple<int,std::string,std::string>>& players, ModelInterface& modelInterface);

}

#endif
