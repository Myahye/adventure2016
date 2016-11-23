#include "CombatCommands.h"
#include <boost/algorithm/string.hpp>
#include <random>

int getPlayerIdInRoom(std::unordered_map<int, Player>* players, const std::unordered_map<int, int>* playerLocations, const int currentRoomId, const std::string& playerName) {
	for(auto& playerIdRoomIdpair : *playerLocations) {
		if(playerIdRoomIdpair.second == currentRoomId) {
			if((*players)[playerIdRoomIdpair.first].getStatus() == "Online") {
				if((*players)[playerIdRoomIdpair.first].getUsername()==playerName){return playerIdRoomIdpair.first;}
				//Yuck, too much nest 4 me.
			}
		}
	}
	// playersInRoom += "\n\n";
	// return playersInRoom;
}

namespace CombatCommands {

	AttackCommand::AttackCommand(networking::Connection connection_, const std::string& message_)
	: connection{connection_}, message{message_} {}

	std::string AttackCommand::execute(Context& context) {
		auto players = context.getPlayers();
		auto rooms = context.getRooms();
		auto playerLocations = context.getPlayerLocations();
		int playerId = connection.playerId;
		std::string playerName = players*

		std::string targetName = message.substr(7);
		std::transform(targetName.begin(), targetName.end(), targetName.begin(), ::tolower);
		boost::trim_if(targetName, boost::is_any_of("\t "));

		std::string response = (*players)[playerId].getUsername() + "> " + message;

		int currentRoomId = (*playerLocations)[playerId];
		Room* currentRoom = &(*rooms)[currentRoomId];

		if(targetName == "") {
			return response + "\n\n" + "Please enter a target";
		}


		//-------------------------------------------------Attack player
		int targetPlayerId = getPlayerInRoom(players, playerLocations, currentRoomId, targetName);
		Player targetPlayer = (*players)[targetPlayerId];
		targetPlayer.attack((*players)[playerId].getUsername());


		return response + "\n\n" + "Combat with " + targetName + " initiated.";
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
