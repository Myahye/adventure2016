#include "Commands.h"
#include <boost/algorithm/string.hpp>

namespace Commands {

	LookCommand::LookCommand(networking::Connection connection_, const std::string& message_)
	: connection{connection_}, message{message_} {}

	std::string LookCommand::execute(Context& context) {
		std::cout << "D" << std::endl;
		auto players = context.getPlayers();
		auto rooms = context.getRooms();
		auto playerLocations = context.getPlayerLocations();
		// auto npcs = context.getNpcs();
		// 		(*rooms)[3012].addNpc((*npcs)[3062],15);

		int playerId = connection.playerIDConnectedToClientConnection;

		std::cout << "E" << std::endl;

		std::string response = (*players)[playerId].getUsername() + "> " + message;
		std::string lookMessage = message.substr(5);
		std::cout << "FEEs" << std::endl;
		std::transform(lookMessage.begin(), lookMessage.end(), lookMessage.begin(), ::tolower);

		std::cout << "FEE" << std::endl;

		int currentRoomId = (*playerLocations)[playerId];
		Room currentRoom = (*rooms)[currentRoomId];

		if(lookMessage == "") {
			std::cout << "FF" << std::endl;
			return response + "\n\n" + currentRoom.getFullRoomDesc();
		}

		//-------------------------------------------------look "cardinal direction"

		//will move this to room class later as if isDirection return door.getDesc()
		auto doorsInRoom = currentRoom.getDoors();

		for(auto currentDoor : doorsInRoom) {
			if(lookMessage == currentDoor.getDir()) {
		  		response += "\n\n" + currentDoor.getDesc() += "\n";

		  		return response;
			}
		}

		std::cout << "F" << std::endl;

		//-------------------------------------------------look "Npc keyword"

		Npc* currentNpc = currentRoom.findNpc(lookMessage);
			//will move this to room class later as if isNpc return npc.getfulldesc()
		if(currentNpc != NULL) {
			response += "\n\n" + currentNpc->getDesc();
			response += "\n     Wearing: "  + currentNpc->getNpcEquipmentDesc();
			response += "\n     Carrying: " + currentNpc->getNpcInventoryDesc() + "\n\n";
			return response;
		}

		//-------------------------------------------------look "Object keyword"

		Object currentObject = currentRoom.findObject(lookMessage);
		//will move this to room class later as if isobject return object.getfulldesc()
		if(currentObject.getId() != 0) {
			response += "\n";
			//move loop out later;
			for(auto descriptionText : currentObject.getExtra().first) {
			  response += descriptionText + "\n";
			}
			return response;
		}

		std::cout << "G" << std::endl;

		return (*players)[playerId].getUsername() + "> " + "Cannot find " + lookMessage + ", no match. \n\n";
	}

	int LookCommand::getId() const {
		return this->connection.playerIDConnectedToClientConnection;
	}

	networking::Connection LookCommand::getConnection() const {
		return this->connection;
	}


	GoCommand::GoCommand(networking::Connection connection_, const std::string& message_) 
	: connection{connection_}, message{message_} {}

	std::string GoCommand::execute(Context& context) {
		auto players = context.getPlayers();
		auto playerLocations = context.getPlayerLocations();
		auto rooms = context.getRooms();

		int playerId = connection.playerIDConnectedToClientConnection;

		std::cout << "Player wants to go " << message << std::endl;
		int currentRoomId  = (*playerLocations)[playerId];
		std::cout << "Current room Id: " << currentRoomId << std::endl;
		Room currentRoom = (*rooms)[currentRoomId];
		std::vector<Door> currentRoomDoors = currentRoom.getDoors();
		std::cout << "number of doors in room: " << currentRoomDoors.size() << std::endl;

		int destRoomId = currentRoom.getRoomInDir(message);

		if(destRoomId != -1) {
			std::cout << "Destination room Id:: " << currentRoom.getRoomInDir(message) << std::endl;
			//throw custom_errors::NoSuchDoorException();
			(*playerLocations)[playerId] = destRoomId;
			return (*players)[playerId].getUsername() + "> " + message + "\n\n" + (*rooms)[destRoomId].getFullRoomDesc();
		} else {
			return (*players)[playerId].getUsername() + "> " + "There is no door in the " + message + " direction." + "\n\n";
		}
	}

	int GoCommand::getId() const {
		return this->connection.playerIDConnectedToClientConnection;
	}

	networking::Connection GoCommand::getConnection() const {
		return this->connection;
	}


	/*Status*/
	StatusCommand::StatusCommand(networking::Connection connection_, const std::string& message_) 
	: connection{connection_}, message{message_} {}

	std::string StatusCommand::execute(Context& context) {
		auto players = context.getPlayers();
		int playerId = connection.playerIDConnectedToClientConnection;
		std::cout<<"status cout"<<std::endl;

		return (*players)[playerId].getUsername()+ "> " + 
				" Health: "+std::to_string((*players)[playerId].getHealth())+"\n\n"+
				" Mana  : "+std::to_string((*players)[playerId].getMana())+"\n\n";


	}

	int StatusCommand::getId() const {
		return this->connection.playerIDConnectedToClientConnection;
	}

	networking::Connection StatusCommand::getConnection() const {
		return this->connection;
	}

	/*InvalidCommand*/
	InvalidCommand::InvalidCommand(networking::Connection connection_, const std::string& message_) 
	: connection{connection_}, message{message_} {}

	std::string InvalidCommand::execute(Context& context) {
		auto players = context.getPlayers();
		int playerId = connection.playerIDConnectedToClientConnection;

		return (*players)[playerId].getUsername()+ "> " + message + " " +
				" is an invalid command.\n\n";
	}

	int InvalidCommand::getId() const {
		return this->connection.playerIDConnectedToClientConnection;
	}

	networking::Connection InvalidCommand::getConnection() const {
		return this->connection;
	}



	StealCommand::StealCommand(networking::Connection connection_, const std::string& message_)
	: connection{connection_}, message{message_} {}

	std::string StealCommand::execute(Context& context) {
		std::cout << "D" << std::endl;
		auto players = context.getPlayers();
		auto rooms = context.getRooms();
		auto playerLocations = context.getPlayerLocations();
		// auto npcs = context.getNpcs();
		// 		(*rooms)[3012].addNpc((*npcs)[3062],15);

		int playerId = connection.playerIDConnectedToClientConnection;

		std::cout << "E" << std::endl;

		std::string response = (*players)[playerId].getUsername() + "> " + message;
		std::string stealMessage = message.substr(6);
		std::cout << "FEEs" << std::endl;
		std::transform(stealMessage.begin(), stealMessage.end(), stealMessage.begin(), ::tolower);

		std::cout << "FEE" << std::endl;

		int currentRoomId = (*playerLocations)[playerId];
		Room currentRoom = (*rooms)[currentRoomId];

		// if(stealMessage == "") {
		// 	std::cout << "FF" << std::endl;
		// 	return response + "\n\n" + currentRoom.getFullRoomDesc();
		// }

		//-------------------------------------------------look "cardinal direction"

		//will move this to room class later as if isDirection return door.getDesc()
		// auto doorsInRoom = currentRoom.getDoors();

		// for(auto currentDoor : doorsInRoom) {
		// 	if(stealMessage == currentDoor.getDir()) {
		//   		response += "\n\n" + currentDoor.getDesc() += "\n";

		//   		return response;
		// 	}
		// }

		// std::cout << "F" << std::endl;

		//-------------------------------------------------look "Npc keyword"
		std::vector<std::string> ObjectTargetPair;
		boost::split(ObjectTargetPair, stealMessage, boost::is_any_of(" "));

		Npc* currentNpc = (*rooms)[currentRoomId].findNpc(ObjectTargetPair[0]);
			//will move this to room class later as if isNpc return npc.getfulldesc()
		if(currentNpc != NULL) {
			response += "\n Steal: " + ObjectTargetPair[0] + " From: " + ObjectTargetPair[1] + "\n\n";
			// if((*rooms)[currentRoomId].removeNpc(3060)) {
				//getNpcsInRoom()[3060][0].getNpcInventory().erase(3120)) {
			currentNpc->removeObjectFromInventory(ObjectTargetPair[1]);
				response += "Success!\n" + (*rooms)[currentRoomId].getNpcsInRoom()[3060][0].getNpcInventoryDesc();
			//}
			return response;
		}

		//-------------------------------------------------look "Object keyword"

		Object currentObject = currentRoom.findObject(ObjectTargetPair[0]);
		//will move this to room class later as if isobject return object.getfulldesc()
		if(currentObject.getId() != 0) {

			//move loop out later;
			response += "\n Take: " + ObjectTargetPair[0] + "\n\n";
			currentRoom.removeObject(ObjectTargetPair[0]);
			return response;
		}

		std::cout << "G" << std::endl;

		return (*players)[playerId].getUsername() + "> " + "Cannot steal " + stealMessage + ", no match. \n\n";
	}

	int StealCommand::getId() const {
		return this->connection.playerIDConnectedToClientConnection;
	}

	networking::Connection StealCommand::getConnection() const {
		return this->connection;
	}
}