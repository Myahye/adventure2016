#ifndef CHARACTER_CPP
#define CHARACTER_CPP

#include "Character.h"

// Constructors:
Character::Character():
id{0} {};

Character::Character (const int id):
id{id} {};

int Character::getArmor() const{
	return armor;
}
void Character::setArmor(const int armor){
	this->armor = armor;
}

int Character::getExp() const{
	return exp;
}
void Character::setExp(const int exp){
	this->exp = exp;
}

int Character::getGold() const{
	return gold;
}
void Character::setGold(const int gold){
	this->gold = gold;
}

int Character::getId() const{
	return id;
}
void Character::setId(const int id){
	this->id = id;
}

int Character::getLevel() const{
	return level;
}
void Character::setLevel(const int level){
	this->level = level;
}

int Character::getThac0() const {
	return thac0;
}
void Character::setThac0(int const thac0) {
	this->thac0 = thac0;
}

std::string Character::getDamage() const{
	return damage;
}
void Character::setDamage(const std::string& damage){
	this->damage = damage;
}

std::string Character::getHit() const{
	return hit;
}
void Character::setHit(const std::string& hit){
	this->hit = hit;
}

std::string Character::getDescription() const{
	std::string descString = "";
	for_each(description.begin(), description.end(), [&descString](const std::string& i){descString += i + "\n";} );	
	return descString;
}
void Character::setDescription(const std::vector<std::string>& description){
	this->description = description;
}

std::vector<std::string> Character::getKeywords() const{
	return keywords;
}
void Character::setKeywords(const std::vector<std::string>& keywords){
	this->keywords = keywords;
}

std::string Character::getLongdesc() const{
	std::string descString = "";
	std::for_each(longdesc.begin(), longdesc.end(), [&descString](const std::string& i){descString += i + "\n";} );	
	return descString;
}
void Character::setLongdesc(const std::vector<std::string>& longdesc){
	this->longdesc = longdesc;
}

#endif