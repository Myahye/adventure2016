#ifndef MODELINTERFACE_h
#define MODELINTERFACE_h

#include "Server.h"
#include "Model.h"
#include "Commands.h"


class ModelInterface {

private:
	std::vector<std::string> filepaths = {"../data/shire.yml", "../data/Midgaard.yml"};
	Model model{filepaths};
	std::deque<std::unique_ptr<Command>> basicCommandQueue;
	std::deque<std::unique_ptr<Command>> combatCommandQueue;

public:
  ModelInterface();

  void  buildCommands(const std::deque<networking::Message>& clientMessages,  std::vector<networking::Connection>& clients);
  void createSayCommandForGroup(std::deque<std::unique_ptr<Command>>& basicCommandQueue, std::vector<networking::Connection> clients, std::string messageText, int playerId);

  int createPlayer(const std::string& username, const std::string& password);
  std::vector<std::tuple<int,std::string,std::string>> getPlayerCredentialsVector() const;
  std::string getCurrentRoomDescription(const int& playerId);
  std::deque<networking::Message> updateGame();
	std::deque<networking::Message> updateCombat();
  void playerDisconnected(networking::Connection c);
  void playerConnect(networking::Connection c);
};

#endif
