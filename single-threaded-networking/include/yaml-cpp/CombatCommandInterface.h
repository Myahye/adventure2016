#ifndef COMBAT_COMMAND_INTERFACE
#define COMBAT_COMMAND_INTERFACE

#include "Context.h"
#include "Server.h"

class CombatCommand {
public:
	virtual std::string execute(Context& context) = 0;

	virtual int getSourceId() const = 0;
	virtual std::string getSourceName() const = 0;
	virtual int getTargetId() const = 0;

	virtual networking::Connection getSourceConnection() const = 0;
	virtual networking::Connection getTargetConnection() const = 0;

	//virtual Npc* getCurrentlySelectedNpc() = 0;
	//virtual void printClass(int n) = 0;
	virtual ~CombatCommand() {}
};

#endif //COMBAT_COMMAND_INTERFACE
