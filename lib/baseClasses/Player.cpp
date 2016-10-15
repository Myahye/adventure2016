#include "Player.h"

//Player constructor
Player::Player (int pid, std::string shortdesc) {
    this->pid = pid;
    this->shortdesc = shortdesc;
}

//Getter and setter for Armor
int Player::getArmor() const {
    return armor;
}
void Player::setArmor(int armor) {
    this->armor = armor;
}

//Getter and setter for Damage
std::string Player::getDamage() const {
    return damage;
}
void Player::setDamage(std::string& damage) {
    this->damage = damage;
}

//Getter and setter for Desc
std::vector<std::string> Player::getDesc() const {
    return description;
}
void Player::setDesc(std::vector<std::string>& description) {
    this->description = description;
}

//Getter and setter for Exp
int Player::getExp() const {
    return exp;
}
void Player::setExp(int exp) {
    this->exp = exp;
}

//Getter and setter for Gold
int Player::getGold() const {
    return gold;
}
void Player::setGold(int gold) {
    this->gold = gold;
}

//Getter and setter for Hit
std::string Player::getHit() const {
    return hit;
}
void Player::setHit(std::string& hit) {
    this->hit = hit;
}

//Getter and setter for Player ID
int Player::getId() const {
    return pid;
}
void Player::setId(int pid) {
    this->pid = pid;
}

//Getter and setter for Keywords
std::vector<std::string> Player::getKeywords() const {
    return keywords;
}
void Player::setKeywords(std::vector<std::string>& keywords) {
    this->keywords = keywords;
}

//Getter and setter for Level
int Player::getLevel() const {
    return level;
}
void Player::setLevel(int level) {
    this->level = level;
}

//Getter and setter for LongDesc
std::vector<std::string> Player::getLongDesc() const {
    return longdesc;
}
void Player::setLongDesc(std::vector<std::string>& longdesc) {
    this->longdesc = longdesc;
}

//Getter and setter for Shortdesc
std::string Player::getShortDesc() const {
    return shortdesc;
}
void Player::setShortDesc(std::string& shortdesc) {
    this->shortdesc = shortdesc;
}

//Getter and setter for Thac0
int Player::getThac0() const {
    return thac0;
}
void Player::setThac0(int thac0) {
    this->thac0 = thac0;
}