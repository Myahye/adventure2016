#ifndef NPC_CPP
#define NPC_CPP

#include "NPC.h"

NPC::NPC (int id_, std::string shortdesc_): 
	id{id_}, shortdesc{shortdesc_}{};

int NPC::getArmor() const {
	return armor;
}
void NPC::setArmor(int armor_) {
	this->armor = armor_;
}
	
std::string NPC::getDamage() const {
	return damage;
}
void NPC::setDamage(std::string& damage_) {
	this->damage = damage_;
}
	
std::vector<std::string> NPC::getDesc() const {
	return description;
}
void NPC::setDesc(std::vector<std::string>& description_) {
	this->description = description_;
}

int NPC::getExp() const {
	return exp;
}
void NPC::setExp(int exp_) {
	this->exp = exp_;
}

int NPC::getGold() const {
	return gold;
}
void NPC::setGold(int gold_) {
	this->gold = gold_;
}

std::string NPC::getHit() const {
	return hit;
}
void NPC::setHit(std::string& hit_) {
	this->hit = hit_;
}

int NPC::getId() const {
	return id;
}
void NPC::setId(int id_) {
	this->id = id_;
}

std::vector<std::string> NPC::getKeywords() const {
	return keywords;
}
void NPC::setKeywords(std::vector<std::string>& keywords_) {
	this->keywords = keywords_;
}

int NPC::getLevel() const {
	return level;
}
void NPC::setLevel(int level_) {
	this->level = level_;
}

std::vector<std::string> NPC::getLongDesc() const {
	return longdesc;
}
void NPC::setLongDesc(std::vector<std::string>& longdesc_) {
	this->longdesc = longdesc_;
}
	
std::string NPC::getShortDesc() const {
	return shortdesc;
}
void NPC::setShortDesc(std::string& shortdesc_) {
	this->shortdesc = shortdesc_;
}

int NPC::getThac0() const {
	return thac0;
}
void NPC::setThac0(int thac0_) {
	this->thac0 = thac0_;
}

//New function added in to test
void NPC::printClass(int n) const{
	std::cout << "\n\n";
	std::cout << "NPC: "<< n << "\n";
	std::cout << "Npc id: " << id << std::endl;
	std::cout << "\tarmor: " << armor << std::endl;
	std::cout << "\texp: " << id << std::endl;
	std::cout << "\tgold: " << gold << std::endl;
	std::cout << "\tlevel: " << level << std::endl;
	std::cout << "\tthac0: " << thac0 << std::endl;
}
#endif