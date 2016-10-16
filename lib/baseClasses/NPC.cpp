#include "NPC.h"

//NPC Constructor
NPC::NPC (int id, std::string shortdesc): 
	id{id}, shortdesc{shortdesc}{};

//Getter and Setter for Armor
int NPC::getArmor() const {
	return armor;
}
void NPC::setArmor(int armor) {
	this->armor = armor;
}

//Getter and Setter for	Damage
std::string NPC::getDamage() const {
	return damage;
}
void NPC::setDamage(std::string& damage) {
	this->damage = damage;
}

//Getter and Setter for	Description
std::vector<std::string> NPC::getDesc() const {
	return description;
}
void NPC::setDesc(std::vector<std::string>& description) {
	this->description = description;
}

//Getter and Setter for Exp
int NPC::getExp() const {
	return exp;
}
void NPC::setExp(int exp) {
	this->exp = exp;
}

//Getter and Setter for Gold
int NPC::getGold() const {
	return gold;
}
void NPC::setGold(int gold) {
	this->gold = gold;
}

//Getter and Setter for Hit
std::string NPC::getHit() const {
	return hit;
}
void NPC::setHit(std::string& hit) {
	this->hit = hit;
}

//Getter and Setter for Id
int NPC::getId() const {
	return id;
}
void NPC::setId(int id) {
	this->id = id;
}

//Getter and Setter for Keywords
std::vector<std::string> NPC::getKeywords() const {
	return keywords;
}
void NPC::setKeywords(std::vector<std::string>& keywords) {
	this->keywords = keywords;
}

//Getter and Setter for Level
int NPC::getLevel() const {
	return level;
}
void NPC::setLevel(int level) {
	this->level = level;
}

//Getter and Setter for Longdesc
std::string NPC::getLongDesc() const {
	return longdesc;
}
void NPC::setLongDesc(std::string& longdesc) {
	this->longdesc = longdesc;
}
	
//Getter and Setter for Shordesc
std::string NPC::getShortDesc() const {
	return shortdesc;
}
void NPC::setShortDesc(std::string& shortdesc) {
	this->shortdesc = shortdesc;
}

//Getter and Setter for Thac0
int NPC::getThac0() const {
	return thac0;
}
void NPC::setThac0(int thac0) {
	this->thac0 = thac0;
}
