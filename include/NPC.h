#ifndef NPC_H
#define NPC_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class NPC {
	int armor, exp, gold, id, level, thac0;
	string damage, hit, shortdesc;
	vector<string> description, keywords, longdesc;

public:
	NPC (int, string);
	
	int getArmor() const;
	void setArmor(int);
	
	string getDamage() const;
	void setDamage(string);
	
	vector<string> getDesc() const;
	void setDesc(vector<string>);

	int getExp() const;
	void setExp(int);

	int getGold() const;
	void setGold(int);

	string getHit() const;
	void setHit(string);

	int getId() const;
	void setId(int);

	vector<string> getKeywords() const;
	void setKeywords(vector<string>);

	int getLevel() const;
	void setLevel(int);

	string getLongDesc() const;
	void setLongDesc(string);
	
	string getShortDesc() const;
	void setShortDesc(string);

	int getThac0() const;
	void setThac0(int);
};

#endif