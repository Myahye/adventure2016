#include "NPC.h"
#include "Room.h"
#include "Object.h"

#ifndef CONTEXT_H
#define CONTEXT_H

class Context {
private:
	std::unordered_map<int,Room>* rooms;
	std::unordered_map<int,NPC>* NPCs;
	std::unordered_map<int,Object>* objects;
	NPC* currentlySelectedNPC = NULL;
public:
	Context();
	Context(std::unordered_map<int,Room>* rooms_, std::unordered_map<int,NPC>* NPCs_, std::unordered_map<int,Object>* objects_);

	std::unordered_map<int,Room>* getRooms();
	std::unordered_map<int,NPC>* getNPCs();
	std::unordered_map<int,Object>* getObjects();

	void setCurrentlySelectedNPC(NPC* npc);
	NPC* getCurrentlySelectedNPC();
};

#endif
