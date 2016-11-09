#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <vector>
#include <string>
#include "Object.h"
#include <unordered_map>
#include <algorithm>

class Character {
	int armor = 0;
	int exp = 0;
	int gold = 0;
	int id = 0;
	int level = 0;
	int thac0;

	std::string damage;
	std::string hit;

	std::vector<std::string> description;
	std::vector<std::string> keywords;
	std::vector<std::string> longdesc;

public:
	Character();
	Character(const int id);

	int getArmor() const;
	void setArmor(const int armor);

	int getExp() const;
	void setExp(const int exp);

	int getGold() const;
    void setGold(const int gold);

	int getId() const;
	void setId(const int id);

	int getLevel() const;
	void setLevel(const int level);

	int getThac0() const;
	void setThac0(int const thac0);
	
	std::string getDamage() const;
	void setDamage(const std::string& damage);

	std::string getHit() const;
	void setHit(const std::string& hit);

	std::string getDescription() const;
	void setDescription(const std::vector<std::string>& description);

	std::vector<std::string> getKeywords() const;
	void setKeywords(const std::vector<std::string>& keywords);

	std::string getLongdesc() const;
	void setLongdesc(const std::vector<std::string>& longdesc);
}; 

#endif 