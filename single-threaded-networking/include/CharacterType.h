#ifndef CHARACTERTYPE_H
#define CHARACTERTYPE_H

#include "Object.h"

#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>

class CharacterType{

public:
	virtual int newHealth(const int lvl);
    virtual int newMana(const int lvl);
    
    //player
    virtual std::string getUsername() const;
    virtual void setUsername(const std::string& username);
	virtual std::string getPassword() const;
	virtual void setPassword(const std::string& password);

	//npc
	virtual std::string getShortDesc() const;
	virtual void setShortDesc(const std::string& shortdesc);

	virtual void addObjectToInventory(const Object& object, unsigned int limit);
	virtual bool removeObjectFromInventory(const std::string& objectName);
	virtual bool equipObject(const Object& object, int slot);
	virtual bool unEquipObject(int slot);
	virtual std::unordered_map<int,std::vector<Object>> getInventory() const;
    virtual std::unordered_map<int,Object> getEquipment() const;
	virtual std::string getInventoryDesc() const;
	virtual std::string getEquipmentDesc() const;
};

#endif