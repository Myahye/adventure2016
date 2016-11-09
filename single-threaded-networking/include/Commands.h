#ifndef COMMANDS_H
#define COMMANDS_H

#include "CommandInterface.h"
#include "Reset.h"
#include "Model.h"

namespace Commands {

	class ResetNPC : public Command {
	public:
		virtual void execute(Model& model, Reset& reset);
	};
}

#endif
