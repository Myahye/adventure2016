#include "Person.h"

// Destructor
Person::~Person() {};

// Getter and setter for id
int Person::getId() const {
	return id;
}

void Person::setId(const int id) {
	this->id = id;
}

// Getter and setter for armor
int Person::getArmor() const {
	return armor;
}

void Person::setArmor(int const armor) {
	this->armor = armor;
}

// Getter and setter for exp
int Person::getExp() const {
	return exp;
}

void Person::setExp(int const exp) {
	this->exp = exp;
}

// Getter and setter for gold
int Person::getGold() const {
	return gold;
}

void Person::setGold(int const gold) {
	this->gold = gold;
}

// Getter and setter for level
int Person::getLevel() const {
	return level;
}

void Person::setLevel(int const level) {
	this->level = level;
}

// Getter and setter for thac0
int Person::getThac0() const {
	return thac0;
}

void Person::setThac0(int const thac0) {
	this->thac0 = thac0;
}

// Getter and setter for damage
std::string Person::getDamage() const {
	return damage;
}
	
void Person::setDamage(const std::string& damage) {
	this->damage = damage; 
}

// Getter and setter for hit
std::string Person::getHit() const {
	return hit;
}

void Person::setHit(const std::string& hit) {
	this->hit = hit;
}

// Getter and setter for description
std::string Person::getDescription() const {
	std::string descString = "";
	std::for_each(description.begin(), description.end(), [&descString](const std::string& i){descString += i + "\n";} );	
	return descString;
}

void Person::setDescription(const std::vector<std::string>& description) {
	this->description = description;
}

// Getter and setter for keywords
std::vector<std::string> Person::getKeywords() const {
	return keywords;
}

void Person::setKeywords(const std::vector<std::string>& keywords) {
	this->keywords = keywords;
}

// Getter and setter for longdesc
std::string Person::getLongdesc() const {
	std::string longDescString = "";
	std::for_each(longdesc.begin(), longdesc.end(), [&longDescString](const std::string& i){longDescString += i + "\n";} );	
	return longDescString;
}

void Person::setLongdesc(const std::vector<std::string>& longdesc) {
	this->longdesc = longdesc;
}