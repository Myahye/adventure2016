#include"Combatant.h"

Combatant::Combatant() {}
Combatant::Combatant(networking::Connection* connection_,Character* character_)
: connection{connection_},character{character_}{}

networking::Message
Combatant::attack(int ammout, const string& targetName){
  int currHealth = character.getHealth();
  character.setHealth(currHealth-ammount);
  std::string response = "ALERT > You have been attacked for " + ammount
                          + " damage by " + targetNamename + "\n\n";
  networking::Message retMessage{connection,response};
  return retMessage;
}

networking::Message
Combatant::sendMessage(const std::string& sourceMessage){
  std::string response = sourceMessage;
  networking::Message retMessage(connection,sourceMessage);
  return retMessage;
}
