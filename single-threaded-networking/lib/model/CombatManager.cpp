#include "CombatManager.h"
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
  auto playerLocations = context.getPlayerLocations();


  //auto context = this->model.getContext();
    for(auto& combatCommand : combatCommandQueue) {
      std::string response = combatCommand->execute(clients, fights, context);
      Message message{combatCommand->getConnection(),response};
      outgoing.push_back(message);
      combatCommandQueue.pop_front();
    }

    auto players = context.getPlayers();
    int index = 0;

    for(Fight fight : fights){ // Please forgive my sins. I should not have done this.

      //check if instigator is dead
      if(fight.instigatorCombatant.character->getCurrentHealth()>0){
        //check if target is dead
        if(fight.targetCombatant.character->getCurrentHealth()>0){

        //check if instigator is still in room
        int currentInstigatorRoomId = (*playerLocations)[fight.instigatorCombatant.character->getId()];

        std::ostringstream currentInstigatorRoomIdIdString;
        currentInstigatorRoomIdIdString << currentInstigatorRoomId;
        std::ostringstream roomIdIdString;
        roomIdIdString << fight.roomID;

        std::cout<<"Checking if currentInstigatorRoomId: " + currentInstigatorRoomIdIdString.str() + " == fight.roomID: "+ roomIdIdString.str()<<std::endl;



        if(currentInstigatorRoomId==fight.roomID){
          //check if target is still in room
          int currentTargetRoomId = (*playerLocations)[fight.targetCombatant.character->getId()];

          if(currentTargetRoomId==fight.roomID){

            //Check for override flag
            if(!fight.targetOverrideFlag){
              outgoing.push_back(fight.instigatorCombatant.attack(1, fight.targetCombatant.name));
              outgoing.push_back(fight.targetCombatant.sendMessage("You have attacked " + fight.instigatorCombatant.name + " for 1 point of damage\n\n"));
            }else{
              fight.setTargetOverrideFlag(false);
              //attack for whatever spell is worth here
            }

            //Check for override flag
            if(!fight.instigatorOverrideFlag){
              outgoing.push_back(fight.targetCombatant.attack(1, fight.instigatorCombatant.name));
              outgoing.push_back(fight.instigatorCombatant.sendMessage("You have attacked " + fight.targetCombatant.name + " for 1 point of damage\n\n"));
            }else{
              fight.setInstigatorOverrideFlag(false);
              //attack for whatever spell is worth here
            }
          }else{
          //Target is no longer in room, end combat
          outgoing.push_back(fight.instigatorCombatant.sendMessage(fight.targetCombatant.name + " has fled!"));
          outgoing.push_back(fight.targetCombatant.sendMessage("You have fled and are no longer in combat"));
          fights.erase (fights.begin()+index);
          //fights.erase(std::remove(fights.begin(), fights.end(), index), fights.end());

          }
        }else{
        //Instigator is no longer in room, end combat
        outgoing.push_back(fight.targetCombatant.sendMessage(fight.instigatorCombatant.name + " has fled!"));
        outgoing.push_back(fight.instigatorCombatant.sendMessage("You have fled and are no longer in combat"));
        fights.erase (fights.begin()+index);
        //fights.erase(std::remove(fights.begin(), fights.end(), index), fights.end());

        }
      }else{
        //Target is dead, end combat
        outgoing.push_back(fight.instigatorCombatant.sendMessage(fight.targetCombatant.name + " is dead!"));
        outgoing.push_back(fight.targetCombatant.sendMessage("You have died!"));
        fights.erase (fights.begin()+index);
        //fights.erase(std::remove(fights.begin(), fights.end(), index), fights.end());

      }
    }else{
      //Instigator is dead, end combat
      outgoing.push_back(fight.targetCombatant.sendMessage(fight.instigatorCombatant.name + " is dead!"));
      outgoing.push_back(fight.instigatorCombatant.sendMessage("You have died!"));
      fights.erase (fights.begin()+index);
      //fights.erase(std::remove(fights.begin(), fights.end(), index), fights.end());

    }

    index++;
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
CombatManager::createAlertMessage(Connection connection, std::string name){
  std::cout<<"6.1 connection == "<<connection.playerId<<std::endl;
  std::string response = "ALERT > You have been attacked by " + name + "\n\n";
  Message sourceMessage{connection,response};
  return sourceMessage;
}
