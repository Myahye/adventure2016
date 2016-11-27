#include "ModelInterface.h"
#include <boost/algorithm/string/predicate.hpp>
#include <iostream>

using namespace networking;

CombatManager::CombatManager() {}

void
CombatManager::buildCombatCommand(const Connection connection, const std::string message) {
  this->combatCommandQueue.push_back(std::make_unique<CombatCommands::AttackCommand>(connection, message));
}

std::deque<Message>
CombatManager::updateCombat(Model::Context& context){
  std::deque<Message> outgoing;


  //auto context = this->model.getContext();
    for(auto& combatCommand : combatCommandQueue) {
      std::string response = combatCommand->execute(context);
      Message message{combatCommand->getSourceConnection(),response};
      outgoing.push_back(message);
      combatCommandQueue.pop_front();
    }
    for(Player p : characterList){//will move this to a function soon
      attack(p);
    }

    for(Fight fight : battles){
      if(!fight.targetOverrideFlag){
        outgoing.pushback(fight.getInstigatorCombatant().attack(1, fight.getTargetCombatant().getName()));
      }
      if(!fight.instigatorOverrideFlag){
        outgoing.pushback(fight.getTargetCombatant().attack(1, fight.getInstigatorCombatant().getName()));
      }
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
