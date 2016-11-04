// Character.cpp
#include "Character.h"

Character::Character() {
	character_ = new CharacterImp(0);
}

Character::Character(int const id) {
	character_ = new CharacterImp(id);
}

// Getter and setter for id
int Character::getId() const {
	return character_->getId();
}

void Character::setId(int const id) {
	character_->setId(id);
}

// Getter and setter for armor
int Character::getArmor() const {
	return character_->getArmor();
}

void Character::setArmor(int const armor) {
	character_->setArmor(armor);
}

// Getter and setter for exp
int Character::getExp() const {
	return character_->getExp();
}

void Character::setExp(int const exp) {
	character_->setExp(exp);
}

// Getter and setter for gold
int Character::getGold() const {
	return character_->getGold();
}

void Character::setGold(int const gold) {
	character_->setGold(gold);
}

// Getter and setter for level
int Character::getLevel() const {
	return character_->getLevel();
}

void Character::setLevel(int const level) {
	character_->setLevel(level);
}

// Getter and setter for thac0
int Character::getThac0() const {
	return character_->getThac0();
}

void Character::setThac0(int const thac0) {
	character_->setThac0(thac0);
}

// Getter and setter for damage
std::string Character::getDamage() const {
	return character_->getDamage();
}
	
void Character::setDamage(const std::string& damage) {
	character_->setDamage(damage); 
}

// Getter and setter for hit
std::string Character::getHit() const {
	return character_->getHit();
}

void Character::setHit(const std::string& hit) {
	character_->setHit(hit);
}

// Getter and setter for description
std::string Character::getDescription() const {
	return character_->getDescription();
}

void Character::setDescription(const std::vector<std::string>& description) {
	character_->setDescription(description);
}

// Getter and setter for keywords
std::vector<std::string> Character::getKeywords() const {
	return character_->getKeywords();
}

void Character::setKeywords(const std::vector<std::string>& keywords) {
	character_->setKeywords(keywords);
}

// Getter and setter for longdesc
std::string Character::getLongdesc() const {
	return character_->getLongdesc();
}

void Character::setLongdesc(const std::vector<std::string>& longdesc) {
	character_->setLongdesc(longdesc);
}
