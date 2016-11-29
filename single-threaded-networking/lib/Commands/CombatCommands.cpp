#include "CombatCommands.h"
#include <boost/algorithm/string.hpp>
#include <random>

int getPlayerIdInRoom(std::unordered_map<int, Player>* players, const std::unordered_map<int, int>* playerLocations, const int currentRoomId, const std::string& playerName) {
	for(auto& playerIdRoomIdpair : *playerLocations) {
		if(playerIdRoomIdpair.second == currentRoomId) {
			if((*players)[playerIdRoomIdpair.first].getStatus() == "Online") {
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
	// playersInRoom += "\n\n";
	// return playersInRoom;
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


		//-------------------------------------------------Attack player
		int targetPlayerId = getPlayerIdInRoom(players, playerLocations, currentRoomId, targetName);

		if(targetPlayerId==-1){
			return "Combat aborted, no player with name "+targetName+" in room.";
		}

		//refactor this out to its own method
		for(Fight fight : fights){
			bool playerIsInstigator = (fight.instigatorCombatant.character->getId()
																	== targetPlayerId);
			bool playerIsTarget = (fight.targetCombatant.character->getId()
																	== targetPlayerId);;
			if(playerIsInstigator || playerIsTarget){
				return "Combat aborted, " + targetName + " is already in combat.";
			}
		}

		std::ostringstream targetPlayerIdString;
		targetPlayerIdString << targetPlayerId;


		for(networking::Connection targetConnection: clients){

			std::ostringstream targetConnectionPlayerIdString;
			targetConnectionPlayerIdString << targetConnection.playerId;

			std::cout<<"Checking if targetConnection.playerid: " + targetConnectionPlayerIdString.str() +" == " + targetPlayerIdString.str() <<std::endl;
			if(targetConnection.playerId == targetPlayerId){
				std::cout<<"getPlayerIdInRoom found that does infact targetConnection.playerid: " + targetConnectionPlayerIdString.str() +" == " + targetPlayerIdString.str() <<std::endl;
				//Create target and instigator combatant, create fight and add to battles
				auto player = (*players)[playerId];
				auto targetPlayer = (*players)[targetPlayerId];


				Combatant instigatorCombatant = Combatant{connection, &(*players)[playerId].playerCharacter, playerName};
				//Combatant instigatorCombatant = Combatant{connection, player->playerCharacter};
				Combatant targetCombatant = Combatant{targetConnection, &(*players)[targetPlayerId].playerCharacter, targetName};

				//Combatant targetCombatant =Combatant{targetConnection, targetPlayer->playerCharacter};
				Fight fight = Fight{instigatorCombatant, targetCombatant};

				fights.push_back(fight);

				return response + "\n\n" + "Combat with " + targetName + " initiated.n\n\n";
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



	// AttackCommand::AttackCommand(std::vector<networking::Connection>& clients_, networking::Connection sourceConnection_, const std::string& message_)
	// : clients{clients_}, sourceConnection{sourceConnection_}, message{message_} {}
	//
	// std::string AttackCommand::execute(Context& context) {
	// 	auto players = context.getPlayers();
	// 	auto rooms = context.getRooms();
	// 	auto playerLocations = context.getPlayerLocations();
	// 	int playerId = this->sourceConnection.playerId;
	//
	// 	std::string messageText = this->message.substr(7);
	// 	std::transform(messageText.begin(), messageText.end(), messageText.begin(), ::tolower);
	//
	// 	std::vector <std::string> takeMessage;
	//   boost::trim_if(messageText, boost::is_any_of("\t "));
	//   boost::split(takeMessage, messageText, boost::is_any_of("\t "), boost::token_compress_on);
	// 	this->sourceName=(*players)[playerId].getUsername();
	// 	std::string sourceResponse = sourceName + "> " + takeMessage[0];
	//
	// 	int currentRoomId = (*playerLocations)[playerId];
	// 	Room* currentRoom = &(*rooms)[currentRoomId];
	//
	// 	//should change this to not return magic number
	// 	int targetPlayerId = currentRoom->findPlayerId(takeMessage[0]);
	// 	for(networking::Connection client: clients){
	// 		if(client.playerId == targetPlayerId){
	// 			this->targetConnection = client;
	// 		}
	// 	}
	// 	if(targetPlayerId != 0) {
	// 		std::cout<<(*players)[targetPlayerId].getUsername() +" is the target name for "+ (*players)[playerId].getUsername()<<std::endl;
	// 		int currentTargetHealth=(*players)[targetPlayerId].getHealth();
	// 		if (currentTargetHealth==0){
	// 			return sourceResponse + " has already been Defeated!\n";
	// 		}else{
	// 			(*players)[targetPlayerId].setHealth(currentTargetHealth-50);
	// 			if ((*players)[targetPlayerId].getHealth()==0){
	// 				int playerXP=(*players)[playerId].getExp();
	// 				(*players)[playerId].setExp(100);
	// 				return sourceResponse + " has been defeated!\n";
	// 			}
	//
	// 		}
	// 		return sourceResponse + " target found Attack Success \n";
	// 	}/*else if(){
	//
	// 	}*/else{
	// 		return sourceResponse + " target not in room / not found \n" ;
	// 	}
	//
	// }
	//
	// std::string AttackCommand::getSourceName() const {
	// 	return this->sourceName;
	// }
	//
	// int AttackCommand::getSourceId() const {
	// 	return this->sourceConnection.playerId;
	// }
	// int AttackCommand::getTargetId() const {
	// 	return this->targetId;
	// }
	// networking::Connection AttackCommand::getSourceConnection() const {
	// 	return this->sourceConnection;
	// }
	// networking::Connection AttackCommand::getTargetConnection() const {
	// 	return this->targetConnection;
	// }
}
