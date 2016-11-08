// Npc.cpp
#include "Npc.h"

// Constructors:
Npc::Npc():
shortdesc{shortdesc} { this->character_ = new NpcImp(0); }

Npc::Npc(int const id, const std::string& shortdesc):
shortdesc{shortdesc} { this->character_ = new NpcImp(id); }

// Getter and setter for id
int Npc::getId() const {
	return character_->getId();
}

void Npc::setId(int const id) {
	character_->setId(id);
}

// Getter and setter for shortdesc
std::string Npc::getShortdesc() const {
	return shortdesc;
}

void Npc::setShortdesc(const std::string& shortdesc) {
	this->shortdesc = shortdesc;
}

// Getter and setter for armor
int Npc::getArmor() const {
	return character_->getArmor();
}

void Npc::setArmor(int const armor) {
	character_->setArmor(armor);
}

// Getter and setter for exp
int Npc::getExp() const {
	return character_->getExp();
}

void Npc::setExp(int const exp) {
	character_->setExp(exp);
}

// Getter and setter for gold
int Npc::getGold() const {
	return character_->getGold();
}

void Npc::setGold(int const gold) {
	character_->setGold(gold);
}

// Getter and setter for level
int Npc::getLevel() const {
	return character_->getLevel();
}

void Npc::setLevel(int const level) {
	character_->setLevel(level);
}

// Getter and setter for thac0
int Npc::getThac0() const {
	return character_->getThac0();
}

void Npc::setThac0(int const thac0) {
	character_->setThac0(thac0);
}

// Getter and setter for damage
std::string Npc::getDamage() const {
	return character_->getDamage();
}
	
void Npc::setDamage(const std::string& damage) {
	character_->setDamage(damage); 
}

// Getter and setter for hit
std::string Npc::getHit() const {
	return character_->getHit();
}

void Npc::setHit(const std::string& hit) {
	character_->setHit(hit);
}

// Getter and setter for description
std::string Npc::getDescription() const {
	return character_->getDescription();
}

void Npc::setDescription(const std::vector<std::string>& description) {
	character_->setDescription(description);
}

// Getter and setter for keywords
std::vector<std::string> Npc::getKeywords() const {
	return character_->getKeywords();
}

void Npc::setKeywords(const std::vector<std::string>& keywords) {
	character_->setKeywords(keywords);
}

// Getter and setter for longdesc
std::string Npc::getLongdesc() const {
	return character_->getLongdesc();
}

void Npc::setLongdesc(const std::vector<std::string>& longdesc) {
	character_->setLongdesc(longdesc);
}


// Other functions not yet implemented:
void Npc::attack() {
	character_->attack();
}