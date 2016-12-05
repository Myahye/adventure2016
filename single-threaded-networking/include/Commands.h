#ifndef COMMANDS_H
#define COMMANDS_H

#include <unordered_map>
#include <iomanip>
#include <string>
#include "CommandInterface.h"
#include "Player.h"
#include "Npc.h"
#include "Room.h"
#include "Object.h"
#include "Resets.h"

//utility functions
bool is_number(const std::string& s);

std::string printMiniMap(std::unordered_map<int,Room>* rooms, const int currentRoomId);

std::string getPlayersInRoomDesc(std::unordered_map<int, Player>* players, const std::unordered_map<int, int>* playerLocations, const int currentRoomId);
std::string printEditCurrentRoomWindow(const std::vector<std::string>& description, const std::vector<Door>& doors, const int currentRoomId, std::vector<std::unique_ptr<Reset>>& resets, const std::vector<int>& resetsInRoomPosition);
std::string printEditRoomDescriptionWindow(const std::vector<std::string>& description);
std::string printEditRoomDoorsWindow(const std::vector<Door>& doors);

class Editor {
private:
	networking::Connection connection;
	std::string message;
public:
	Editor();

	Editor(networking::Connection connection_, const std::string& message_);

	std::string execute(Context& context, std::vector<std::unique_ptr<Reset>>& resets);

	void setMessage(const std::string& s);

	networking::Connection getConnection() const;

	int getId() const;
};

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
	};

	class EquipCommand : public Command {
	private:
		networking::Connection connection;
		std::string message;
	public:
		EquipCommand(networking::Connection connection_, const std::string& message_);

		std::string execute(Context& context);

		int getId() const;

		networking::Connection getConnection() const;

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
		std::string message;

	public:
		ListCommand(networking::Connection connection_, const std::unordered_map<std::string, std::string>& commands_, const std::string& message_);

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

	class SwapCommand : public Command {
  	private:
  		networking::Connection connection;
  		std::string message;
  	public:
  		SwapCommand(networking::Connection connection_, const std::string& message);

  		std:: string execute(Context& context);

  		int getId() const;

  		networking::Connection getConnection() const;
  	};

		class StealCommand : public Command {
		private:
			networking::Connection connection;
			std::string message;
		public:
			StealCommand(networking::Connection connection_, const std::string& message_);

			std::string execute(Context& context);

			int getId() const;

			networking::Connection getConnection() const;
		};

		class TeleportCommand : public Command {
		private:
			networking::Connection connection;
			std::string message;
		public:
			TeleportCommand(networking::Connection connection_, const std::string& message_);

			std::string execute(Context& context);

			int getId() const;

			networking::Connection getConnection() const;
		};

		class SummonCommand : public Command {
		private:
			networking::Connection connection;
			std::string message;
		public:
			SummonCommand(networking::Connection connection_, const std::string& message_);

			std::string execute(Context& context);

			int getId() const;

			networking::Connection getConnection() const;
		};

		class GlobalChatCommand : public Command {
		private:
			networking::Connection connection;
			std::string message;
		public:
			GlobalChatCommand(networking::Connection connection_, const std::string& message_);

			std::string execute(Context& context);

			int getId() const;

			networking::Connection getConnection() const;
		};

}

namespace MagicCommands{
	class CastCommand : public MagicCommand {
		private:
			int targetId;
			std::string sourceName;
			std::string spellName;
			std::string spellDamage;
			std::string spellType;
			std::vector<networking::Connection>& clients;
			networking::Connection connection;
			networking::Connection Targetconnection;

		std::string message;
	public:
		CastCommand(std::vector<networking::Connection>& clients_,networking::Connection connection_, const std::string& message_);

		std::string execute(Context& context);

		int getId() const;
		std::string getSourceName() const;
		int getTargetId() const;

		std::string getSpellName() const;
		std::string getSpellDamage() const;
		std::string getSpellType() const;

		Spells* getCastedSpell(const std::string& castName_, std::vector<Spells>& spells_);

		bool checkMana(const int spellMana, const int playerMana);

		std::string replaceTargetName(std::string hitString, const std::string& targetName);

		networking::Connection getConnection() const;
		networking::Connection getTargetConnection() const;
	};

	class ConfuseCommand : public MagicCommand {
    private:
			int targetId;
			std::vector<networking::Connection>& clients;
			networking::Connection connection;
			networking::Connection Targetconnection;
			std::string sourceName;
      std::string message;
			std::string spellName;
			std::string spellDamage;
			std::string spellType;

    public:
        ConfuseCommand(std::vector<networking::Connection>& clients_,networking::Connection connection_, const std::string& message_);

        std::string execute(Context& context);

        int getId() const;
				int getTargetId() const;
				std::string getSpellName() const;
				std::string getSourceName() const;
				std::string getSpellDamage() const;
				std::string getSpellType() const;


        bool checkMana(const int spellMana, const int playerMana);

        networking::Connection getConnection() const;
				networking::Connection getTargetConnection() const;

    };
}
#endif
