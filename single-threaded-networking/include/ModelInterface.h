#ifndef MODELINTERFACE_h
#define MODELINTERFACE_h

#include "Server.h"
#include "Model.h"
#include "Commands.h"


class ModelInterface {

private:
	std::vector<std::string> filepath = {"../data/shire.yml", "../data/Midgaard.yml"};
	Model model{filepath};
	std::deque<std::unique_ptr<Command>> basicCommandQueue;
	std::deque<std::unique_ptr<Command>> combatCommandQueue;

public:
  ModelInterface();

  void  buildCommands(const std::deque<networking::Message>& clientMessages,  std::vector<networking::Connection>& clients);

  int createPlayer(const std::string& username, const std::string& password);
  std::vector<std::tuple<int,std::string,std::string>> getPlayerCredentialsVector() const;
  std::string getCurrentRoomDescription(const int& playerId);
  std::deque<networking::Message> updateGame();
};

#endif /* serverhelper_h */
