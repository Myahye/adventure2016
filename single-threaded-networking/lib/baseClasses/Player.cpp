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
