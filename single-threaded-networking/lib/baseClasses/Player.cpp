#ifndef PLAYER_CPP
#define PLAYER_CPP

#include "Player.h"

//Player constructor
Player::Player ():
    playerCharacter{0,true}, username{""}, password{""}{};
Player::Player (int const id, std::string const username, std::string const password):
    playerCharacter{id,true}, username{username}, password{password}{};

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

void Player::setCharacter(const Character& character){
  	this->playerCharacter = character;
}

std::string Player::getStatus() const {
  return status;
}
void Player::setStatus(std::string s) {
  status = s;
}

void
Player::attack(const std::string& name){
	std::cout << "You are being attacked by " +name << std::endl;
}

#endif
