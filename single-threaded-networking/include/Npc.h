#ifndef NPC_H
#define NPC_H

#include "Character.h"

class Npc {

    std::unordered_map<int,std::vector<Object>> npcInventory;
    std::unordered_map<int,Object> npcEquipment;

public:
    Npc();
    Npc(const int id);
    Character npcCharacter;

    void setCharacter(const Character& character);
};

#endif