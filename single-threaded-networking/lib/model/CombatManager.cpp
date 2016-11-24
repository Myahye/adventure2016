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
CombatManager::updateCombat(std::vector<Connection>& clients
  , Model::Context& context
){
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
  return outgoing;
}

void
CombatManager::attack(Player& player) {
  if(player.getVictim()!=null){

  }
}

void
CombatManager::addToCharacterList(Player& player){

}

void
CombatManager::removeFromCharacterList(const Player& player){
  int pos = find(characterList.begin(), characterList.end(), player) - characterList.begin();
  if(pos >= characterList.size()) {
      //Not found
  }else{
    characterList.erase(pos);
    createMessageToPlayer(player.getId, "You are no longer in the combat list");
  }
}

void
CombatManager::createMessageToPlayer(const int pid, const std::string& msg){
  this->combatCommandQueue.push_back(std::make_unique<CombatCommands::messageToUser>(pid, message));
}
