#include "CombatCommands.h"
#include <boost/algorithm/string.hpp>
#include <random>

int getPlayerIdInRoom(std::unordered_map<int, Player>* players, const std::unordered_map<int, int>* playerLocations, const int currentRoomId, const std::string& playerName) {
	for(auto& playerIdRoomIdpair : *playerLocations) {
		if(playerIdRoomIdpair.second == currentRoomId) {
			if((*players)[playerIdRoomIdpair.first].playerCharacter.getStatus() == "Online") {
				std::cout<<"Checking if " + (*players)[playerIdRoomIdpair.first].getUsername()+" == " + playerName <<std::endl;
				if((*players)[playerIdRoomIdpair.first].getUsername()==playerName){
					std::cout<<"getPlayerIdInRoom found that does infact " + (*players)[playerIdRoomIdpair.first].getUsername()+" == " + playerName <<std::endl;
					return playerIdRoomIdpair.first;
				}
				//Yuck, too much nest 4 me.
			}
		}
	}
	return -1;//Please forgive me.
}

namespace CombatCommands {

	AttackCommand::AttackCommand(networking::Connection connection_, const std::string& message_)
	: connection{connection_}, message{message_} {}



	std::string AttackCommand::execute(std::vector<networking::Connection>& clients, std::vector<Fight>& fights, Context& context) {
		auto players = context.getPlayers();
		auto rooms = context.getRooms();
		auto playerLocations = context.getPlayerLocations();
		int playerId = connection.playerId;
		std::string playerName = (*players)[playerId].getUsername();


		//auto player = &(*players)[playerId];

		//Create instigator combatant

		std::string targetName = message.substr(7);
		std::ostringstream playerIdString;
		playerIdString << playerId;
		std::cout<<"Player: " + playerName+" ID: " + playerIdString.str() + " initiated combat with " + targetName<<std::endl;

		std::transform(targetName.begin(), targetName.end(), targetName.begin(), ::tolower);
		boost::trim_if(targetName, boost::is_any_of("\t "));


		std::string response = playerName + "> " + message;

		//refactor this out to its own method
		for(Fight fight : fights){
			bool playerIsInstigator = (fight.instigatorCombatant.character->getId()
																	== playerId);
			bool playerIsTarget = (fight.targetCombatant.character->getId()
																	== playerId);;
			if(playerIsInstigator || playerIsTarget){
				return "Combat aborted, you are already in combat.\n\n";
			}
		}

		int currentRoomId = (*playerLocations)[playerId];


		Room* currentRoom = &(*rooms)[currentRoomId];

		if(targetName == "") {
			return response + "\n\n" + "Please enter a target\n\n";
		}

		bool npcFlag = false;
		//-------------------------------------------------Attack player
		int targetPlayerId = getPlayerIdInRoom(players, playerLocations, currentRoomId, targetName);
		auto targetCharacter = &(*players)[targetPlayerId].playerCharacter;
targetCharacter = NULL;
		if(targetPlayerId==-1){
			std::cout<<"targetPlayerId==-1"<<std::endl;

			Npc* targetNpc = currentRoom->findNpc(targetName);

			if(targetNpc != NULL) {
				targetNpc->npcCharacter.setStatus("Online");
				targetCharacter = &targetNpc->npcCharacter;
				npcFlag = true;
			}else{
				return "Combat aborted, there is no one with the name "+targetName+" in room.";
			}
		}else{
			std::cout<<"targetPlayerId!=-1"<<std::endl;

			//refactor this out to its own method
			bool playerIsInstigator = false;
			bool playerIsTarget = false;
			for(Fight fight : fights){
				playerIsInstigator = (fight.instigatorCombatant.character->getId()
																		== targetPlayerId);
				playerIsTarget = (fight.targetCombatant.character->getId()
																		== targetPlayerId);;
				if(playerIsInstigator || playerIsTarget){
					return "Combat aborted, " + targetName + " is already in combat.";

				}
			}
			std::cout<<"Player assigned"<<std::endl;

			targetCharacter = &(*players)[targetPlayerId].playerCharacter;
		}
		std::cout<<"end of if else"<<std::endl;
		if(targetCharacter==NULL){
std::cout<<"shit"<<std::endl;
		}
		std::ostringstream targetPlayerIdString;
		targetPlayerIdString << targetPlayerId;


		for(networking::Connection targetConnection: clients){

			std::ostringstream targetConnectionPlayerIdString;
			targetConnectionPlayerIdString << targetConnection.playerId;

			std::cout<<"Checking if targetConnection.playerid: " + targetConnectionPlayerIdString.str() +" == " + targetPlayerIdString.str() <<std::endl;
			if(targetConnection.playerId == targetPlayerId || npcFlag){
				std::cout<<"getPlayerIdInRoom found that does infact targetConnection.playerid: " + targetConnectionPlayerIdString.str() +" == " + targetPlayerIdString.str() <<std::endl;
				//Create target and instigator combatant, create fight and add to battles
				auto player = (*players)[playerId];
				auto targetPlayer = (*players)[targetPlayerId];

				Combatant instigatorCombatant = Combatant{connection, &(*players)[playerId].playerCharacter, playerName, false};
				//Combatant instigatorCombatant = Combatant{connection, player->playerCharacter};
				std::cout<<"targetName: " + targetName +", npcFlag: " << std::boolalpha << npcFlag <<std::endl;
				Combatant targetCombatant = Combatant{targetConnection, targetCharacter, targetName, npcFlag};

				std::ostringstream currentRoomIdString;
				currentRoomIdString << currentRoomId;
				std::cout<<"currentRoomId:::: " + currentRoomIdString.str()<<std::endl;

				//Combatant targetCombatant =Combatant{targetConnection, targetPlayer->playerCharacter};
				Fight fight = Fight{instigatorCombatant, targetCombatant, currentRoomId};

				fights.push_back(fight);

				return response + "\n\n" + "Combat with " + targetName + " initiated.\n\n";
			}
			//To self - this is trash, remove asap

		}
		std::cout<<"Error at end of CombatCommands::Attack.execute"<<std::endl;
		return "Error";


	}

	int AttackCommand::getId() const {
		return this->connection.playerId;
	}

	networking::Connection AttackCommand::getConnection() const {
		return this->connection;
	}


}
