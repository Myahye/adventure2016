#ifndef COMMANDS_H
#define COMMANDS_H

#include <unordered_map>
#include <iomanip>
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

	/*class CastCommand : public Command {
	private:
		networking::Connection connection;
		std::string message;
	public:
		CastCommand(networking::Connection connection_, const std::string& message_);

		std::string execute(Context& context);

		int getId() const;

		Spells* getCastedSpell(const std::string& castName_, std::vector<Spells>& spells_);

		bool checkMana(const int spellMana, const int playerMana);

		std::string replaceTargetName(std::string hitString, const std::string& targetName);

		networking::Connection getConnection() const;
	};
*/
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

  	class ConfuseCommand : public Command {
    private:
        networking::Connection connection;
        std::string message;
    public:
        ConfuseCommand(networking::Connection connection_, const std::string& message_);
        
        std::string execute(Context& context);
        
        int getId() const;
        
        bool checkMana(const int spellMana, const int playerMana);

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
}
#endif
