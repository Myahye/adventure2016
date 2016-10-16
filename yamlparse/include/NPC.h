#ifndef NPC_H
#define NPC_H

#include <iostream>
#include <vector>
#include <string>


class NPC {
	int armor, exp, gold, id, level, thac0;
	std::string damage, hit, shortdesc;
	std::vector<std::string> description, keywords, longdesc;

public:
	NPC (int , std::string );
	
	int getArmor() const;
	void setArmor(int armor_);
	
	std::string getDamage() const;
	void setDamage(std::string& damage_);
	
	std::vector<std::string> getDesc() const;
	void setDesc(std::vector<std::string>& description_);

	int getExp() const;
	void setExp(int exp_);

	int getGold() const;
	void setGold(int gold_);

	std::string getHit() const;
	void setHit(std::string& hit_);

	int getId() const;
	void setId(int id_);

	std::vector<std::string> getKeywords() const;
	void setKeywords(std::vector<std::string>& keywords_);

	int getLevel() const;
	void setLevel(int level_);

	std::vector<std::string> getLongDesc() const;
	void setLongDesc(std::vector<std::string>& longdesc_);
	
	std::string getShortDesc() const;
	void setShortDesc(std::string& shortdesc_);

	int getThac0() const;
	void setThac0(int thac0_);

	//New function added in to test
	void printClass() const;
};

#endif