#ifndef NPC_H
#define NPC_H

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
	//NPC Constructor
	NPC (int id, std::string shortdesc);
	
	//Armor
	int getArmor() const;
	void setArmor(int armor);
	
	//Damage
	std::string getDamage() const;
	void setDamage(std::string& damage);
	
	//Description
	std::vector<string> getDesc() const;
	void setDesc(vector<std::string>& description);

	//Exp
	int getExp() const;
	void setExp(int exp);

	//Gold
	int getGold() const;
	void setGold(int gold);

	//Hit
	std::string getHit() const;
	void setHit(std::string& hit);

	//ID
	int getId() const;
	void setId(int id);

	//Keywords
	std::vector<std::string> getKeywords() const;
	void setKeywords(std::vector<string>& keywords);

	//Level
	int getLevel() const;
	void setLevel(int level);

	//LongDesc
	std::string getLongDesc() const;
	void setLongDesc(std::string& longdesc);
	
	//ShortDesc
	std::string getShortDesc() const;
	void setShortDesc(std::string& shortdesc);

	//Thac0
	int getThac0() const;
	void setThac0(int thac0);
};

#endif