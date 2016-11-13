// CharacterType.cpp
#include "CharacterType.h"

int CharacterType::newHealth(const int lvl) {
	return 0;
}

int CharacterType::newMana(const int lvl) {
	return 0;
}

//Player
std::string CharacterType::getUsername() const {
	return "";
}

void CharacterType::setUsername(const std::string& username) {}

std::string CharacterType::getPassword() const {
	return "";
}

void CharacterType::setPassword(const std::string& password) {}

//Npc
std::string CharacterType::getShortDesc() const {
	return "";
}
void CharacterType::setShortDesc(const std::string& shortdesc) {}


void CharacterType::addObjectToInventory(const Object& object, unsigned int limit) {}

bool CharacterType::removeObjectFromInventory(const std::string& objectName) {
	return false;
};

bool CharacterType::equipObject(const Object& object, int slot) {
	return false; 
}

bool CharacterType::unEquipObject(int slot) {
	return false;
}

std::unordered_map<int,std::vector<Object>> CharacterType::getInventory() const {
	std::unordered_map<int,std::vector<Object>> inventory;
	return inventory;
}

std::unordered_map<int,Object> CharacterType::getEquipment() const {
	std::unordered_map<int,Object> equipment;
	return equipment;
}

std::string CharacterType::getInventoryDesc() const {
	return "";
}

std::string CharacterType::getEquipmentDesc() const {
	return "";
}