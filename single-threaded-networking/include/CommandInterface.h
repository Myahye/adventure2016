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

#endif