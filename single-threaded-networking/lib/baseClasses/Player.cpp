#ifndef PLAYER_CPP
#define PLAYER_CPP

#include "Player.h"

//Player constructor
Player::Player ():
    username{""}, password{""}
    {};

Player::Player (std::string const username, std::string const password):
    username{username}, password{password}
    {};

Player::~Player(){}

std::string Player::getUsername() const {
    return username;
}
void Player::setUsername(std::string& username) {
    this->username = username;
}

//Getter and setter for Shortdesc
std::string Player::getPassword() const {
    return password;
}
void Player::setPassword(std::string& password) {
    this->password = password;
}

/*helper functions to level up*/
/*
void Player::addObjectToInventory(const Object& object, unsigned int limit){
    //todo
}

bool Player::removeObjectFromInventory(const std::string& objectName){
    //todo
    return false;
}

bool Player::equipObject(const Object& object, int slot){
    //todo
    return false;
}

bool Player::unEquipObject(int slot){
    //todo
    return false;
}

std::unordered_map<int,std::vector<Object>> Player::getInventory() const{
    //todo
    return NULL;
}

std::unordered_map<int,Object> Player::getEquipment() const{
    //todo
    return NULL;
}

std::string Player::getInventoryDesc() const{
    //todo
    return "";
}

std::string Player::getEquipmentDesc() const{
    //todo
    return "";
}
*/
int Player::newHealth(int const lvl){
    return DEFAULT_PLAYER_HEALTH+lvl*lvl*2;
}

int Player::newMana(int const lvl){
    return 95+lvl*lvl*1.5;
}

/*void Player::setNewStats(){
    setNewHealth(level);
    setNewMana(level);
}
*/

#endif
