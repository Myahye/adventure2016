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

//std::string getPlayersInRoomDesc(std::unordered_map<int, Player>* players, const std::unordered_map<int, int>* playerLocations, const int currentRoomId);

int getPlayerIdInRoom(std::unordered_map<int, Player>* players, const std::unordered_map<int, int>* playerLocations, const int CcurrentRoomId, const std::string& playerName);

namespace CombatCommands {
	class AttackCommand : public CombatCommand {
	private:
		networking::Connection connection;
		std::string message;
		//Room* currentRoom; I want to have a pointer to the current room, but if that room is deleted before execute() is called then
		//there will be undefined behaviour as the Room* will point to garbage
	public:
		AttackCommand(networking::Connection connection_, const std::string& message_);

		std::string execute(std::vector<networking::Connection>& clients, std::vector<Fight>& fights, Context& context);

		int getId() const;

		networking::Connection getConnection() const;
	};


	// class AttackCommand : public CombatCommand {
	// 	private:
	// 		int targetId;
	// 		std::string sourceName;
	// 		std::vector<networking::Connection>& clients;
	// 		//networking::Connection sourceConnection;
	// 		// networking::Connection targetConnection;
	// 		//std::string message;
	// 	public:
	// 		AttackCommand(std::vector<networking::Connection>& clients_, networking::Connection connection_, const std::string& message_);
	//
	// 		std::string execute(Context& context);
	// 		// std::string getSourceName() const;
	// 		// int getSourceId() const;
	// 		// int getTargetId() const;
	// 		//
	// 		// networking::Connection getSourceConnection() const;
	// 		// networking::Connection getTargetConnection() const;
	// 	};
}


#endif //COMBATCOMMANDS_H
