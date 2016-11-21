#ifndef COMMANDS_H
#define COMMANDS_H

#include <unordered_map>

#include "CommandInterface.h"
#include "Player.h"
#include "Npc.h"
#include "Room.h"
#include "Object.h"

namespace Commands {

	class LookCommand : public Command {
	private:
		networking::Connection connection;
		std::string message;
		//Room* currentRoom; I want to have a pointer to the current room, but if that room is deleted before execute() is called then
		//there will be undefined behaviour as the Room* will point to garbage
	public:
		LookCommand(networking::Connection connection_, const std::string& message_);

		std::string execute(Context& context);

		int getId() const;

		networking::Connection getConnection() const;
	};

	class GoCommand : public Command {
	private:
		networking::Connection connection;
		std::string message;
		//Room* currentRoom; I want to have a pointer to the current room, but if that room is deleted before execute() is called then
		//there will be undefined behaviour as the Room* will point to garbage
	public:
		GoCommand(networking::Connection connection_, const std::string& message_);

		std::string execute(Context& context);

		int getId() const;

		networking::Connection getConnection() const;
	};

	class AttackCommand : public Command {
  	private:
  		networking::Connection connection;
  		std::string message;
  	public:
  		AttackCommand(networking::Connection connection_, const std::string& message_);

  		std::string execute(Context& context);

  		int getId() const;

  		networking::Connection getConnection() const;
  	};


	class FleeCommand : public Command {
  	private:
  		networking::Connection connection;
  		std::string message;
  	public:
  		FleeCommand(networking::Connection connection_, const std::string& message_);

  		std::string execute(Context& context);

  		int getId() const;

  		networking::Connection getConnection() const;
  	};

	class StatusCommand : public Command {
	private:
		networking::Connection connection;
		std::string message;
	public:
		StatusCommand(networking::Connection connection_, const std::string& message_);

		std::string execute(Context& context);

		int getId() const;

		networking::Connection getConnection() const;
	};

	class TakeCommand : public Command {
	private:
		networking::Connection connection;
		std::string message;
	public:
		TakeCommand(networking::Connection connection_, const std::string& message_);

		std::string execute(Context& context);

		int getId() const;

		networking::Connection getConnection() const;

		//need to move out later
		bool is_number(const std::string& s);
	};

	class InvalidCommand : public Command {
	private:
		networking::Connection connection;
		std::string message;
	public:
		InvalidCommand(networking::Connection connection_, const std::string& message_);

		std::string execute(Context& context);

		int getId() const;

		networking::Connection getConnection() const;
	};

	class ListCommand : public Command {
	private:
		networking::Connection connection;
		std::unordered_map<std::string, std::string> commands;
	public:
		ListCommand(networking::Connection connection_, const std::unordered_map<std::string, std::string>& commands_);

		std::string execute(Context& context);

		int getId() const;

		networking::Connection getConnection() const;
	};

	class SayCommand : public Command {
	private:
		networking::Connection connection;
		std::string message;
		int playerId;
	public:
		SayCommand(networking::Connection connection_, const std::string& message_, int playerId_);

		std::string execute(Context& context);

		int getId() const;

		networking::Connection getConnection() const;
	};

}



namespace CombatCommands {
	class AttackCommand : public CombatCommand {
		private:
			int targetId;
			std::string sourceName;
			std::vector<networking::Connection>& clients;
			networking::Connection sourceConnection;
			networking::Connection targetConnection;
			std::string message;
		public:
			AttackCommand(std::vector<networking::Connection>& clients_, networking::Connection connection_, const std::string& message_);

			std::string execute(Context& context);
			std::string getSourceName() const;
			int getSourceId() const;
			int getTargetId() const;

			networking::Connection getSourceConnection() const;
			networking::Connection getTargetConnection() const;
		};
}


#endif
