#ifndef COMBATMANAGER_h
#define COMBATMANAGER_h

#include "Server.h"
#include "Model.h"
#include "Commands.h"
#include "Player.h"


class CombatManager {

private:
	std::deque<std::unique_ptr<CombatCommand>> combatCommandQueue;

  std::vector<Player>& characterList;


	//networking::Message createAlertMessage(networking::Connection, std::string);

public:
  CombatManager();
  void buildCombatCommand(const networking::Connection, const std::string&);
  std::deque<networking::Message> updateCombat(Model::Context& context&);
  void updateCharacterList(const Player&);
  void createMessageToPlayer(const int pid, const std::string& msg);
};

#endif
