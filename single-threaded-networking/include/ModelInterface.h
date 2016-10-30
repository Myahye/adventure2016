#ifndef modelinterface_h
#define modelinterface_h

#include "Server.h"
#include "Model.h"


class ModelInterface {

private:
	Model model{"../data/shire.yml"};

public:
  ModelInterface();

  std::deque<networking::Message>  parseCommands(const std::deque<networking::Message>& clientMessages,  std::vector<networking::Connection>& clients);

  int createPlayer(const std::string& username, const std::string& password);
  std::vector<std::tuple<int,std::string,std::string>> getPlayerCredentialsVector() const;
  std::string getCurrentRoomDescription(const int& playerId);
};

#endif /* modelinterface_h */
