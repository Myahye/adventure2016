#ifndef NPC_CPP
#define NPC_CPP

#include "Npc.h"

//Npc Constructor
Npc::Npc():
<<<<<<< HEAD
    npcCharacter{0} {};

Npc::Npc (const int id):
    npcCharacter{id}{};
=======
    npcCharacter{0, false} {};

Npc::Npc (const int id):
    npcCharacter{id, false} {};
>>>>>>> master

void Npc::setCharacter(const Character& character){
    this->npcCharacter = character;
}

#endif