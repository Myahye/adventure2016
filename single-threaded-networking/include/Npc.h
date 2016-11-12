#ifndef NPC_H
#define NPC_H

#include "CharacterType.h"

class Npc : public CharacterType {
protected:
	std::string shortdesc;

	std::unordered_map<int,std::vector<Object>> npcInventory;
	std::unordered_map<int,Object> npcEquipment;

public:
    const int DEFAULT_NPC_LEVEL = 2;
    const int DEFAULT_NPC_HEALTH = 100;
    const int DEFAULT_NPC_MANA = 50;
	Npc();
	//Npc Constructor
	Npc(std::string const shortdesc);

    ~Npc();

	std::string getShortDesc() const;
	void setShortDesc(const std::string& shortdesc);

	//--------------------------------------Lawrence Yu
    void addObjectToInventory(const Object& object, unsigned int limit);
    
    bool removeObjectFromInventory(const std::string& objectName);

    bool equipObject(const Object& object, int slot);
    bool unEquipObject(int slot);
    //bool unequipObject();

    std::unordered_map<int,std::vector<Object>> getInventory() const;
    std::unordered_map<int,Object> getEquipment() const;

    std::string getEquipmentDesc() const;
    std::string getInventoryDesc() const;
    int newHealth(const int lvl);
    int newMana(const int lvl);
};

#endif