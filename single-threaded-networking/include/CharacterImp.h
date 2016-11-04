// Character.h
#ifndef CHARACTER_IMP_h
#define CHARACTER_IMP_H

#include <iostream>
#include <vector>
#include <string>
// #include "Object.h"
#include <unordered_map>
#include <algorithm>

class CharacterImp {
protected:
	int id;
	int armor;
	int exp;
	int gold;
	int level;
	int thac0;

	std::string damage;
	std::string hit;
	std::vector<std::string> description;
	std::vector<std::string> keywords;
	std::vector<std::string> longdesc;

	// Inventory:
	// std::unordered_map<int,std::vector<Object>> inventory;
	// std::unordered_map<int,Object> equipment;

public:
	// Constructor
	CharacterImp();
	CharacterImp(const int id);

	// ID
	virtual int getId() const;
	virtual void setId(const int id);

	// Armor
	virtual int getArmor() const;
	virtual void setArmor(int const armor);

	// Exp
	virtual int getExp() const;
	virtual void setExp(int const exp);

	// Gold
	virtual int getGold() const;
	virtual void setGold(int const gold);

	// Level
	virtual int getLevel() const;
	virtual void setLevel(int const level);

	// Thac0
	virtual int getThac0() const;
	virtual void setThac0(int const thac0);

	// Damage
	virtual std::string getDamage() const;
	virtual void setDamage(const std::string& damage);

	// Description
	virtual std::string getDescription() const;
	virtual void setDescription(const std::vector<std::string>& description);

	// Hit
	virtual std::string getHit() const;
	virtual void setHit(const std::string& hit);

	// Keywords
	virtual std::vector<std::string> getKeywords() const;
	virtual void setKeywords(const std::vector<std::string>& keywords);

	// LongDesc
	virtual std::string getLongdesc() const;
	virtual void setLongdesc(const std::vector<std::string>& longdesc);

}; 

#endif