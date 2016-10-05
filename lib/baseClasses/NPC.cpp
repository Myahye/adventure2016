#ifndef NPC_CPP
#define NPC_CPP

#include "NPC.h"

using namespace std;

NPC::NPC (int id_, string shortdesc_) {
  this->setId(id_);
  this->setShortDesc(shortdesc_);
}

int NPC::getArmor() const {
	return armor;
}
void NPC::setArmor(int armor_) {
	this->armor = armor_;
}
	
string NPC::getDamage() const {
	return damage;
}
void NPC::setDamage(string damage_) {
	this->damage = damage_;
}
	
vector<string> NPC::getDesc() const {
	return description;
}
void NPC::setDesc(vector<string> description_) {
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

string NPC::getHit() const {
	return hit;
}
void NPC::setHit(string hit_) {
	this->hit = hit_;
}

int NPC::getId() const {
	return id;
}
void NPC::setId(int id_) {
	this->id = id_;
}

vector<string> NPC::getKeywords() const {
	return keywords;
}
void NPC::setKeywords(vector<string> keywords_) {
	this->keywords = keywords_;
}

int NPC::getLevel() const {
	return level;
}
void NPC::setLevel(int level_) {
	this->level = level_;
}

string NPC::getLongDesc() const {
	return longdesc;
}
void NPC::setLongDesc(string longdesc_) {
	this->longdesc = longdesc_;
}
	
string NPC::getShortDesc() const {
	return shortdesc;
}
void NPC::setShortDesc(string shortdesc_) {
	this->shortdesc = shortdesc_;
}

int NPC::getThac0() const {
	return thac0;
}
void NPC::setThac0(int thac0_) {
	this->thac0 = thac0_;
}

#endif