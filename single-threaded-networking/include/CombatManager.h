#ifndef COMBATMANAGER_h
#define COMBATMANAGER_h

#include "Server.h"
#include "Model.h"
#include "Context.h"
#include "Commands.h"
#include "Player.h"
#include "Fight.h"
#include "Combatant.h"

class CombatManager {

private:

	//Queue of combat commands to be executed6
	std::deque<std::unique_ptr<CombatCommand>> combatCommandQueue;

	//NPCs and Players in combat
	//Just players for now
  std::vector<Player> characterList;
	std::vector<Fight> fights;

	//networking::Message createAlertMessage(networking::Connection, std::string);

public:
  CombatManager();

	//Used by ModelInterface to create a CombatCommand
  void buildCombatCommand(const networking::Connection& connection, const std::string& message);

	//Used by ModelInterface to initiate one combat cycle
	std::deque<networking::Message> updateCombat(std::vector<networking::Connection>& clients, Context& context);

	//What is this for?
	// Maybe we dont need this as players and NPCs will enter and exit combat on
	// their own?
	//void updateCharacterList(const Player& player);



	//This will be used by Player to send itself a message
  //void createMessageForClient(const int playerId, const std::string& message);
  networking::Message createAlertMessage(networking::Connection, std::string);

};

#endif
