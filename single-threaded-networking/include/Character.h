// Character.h
// Interface for Npc and Player classes

#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <vector>
#include <string>
// #include "Object.h"
#include <unordered_map>
#include <algorithm>

class Character {
public:
	// ID
	virtual int getId() const = 0;
	virtual void setId(const int id) = 0;

	// Armor
	virtual int getArmor() const = 0;
	virtual void setArmor(int const armor) = 0;

	// Exp
	virtual int getExp() const = 0;
	virtual void setExp(int const exp) = 0;

	// Gold
	virtual int getGold() const = 0;
	virtual void setGold(int const gold) = 0;

	// Level
	virtual int getLevel() const = 0;
	virtual void setLevel(int const level) = 0;

	// Thac0
	virtual int getThac0() const = 0;
	virtual void setThac0(int const thac0) = 0;

	// Damage
	virtual std::string getDamage() const = 0;
	virtual void setDamage(const std::string& damage) = 0;

	// Description
	virtual std::string getDescription() const = 0;
	virtual void setDescription(const std::vector<std::string>& description) = 0;

	// Hit
	virtual std::string getHit() const = 0;
	virtual void setHit(const std::string& hit) = 0;

	// Keywords
	virtual std::vector<std::string> getKeywords() const = 0;
	virtual void setKeywords(const std::vector<std::string>& keywords) = 0;

	// LongDesc
	virtual std::string getLongdesc() const = 0;
	virtual void setLongdesc(const std::vector<std::string>& longdesc) = 0;

	virtual void attack() = 0;

}; 

#endif 