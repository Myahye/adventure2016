#ifndef NPC_H
#define NPC_H

#include "Character.h"

class Npc {

	std::string shortdesc;

	std::unordered_map<int,std::vector<Object>> npcInventory;
	std::unordered_map<int,Object> npcEquipment;

public:
	Character npcCharacter;
	Npc();
	//Npc Constructor
	Npc(int const id, std::string const shortdesc);

	std::string getShortDesc() const;
	void setShortDesc(const std::string& shortdesc);

	//--------------------------------------Lawrence Yu
    void addObjectToInventory(const Object& object, unsigned int limit);
    
    bool removeObjectFromInventory(const std::string& objectName);

    bool equipObject(const Object& object, int slot);
    bool unEquipObject(int slot);
    //bool unequipObject();

    std::unordered_map<int,std::vector<Object>> getNpcInventory() const;
    std::unordered_map<int,Object> getNpcEquipment() const;

    std::string getNpcEquipmentDesc() const;
    std::string getNpcInventoryDesc() const;
};

#endif