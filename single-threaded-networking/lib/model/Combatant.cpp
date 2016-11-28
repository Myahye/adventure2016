#include "Combatant.h"

Combatant::Combatant(networking::Connection connection_,Character* character_)
:connection{connection_},character{character_}{}

networking::Message
Combatant::attack(int amount, const std::string& targetName){
  int currHealth = character->getCurrentHealth();
  character->setCurrentHealth(currHealth-amount);

	std::ostringstream amountString;
	amountString << amount;
  std::string response = "ALERT > You have been attacked for " + amountString.str()
                          + " damage by " + targetName + "\n\n";
  networking::Message retMessage{connection,response};
  return retMessage;
}

networking::Message
Combatant::sendMessage(const std::string& sourceMessage){
  std::string response = sourceMessage;
  networking::Message retMessage{connection,sourceMessage};
  return retMessage;
}
