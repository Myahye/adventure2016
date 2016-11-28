#include "ModelInterface.h"
#include <boost/algorithm/string/predicate.hpp>
#include <iostream>

using namespace networking;

CombatManager::CombatManager() {}

void
CombatManager::buildCombatCommand(const networking::Connection& connection, const std::string& message) {
  this->combatCommandQueue.push_back(std::make_unique<CombatCommands::AttackCommand>(connection, message));
}

std::deque<Message>
CombatManager::updateCombat(std::vector<networking::Connection>& clients, Context& context){
  std::deque<Message> outgoing;


  //auto context = this->model.getContext();
    for(auto& combatCommand : combatCommandQueue) {
      std::string response = combatCommand->execute(clients, fights, context);
      Message message{combatCommand->getSourceConnection(),response};
      outgoing.push_back(message);
      combatCommandQueue.pop_front();
    }

    for(Fight fight : fights){
      if(!fight.targetOverrideFlag){
        outgoing.pushback(fight.getInstigatorCombatant().attack(1, fight.getTargetCombatant().getName()));
        outgoing.pushback(fight.getTargetCombatant().sendMessage("You have attacked " + fight.getInstigatorCombatant() + " for 1 point of damage");
      }
      fight.setTargetOverrideFlag(false);
      if(!fight.instigatorOverrideFlag){
        outgoing.pushback(fight.getTargetCombatant().attack(1, fight.getInstigatorCombatant().getName()));
        outgoing.pushback(fight.getInstigatorCombatant().sendMessage("You have attacked " + fight.getTargetCombatant() + " for 1 point of damage");
      }
      fight.setInstigatorOverrideFlag(false);
    }


  // //auto context = this->model.getContext();
  //   for(auto& combatCommand : combatCommandQueue) {
  //     std::string response = combatCommand->execute(context);
  //     Message message{combatCommand->getSourceConnection(),response};
  //     outgoing.push_back(message);
  //     combatCommandQueue.pop_front();
  //   }
  //   for(Player p : characterList){//will move this to a function soon
  //     attack(p);
  //   }
  return outgoing;
}

Message
ModelInterface::createAlertMessage(Connection connection, std::string name){
  std::cout<<"6.1 connection == "<<connection.playerId<<std::endl;
  std::string response = "ALERT > You have been attacked by " + name + "\n\n";
  Message sourceMessage{connection,response};
  return sourceMessage;
}
