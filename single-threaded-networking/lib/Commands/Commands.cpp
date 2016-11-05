#include "Commands.h"
#include <boost/algorithm/string.hpp>
#include <random>

namespace Commands {

	LookCommand::LookCommand(networking::Connection connection_, const std::string& message_)
	: connection{connection_}, message{message_} {}

	std::string LookCommand::execute(Context& context) {
		auto players = context.getPlayers();
		auto rooms = context.getRooms();
		auto playerLocations = context.getPlayerLocations();
		int playerId = connection.playerIDConnectedToClientConnection;

		std::string lookMessage = message.substr(4);
		std::transform(lookMessage.begin(), lookMessage.end(), lookMessage.begin(), ::tolower);
	    boost::trim_if(lookMessage, boost::is_any_of("\t "));

		std::string response = (*players)[playerId].getUsername() + "> " + message;

		int currentRoomId = (*playerLocations)[playerId];
		Room* currentRoom = &(*rooms)[currentRoomId];

		if(lookMessage == "") {
			std::cout << "FF" << std::endl;
			return response + "\n\n" + currentRoom->getFullRoomDesc();
		}

		//-------------------------------------------------look "cardinal direction"

		//will move this to room class later as if isDirection return door.getDesc()
		auto doorsInRoom = currentRoom->getDoors();

		for(auto currentDoor : doorsInRoom) {
			if(lookMessage == currentDoor.getDir()) {
		  		response += "\n\n" + currentDoor.getDesc() += "\n";

		  		return response;
			}
		}

		std::cout << "F" << std::endl;

		//-------------------------------------------------look "Npc keyword"

		Npc* currentNpc = currentRoom->findNpc(lookMessage);
			//will move this to room class later as if isNpc return npc.getfulldesc()
		if(currentNpc != NULL) {
			response += "\n\n" + currentNpc->getDesc();
			response += "\n     Wearing: "  + currentNpc->getNpcEquipmentDesc();
			response += "\n     Carrying: " + currentNpc->getNpcInventoryDesc() + "\n\n";
			return response;
		}

		//-------------------------------------------------look "Object keyword"


		Object* currentObject = currentRoom->findObject(lookMessage);
		//will move this to room class later as if isobject return object.getfulldesc()
		if(currentObject != NULL) {
			response += "\n";
			//move loop out later;
					//need look through all currentobject get extra for keyword
			for(auto descriptionText : currentObject->getExtra().first) {
			  response += descriptionText + "\n";
			}
			return response;
		}

		//look extended description in room

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

		std::string goMessage = message.substr(2);
		std::transform(goMessage.begin(), goMessage.end(), goMessage.begin(), ::tolower);
	    boost::trim_if(goMessage, boost::is_any_of("\t "));

		std::cout << "Player wants to go " << goMessage << std::endl;
		int currentRoomId  = (*playerLocations)[playerId];
		std::cout << "Current room Id: " << currentRoomId << std::endl;
		Room* currentRoom = &(*rooms)[currentRoomId];
		std::vector<Door> currentRoomDoors = currentRoom->getDoors();
		std::cout << "number of doors in room: " << currentRoomDoors.size() << std::endl;

		int destRoomId = currentRoom->getRoomInDir(goMessage);

		if(destRoomId != -1) {
			std::cout << "Destination room Id:: " << currentRoom->getRoomInDir(goMessage) << std::endl;
			//throw custom_errors::NoSuchDoorException();
			(*playerLocations)[playerId] = destRoomId;
			return (*players)[playerId].getUsername() + "> " + message + "\n\n" + (*rooms)[destRoomId].getFullRoomDesc();
		} else {
			return (*players)[playerId].getUsername() + "> " + "There is no door in the " + goMessage + " direction." + "\n\n";
		}
	}

	int GoCommand::getId() const {
		return this->connection.playerIDConnectedToClientConnection;
	}

	networking::Connection GoCommand::getConnection() const {
		return this->connection;
	}

	/*Flee command*/
	FleeCommand::FleeCommand(networking::Connection connection_, const std::string& message_) 
	: connection{connection_}, message{message_} {}

	std::string FleeCommand::execute(Context& context) {
		auto players = context.getPlayers();
		auto playerLocations = context.getPlayerLocations();
		auto rooms = context.getRooms();

		int playerId = connection.playerIDConnectedToClientConnection;

		std::cout << "Player wants to Flee " << message << std::endl;
		int currentRoomId  = (*playerLocations)[playerId];
		std::cout << "Current room Id: " << currentRoomId << std::endl;
		Room currentRoom = (*rooms)[currentRoomId];
		std::vector<Door> currentRoomDoors = currentRoom.getDoors();
		std::cout << "number of doors in room: " << currentRoomDoors.size() << std::endl;

		
		/*select a random door from the avaliable doors*/
		std::random_device seed ;
			// generator
  		 std::mt19937 engine( seed( ) ) ;
   			// number distribution
  		 std::uniform_int_distribution<int> choose( 0 , currentRoomDoors.size( ) - 1 ) ;
  		 Door destination = currentRoomDoors[choose (engine)];

		int destRoomId = currentRoom.getRoomInDir(destination.getDir());

		if(destRoomId != -1) {
			std::cout << " Flee Destination room Id:: " << currentRoom.getRoomInDir(destination.getDir()) << std::endl;
			//throw custom_errors::NoSuchDoorException();
			(*playerLocations)[playerId] = destRoomId;
			return (*players)[playerId].getUsername() + "> Flee to " + destination.getDir() + "\n\n" + (*rooms)[destRoomId].getFullRoomDesc();
		} else {
			return (*players)[playerId].getUsername() + "> " + "There is no door to flee in any direction." + "\n\n";
		}
	}

	int FleeCommand::getId() const {
		return this->connection.playerIDConnectedToClientConnection;
	}

	networking::Connection FleeCommand::getConnection() const {
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



	TakeCommand::TakeCommand(networking::Connection connection_, const std::string& message_)
	: connection{connection_}, message{message_} {}

	std::string TakeCommand::execute(Context& context) {
		auto players = context.getPlayers();
		auto rooms = context.getRooms();
		auto playerLocations = context.getPlayerLocations();
		int playerId = connection.playerIDConnectedToClientConnection;

		std::string messageText = message.substr(5);
		std::transform(messageText.begin(), messageText.end(), messageText.begin(), ::tolower);

		std::vector <std::string> takeMessage;
	    boost::trim_if(messageText, boost::is_any_of("\t "));
	    boost::split(takeMessage, messageText, boost::is_any_of("\t "), boost::token_compress_on);

		std::string response = (*players)[playerId].getUsername() + "> " + message;

		int currentRoomId = (*playerLocations)[playerId];
		Room* currentRoom = &(*rooms)[currentRoomId];

		// if(takeMessage == "") {
		// 	std::cout << "FF" << std::endl;
		// 	return response + "\n\n" + currentRoom->getFullRoomDesc();
		// }

		//-------------------------------------------------look "cardinal direction"

		//will move this to room class later as if isDirection return door.getDesc()
		// auto doorsInRoom = currentRoom->getDoors();

		// for(auto currentDoor : doorsInRoom) {
		// 	if(takeMessage == currentDoor.getDir()) {
		//   		response += "\n\n" + currentDoor.getDesc() += "\n";

		//   		return response;
		// 	}
		// }


		// std::cout << "F" << std::endl;

		//-------------------------------------------------look "Npc keyword"

		//OK findNpc/findRoom will return a Npc* object which we can use to directly modify the selected npc/object in the room 
		Npc* currentNpc = currentRoom->findNpc(takeMessage[1]);

		if(currentNpc != NULL) {
			response += "\n Steal: " + takeMessage[0] + " From: " + takeMessage[1] + "\n\n";

			//Npc will use a currentNpc->findObject(objectTargetPair[0]) method which returns the object ID	of the object in inventory 
			//Will change removeObjectfromInventory() to take in the objectID (maybe pass in selected index "eg. steal apple '1'");
			if(currentNpc->removeObjectFromInventory(takeMessage[0])) {
				response += "Success!\n";
			} else {
				response += "Failure.\n";
			}
			//}

			return response;
		}

		//-------------------------------------------------look "Object keyword"

		//Object* currentObject = currentRoom->>findObject(ObjectTargetPair[0]);

		//Room will use a currentRoom->>findObject(objectTargetPair[0]) method which returns the object ID of the object in inventory 
		//Will change removeObject() to take in the objectID (maybe pass in selected index "eg. steal apple '1'");
		if(currentRoom->removeObject(takeMessage[0])) {
			response += "\n Take: " + takeMessage[0] + "\n\n";
			return response;
		}

		//room will use a currentRoom->>findNpc(objectTargetPair[0]) method which returns the object ID	of the object in inventory 
		//Will change removeNPC() to take in the npcID (maybe pass in selected duplicate index "eg. steal apple '1'");
		if(currentRoom->removeNpc(takeMessage[0])) {
			response += "\n Take: " + takeMessage[0] + "\n\n";
			return response;
		}
		
		std::cout << "G" << std::endl;

		return (*players)[playerId].getUsername() + "> " + "Cannot steal " + takeMessage[0] + ", no match. \n\n";
	}

	int TakeCommand::getId() const {
		return this->connection.playerIDConnectedToClientConnection;
	}

	networking::Connection TakeCommand::getConnection() const {
		return this->connection;
	}

	ListCommand::ListCommand(networking::Connection connection_, const std::unordered_map<std::string, std::string>& commands_) 
	: connection{connection_}, commands{commands_} {}

	std::string ListCommand::execute(Context& context) {
		auto players = context.getPlayers();
		int playerId = connection.playerIDConnectedToClientConnection;
		std::string allCommands = "";

		for( const auto& i : commands){
    		allCommands += i.second + "\n";
  		}

		return (*players)[playerId].getUsername()+ "> " + "All possible Commands:\n" + allCommands + "\n";
	}

	int ListCommand::getId() const {
		return this->connection.playerIDConnectedToClientConnection;
	}

	networking::Connection ListCommand::getConnection() const {
		return this->connection;
	}

	SayCommand::SayCommand(networking::Connection connection_, const std::string& message_, int playerId_) 
	: connection{connection_}, message{message_}, playerId{playerId_} {}

	std::string SayCommand::execute(Context& context) {
		auto players = context.getPlayers();
		return (*players)[this->playerId].getUsername()+ "> " + message.substr(4) + "\n";
	}

	int SayCommand::getId() const {
		return this->connection.playerIDConnectedToClientConnection;
	}

	networking::Connection SayCommand::getConnection() const {
		return this->connection;
	}
}

//Add teleport command to help testing