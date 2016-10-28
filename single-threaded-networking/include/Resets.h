#ifndef RESETS_H
#define RESETS_H

#include <unordered_map>

#include "ResetInterface.h"
#include "NPC.h"
#include "Room.h"
#include "Object.h"

//using namespace Resets;

namespace Resets {

	class ResetNPC : public Reset {
	private:
		std::string action;
		std::string comment;
		int id;
		int limit;
		int room;
		NPC* currentlySelectedNPC = NULL;
	public:
		ResetNPC(const std::string& action, int const id, int const limit, int const room, const std::string& comment);

		void execute(Context& context);

		NPC* getCurrentlySelectedNPC();

		void printClass(int n);
	};

	//-----------------------------------------ResetObject

	class ResetObject : public Reset {
	private:
		std::string action;
		std::string comment;
		int id;
		int limit;
		int room;
		NPC* currentlySelectedNPC = NULL;
	public:
		ResetObject(const std::string& action, int const id, int const limit, int const room, const std::string& comment);

		void execute(Context& context);

		NPC* getCurrentlySelectedNPC();

		void printClass(int n);
	};

	//-----------------------------------------ResetGive

	class ResetGive : public Reset {
	private:
		std::string action;
		std::string comment;
		int id;
		int limit;
		int room;
		NPC* currentlySelectedNPC = NULL;
	public:
		ResetGive(const std::string& action, int const id, int const limit, int const room, const std::string& comment);

		void execute(Context& context);

		NPC* getCurrentlySelectedNPC();

		void printClass(int n);
	};

	//-----------------------------------------ResetEquip
}

#endif