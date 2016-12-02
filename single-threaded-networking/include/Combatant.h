#ifndef COMBATANT_H
#define COMBATANT_H

#include "Server.h"
#include "Character.h"

class Combatant {
private:
  //bool isNpc;

public:
//  Combatant(bool isNpc_, networking::Connection connection_, Character* character_);
  Combatant(networking::Connection connection_, Character* character_, std::string name, bool npcFlag);
	networking::Connection connection;
  Character* character;
	std::string name;
  bool npcFlag;
  //bool isNpc();
  networking::Message sendMessage(const std::string& message);
  networking::Message attack(int amount, const std::string& targetName );

};

#endif /* COMBATANT_H */
