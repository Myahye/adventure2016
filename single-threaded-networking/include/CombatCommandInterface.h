#ifndef COMBATCOMMAND_INTERFACE
#define COMBATCOMMAND_INTERFACE

#include "Context.h"
#include "Server.h"

class CombatCommand {
public:
	//virtual std::string execute(Context& context) = 0;
	virtual std::string execute(std::vector<networking::Connection>& clients, std::vector<Fight>& fights, Context& context) = 0;
	virtual int getId() const = 0;
	virtual networking::Connection getConnection() const = 0;
	// virtual int getSourceId() const = 0;
	// virtual std::string getSourceName() const = 0;
	// virtual int getTargetId() const = 0;
	//
	// virtual networking::Connection getSourceConnection() const = 0;
	// virtual networking::Connection getTargetConnection() const = 0;

	//virtual Npc* getCurrentlySelectedNpc() = 0;
	//virtual void printClass(int n) = 0;
	virtual ~CombatCommand() {}
};

#endif//COMBATCOMMAND_INTERFACE
