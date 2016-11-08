#ifndef COMMAND_INTERFACE
#define COMMAND_INTERFACE

#include "Context.h"
#include "Server.h"

class Command {
public:
	virtual std::string execute(Context& context) = 0;
	virtual int getId() const = 0;
	virtual networking::Connection getConnection() const = 0;
	virtual ~Command() {}
};

class CombatCommand {
public:
	virtual std::string execute(Context& context) = 0;

	virtual int getSourceId() const = 0;
	virtual std::string getSourceName() const = 0;
	virtual int getTargetId() const = 0;

	virtual networking::Connection getSourceConnection() const = 0;
	virtual networking::Connection getTargetConnection() const = 0;
	virtual ~CombatCommand() {}
};

#endif
