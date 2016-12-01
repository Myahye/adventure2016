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
			response += "\n\n" + currentNpc->npcCharacter.getDescription();
			response += "\n     Wearing: "  + currentNpc->npcCharacter.getEquipmentDesc();
			response += "\n     Carrying: " + currentNpc->npcCharacter.getInventoryDesc() + "\n\n";
			return response;
		}

		//-------------------------------------------------look "Object keyword"


		Object* currentObject = currentRoom->findObject(lookMessage);
		//will move this to room class later as if isobject return object.getfulldesc()
		if(currentObject != NULL) {
			response += "\n";
			//move loop out later;
					//need look through all currentobject get extra for keyword
			for (auto eachPair : currentObject->getExtra()){
				for(auto descriptionText : eachPair.first) {
				  response += descriptionText + "\n";
				}
				response += "\n";
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
		auto players = context.getPlayers();
		auto rooms = context.getRooms();
		auto playerLocations = context.getPlayerLocations();
		int playerId = connection.playerId;

		std::string messageText = message.substr(4);
		std::transform(messageText.begin(), messageText.end(), messageText.begin(), ::tolower);

		std::vector <std::string> takeMessage;
	    boost::trim_if(messageText, boost::is_any_of("\t "));
	    boost::split(takeMessage, messageText, boost::is_any_of("\t "), boost::token_compress_on);

		std::string response = (*players)[playerId].getUsername() + "> " + message;

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
			if(currentRoom->removeObject(currentObject->getId())) {
				response += "\n Take: " + takeMessage[0] + "\n\n";
				return response;
			}
		}

		std::cout << "EEEE" << std::endl;

		//room will use a currentRoom->findNpcId(objectTargetPair[0]) method which returns the object ID	of the object in inventory
		//Will change removeNPC() to take in the npcID (maybe pass in selected duplicate index "eg. steal apple '1'");
		//if(is_number(takeMessage.end()) {}

		Npc* currentNpc = currentRoom->findNpc(takeMessage[0]);
		if(currentNpc != NULL) {
			if(currentRoom->removeNpc(currentNpc->npcCharacter.getId())) {
				response += "\n Take: " + takeMessage[0] + "\n\n";
				return response;
			}
		}

		//-----take player

		int currentPlayerId = currentRoom->findPlayerId(takeMessage[0]);
		if(currentPlayerId != 0) {
			if(currentRoom->removePlayer(currentPlayerId)) {
				response += "\n Take: " + takeMessage[0] + "\n\n";
				return response;
			}
		}
		std::cout << "size " << currentRoom->playersInRoom.size() << std::endl;

		std::cout << "G" << std::endl;

		return (*players)[playerId].getUsername() + "> " + "Cannot steal " + takeMessage[0] + ", no match. \n\n";
	}
	int TakeCommand::getId() const {
		return this->connection.playerId;
	}

	networking::Connection TakeCommand::getConnection() const {
		return this->connection;
	}

	//Need to move out but don't know where
	bool TakeCommand::is_number(const std::string& s)
	{
		return !s.empty() && std::find_if(s.begin(),
			s.end(), [](char c) { return !std::isdigit(c); }) == s.end();
	}



	ListCommand::ListCommand(networking::Connection connection_, const std::unordered_map<std::string, std::string>& commands_, const std::string& message_)
		: connection{connection_}, commands{commands_}, message{message_} {}

	std::string ListCommand::execute(Context& context) {
		auto players = context.getPlayers();
		int playerId = connection.playerId;
		std::string allCommands = "";

		for( const auto& i : commands){
    		allCommands += i.second + "\n";
  		}

		return (*players)[playerId].getUsername()+ "> " + "All possible Commands:\n" + allCommands + "\n";
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
		Player currentPlayer = (*players)[playerId];
		int currentRoomId = (*playerLocations)[playerId];
		Room* currentRoom = &(*rooms)[currentRoomId];

		if (currentPlayer.playerCharacter.getSwappedStatus()){
			return "You have already been swapped.\n";
		}
		if (currentPlayer.playerCharacter.getCurrentMana() < manaCost){
			return "You do not have enough mana.\n";
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

			return "A player and an NPC have the same name " + swapMessage + ": " +
					"\n \t Type 'swap "+ swapMessage + " p'" + " to swap with the player." +
					"\n \t Type 'swap "+ swapMessage + " n'" + " to swap with the npc. \n";
		}

		// Swap with another player in the same room
		swapWithPlayer:
		if(targetPlayerId) {
			if ((*players)[targetPlayerId].playerCharacter.getSwappedStatus()){
				return "Your target player has already been swapped.\n";
			}
			currentPlayer.playerCharacter.setCurrentMana(currentPlayer.playerCharacter.getCurrentMana() - manaCost);
			std::swap(currentPlayer.playerCharacter, (*players)[targetPlayerId].playerCharacter);
			currentPlayer.playerCharacter.setSwappedStatus(true);
			(*players)[targetPlayerId].playerCharacter.setSwappedStatus(true);
			return currentPlayer.getUsername() + "> " + "You have swapped with player " + swapMessage + "\n";
		}
		// Swap with Npc in the same room
		swapWithNpc:
		if(targetNpc != NULL) {
			if (targetNpc->npcCharacter.getSwappedStatus()){
				return "Your target npc has already been swapped.\n" + std::to_string(targetNpc->npcCharacter.getSwappedStatus());
			}
			currentPlayer.playerCharacter.setCurrentMana(currentPlayer.playerCharacter.getCurrentMana() - manaCost);
			std::swap(currentPlayer.playerCharacter, targetNpc->npcCharacter);
			currentPlayer.playerCharacter.setSwappedStatus(true);
			targetNpc->npcCharacter.setSwappedStatus(true);
			return currentPlayer.getUsername() + "> " + "You have swapped with npc " + swapMessage + "\n";
		}
		// No target found 
		return currentPlayer.getUsername() + "> " + "Unable to locate " + swapMessage + "\n";
	}

	int SwapCommand::getId() const {
		return this->connection.playerId;
	}

	networking::Connection SwapCommand::getConnection() const {
		return this->connection;
	}

}
