#ifndef COMMAND_INTERFACE_H
#define COMMAND_INTERFACE_H

#include "Reset.h"

class Command {
private:
	virtual void execute(Reset& reset) = 0;
};

#endif
