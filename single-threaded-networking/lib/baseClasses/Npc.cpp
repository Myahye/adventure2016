#ifndef NPC_CPP
#define NPC_CPP

#include "Npc.h"

//Npc Constructor
Npc::Npc():
    npcCharacter{0} {};

Npc::Npc (const int id):
    npcCharacter{id}{};

void Npc::setCharacter(const Character& character){
    this->npcCharacter = character;
}

#endif