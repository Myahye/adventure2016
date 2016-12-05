#ifndef RESETS_H
#define RESETS_H

#include <unordered_map>

#include "ResetInterface.h"
#include "Npc.h"
#include "Room.h"
#include "Object.h"

//using namespace Resets;

namespace Resets {

	//-----------------------------------------ResetNpc

	class ResetNpc : public Reset {
	private:
		Npc* currentlySelectedNpc = NULL;
	public:
		std::string action;
		int id;
		unsigned int limit;
		int room;
		std::string comment;

		ResetNpc(const std::string& action, int const id, unsigned int const limit, int const room, const std::string& comment);

		void execute(Context& context);

		Npc* getCurrentlySelectedNpc();

		std::string printClass();

		int getRoom();
	};

	//-----------------------------------------ResetObject

	class ResetObject : public Reset {
	private:
		Npc* currentlySelectedNpc = NULL;
	public:
		std::string action;
		int id;
		unsigned int limit;
		int room;
		std::string comment;

		ResetObject(const std::string& action, int const id, unsigned int const limit, int const room, const std::string& comment);

		void execute(Context& context);

		Npc* getCurrentlySelectedNpc();

		std::string printClass();

		int getRoom();
	};

	//-----------------------------------------ResetGive

	class ResetGive : public Reset {
	private:
		std::string action;
		int id;
		unsigned int limit;
		int room;
		std::string comment;
		Npc* currentlySelectedNpc = NULL;
	public:
		ResetGive(const std::string& action, int const id, unsigned int const limit, int const room, const std::string& comment);

		void execute(Context& context);

		Npc* getCurrentlySelectedNpc();

		std::string printClass();

		int getRoom();
	};

	//-----------------------------------------ResetEquip

	class ResetEquip : public Reset {
	private:
		std::string action;
		int id;
		std::string slot;
		std::string comment;
		Npc* currentlySelectedNpc = NULL;
	public:
		ResetEquip(const std::string& action, int const id, const std::string& slot, const std::string& comment);

		void execute(Context& context);

		Npc* getCurrentlySelectedNpc();

		std::string printClass();

		int getRoom();
	};
}

#endif