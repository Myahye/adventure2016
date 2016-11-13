#include "ModelInterface.h"
#include <boost/algorithm/string/predicate.hpp>
#include <iostream>

using namespace networking;

CombatManager::CombatManager() {}


void
CombatManager::buildCombatCommand(const networking::Connection connection, const std::string message) {
  this->combatCommandQueue.push_back(std::make_unique<CombatCommands::AttackCommand>(connection, message));
}



std::deque<Message>
CombatManager::updateCombat(auto context&){

  std::deque<Message> outgoing;
  //auto context = this->model.getContext();
    for(auto& combatCommand : combatCommandQueue) {
      std::string response = combatCommand->execute(context);
      Message sourceMessage{combatCommand->getSourceConnection(),response};
      outgoing.push_back(sourceMessage);
      outgoing.push_back(createAlertMessage(combatCommand->getTargetConnection(), combatCommand->getSourceName()));
      combatCommandQueue.pop_front();
    }
    for(Player p : characterList){
      //attck(p->victim);
    }
  //move out later
  //this->model.reset();

  return outgoing;

}


// Message
// ModelInterface::createAlertMessage(Connection connection, std::string name){
//   std::cout<<"6.1 connection == "<<connection.playerId<<std::endl;
//   std::string response = "ALERT > You have been attacked by " + name + "\n\n";
//   Message sourceMessage{connection,response};
//   return sourceMessage;
//}
