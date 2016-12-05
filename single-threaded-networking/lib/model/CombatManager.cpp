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

  for(auto& combatCommand : combatCommandQueue) {
    std::string response = combatCommand->execute(clients, fights, context);
    Message message{combatCommand->getConnection(),response};
    outgoing.push_back(message);
    combatCommandQueue.pop_front();
  }

    int index = 0;
    for(Fight fight : fights){ // Please forgive my sins. I should not have done this.
    bool instigatorNPCFlag = fight.instigatorCombatant.npcFlag;
    bool targetNPCFlag = fight.targetCombatant.npcFlag;
    //check if instigator is dead
    //if instigator disconnected
    if(fight.instigatorCombatant.character->getStatus() == "Online"){

      //if target disconnected
      if(fight.targetCombatant.character->getStatus() == "Online"){

        if(fight.instigatorCombatant.character->getCurrentHealth()>0){
          if(fight.targetCombatant.character->getCurrentHealth()>0){
            //check if instigator is still in room
            int currentInstigatorRoomId = (*playerLocations)[fight.instigatorCombatant.character->getId()];

            std::ostringstream currentInstigatorRoomIdIdString;
            currentInstigatorRoomIdIdString << currentInstigatorRoomId;
            std::ostringstream roomIdIdString;
            roomIdIdString << fight.roomID;


            if(currentInstigatorRoomId==fight.roomID || instigatorNPCFlag){
              //check if target is still in room
              int currentTargetRoomId = (*playerLocations)[fight.targetCombatant.character->getId()];

              if(currentTargetRoomId==fight.roomID || targetNPCFlag){
                //Check for override flag
                std::cout<<"fight.getTargetOverrideFlag(): "<<std::boolalpha <<fight.getTargetOverrideFlag()<<std::endl;


                if(!fight.getTargetOverrideFlag()){
                  networking::Message instigatorAttackMessage = fight.instigatorCombatant.attack(1, fight.targetCombatant.name);
                  if(!instigatorNPCFlag){
                    outgoing.push_back(instigatorAttackMessage);
                  }
                  if(!targetNPCFlag){
                    outgoing.push_back(fight.targetCombatant.sendMessage("You have attacked " + fight.instigatorCombatant.name + " for 1 point of damage\n\n"));
                  }
                }else{
                  fight.setTargetOverrideFlag(false);
                  //attack for whatever spell is worth here
                }


                //Check for override flag
                if(!fight.getInstigatorOverrideFlag()){
                  networking::Message targetAttackMessage = fight.targetCombatant.attack(1, fight.instigatorCombatant.name);
                  if(!targetNPCFlag){
                    outgoing.push_back(targetAttackMessage);
                  }
                  if(!instigatorNPCFlag){
                    outgoing.push_back(fight.instigatorCombatant.sendMessage("You have attacked " + fight.targetCombatant.name + " for 1 point of damage\n\n"));
                  }
                }else{
                  fight.setInstigatorOverrideFlag(false);
                  //attack for whatever spell is worth here
                }
              }else{
                //Target is no longer in room, end combat
                if(!instigatorNPCFlag){
                  outgoing.push_back(fight.instigatorCombatant.sendMessage("Combat over, " + fight.targetCombatant.name + " has fled!\n\n"));
                }
                if(!targetNPCFlag){
                  outgoing.push_back(fight.targetCombatant.sendMessage("You have fled and are no longer in combat\n\n"));
                }
                fights.erase (fights.begin()+index);

              }
            }else{
              //Instigator is no longer in room, end combat
              if(!targetNPCFlag){
                outgoing.push_back(fight.targetCombatant.sendMessage("Combat over, " + fight.instigatorCombatant.name + " has fled!\n\n"));
              }
              if(!instigatorNPCFlag){
                outgoing.push_back(fight.instigatorCombatant.sendMessage("You have fled and are no longer in combat\n\n"));
              }
              fights.erase (fights.begin()+index);

            }
          }else{
            //Target is dead, end combat
            if(!instigatorNPCFlag){
              int currentInstigatorLevel=fight.instigatorCombatant.character->getLevel();
              fight.instigatorCombatant.character->setExp(100);
              int newInstigatorLevel=fight.instigatorCombatant.character->getLevel();
              if(currentInstigatorLevel<newInstigatorLevel){
                outgoing.push_back(fight.instigatorCombatant.sendMessage("Combat over, " + fight.targetCombatant.name + " is dead!\n\n"+" \t Congraulation!! You Have Leveled UP\n"));
              }else{
                outgoing.push_back(fight.instigatorCombatant.sendMessage("Combat over, " + fight.targetCombatant.name + " is dead!\n\n"));
              }
            }
            if(!targetNPCFlag){
              outgoing.push_back(fight.targetCombatant.sendMessage("You have died!\n\n"));
            }
            fights.erase (fights.begin()+index);

          }
        }else{
          //Instigator is dead, end combat
          if(!targetNPCFlag){
            int currentTargetLevel=fight.targetCombatant.character->getLevel();
            fight.targetCombatant.character->setExp(100);
            int newTargetLevel=fight.targetCombatant.character->getLevel();
            if(currentTargetLevel<newTargetLevel){
              outgoing.push_back(fight.targetCombatant.sendMessage("Combat over, " + fight.instigatorCombatant.name + " is dead!\n\n"+" \t Congraulation!! You Have Leveled UP\n"));
            }else{
              outgoing.push_back(fight.targetCombatant.sendMessage("Combat over, " + fight.instigatorCombatant.name + " is dead!\n\n"));
            }
          }
          if(!instigatorNPCFlag){
            outgoing.push_back(fight.instigatorCombatant.sendMessage("You have died!\n\n"));
          }
          fights.erase (fights.begin()+index);

        }
      }else{
        //target is offline
        if(!instigatorNPCFlag){
          outgoing.push_back(fight.instigatorCombatant.sendMessage("Combat over, " + fight.targetCombatant.name + " has gone offline.\n\n"));
        }
        fights.erase (fights.begin()+index);

      }
    }else{
      //instigator is offline
      if(!targetNPCFlag){
        outgoing.push_back(fight.targetCombatant.sendMessage("Combat over, " + fight.instigatorCombatant.name + " has gone offline.\n\n"));
      }
      fights.erase (fights.begin()+index);

    }

    index++;
  }
  return outgoing;
}

Message
CombatManager::createAlertMessage(Connection connection, std::string name, bool npcFlag){
  std::cout<<"6.1 connection == "<<connection.playerId<<std::endl;
  std::string response = "ALERT > You have been attacked by " + name + "\n\n";
  Message sourceMessage{connection,response};
  return sourceMessage;
}
