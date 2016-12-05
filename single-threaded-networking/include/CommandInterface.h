#ifndef COMMAND_INTERFACE
#define COMMAND_INTERFACE

#include "Context.h"
#include "Server.h"

class Command {
public:
	virtual std::string execute(Context& context) = 0;
	virtual int getId() const = 0;
	virtual networking::Connection getConnection() const = 0;
	//virtual Npc* getCurrentlySelectedNpc() = 0;
	//virtual void printClass(int n) = 0;
	virtual ~Command() {}
};

class MagicCommand {
public:
	virtual std::string execute(Context& context) = 0;

	virtual int getId() const = 0;
	virtual std::string getSourceName() const = 0;
	virtual int getTargetId() const = 0;
	virtual	std::string getSpellName() const = 0;
	virtual std::string getSpellDamage() const = 0;
	virtual std::string getSpellType() const = 0;


	virtual networking::Connection getConnection() const = 0;
	virtual networking::Connection getTargetConnection() const = 0;

	//virtual Npc* getCurrentlySelectedNpc() = 0;
	//virtual void printClass(int n) = 0;
	virtual ~MagicCommand() {}
};

#endif