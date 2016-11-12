#ifndef CHARACTERTYPE_H
#define CHARACTERTYPE_H

#include "Object.h"

#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>

class CharacterType{

public:
	virtual void addObjectToInventory(const Object& object, unsigned int limit);
	virtual std::string getInventoryDesc() const;
	virtual std::string getEquipmentDesc() const;
	virtual bool removeObjectFromInventory(const std::string& objectName);
	virtual std::string getUsername() const;
	virtual int newHealth(const int lvl);
    virtual int newMana(const int lvl);

};

#endif