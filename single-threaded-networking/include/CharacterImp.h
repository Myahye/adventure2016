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

public:
	// Constructor
	CharacterImp();
	CharacterImp(const int id);

	// Getter and setters:
	// ID
	int getId() const;
	void setId(const int id);

	// Armor
	int getArmor() const;
	void setArmor(int const armor);

	// Exp
	int getExp() const;
	void setExp(int const exp);

	// Gold
	int getGold() const;
	void setGold(int const gold);

	// Level
	int getLevel() const;
	void setLevel(int const level);

	// Thac0
	int getThac0() const;
	void setThac0(int const thac0);

	// Damage
	std::string getDamage() const;
	void setDamage(const std::string& damage);

	// Description
	std::string getDescription() const;
	void setDescription(const std::vector<std::string>& description);

	// Hit
	std::string getHit() const;
	void setHit(const std::string& hit);

	// Keywords
	std::vector<std::string> getKeywords() const;
	void setKeywords(const std::vector<std::string>& keywords);

	// LongDesc
	std::string getLongdesc() const;
	void setLongdesc(const std::vector<std::string>& longdesc);

	virtual void attack() = 0;

};

#endif