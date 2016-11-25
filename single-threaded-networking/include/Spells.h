#ifndef SPELLS_H
#define SPELLS_H

#include <string>
#include <iostream>

class Spells{

std::string name;
std::string effect;
std::string hitChar;
std::string hitRoom;
std::string hitVict;
std::string wearOff;
std::string damMsg;
std::string immChar;

int duration;
int mana;
int minLevel;

public:
	Spells();
	Spells(std::string name, int mana, int minLevel);
	
	void setName(std::string& name);
	std::string getName() const;
	
	void setEffect(std::string& effect);
	std::string getEffect() const;

	void setHitChar(std::string& hitChar);
	std::string getHitChar() const;

	void setHitRoom(std::string& hitRoom);
	std::string getHitRoom() const;

	void setHitVict(std::string& hitVict);
	std::string getHitVict() const;

	void setWearOff(std::string& wearOff);
	std::string getWearOff() const;

	void setDamMsg(std::string& damMsg);
	std::string getDamMsg() const;

	void setImmChar(std::string& immChar);
	std::string getImmChar() const;

	void setDuration(int duration);
	int getDuration() const;

	void setMana(int mana);
	int getMana() const;

	void setMinLevel(int level);
	int getMinLevel() const;

	void printClass();
};

#endif