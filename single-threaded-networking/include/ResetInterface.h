#ifndef RESET_INTERFACE
#define RESET_INTERFACE

#include "Context.h"

class Reset {
public:
	virtual void execute(Context& context) = 0;
	virtual Npc* getCurrentlySelectedNpc() = 0;
	virtual std::string printClass() = 0;
	virtual ~Reset() {}
	virtual int getRoom() = 0;
};

#endif