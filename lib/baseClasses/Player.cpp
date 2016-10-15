//
//  Player.cpp
//  Player
//
//  Created by JUN DA LI on 2016/10/12.
//  Copyright © 2016年 JUN DA LI. All rights reserved.
//

#include "Player.h"

#include <iostream>
#include <vector>
#include <string>

using namespace std;

//    intial a Player
Player::Player (int new_pid, string new_shortdesc) {
    pid = new_pid;
    shortdesc = new_shortdesc;
}

//    set and get Armor
int Player::getArmor() const {
    return armor;
}
void Player::setArmor(int new_armor) {
    this->armor = new_armor;
}

//    set and get Damage
string Player::getDamage() const {
    return damage;
}
void Player::setDamage(string new_damage) {
    this->damage = new_damage;
}

//    set and get Desc
vector<string> Player::getDesc() const {
    return description;
}
void Player::setDesc(vector<string> new_description) {
    this->description = new_description;
}

//    set and get Exp
int Player::getExp() const {
    return exp;
}
void Player::setExp(int new_exp) {
    this->exp = new_exp;
}

//    set and get Gold
int Player::getGold() const {
    return gold;
}
void Player::setGold(int new_gold) {
    this->gold = new_gold;
}

//    set and get hit
string Player::getHit() const {
    return hit;
}
void Player::setHit(string new_hit) {
    this->hit = new_hit;
}

//    set and get Player ID
int Player::getId() const {
    return pid;
}
void Player::setId(int new_pid) {
    this->pid = new_pid;
}

//    set and get keywords
vector<string> Player::getKeywords() const {
    return keywords;
}
void Player::setKeywords(vector<string> new_keywords) {
    this->keywords = new_keywords;
}

//    set and get Level
int Player::getLevel() const {
    return level;
}
void Player::setLevel(int new_level) {
    this->level = new_level;
}

//    set and get LongDesc
vector<string> Player::getLongDesc() const {
    return longdesc;
}
void Player::setLongDesc(vector<string> new_longdesc) {
    this->longdesc = new_longdesc;
}

//    set and get shortdesc
string Player::getShortDesc() const {
    return shortdesc;
}
void Player::setShortDesc(string new_shortdesc) {
    this->shortdesc = new_shortdesc;
}

//    set and get Thac0
int Player::getThac0() const {
    return thac0;
}
void Player::setThac0(int new_thac0) {
    this->thac0 = new_thac0;
}

