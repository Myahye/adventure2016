#ifndef COMBATCOMMANDS_H
#define COMBATCOMMANDS_H

#include <unordered_map>
#include "Combatant.h"
#include "Fight.h"
#include "CombatCommandInterface.h"
#include "Npc.h"
#include "Room.h"
#include "Object.h"
#include "Player.h"
#include "Server.h"


//utility functions
bool is_number(const std::string& s);

int getPlayerIdInRoom(std::unordered_map<int, Player>* players, const std::unordered_map<int, int>* playerLocations, const int CcurrentRoomId, const std::string& playerName);

namespace CombatCommands {
	class AttackCommand : public CombatCommand {
	private:
		networking::Connection connection;
		std::string message;

	public:
		AttackCommand(networking::Connection connection_, const std::string& message_);

		std::string execute(std::vector<networking::Connection>& clients, std::vector<Fight>& fights, Context& context);

		int getId() const;

		networking::Connection getConnection() const;
	};


}


#endif //COMBATCOMMANDS_H
