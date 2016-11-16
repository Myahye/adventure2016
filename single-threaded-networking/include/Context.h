#include "Npc.h"
#include "Room.h"
#include "Object.h"
#include "Player.h"

#ifndef CONTEXT_H
#define CONTEXT_H

/*		@class     	Context 
*		@breif     	Coontext helps in the retivals of data and 
*					thus helps in the implementation of excute 
*					in the commands interface
*/
class Context {
private:
	std::unordered_map<int,Room>* rooms;
	std::unordered_map<int,Npc>* Npcs;
	std::unordered_map<int,Object>* objects;
	Npc* currentlySelectedNpc = NULL;
	std::unordered_map<int,Player>* players;
	std::unordered_map<int,int>* playerLocations;

public:
	Context();
	Context(std::unordered_map<int,Room>* rooms_, std::unordered_map<int,Npc>* Npcs_, std::unordered_map<int,Object>* objects_, std::unordered_map<int,Player>* players_, std::unordered_map<int,int>* playerLocations_);

	std::unordered_map<int,Room>* getRooms();
	std::unordered_map<int,Npc>* getNpcs();
	std::unordered_map<int,Object>* getObjects();
	std::unordered_map<int,Player>* getPlayers();
	std::unordered_map<int,int>* getPlayerLocations();

	void setCurrentlySelectedNpc(Npc* npc);
	Npc* getCurrentlySelectedNpc();
};

#endif
