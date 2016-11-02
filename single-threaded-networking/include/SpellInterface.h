#ifndef SPELL_INTERFACE
#define SPELL_INTERFACE

#include "Context.h"
#include "Server.h"

class Spell {
public:
	virtual std::string execute(Context& context) = 0;
	virtual std::string getName() const = 0;
	virtual networking::Connection getConnection() const = 0;
	//virtual Npc* getCurrentlySelectedNpc() = 0;
	//virtual void printClass(int n) = 0;
};

#endif