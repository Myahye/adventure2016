#include "Room.h"
#include "Object.h"
#include "Npc.h"
#include "Player.h"
#include "Spells.h"

#ifndef CONTEXT_H
#define CONTEXT_H

class Context {
private:
	std::unordered_map<int,Room>* rooms;
	std::unordered_map<int,Npc>* Npcs;
	std::unordered_map<int,Object>* objects;
	Npc* currentlySelectedNpc = NULL;
	std::unordered_map<int,Player>* players;
	std::unordered_map<int,int>* playerLocations;
	std::vector<Spells>* offenseSpells;
  	std::vector<Spells>* defenseSpells;
  	std::unordered_map<Character, Character>* swappedCharacters;

public:
	Context();
	Context(std::unordered_map<int,Room>* rooms_, std::unordered_map<int,Npc>* Npcs_, std::unordered_map<int,Object>* objects_, std::unordered_map<int,Player>* players_, std::unordered_map<int,int>* playerLocations_, std::vector<Spells>* offenseSpells_, std::vector<Spells>* defenseSpells_);

	std::unordered_map<int,Room>* getRooms();
	std::unordered_map<int,Npc>* getNpcs();
	std::unordered_map<int,Object>* getObjects();
	std::unordered_map<int,Player>* getPlayers();
	std::unordered_map<int,int>* getPlayerLocations();
	std::vector<Spells>* getOffenseSpells();
  	std::vector<Spells>* getDefenseSpells();
  	std::unordered_map<Character, Character>* getSwappedCharacters();

	void setCurrentlySelectedNpc(Npc* npc);
	Npc* getCurrentlySelectedNpc();
};

#endif
