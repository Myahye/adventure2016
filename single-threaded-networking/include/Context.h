#include "Room.h"
#include "Object.h"
#include "Character.h"

#ifndef CONTEXT_H
#define CONTEXT_H

class Context {
private:
	std::unordered_map<int,Room>* rooms;
	std::unordered_map<int,Character>* Npcs;
	std::unordered_map<int,Object>* objects;
	Character* currentlySelectedNpc = NULL;
	std::unordered_map<int,Character>* players;
	std::unordered_map<int,int>* playerLocations;

public:
	Context();
	Context(std::unordered_map<int,Room>* rooms_, std::unordered_map<int,Character>* Npcs_, std::unordered_map<int,Object>* objects_, std::unordered_map<int,Character>* players_, std::unordered_map<int,int>* playerLocations_);

	std::unordered_map<int,Room>* getRooms();
	std::unordered_map<int,Character>* getNpcs();
	std::unordered_map<int,Object>* getObjects();
	std::unordered_map<int,Character>* getPlayers();
	std::unordered_map<int,int>* getPlayerLocations();

	void setCurrentlySelectedNpc(Character* npc);
	Character* getCurrentlySelectedNpc();
};

#endif
