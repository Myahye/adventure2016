// Npc.h
#ifndef NPC_H
#define NPC_C

#include <iostream>
#include <vector>
#include <string>
// #include "Object.h"
#include <unordered_map>
#include <algorithm>

#include "Character.h"
#include "NpcImp.h"

class Npc : public Character {
protected:
	std::string shortdesc;

public:
	Npc();
	Npc(int const id, const std::string& shortdesc);

	// ID
	int getId() const;
	void setId(const int id);

	// Shortdesc
	std::string getShortdesc() const;
	void setShortdesc(const std::string& shortdesc);

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

	// Other functions not yet implemented:
	void attack();

};

#endif