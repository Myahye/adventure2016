#ifndef SPELLS_CPP
#define SPELLS_CPP

#include "Spells.h"

Spells::Spells()
:	name(""), mana(0), minLevel(0){};

Spells::Spells(std::string name, int mana, int minLevel)
:	name{name},
	mana{mana},
	minLevel{minLevel} {};

void Spells::setName(std::string& name){
	this->name = name;
}
std::string Spells::getName() const {
	return this->name;
}
	
void Spells::setEffect(std::string& effect){
	this->effect = effect;
}
std::string Spells::getEffect() const {
	return this->effect;
}

void Spells::setHitChar(std::string& hitChar){
	this->hitChar = hitChar;
}
std::string Spells::getHitChar() const {
	return this->hitChar;
}

void Spells::setHitRoom(std::string& hitRoom){
	this->hitRoom = hitRoom;
}
std::string Spells::getHitRoom() const {
	return this->hitRoom;
}

void Spells::setHitVict(std::string& hitVict){
	this->hitVict = hitVict;
}
std::string Spells::getHitVict() const {
	return this->hitVict;
}

void Spells::setWearOff(std::string& wearOff){
	this->wearOff = wearOff;
}
std::string Spells::getWearOff() const {
	return this->wearOff;
}

void Spells::setDamMsg(std::string& damMsg){
	this->damMsg = damMsg;
}
std::string Spells::getDamMsg() const {
	return this->damMsg;
}

void Spells::setImmChar(std::string& immChar){
	this->immChar = immChar;
}
std::string Spells::getImmChar() const {
	return this->immChar;
}

void Spells::setDuration(int duration){
	this->duration = duration;
}
int Spells::getDuration() const {
	return this->duration;
}

void Spells::setMana(int mana){
	this->mana = mana;
}
int Spells::getMana() const {
	return this->mana;
}

void Spells::setMinLevel(int minLevel){
	this->minLevel = minLevel;
}
int Spells::getMinLevel() const {
	return this->minLevel;
}

void Spells::printClass(){
	std::cout << "Name: " << name << std::endl;
	std::cout << "Effect: " << effect << std::endl;
	std::cout << "HitChar: " << hitChar << std::endl;
	std::cout << "HitRoom: " << hitRoom << std::endl;
	std::cout << "HitVict: " << hitVict << std::endl;
	std::cout << "WearOff: " << wearOff << std::endl;
	std::cout << "DamageMsg: " << damMsg << std::endl;
	std::cout << "ImmChar: " << immChar << std::endl;
	std::cout << "Duration: " << duration << std::endl;
	std::cout << "Mana: " << mana << std::endl;
	std::cout << "MinLevel: " << minLevel << std::endl;
}

#endif