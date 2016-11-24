#include "Player.h"

//Player constructor
Player::Player (int const pid, std::string const username, std::string const password, CombatManager& view):
    pid{pid}, username{username}, password{password}, view{view}{};
Player::Player ():
    pid{0}, username{""}, password{""}{};

void Player::setFighting(Player& victim){
  if(this->victim!=NULL&&){
    this->victim=victim;
    view.createMessageToPlayer(this->victim->pid, "Alert, "+this->username+" is attacking you!");
  }else{
    view.createMessageToPlayer(this->pid, "You are already attacking "+this->victim->username
    +". \nYou will need to end your fight with "+this->victim->username+" before you can attack victim->");
  }
}

void Player::stopFighting(Player& victim){
  if(this->victim!=NULL){
    this->victim=NULL;
  }
}

Player& Player::getVictim(){
  return this->victim;
}

std::string Player::getUsername() const {
    return username;
}

void Player::applyDamage(const int damage){
    this->health-=damage;
    this->view.createMessageToPlayer(this->pid, "Alert, you have taken "+damage+" damage!")
}

void
Player::setUsername(std::string& username) {
    this->username = username;
}

//Getter and setter for Shortdesc
std::string
Player::getPassword() const {
    return password;
}
void
Player::setPassword(std::string& password) {
    this->password = password;
}

int
Player::getHealth() const{
    return health;
}

void
Player::setHealth(int const health){
    this->health = health;
}

int
Player::getMana() const{
    return mana;
}

void
Player::setMana(int const manaa){
    this->mana = manaa;
}

//Getter and setter for Armor
int
Player::getArmor() const {
    return armor;
}
void
Player::setArmor(int const armor) {
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
void Player::setExp(int const XP) {
    int baseXP = 95;
    exp += XP;
    if((baseXP*level)<=exp){
        level+=1;
        setNewStats();
    }
}

/*helper functions to level up*/
void Player::setNewStats(){
    setNewHealth(level);
    setNewMana(level);
}

void Player::setNewHealth(int const lvl){
    health=100+lvl*lvl*2;
}

void Player::setNewMana(int const lvl){
    mana=95+lvl*lvl*1.5;
}


//Getter and setter for Gold
int Player::getGold() const {
    return gold;
}
void Player::setGold(int const gold) {
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
void Player::setId(int const pid) {
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
void Player::setLevel(int const level) {
    this->level = level;
}

//Getter and setter for LongDesc
std::vector<std::string> Player::getLongDesc() const {
    return longdesc;
}
void Player::setLongDesc(std::vector<std::string>&  longdesc) {
    this->longdesc = longdesc;
}

//Getter and setter for Thac0
int Player::getThac0() const {
    return thac0;
}
void Player::setThac0(int const thac0) {
    this->thac0 = thac0;
}
