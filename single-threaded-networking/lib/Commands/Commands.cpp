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
		int playerId = connection.playerId;

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

			currentRoom->removePlayer(playerId);
			destRoom->addPlayer(playerId, currentPlayer.getUsername());

			return currentPlayer.getUsername() + "> " + message + "\n\n" + destRoom->getFullRoomDesc();
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
			int currentTargetHealth=(*players)[targetPlayerId].getHealth();



			if (currentTargetHealth==0){
				return response + " Already Defeated! Fatality \n";
			}else{
				(*players)[targetPlayerId].setHealth(currentTargetHealth-50);
				if ((*players)[targetPlayerId].getHealth()==0){
					int playerXP=(*players)[playerId].getExp();
					(*players)[playerId].setExp(100);
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
				" Health: "+std::to_string((*players)[playerId].getHealth())+"\n"+
				" Mana  : "+std::to_string((*players)[playerId].getMana())+"\n"+
				" EXP   : "+std::to_string((*players)[playerId].getExp())+"\n"+
				" Level : "+std::to_string((*players)[playerId].getLevel())+"\n"+
				" Armor : "+std::to_string((*players)[playerId].getArmor())+"\n"
				" Attack : "+std::to_string((*players)[playerId].getThac0())+"\n";


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

		std::vector <std::string> takeMessage;
	    boost::trim_if(messageText, boost::is_any_of("\t "));
	    boost::split(takeMessage, messageText, boost::is_any_of("\t "), boost::token_compress_on);

		std::string response = "";
		std::string takeString = "take";

		int currentRoomId = (*playerLocations)[playerId];
		Room* currentRoom = &(*rooms)[currentRoomId];
		//add dummy object to room to test
		currentRoom->addObject((*objects)[1107],1); // mithril/axe
		Object* currentObject = currentRoom->findObject(messageText);

		std::cout << "\n\n\n";
		std::cout << messageText << "\n";

		// if(takeMessage.size() == 2) {
		// 	Npc* currentNpc = currentRoom->findNpc(takeMessage[1]);
		// 	std::cout << takeMessage.size() << std::endl;
		// 	if(currentNpc != NULL) {
		// 		std::cout << "wewwr" << std::endl;
		// 		response += "\n Steal: " + takeMessage[0] + " From: " + takeMessage[1] + "\n\n";
		// 		std::cout << "wsfsdfer" << std::endl;
		// 		//Npc will use a currentNpc->findObjectId(objectTargetPair[0]) method which returns the object ID	of the object in inventory
		// 		//Will change removeObjectfromInventory() to take in the objectID (maybe pass in selected index "eg. steal apple '1'");
		// 		if(currentNpc->removeObjectFromInventory(takeMessage[0])) {
		// 			response += "Success!\n";
		// 		} else {
		// 			response += "Failure.\n";
		// 		}
		// 		//}

		// 		return response;
		// 	}
		// }


		 std::cout << "EHTH" << std::endl;

		 /*
		 * Make static function findObject() at the top of this file that searches through the object Map and returns the object ID
		 */

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
				if(currentNpc->removeObjectFromInventory(takeMessage[0])) {
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
	
	//Need to move out but don't know where (move to top of ffile as static function)
	bool TakeCommand::is_number(const std::string& s)
	{
		return !s.empty() && std::find_if(s.begin(), 
			s.end(), [](char c) { return !std::isdigit(c); }) == s.end();
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
}

//Add teleport command to help testing
namespace CombatCommands {
	AttackCommand::AttackCommand(std::vector<networking::Connection>& clients_, networking::Connection sourceConnection_, const std::string& message_)
	: clients{clients_}, sourceConnection{sourceConnection_}, message{message_} {}

	std::string AttackCommand::execute(Context& context) {
		auto players = context.getPlayers();
		auto rooms = context.getRooms();
		auto playerLocations = context.getPlayerLocations();
		int playerId = this->sourceConnection.playerId;

		std::string messageText = this->message.substr(7);
		std::transform(messageText.begin(), messageText.end(), messageText.begin(), ::tolower);

		std::vector <std::string> takeMessage;
    boost::trim_if(messageText, boost::is_any_of("\t "));
    boost::split(takeMessage, messageText, boost::is_any_of("\t "), boost::token_compress_on);
		this->sourceName=(*players)[playerId].getUsername();
		std::string sourceResponse = sourceName + "> " + takeMessage[0];

		int currentRoomId = (*playerLocations)[playerId];
		Room* currentRoom = &(*rooms)[currentRoomId];

		//should change this to not return magic number
		int targetPlayerId = currentRoom->findPlayerId(takeMessage[0]);
		for(networking::Connection client: clients){
			if(client.playerId == targetPlayerId){
				this->targetConnection = client;
			}
		}
		if(targetPlayerId != 0) {
			std::cout<<(*players)[targetPlayerId].getUsername() +" is the target name for "+ (*players)[playerId].getUsername()<<std::endl;
			int currentTargetHealth=(*players)[targetPlayerId].getHealth();
			if (currentTargetHealth==0){
				return sourceResponse + " has already been Defeated!\n";
			}else{
				(*players)[targetPlayerId].setHealth(currentTargetHealth-50);
				if ((*players)[targetPlayerId].getHealth()==0){
					int playerXP=(*players)[playerId].getExp();
					(*players)[playerId].setExp(100);
					return sourceResponse + " has been defeated!\n";
				}

			}
			return sourceResponse + " target found Attack Success \n";
		}/*else if(){

		}*/else{
			return sourceResponse + " target not in room / not found \n" ;
		}

	}

	std::string AttackCommand::getSourceName() const {
		return this->sourceName;
	}

	int AttackCommand::getSourceId() const {
		return this->sourceConnection.playerId;
	}
	int AttackCommand::getTargetId() const {
		return this->targetId;
	}
	networking::Connection AttackCommand::getSourceConnection() const {
		return this->sourceConnection;
	}
	networking::Connection AttackCommand::getTargetConnection() const {
		return this->targetConnection;
	}
}
