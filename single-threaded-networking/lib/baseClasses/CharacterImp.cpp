#include "CharacterImp.h"

// Constructor
CharacterImp::CharacterImp():
id{0} {};

CharacterImp::CharacterImp(const int id):
id{id} {};

// Getter and setter for id
int CharacterImp::getId() const {
	return id;
}

void CharacterImp::setId(const int id) {
	this->id = id;
}


// Getter and setter for armor
int CharacterImp::getArmor() const {
	return armor;
}

void CharacterImp::setArmor(int const armor) {
	this->armor = armor;
}

// Getter and setter for exp
int CharacterImp::getExp() const {
	return exp;
}

void CharacterImp::setExp(int const exp) {
	this->exp = exp;
}

// Getter and setter for gold
int CharacterImp::getGold() const {
	return gold;
}

void CharacterImp::setGold(int const gold) {
	this->gold = gold;
}

// Getter and setter for level
int CharacterImp::getLevel() const {
	return level;
}

void CharacterImp::setLevel(int const level) {
	this->level = level;
}

// Getter and setter for thac0
int CharacterImp::getThac0() const {
	return thac0;
}

void CharacterImp::setThac0(int const thac0) {
	this->thac0 = thac0;
}

// Getter and setter for damage
std::string CharacterImp::getDamage() const {
	return damage;
}
	
void CharacterImp::setDamage(const std::string& damage) {
	this->damage = damage; 
}

// Getter and setter for hit
std::string CharacterImp::getHit() const {
	return hit;
}

void CharacterImp::setHit(const std::string& hit) {
	this->hit = hit;
}

// Getter and setter for description
std::string CharacterImp::getDescription() const {
	std::string descString = "";
	std::for_each(description.begin(), description.end(), [&descString](const std::string& i){descString += i + "\n";} );	
	return descString;
}

void CharacterImp::setDescription(const std::vector<std::string>& description) {
	this->description = description;
}

// Getter and setter for keywords
std::vector<std::string> CharacterImp::getKeywords() const {
	return keywords;
}

void CharacterImp::setKeywords(const std::vector<std::string>& keywords) {
	this->keywords = keywords;
}

// Getter and setter for longdesc
std::string CharacterImp::getLongdesc() const {
	std::string longDescString = "";
	std::for_each(longdesc.begin(), longdesc.end(), [&longDescString](const std::string& i){longDescString += i + "\n";} );	
	return longDescString;
}

void CharacterImp::setLongdesc(const std::vector<std::string>& longdesc) {
	this->longdesc = longdesc;
}
