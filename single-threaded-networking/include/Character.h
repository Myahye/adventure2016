#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <vector>
#include <string>
#include "Object.h"
#include <unordered_map>
#include <algorithm>

class Character {

	std::unordered_map<int, std::vector<Object>> inventory;
	std::unordered_map<std::string, Object> equipment;

	//int inventoryLimit = 10;

	bool isPlayer;
	bool isSwapped = false;

	int armor = 0;
	int exp = 0;
	int gold = 0;
	int id = 0;
	int level = 1;
	int thac0;

	int maxHealth = 100;
	int maxMana = 85;

	int currentHealth = 100;
	int currentMana = 85;

	std::string damage;
	std::string hit;
	std::string shortdesc;

	std::vector<std::string> description;
	std::vector<std::string> keywords;
	std::vector<std::string> longdesc;

	std::string status = "Offline";


public:
	Character(bool isPlayer);
	Character(const int id, bool isPlayer);

	std::string getStatus() const;
	void setStatus(std::string s);

	bool checkCharacterType();
	void setCharacterType(bool isPlayer);

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

	int getMaxHealth() const;
	void setMaxHealth(const int maxHealth);

	int getMaxMana() const;
	void setMaxMana(const int maxMana);

	int getCurrentHealth() const;
	void setCurrentHealth(const int currentHealth);

	int getCurrentMana() const;
	void setCurrentMana(const int currentMana);

	int getThac0() const;
	void setThac0(int const thac0);

	std::string getDamage() const;
	void setDamage(const std::string& damage);

	std::string getHit() const;
	void setHit(const std::string& hit);

	std::string getDescription() const;
	std::vector<std::string> getDescriptionV() const;
	void setDescription(const std::vector<std::string>& description);

	std::string getShortDesc() const;
    void setShortDesc(const std::string& shortdesc);

	std::vector<std::string> getKeywords() const;
	void setKeywords(const std::vector<std::string>& keywords);

	std::string getLongDesc() const;
	std::vector<std::string> getLongDescV() const;
	void setLongDesc(const std::vector<std::string>& longdesc);

	void addObjectToInventory(const Object& object, unsigned int limit);
	bool removeObjectFromInventory(const std::string& objectName);

	bool equipObject(const Object& object, const std::string& slot);
    bool unEquipObject(const std::string& slot);

    //int getInventoryLimit() const;
    //void setInventoryLimit(const int inventoryLimit);

    std::unordered_map<int,std::vector<Object>> getInventory() const;
    void setInventory(std::unordered_map<int, std::vector<Object>>& inventory);

    std::unordered_map<std::string,Object> getEquipment() const;
    void setEquipment(std::unordered_map<std::string, Object>& equipment);

    std::string getEquipmentDesc() const;
    std::string getInventoryDesc() const;

    bool getSwappedStatus() const;
    void setSwappedStatus(bool swap);
};

#endif
