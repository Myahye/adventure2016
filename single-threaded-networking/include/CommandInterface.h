#ifndef COMMAND_INTERFACE
#define COMMAND_INTERFACE

#include "Context.h"
#include "Server.h"
/**
*	@Class  Command Interface class
*	@breif  Basically a class that acts as a interface to commands thus 
*			seperating the class from its implementation. The base classes 
*			thus only intreact with the help of interface.
*/

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
