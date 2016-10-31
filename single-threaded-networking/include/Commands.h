#ifndef COMMANDS_H
#define COMMANDS_H

#include <unordered_map>

#include "CommandInterface.h"
#include "Npc.h"
#include "Room.h"
#include "Object.h"

namespace Commands {

	class LookCommand : public Command {
	private:
		int playerId;
		std::string message;
		int roomId;
		//Room* currentRoom; I want to have a pointer to the current room, but if that room is deleted before execute() is called then 
		//there will be undefined behaviour as the Room* will point to garbage
	public:
		LookCommand(int playerId_, const std::string& message_, int roomId_);

		std::string execute(Context& context);

		int getId() const;
	};

	class GoCommand : public Command {
	private:
		int playerId;
		std::string message;
		int roomId;
		//Room* currentRoom; I want to have a pointer to the current room, but if that room is deleted before execute() is called then 
		//there will be undefined behaviour as the Room* will point to garbage
	public:
		GoCommand(int playerId_, const std::string& message_, int roomId_);

		std::string execute(Context& context);

		int getId() const;
	};
}

#endif
