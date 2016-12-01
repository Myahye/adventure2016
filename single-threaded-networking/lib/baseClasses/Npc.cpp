#ifndef NPC_CPP
#define NPC_CPP

#include "Npc.h"

//Npc Constructor
Npc::Npc():
    npcCharacter{0, false} {};

Npc::Npc (const int id):
    npcCharacter{id, false} {};

void Npc::setCharacter(const Character& character){
    this->npcCharacter = character;
}

#endif
