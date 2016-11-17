#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include "Player.h"
#include "Npc.h"
#include "CharacterType.h"

class Character {
protected:
	CharacterType* charType;

	int armor = 0;
	int exp = 0;
	int gold = 0;
	int id = 0;
	int level = 0;
	
	int MaxHealth = 100;
	int MaxMana = 85;
	int health = 100;
    int mana = 85;

	int thac0;

	std::string damage;
	std::string hit;

	std::vector<std::string> description;
	std::vector<std::string> keywords;
	std::vector<std::string> longdesc;

public:
	Character();
	Character(const int id);
	Character(const int id, const std::string& shortdesc);
	Character(const int id, const std::string& username, const std::string& password);

	~Character();
	
	int getArmor() const;
	void setArmor(const int armor);

	int getMaxHealth() const;
	void setMaxHealth(const int health);

	int getMaxMana() const;
	void setMaxMana(const int mana);

	int getExp() const;
	void setExp(const int exp);
	void setNewStats(const int lvl);

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

	std::string getLongDesc() const;
	void setLongDesc(const std::vector<std::string>& longdesc);

	int getHealth() const;
    void setHealth(int const health);

    int getMana() const;
    void setMana(int const mana);

	CharacterType& getCharacterType();
}; 

#endif

