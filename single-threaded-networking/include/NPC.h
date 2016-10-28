#ifndef NPC_H
#define NPC_H

#include <iostream>
#include <vector>
#include <string>
#include "Object.h"
#include <unordered_map>

class NPC {
	int armor;
	int exp;
	int gold;
	int id;
	int level;
	int thac0;

	std::string damage;
	std::string hit;
	std::string shortdesc;

	std::vector<std::string> description;
	std::vector<std::string> keywords;
	std::vector<std::string> longdesc;

	//----------------------------Lawrence Yu
	std::unordered_map<int,std::vector<Object>> NPCInventory;

public:
	NPC();
	//NPC Constructor
	NPC (int const id, std::string const shortdesc);

	//Armor
	int getArmor() const;
	void setArmor(int const armor);

	//Damage
	std::string getDamage() const;
	void setDamage(const std::string& damage);

	//Description
	std::vector<std::string> getDesc() const;
	void setDesc(const std::vector<std::string>& description);

	//Exp
	int getExp() const;
	void setExp(int const exp);

	//Gold
	int getGold() const;
	void setGold(int const gold);

	//Hit
	std::string getHit() const;
	void setHit(const std::string& hit);

	//ID
	int getId() const;
	void setId(int const id);

	//Keywords
	std::vector<std::string> getKeywords() const;
	void setKeywords(const std::vector<std::string>& keywords);

	//Level
	int getLevel() const;
	void setLevel(int const level);

	//LongDesc
	std::vector<std::string> getLongDesc() const;
	void setLongDesc(const std::vector<std::string>& longdesc);

	//ShortDesc
	std::string getShortDesc() const;
	void setShortDesc(const std::string& shortdesc);

	//Thac0
	int getThac0() const;
	void setThac0(int const thac0);

	//--------------------------------------Lawrence Yu
    void addObjectToInventory(const Object& object, int limit);
    bool removeObjectFromInventory(int objectID);

    std::unordered_map<int,std::vector<Object>> getNPCInventory() const;
};

#endif
