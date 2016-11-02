// NPC.h
#ifndef NPC_H
#define NPC_H

#include "Person.h"

class NPC : public Person {
private:
	std::string shortdesc;

public:
	NPC();
	NPC(int const id, const std::string& shortdesc);

	std::string getShortdesc();
	void setShortdesc(const std::string& shortdesc);

	/* Lawrence Yu -----------------------------------------------------
	void addObjectToInventory(const Object& object, unsigned int limit);
    void removeObjectFromInventory(int objectID);

    void equipObject(const Object& object, int slot);
    void unEquipObject(int objectId);
    //bool unequipObject();

    std::unordered_map<int,std::vector<Object>> getNpcInventory() const;
    std::unordered_map<int,Object> getNpcEquipment() const;

    std::string getNpcEquipmentDesc() const;
    std::string getNpcInventoryDesc() const;
    */
};

#endif