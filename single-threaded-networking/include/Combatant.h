#ifndef COMBATANT_H
#define COMBATANT_H

#include "Server.h"
#include "Character.h"
#include "Players.h"

class Combatant {
private:
  //bool isNpc;
  networking::Connection* connection;
  Character* character;
public:
//  Combatant(bool isNpc_, networking::Connection connection_, Character* character_);
  Combatant(networking::Connection* connection_,Character* character_);

  //bool isNpc();
  networking::Message sendMessage(const std::string& message);
  networking::Message attack(int amount, const std::string& targetName );

}

#endif /* COMBATANT_H */
