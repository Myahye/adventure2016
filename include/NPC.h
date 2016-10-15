#ifndef NPC_H
#define NPC_H

#include <iostream>
#include <vector>
#include <string>

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

public:
	NPC (int, std::string);
	
	int getArmor() const;
	void setArmor(int);
	
	std::string getDamage() const;
	void setDamage(std::string&);
	
	std::vector<string> getDesc() const;
	void setDesc(vector<std::string>&);

	int getExp() const;
	void setExp(int);

	int getGold() const;
	void setGold(int);

	std::string getHit() const;
	void setHit(std::string&);

	int getId() const;
	void setId(int);

	std::vector<std::string> getKeywords() const;
	void setKeywords(std::vector<string>&);

	int getLevel() const;
	void setLevel(int);

	std::string getLongDesc() const;
	void setLongDesc(std::string&);
	
	std::string getShortDesc() const;
	void setShortDesc(std::string&);

	int getThac0() const;
	void setThac0(int);
};

#endif