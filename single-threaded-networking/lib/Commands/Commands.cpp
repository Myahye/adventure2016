#include "Commands.h"
#include <boost/algorithm/string.hpp>
#include <random>

//utility functions
bool is_number(const std::string& s)
{
	return !s.empty() && std::find_if(s.begin(), 
		s.end(), [](char c) { return !std::isdigit(c); }) == s.end();
}

std::string printMiniMap(std::unordered_map<int,Room>* rooms, const int currentRoomId) {
	std::string miniMapS = "     ";
	std::vector<std::vector<int>> miniMap{{0,0,0,0,0,0,0,0,0,0,0,0,0},
										  {0,0,0,0,0,0,0,0,0,0,0,0,0},	
										  {0,0,0,0,0,0,0,0,0,0,0,0,0},
										  {0,0,0,0,0,0,0,0,0,0,0,0,0},
										  {0,0,0,0,0,0,0,0,0,0,0,0,0},
										  {0,0,0,0,0,0,0,0,0,0,0,0,0},
										  {0,0,0,0,0,0,9,0,0,0,0,0,0},
										  {0,0,0,0,0,0,0,0,0,0,0,0,0},
										  {0,0,0,0,0,0,0,0,0,0,0,0,0},
										  {0,0,0,0,0,0,0,0,0,0,0,0,0},
										  {0,0,0,0,0,0,0,0,0,0,0,0,0},
										  {0,0,0,0,0,0,0,0,0,0,0,0,0},
										  {0,0,0,0,0,0,0,0,0,0,0,0,0}};
	int temp = 0;

	int currentRoom = currentRoomId;
	for(int i = 0; i < 6; i+=2) {
		currentRoom = (*rooms)[currentRoom].getRoomInDir("west");
		if(currentRoom != -1) {
			miniMap[6][5-i] = 1;
			miniMap[6][5-i-1] = 3;
		}

		// temp = currentRoom;
		// for(int j = 0; j < 6; j+=2) {
		// 	temp = (*rooms)[temp].getRoomInDir("north");
		// 	if(temp != -1) {
		// 		miniMap[5-j][5-i-1] = 2;
		// 		miniMap[5-j-1][5-i-1] = 3;
		// 	}
		// }

		// temp = currentRoom;
		// for(int j = 0; j < 6; j+=2) {
		// 	temp = (*rooms)[temp].getRoomInDir("south");
		// 	if(temp != -1) {
		// 		miniMap[7+j][5-i-1] = 2;
		// 		miniMap[7+j+1][5-i-1] = 3;
		// 	}
		// }
	}

	currentRoom = currentRoomId;
	for(int i = 0; i < 6; i+=2) {
		currentRoom = (*rooms)[currentRoom].getRoomInDir("north");
		if(currentRoom != -1) {
			miniMap[5-i][6] = 2;
			miniMap[5-i-1][6] = 3;
		}

		temp = currentRoom;
		for(int j = 0; j < 6; j+=2) {
			temp = (*rooms)[temp].getRoomInDir("west");
			if(temp != -1) {
				miniMap[5-i-1][5-j] = 1;
				miniMap[5-i-1][5-j-1] = 3;
			}
		}

		temp = currentRoom;
		for(int j = 0; j < 6; j+=2) {
			temp = (*rooms)[temp].getRoomInDir("east");
			if(temp != -1) {
				miniMap[5-i-1][7+j] = 1;
				miniMap[5-i-1][7+j+1] = 3;
			}
		}
	}

	currentRoom = currentRoomId;
	for(int i = 0; i < 6; i+=2) {
		currentRoom = (*rooms)[currentRoom].getRoomInDir("south");
		if(currentRoom != -1) {
			miniMap[7+i][6] = 2;
			miniMap[7+i+1][6] = 3;
		}

		temp = currentRoom;
		for(int j = 0; j < 6; j+=2) {
			temp = (*rooms)[temp].getRoomInDir("west");
			if(temp != -1) {
				miniMap[7+i+1][5-j] = 1;
				miniMap[7+i+1][5-j-1] = 3;
			}
		}

		temp = currentRoom;
		for(int j = 0; j < 6; j+=2) {
			temp = (*rooms)[temp].getRoomInDir("east");
			if(temp != -1) {
				miniMap[7+i+1][7+j] = 1;
				miniMap[7+i+1][7+j+1] = 3;
			}
		}
	}

	currentRoom = currentRoomId;
	for(int i = 0; i < 6; i+=2) {
		currentRoom = (*rooms)[currentRoom].getRoomInDir("east");
		if(currentRoom != -1) {
			miniMap[6][7+i] = 1;
			miniMap[6][7+i+1] = 3;
		}

		// temp = currentRoom;
		// for(int j = 0; j < 6; j+=2) {
		// 	temp = (*rooms)[temp].getRoomInDir("north");
		// 	if(temp != -1) {
		// 		miniMap[5-j][7+i+1] = 2;
		// 		miniMap[5-j-1][7+i+1] = 3;
		// 	}
		// }

		// temp = currentRoom;
		// for(int j = 0; j < 6; j+=2) {
		// 	temp = (*rooms)[temp].getRoomInDir("south");
		// 	if(temp != -1) {
		// 		miniMap[7+j][7+i+1] = 2;
		// 		miniMap[7+j+1][7+i+1] = 3;
		// 	}
		// }
	}


	for(int row = 0; row < 13; ++row) {
		for(int column = 0; column < 13; ++column) {
			if(miniMap[row][column] == 1) {
				miniMapS += "-";
			} else if(miniMap[row][column] == 2) {
				miniMapS += "|";
			} else if (miniMap[row][column] == 3) {
				miniMapS += "*";
			} else if (miniMap[row][column] == 9) {
				miniMapS += "P";
			} else {
				miniMapS += " ";
			}
		}
		miniMapS += "\n     ";
	}

	return miniMapS + "\n";
}

std::string getPlayersInRoomDesc(std::unordered_map<int, Player>* players, const std::unordered_map<int, int>* playerLocations, const int currentRoomId) {
	std::string playersInRoom = "     Players: " ;
	for(auto& playerIdRoomIdpair : *playerLocations) {
		if(playerIdRoomIdpair.second == currentRoomId) {
			if((*players)[playerIdRoomIdpair.first].getStatus() == "Online") {
				playersInRoom += (*players)[playerIdRoomIdpair.first].getUsername() + ", ";
			}
		}
	}
	playersInRoom += "\n\n";
	return playersInRoom;
}


namespace Commands {

	LookCommand::LookCommand(networking::Connection connection_, const std::string& message_)
	: connection{connection_}, message{message_} {}

	std::string LookCommand::execute(Context& context) {
		auto players = context.getPlayers();
		auto rooms = context.getRooms();
		auto playerLocations = context.getPlayerLocations();
		auto objects = context.getObjects();
		int playerId = connection.playerId;

		std::string lookMessage = message.substr(4);
		std::transform(lookMessage.begin(), lookMessage.end(), lookMessage.begin(), ::tolower);
	    boost::trim_if(lookMessage, boost::is_any_of("\t "));

		std::string response = (*players)[playerId].getUsername() + "> " + message;

		int currentRoomId = (*playerLocations)[playerId];
		Room* currentRoom = &(*rooms)[currentRoomId];

		if(lookMessage == "") {
			return response + "\n\n" + printMiniMap(rooms, currentRoomId) + currentRoom->getFullRoomDesc() + getPlayersInRoomDesc(players, playerLocations, currentRoomId);
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
			response += "\n\n" + currentNpc->npcCharacter.getDescription();
			response += "\n     Wearing: "  + currentNpc->npcCharacter.getEquipmentDesc();
			response += "\n     Carrying: " + currentNpc->npcCharacter.getInventoryDesc() + "\n\n";
			return response;
		}

		//-------------------------------------------------look "Object keyword"


		Object* currentObject = currentRoom->findObject(lookMessage);
		//will move this to room class later as if isobject return object.getfulldesc()
		if(currentObject != NULL) {
			response += "\n\n";
			//should be vector of pair of vectors
					//need look through all currentobject get extra for keyword
			response += currentObject->getShortDesc() + "\n";
			for(auto& extraPair : currentObject->getExtra()) {
				for(auto& keyword : extraPair.second) {
					if(lookMessage.find(keyword) != std::string::npos) {
						for(auto& descriptionText : extraPair.first) {
				  			response += descriptionText + "\n";
						}
					}
				}
			}
			
			return response;
		}

		//-----------------------------------------------look extended description in room

		//should be vector of pair of vectors
		auto extendedDescription = currentRoom->getExtendedDesc();
		for(auto& extendedDescPair : extendedDescription) {
			for(auto& keyword : extendedDescPair.second) {
				std::cout << "sdfsdf" << std::endl;
				if(lookMessage.find(keyword) != std::string::npos) {
					response += "\n\n";
					for(auto& descriptionText : extendedDescPair.first) {
				  		response += descriptionText + "\n";
					}
					return response;
				}
			}
		}

		//------------look object in player inventory

		int currentObjectId = 0;
		for(auto& object : *objects) {
			for(auto& keyword : object.second.getKeywords()) {
				if(lookMessage.find(keyword) != std::string::npos) {
					currentObjectId = object.first;
					break;
				}
			}
		}

		if(currentObjectId != 0) {
			auto playerInventory = (*players)[playerId].getPlayerInventory();
			if(playerInventory.find(currentObjectId) != playerInventory.end()) {
				response += "\n\n";
				for(auto& extraPair : (*objects)[currentObjectId].getExtra()) {
					for(auto& keyword : extraPair.second) {
						if(lookMessage.find(keyword) != std::string::npos) {
							for(auto& descriptionText : extraPair.first) {
					  			response += descriptionText + "\n";
							}
						}
					}
				}
				return response;
			}
		}

		if(currentObject != NULL) {
			response += "\n\n";
			//should be vector of pair of vectors
					//need look through all currentobject get extra for keyword
			response += currentObject->getShortDesc() + "\n";
			for(auto& extraPair : currentObject->getExtra()) {
				for(auto& keyword : extraPair.second) {
					if(lookMessage.find(keyword) != std::string::npos) {
						for(auto& descriptionText : extraPair.first) {
				  			response += descriptionText + "\n";
						}
					}
				}
			}
			
			return response;
		}


		std::cout << "G" << std::endl;

		return (*players)[playerId].getUsername() + "> " + "Cannot find " + lookMessage + ", no match. \n\n";
	}

	int LookCommand::getId() const {
		return this->connection.playerId;
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

		int playerId = connection.playerId;

		std::string goMessage = message.substr(2);
		std::transform(goMessage.begin(), goMessage.end(), goMessage.begin(), ::tolower);
	    boost::trim_if(goMessage, boost::is_any_of("\t "));

		std::cout << "Player wants to go " << goMessage << std::endl;
		int currentRoomId  = (*playerLocations)[playerId];
		std::cout << "Current room Id: " << currentRoomId << std::endl;
		Room* currentRoom = &(*rooms)[currentRoomId];
		std::vector<Door> currentRoomDoors = currentRoom->getDoors();
		std::cout << "number of doors in room: " << currentRoomDoors.size() << std::endl;

		Player currentPlayer = (*players)[playerId];

		int destRoomId = currentRoom->getRoomInDir(goMessage);
		Room* destRoom = &(*rooms)[destRoomId];

		if(destRoomId != -1) {
			std::cout << "Destination room Id:: " << currentRoom->getRoomInDir(goMessage) << std::endl;
			//throw custom_errors::NoSuchDoorException();
			(*playerLocations)[playerId] = destRoomId;

			return currentPlayer.getUsername() + "> " + message + "\n\n" + printMiniMap(rooms, destRoomId) + destRoom->getFullRoomDesc() + getPlayersInRoomDesc(players, playerLocations, destRoomId);
		} else {
			return currentPlayer.getUsername() + "> " + "There is no door in the " + goMessage + " direction." + "\n\n";
		}
	}

	int GoCommand::getId() const {
		return this->connection.playerId;
	}

	networking::Connection GoCommand::getConnection() const {
		return this->connection;
	}

	/*Attack command*/
	/*AttackCommand::AttackCommand(networking::Connection connection_, const std::string& message_)
	: connection{connection_}, message{message_} {}

	std::string AttackCommand::execute(Context& context) {
		auto players = context.getPlayers();
		auto rooms = context.getRooms();
		auto playerLocations = context.getPlayerLocations();
		int playerId = connection.playerId;

		std::string messageText = message.substr(7);
		std::transform(messageText.begin(), messageText.end(), messageText.begin(), ::tolower);

		std::vector <std::string> takeMessage;
	    boost::trim_if(messageText, boost::is_any_of("\t "));
	    boost::split(takeMessage, messageText, boost::is_any_of("\t "), boost::token_compress_on);

		std::string response = (*players)[playerId].getUsername() + "> " + takeMessage[0];

		int currentRoomId = (*playerLocations)[playerId];
		Room* currentRoom = &(*rooms)[currentRoomId];


		int targetPlayerId = currentRoom->findPlayerId(takeMessage[0]);
		if(targetPlayerId != 0) {
			std::cout<<(*players)[targetPlayerId].getUsername() +" is the target name for "+ (*players)[playerId].getUsername()<<std::endl;
			int currentTargetCurrentHealth=(*players)[targetPlayerId].playerCharacter.getCurrentHealth();



			if (currentTargetCurrentHealth==0){
				return response + " Already Defeated! Fatality \n";
			}else{
				(*players)[targetPlayerId].playerCharacter.setHealth(currentTargetCurrentHealth-50);
				if ((*players)[targetPlayerId].playerCharacter.getCurrentHealth()==0){
					int playerXP=(*players)[playerId].playerCharacter.getExp();
					(*players)[playerId].playerCharacter.setExp(100);
					return response + " Defeated! Fatality \n";
				}

			}


			return response + " target found Attack Success \n";
		}
		std::cout << "size " << currentRoom->playersInRoom.size() << std::endl;




		return response + " target not in room / not found \n" ;
	}

	int AttackCommand::getId() const {
		return this->connection.playerId;
	}

	networking::Connection AttackCommand::getConnection() const {
		return this->connection;
	}
*//*Flee command*/
	FleeCommand::FleeCommand(networking::Connection connection_, const std::string& message_)
	: connection{connection_}, message{message_} {}

	std::string FleeCommand::execute(Context& context) {
		auto players = context.getPlayers();
		auto playerLocations = context.getPlayerLocations();
		auto rooms = context.getRooms();

		int playerId = connection.playerId;

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
		return this->connection.playerId;
	}

	networking::Connection FleeCommand::getConnection() const {
		return this->connection;
	}


	/*Status*/
	StatusCommand::StatusCommand(networking::Connection connection_, const std::string& message_)
	: connection{connection_}, message{message_} {}

	std::string StatusCommand::execute(Context& context) {
		auto players = context.getPlayers();
		int playerId = connection.playerId;
		std::cout<<"status cout"<<std::endl;

		return (*players)[playerId].getUsername()+ "> \n" +
				" Health: "+std::to_string((*players)[playerId].playerCharacter.getCurrentHealth())+"/"+std::to_string((*players)[playerId].playerCharacter.getMaxHealth())+"\n"+
				" Mana  : "+std::to_string((*players)[playerId].playerCharacter.getCurrentMana())+"/"+std::to_string((*players)[playerId].playerCharacter.getMaxMana())+"\n"+
				" EXP   : "+std::to_string((*players)[playerId].playerCharacter.getExp())+"\n"+
				" Level : "+std::to_string((*players)[playerId].playerCharacter.getLevel())+"\n"+
				" Swap Status: "+std::to_string((*players)[playerId].playerCharacter.getSwappedStatus())+"\n";
	}
	int StatusCommand::getId() const {
		return this->connection.playerId;
	}

	networking::Connection StatusCommand::getConnection() const {
		return this->connection;
	}


	/*InvalidCommand*/
	InvalidCommand::InvalidCommand(networking::Connection connection_, const std::string& message_)
	: connection{connection_}, message{message_} {}

	std::string InvalidCommand::execute(Context& context) {
		auto players = context.getPlayers();
		int playerId = connection.playerId;

		return (*players)[playerId].getUsername()+ "> " + message + " " +
				" is an invalid command.\n\n";
	}

	int InvalidCommand::getId() const {
		return this->connection.playerId;
	}

	networking::Connection InvalidCommand::getConnection() const {
		return this->connection;
	}



	TakeCommand::TakeCommand(networking::Connection connection_, const std::string& message_)
	: connection{connection_}, message{message_} {}

	std::string TakeCommand::execute(Context& context) {
		int playerId = connection.playerId;
		auto players = context.getPlayers();
		auto player = &(*players)[playerId];
		auto rooms = context.getRooms();
		auto objects = context.getObjects();
		auto playerLocations = context.getPlayerLocations();

		std::string messageText = message.substr(4);
		std::transform(messageText.begin(), messageText.end(), messageText.begin(), ::tolower);

		//std::vector <std::string> takeMessage;
	    boost::trim_if(messageText, boost::is_any_of("\t "));
	    //boost::split(takeMessage, messageText, boost::is_any_of("\t "), boost::token_compress_on);

		std::string response = "";
		std::string takeString = "take";

		int currentRoomId = (*playerLocations)[playerId];
		Room* currentRoom = &(*rooms)[currentRoomId];

	 	std::cout << "EHTH" << std::endl;

		//-------------------------------------------------look "Npc keyword"

		//OK findNpc/findRoom will return a Npc* object which we can use to directly modify the selected npc/object in the room
		if(takeMessage.size() == 2) {
			Npc* currentNpc = currentRoom->findNpc(takeMessage[1]);
			std::cout << takeMessage.size() << std::endl;
			if(currentNpc != NULL) {
				std::cout << "wewwr" << std::endl;
				response += "\n Steal: " + takeMessage[0] + " From: " + takeMessage[1] + "\n\n";
				std::cout << "wsfsdfer" << std::endl;
				//Npc will use a currentNpc->findObjectId(objectTargetPair[0]) method which returns the object ID	of the object in inventory
				//Will change removeObjectfromInventory() to take in the objectID (maybe pass in selected index "eg. steal apple '1'");
				if(currentNpc->npcCharacter.removeObjectFromInventory(takeMessage[0])) {
					response += "Success!\n";
				} else {
					response += "Failure.\n";
				}
				//}

				return response;
			}
		}
		std::cout << "POIP" << std::endl;
		//-------------------------------------------------look "Object keyword"

		//Room will use a currentRoom->findObjectId(objectTargetPair[0]) method which returns the object ID of the object in inventory
		//Will change removeObject() to take in the objectID (maybe pass in selected index "eg. steal apple '1'");
		//if(std::isdigit(takeMessage.end()) )

		Object* currentObject = currentRoom->findObject(takeMessage[0]);

		if(currentObject != NULL){
			if( std::find((currentObject->getWearFlags()).begin(), 
				(currentObject->getWearFlags()).end(), takeString )!=(currentObject->getWearFlags()).end() ){
				
				player->addObjectToInventory(*currentObject, 1);
				std::cout << "player inventory: " << player->getPlayerInventoryDesc() << "\n";
				//bool ret = currentRoom->removeObject(currentObject->getId());
				//response += messageText + "added to inventory\n\n";
				return player->getUsername() + "> " + messageText + " added to inventory\n\n";
			}
			else{
				//response += messageText + "is not an object you can take!\n\n";
				return player->getUsername() + "> " + messageText + " is not an object you can take!\n\n";
			}
		} 
		else{
			//response += "Cannot take " + messageText + ", no match. \n\n";
			return player->getUsername() + "> " + "Cannot take " + messageText + ", no match. \n\n";
		}
		

		//-------------------------------------------------look "Object keyword"

		//Object* currentObject = currentRoom->>findObject(ObjectTargetPair[0]);

		//Room will use a currentRoom->>findObject(objectTargetPair[0]) method which returns the object ID of the object in inventory 
		//Will change removeObject() to take in the objectID (maybe pass in selected index "eg. steal apple '1'");

		//return player.getUsername() + "> " + response;
	}
	int TakeCommand::getId() const {
		return this->connection.playerId;
	}

	networking::Connection TakeCommand::getConnection() const {
		return this->connection;
	}


	EquipCommand::EquipCommand(networking::Connection connection_, const std::string& message_)
	: connection{connection_}, message{message_} {}

	std::string EquipCommand::execute(Context& context) {
		int playerId = connection.playerId;
		auto players = context.getPlayers();
		auto player = &(*players)[playerId]; //need to make it a reference so it changes the object itself rather than changing a copy of object
		auto rooms = context.getRooms();
		auto playerLocations = context.getPlayerLocations();

		std::string messageText = message.substr(5);
		std::transform(messageText.begin(), messageText.end(), messageText.begin(), ::tolower);
	    boost::trim_if(messageText, boost::is_any_of("\t "));
		std::string response = "";

		int currentRoomId = (*playerLocations)[playerId];
		Room* currentRoom = &(*rooms)[currentRoomId];
		Object* currentObject = currentRoom->findObject(messageText);

		//currentobject can not be found
		if(currentObject == NULL){
			return player->getUsername() + "> " + "Cannot equip " + messageText + ", no match. \n\n";
		}

		const std::string& armorFlag = " armor";
		std::string weaponFlag = "weapon";
		std::string itemtype = currentObject->getItemType();
		//boost::trim_if(itemtype, boost::is_any_of(" "));
		bool equipObjectRet;
		std::cout << "objects itemtype : " << itemtype << "\n";
		if( itemtype == armorFlag ){	// need to change to work with midgaard
			equipObjectRet = player->equipObject(*currentObject, armorFlag);
			int currentArmor = player->getArmor();
			player->setArmor(currentArmor + 10); //maybe change this later
			//std::cout << "line 425 commands\n";
		} else if (itemtype == weaponFlag){ // need to change to work with midgaard
			equipObjectRet = player->equipObject(*currentObject, weaponFlag);
			int currentAttack = player->getThac0();
			player->setThac0(currentAttack + 10); //maybe change this later
			//std::cout << "line 428 commands\n";
		} else{
			//std::cout << "line 430 commands\n";
			return player->getUsername() + "> " + messageText + " is not an item that can be equipped! \n\n";
		}
		
		if(equipObjectRet){
			return player->getUsername() + "> " + messageText + " has been equipped!\n\n";
		} else {
			return player->getUsername() + "> " + messageText + " is not in your inventory!\n\n";
		}
	}

	int EquipCommand::getId() const {
		return this->connection.playerId;
	}

	networking::Connection EquipCommand::getConnection() const {
		return this->connection;
	}
	

	ListCommand::ListCommand(networking::Connection connection_, const std::unordered_map<std::string, std::string>& commands_, const std::string& message_) 
	: connection{connection_}, commands{commands_}, message{message_} {}

	std::string ListCommand::execute(Context& context) {
		int playerId = connection.playerId;
		auto players = context.getPlayers();
		auto player = (*players)[playerId];

		std::string allCommands = "";

		std::string lsMessage = message.substr(2);
		std::transform(lsMessage.begin(), lsMessage.end(), lsMessage.begin(), ::tolower);
	    boost::trim_if(lsMessage, boost::is_any_of("\t "));

		if(lsMessage == ""){
			for( const auto& i : commands){
    			allCommands += i.second + "\n";
  			}
  			return (*players)[playerId].getUsername()+ "> " + "All possible Commands:\n" + allCommands + "\n\n";
  		}else if (lsMessage == "inventory"){
  			return (*players)[playerId].getUsername()+ "> " + "Inventory:\n" + player.getPlayerInventoryDesc() + "\n\n";
		}else if (lsMessage == "equipment"){
			return (*players)[playerId].getUsername()+ "> " + "Equipment:\n" + player.getPlayerEquipmentDesc() + "\n\n";
  		}else{
  			return (*players)[playerId].getUsername()+ "> " + "Cannot list " + lsMessage + ", no match\n\n";
  		}
	}

	int ListCommand::getId() const {
		return this->connection.playerId;
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
		return this->connection.playerId;
	}

	networking::Connection SayCommand::getConnection() const {
		return this->connection;
	}
	
	StealCommand::StealCommand(networking::Connection connection_, const std::string& message_)
	: connection{connection_}, message{message_} {}

	std::string StealCommand::execute(Context& context) {
		int playerId = connection.playerId;
		auto players = context.getPlayers();
		auto player = &(*players)[playerId];
		auto rooms = context.getRooms();
		auto objects = context.getObjects();
		auto playerLocations = context.getPlayerLocations();

		std::string messageText = message.substr(5);
		std::transform(messageText.begin(), messageText.end(), messageText.begin(), ::tolower);

		std::vector <std::string> stealMessage;
	    boost::trim_if(messageText, boost::is_any_of("\t "));
	    boost::split(stealMessage, messageText, boost::is_any_of("\t "), boost::token_compress_on);

		std::string response = "";

		int currentRoomId = (*playerLocations)[playerId];
		Room* currentRoom = &(*rooms)[currentRoomId];
		//add dummy object to room to test


		 std::cout << "EHTH" << std::endl;

		 /*
		 * Make static function findObject() at the top of this file that searches through the object Map and returns the object ID
		 */

		//-------------------------------------------------look "Npc keyword"

		//OK findNpc/findRoom will return a Npc* object which we can use to directly modify the selected npc/object in the room 
		if(stealMessage.size() == 2) {
			Npc* currentNpc = currentRoom->findNpc(stealMessage[1]);
			std::cout << stealMessage.size() << std::endl;
			if(currentNpc != NULL) {
				std::cout << "wewwr" << std::endl;
				response += "\n Steal: " + stealMessage[0] + " From: " + stealMessage[1] + "\n\n";
				std::cout << "wsfsdfer" << std::endl;
				//Npc will use a currentNpc->findObjectId(objectTargetPair[0]) method which returns the object ID	of the object in inventory 
				//Will change removeObjectfromInventory() to take in the objectID (maybe pass in selected index "eg. steal apple '1'");
				if(currentNpc->removeObjectFromInventory(stealMessage[0])) {
					response += "Success!\n";
				} else {
					response += "Failure.\n";
				}
				//}

				return response;
			}
		}
		std::cout << "POIP" << std::endl;

		return player->getUsername() + "> " + "Cannot steal " + messageText + ", no match. \n\n";
	}

	int StealCommand::getId() const {
		return this->connection.playerId;
	}

	networking::Connection StealCommand::getConnection() const {
		return this->connection;
	}

	TeleportCommand::TeleportCommand(networking::Connection connection_, const std::string& message_)
	: connection{connection_}, message{message_} {}

	std::string TeleportCommand::execute(Context& context) {
		auto players = context.getPlayers();
		auto playerLocations = context.getPlayerLocations();
		auto rooms = context.getRooms();

		int playerId = connection.playerId;

		std::string teleportMessage = message.substr(8);
		std::transform(teleportMessage.begin(), teleportMessage.end(), teleportMessage.begin(), ::tolower);
	    boost::trim_if(teleportMessage, boost::is_any_of("\t "));

		(*playerLocations)[playerId] = std::stoi(teleportMessage);

		return (*players)[playerId].getUsername() + "> " + message + "\n\n" + printMiniMap(rooms, std::stoi(teleportMessage)) + (*rooms)[std::stoi(teleportMessage)].getFullRoomDesc() + getPlayersInRoomDesc(players, playerLocations, std::stoi(teleportMessage));
	}

	int TeleportCommand::getId() const {
		return this->connection.playerId;
	}

	networking::Connection TeleportCommand::getConnection() const {
		return this->connection;
	}
}

	//CastCommand
	CastCommand::CastCommand(networking::Connection connection_, const std::string& message_)
	: connection{connection_}, message{message_} {}

	std::string CastCommand::execute(Context& context) {
		auto players = context.getPlayers();
		auto rooms = context.getRooms();
		auto playerLocations = context.getPlayerLocations();
		auto offenseSpells = context.getOffenseSpells();
		auto defenseSpells = context.getDefenseSpells();

		int playerId = connection.playerId;

		std::string messageText = this->message.substr(4);
		std::transform(messageText.begin(), messageText.end(), messageText.begin(), ::tolower);

		std::vector <std::string> castMessage;
    	boost::trim_if(messageText, boost::is_any_of("\t "));
    	boost::split(castMessage, messageText, boost::is_any_of("\t "), boost::token_compress_on);
		
		int currentRoomId = (*playerLocations)[playerId];
		Room* currentRoom = &(*rooms)[currentRoomId];
		Spells* castedDefenseSpell = getCastedSpell(castMessage[0], (*defenseSpells));
		Spells* castedOffenseSpell = getCastedSpell(castMessage[0], (*offenseSpells));
		Spells* currentSpell;
		
		if(castedDefenseSpell != nullptr){
			std::cout << "line 492\n";
			currentSpell = castedDefenseSpell;
		}
		else if(castedOffenseSpell != nullptr){
			std::cout << "line 496\n";
			currentSpell = castedOffenseSpell;
		}
		else{
			return (*players)[playerId].getUsername() + "> " + "Cannot cast " + castMessage[0] + ", no match\n\n";
		}
		
		int targetId = currentRoom->findPlayerId(castMessage[1]);
		auto target = &(*players)[targetId].playerCharacter;
		int currentTargetHealth= target->getCurrentHealth();
		auto player = &(*players)[playerId].playerCharacter;
		int currentPlayerMana = player->getCurrentMana();
		int spellMana = currentSpell->getMana();


		//if findPlayerId can't find the player it will return 0
		//might need to change this
		if(targetId == 0){
			return (*players)[playerId].getUsername() + "> " + "Target " + castMessage[1] + " not found\n\n";
		}
		
		/* -- for testing purposes this will be commented out, uncomment out later
		if(targetId == playerId && castedOffenseSpell != nullptr){
			return (*players)[playerId].getUsername() + "> " + "Cannot cast " + castMessage[0] + " on yourself!\n\n";
		}
		*/

		if(currentTargetHealth == 0){
			return (*players)[playerId].getUsername() + "> " + "Target " + castMessage[1] + " has already been defeated!\n\n";
		}

		if(!checkMana(spellMana, currentPlayerMana)){
			return (*players)[playerId].getUsername() + "> " + "Not enough mana to cast " + castMessage[0] + "\n\n";
		}

		player->setCurrentMana(currentPlayerMana - spellMana);
		std::string targetName = (*players)[targetId].getUsername();
		std::string hitChar = replaceTargetName(currentSpell->getHitChar(), targetName);
		int playerLevel = player->getLevel();
		int currentPlayerExp = player->getExp();
		player->setExp(currentPlayerExp + (playerLevel*2 + 10)); //need leveling up method in player


		if(currentSpell->getType() == "defense"){
			target->setCurrentHealth(currentTargetHealth + (playerLevel*2 + 50));
		} 
		else{
			target->setCurrentHealth(currentTargetHealth - (playerLevel*2 + 50)); 
			//todo: if target dies -- increase xp/lvl up
		}


		return (*players)[playerId].getUsername() + "> " + castMessage[0] + " has been cast on " + castMessage[1] + "\n\t" + hitChar + "\n\n";
 		
 		//todo: setmax and setcurrent in character need to be changed, specifically
 		//setcurrent needs to check it the parameter passed is greater than max
 		//if it is, then set it to max, else set it to parameter passed

	}

	Spells* CastCommand::getCastedSpell(const std::string& castName_, std::vector<Spells>& spells_){
		for (auto & spell: spells_) {
			if(spell.getName() == castName_) {
				return &spell;
			}
		}
		return nullptr;
	}

	bool CastCommand::checkMana(const int spellMana, const int playerMana){
		if(spellMana <= playerMana){
			return true;
		}
		else{
			return false;
		}
	}

	//--Mohamed
	//will replace every instance of $N to targetName
	std::string CastCommand::replaceTargetName(std::string hitString, const std::string& targetName){
  		boost::replace_all(hitString, "$N", targetName); // <#include <boost/algorithm/string/replace.hpp>
		return hitString;
	}

	int CastCommand::getId() const {
		return this->connection.playerId;
	}

	networking::Connection CastCommand::getConnection() const {
		return this->connection;
	}


	/*
	***************************************************************************************************************
	* TODO: Handle when a player and npc have the same name, swapping back to origin on death/logout
	***************************************************************************************************************
	*/
	/*Swap command*/
	SwapCommand::SwapCommand(networking::Connection connection_, const std::string& message_)
	: connection{connection_}, message{message_} {}

	std::string SwapCommand::execute(Context& context) {
		
		const int manaCost = 10;

		auto players = context.getPlayers();
		auto playerLocations = context.getPlayerLocations();
		auto rooms = context.getRooms();
		auto npcs = context.getNpcs();

		int playerId = connection.playerId;
		Player* currentPlayer = &(*players)[playerId];
		int currentRoomId = (*playerLocations)[playerId];
		Room* currentRoom = &(*rooms)[currentRoomId];

		if (currentPlayer->playerCharacter.getSwappedStatus()){
			return currentPlayer->getUsername() + "> You have already been swapped.\n";
		}
		if (currentPlayer->playerCharacter.getCurrentMana() < manaCost){
			return currentPlayer->getUsername() + "> You do not have enough mana.\n";
		}

		std::string swapMessage = message.substr(4);
		boost::trim_if(swapMessage, boost::is_any_of("\t "));

		int targetPlayerId = currentRoom->findPlayerId(swapMessage);
		Npc* targetNpc = currentRoom->findNpc(swapMessage);

		if (swapMessage.substr(swapMessage.length() - 2) == " p"){
			swapMessage = swapMessage.substr(0, swapMessage.length()-2);
			targetPlayerId = currentRoom->findPlayerId(swapMessage);
			goto swapWithPlayer;
		}
		else if (swapMessage.substr(swapMessage.length() - 2) == " n"){
			swapMessage = swapMessage.substr(0, swapMessage.length()-2);
			targetNpc = currentRoom->findNpc(swapMessage);
			goto swapWithNpc;
		}

		else if (targetPlayerId && targetNpc != NULL){
			return currentPlayer->getUsername() + "> A player and an NPC have the same name " + swapMessage + ": " +
					"\n \t Type 'swap "+ swapMessage + " p'" + " to swap with the player." +
					"\n \t Type 'swap "+ swapMessage + " n'" + " to swap with the npc. \n";
		}

		// Swap with another player in the same room
		swapWithPlayer:
		if(targetPlayerId) {
			if(playerId == targetPlayerId) {
				return currentPlayer->getUsername() + "> You cannot swap with yourself.\n";
			}

			if ((*players)[targetPlayerId].playerCharacter.getSwappedStatus()){
				return currentPlayer->getUsername() + "> Your target player has already been swapped.\n";
			}
			currentPlayer->playerCharacter.setCurrentMana(currentPlayer->playerCharacter.getCurrentMana() - manaCost);

			// Keep track of Player who was swapped
			currentPlayer->setSwapTarget((*players)[targetPlayerId].playerCharacter);
			(*players)[targetPlayerId].setSwapTarget(currentPlayer->playerCharacter);

			std::swap(currentPlayer->playerCharacter, (*players)[targetPlayerId].playerCharacter);
			currentPlayer->playerCharacter.setSwappedStatus(true);
			(*players)[targetPlayerId].playerCharacter.setSwappedStatus(true);
			return currentPlayer->getUsername() + "> " + "You have swapped with player " + swapMessage + "\n";
		}
		// Swap with Npc in the same room
		swapWithNpc:
		if(targetNpc != NULL) {
			if (targetNpc->npcCharacter.getSwappedStatus()){
				return currentPlayer->getUsername() + "> Your target npc has already been swapped.\n" + std::to_string(targetNpc->npcCharacter.getSwappedStatus());
			}
			currentPlayer->playerCharacter.setCurrentMana(currentPlayer->playerCharacter.getCurrentMana() - manaCost);

			// Keep track of Npc who was swapped
			currentPlayer->setSwapTarget(targetNpc->npcCharacter);

			std::swap(currentPlayer->playerCharacter, targetNpc->npcCharacter);
			currentPlayer->playerCharacter.setSwappedStatus(true);
			targetNpc->npcCharacter.setSwappedStatus(true);
			return currentPlayer->getUsername() + "> " + "You have swapped with npc " + swapMessage + "\n";
		}
		// No target found 
		return currentPlayer->getUsername() + "> " + "Unable to locate " + swapMessage + "\n";
	}

	int SwapCommand::getId() const {
		return this->connection.playerId;
	}

	networking::Connection SwapCommand::getConnection() const {
		return this->connection;
	}
}
