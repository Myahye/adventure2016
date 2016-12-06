#include "Commands.h"
#include <boost/algorithm/string.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/algorithm/string/iter_find.hpp>
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






std::string getPlayersInRoomDesc(std::unordered_map<int, Player>* players, const std::unordered_map<int, int>* playerLocations,
	const int currentRoomId) {
	std::string playersInRoom = "     Players: " ;
	for(auto& playerIdRoomIdpair : *playerLocations) {
		if(playerIdRoomIdpair.second == currentRoomId) {
			if((*players)[playerIdRoomIdpair.first].playerCharacter.getStatus() == "Online") {
				playersInRoom += (*players)[playerIdRoomIdpair.first].getUsername() + ", ";
			}
		}
	}
	playersInRoom += "\n\n";
	return playersInRoom;
}
std::string printEditCurrentRoomWindow(const std::vector<std::string>& description,
	const std::vector<Door>& doors, const int currentRoomId, std::vector<std::unique_ptr<Reset>>& resets,
	const std::vector<int>& resetsInRoomPosition) {
	std::string response = std::string("\n\n      Type '1' to edit the room description\n") +
								"      Type '2' to edit the room doors/exits\n" +
								"      Type 'add [reset type] [object/npc id] [limit] [comment]' to add a new reset eg. 'add npc 3001 1 baker'\n" +
								"      Type 'remove [line number]' remove the selected reset eg. 'remove 3'\n" +
								"      Type 'stop' to quit the editor\n\n";

	response += "      Current Room Full Description:";

	response += "\n\n        Room Id: " + std::to_string(currentRoomId) + "\n\n";

	response += "        Room Description: \n";
	for(auto& d : description) {
		response += std::string("        ") + d + "\n";
	}

	response += "\n        Resets in Room: \n";
	int i = 0;
	for(auto & reset : resetsInRoomPosition) {
		response += std::string("        ") + std::to_string(i) + " - " + resets[reset]->printClass();
		i++;
	}

	response += "\n        Doors in Room: \n";
	for(auto & door : doors) {
		response += std::string("        ") + "door: " + door.getDir() + " to Room: " + std::to_string(door.getDestinationId()) + " Desc: " + door.getDesc() + "\n";
	}

	return response;
}
std::string printEditRoomDescriptionWindow(const std::vector<std::string>& description) {
	std::string response = std::string("\n\n") +    "      Type 'add [description text]' to add a new line of text to description eg. 'add The room is cold and barren.' \n" +
						 			     "      Type 'remove [line number]' to remove the selected line of text from description eg. 'remove 3'\n" +
										 "      Type 'set [line number] [description text]' to set a new description for that line eg. 'set 2 The room is cold and barren.' \n" +
										 "      Type 'back' to go back to the previous window\n"
										 "      Type 'stop' to quit the editor\n\n";
	response += "        Room Description: \n";
	int i = 0;
	for(auto& d : description) {
		response += "      ";
		response += std::to_string(i) + " - " + d + "\n";
		i++;
	}
	return response + "\n";
}

std::string printEditRoomDoorsWindow(const std::vector<Door>& doors) {
	std::string response = std::string("\n\n") +  "      Type 'add [dir] [destination Id] -d [description text]' to add a new door eg. 'add west 1100 -d You see the general store.'\n" +
							 "      Type 'remove [line number]' to remove the selected door eg. 'remove 2'\n" +
							 "      Type 'back' to go back to previous window\n" +
							 "      Type 'stop' to quit the editor\n\n";

	response += "        Doors in Room: \n";
	int i = 0;
	for(auto & door : doors) {
		response += std::string("        ") + std::to_string(i) + " - " + "door: " + door.getDir() + " to Room: " + std::to_string(door.getDestinationId()) + " Desc: " + door.getDesc() + "\n";
		i++;
	}

	return response + "\n";
}

Editor::Editor() {}

Editor::Editor(networking::Connection connection_, const std::string& message_)
: connection{connection_}, message{message_} {}

std::string Editor::execute(Context& context, std::vector<std::unique_ptr<Reset>>& resets) {
	auto players = context.getPlayers();
	auto rooms = context.getRooms();
	auto playerLocations = context.getPlayerLocations();
	//auto objects = context.getObjects();
	int playerId = connection.playerId;

	std::string response = (*players)[playerId].getUsername() + "> " + message;

	boost::trim_if(message, boost::is_any_of("\t "));

	int currentRoomId = (*playerLocations)[playerId];
	Room* currentRoom = &(*rooms)[currentRoomId];

	Player* player = &(*players)[playerId];

	auto doors = currentRoom->doors;
	auto description = currentRoom->getDescV();

	std::vector<int> resetsInRoomPosition;

	int i = 0;
	for(auto & reset : resets) {
		if(reset->getRoom() == currentRoomId) {
			resetsInRoomPosition.push_back(i);
		}
		i++;
	}


	if(message == "") {
		return "";
	}




	if(message == "stop") {
		player->playerCharacter.setStatus("Online");
		message = "";
		return response + "\n\n" + "      Quiting Editor.\n\n";
	}




	if(player->playerCharacter.getStatus() == "WorldBuilding" && message == "1") {
		player->playerCharacter.setStatus("EditCurrentRoom");
		message = "";
	}
	if(player->playerCharacter.getStatus() == "WorldBuilding" && message == "2") {
		int i = rooms->size()+4000;
		(*rooms)[i] = Room();
		(*rooms)[i].setRoomId(i);
		(*playerLocations)[playerId] = i;

		currentRoomId = (*playerLocations)[playerId];
		currentRoom = &(*rooms)[currentRoomId];

		doors = currentRoom->doors;
		description = currentRoom->getDescV();

		resetsInRoomPosition.clear();
		i = 0;
		for(auto & reset : resets) {
			if(reset->getRoom() == currentRoomId) {
				resetsInRoomPosition.push_back(i);
			}
			i++;
		}

		player->playerCharacter.setStatus("EditCurrentRoom");
		message = "";
	}
	if(player->playerCharacter.getStatus() == "WorldBuilding") {
		response += "\n\n      CURRENTLY EDITING\n---------------------------------------------";
		message = "";
		return response + "\n\n" +  "      Type '1' to edit current room\n" +
									"      Type '2' to create new room\n" +
									"      Type 'stop' to quit the editor\n\n";
	}




	if(player->playerCharacter.getStatus() == "EditCurrentRoom" && message == "1") {
		player->playerCharacter.setStatus("EditRoomDescription");
		message = "";
	}
	if(player->playerCharacter.getStatus() == "EditCurrentRoom" && message == "2") {
		player->playerCharacter.setStatus("EditRoomDoors");
		message = "";
	}
	//I rushed this out so insufficient error checking
	if(player->playerCharacter.getStatus() == "EditCurrentRoom") {

		if(message.substr(0,4) == "add ") {
			response += "\n\n      CURRENTLY EDITING ROOM\n---------------------------------------------";
			try {
				message = message.substr(4);

				std::vector<std::string> addResetMessage;
			    boost::split(addResetMessage, message, boost::is_any_of("\t "), boost::token_compress_on);

			    if(addResetMessage.size() != 4) {
			    	response += "\n\n      Invalid Format.";
			    } else {
			    	if(addResetMessage[0] == "npc") {
			    		resets.push_back(std::make_unique<Resets::ResetNpc>(addResetMessage[0], boost::lexical_cast<int>(addResetMessage[1]) , boost::lexical_cast<int>(addResetMessage[2])
			    		, currentRoomId, addResetMessage[3]));
			    		resetsInRoomPosition.push_back(resets.size()-1);
			    		response += " \n\n       successfully added npc reset";
			    	} else if(addResetMessage[0] == "object") {
			    		resets.push_back(std::make_unique<Resets::ResetObject>(addResetMessage[0], boost::lexical_cast<int>(addResetMessage[1]) , boost::lexical_cast<int>(addResetMessage[2])
			    		, currentRoomId, addResetMessage[3]));
			    		resetsInRoomPosition.push_back(resets.size()-1);
			    		response += " \n\n       successfully added object reset";
			    	}
			    }
			} catch (boost::bad_lexical_cast) {
				response += "\n\n      Please enter valid numbers";
			}
		} else if(message.substr(0,7) == "remove ") {
			response += "\n\n      CURRENTLY EDITING ROOM\n---------------------------------------------";
			try {
		        int selectedLineNumber = boost::lexical_cast<int>(message.substr(7,1));
			    if(selectedLineNumber < 0 || (unsigned)selectedLineNumber >= resetsInRoomPosition.size()) {
		    		response += "\n\n      Could not find line number " + message.substr(7,1) + ", removal failed";
			    } else {
				    int resetPositionNumber = resetsInRoomPosition[selectedLineNumber];
					resets.erase(resets.begin()+resetPositionNumber);
					resetsInRoomPosition.clear();
					int i = 0;
					for(auto & reset : resets) {
						if(reset->getRoom() == currentRoomId) {
							resetsInRoomPosition.push_back(i);
						}
						i++;
					}
					response += " \n\n       reset: '" + std::to_string(selectedLineNumber) + "' removed";
				}
			} catch (boost::bad_lexical_cast) {
		        response += "\n\n      Please enter a valid line number";
		    }
		} else {
			response += "\n\n      CURRENTLY EDITING ROOM\n---------------------------------------------";
		}

		response += printEditCurrentRoomWindow(description, doors, currentRoom->getRoomId(), resets, resetsInRoomPosition) + "\n   ";
		message = "";
		return response;
	}




	if(player->playerCharacter.getStatus() == "EditRoomDescription") {
		if(message.substr(0,4) == "add ") {
			response += "\n\n      CURRENTLY EDITING ROOM DESCRIPTION\n---------------------------------------------";
			description.push_back(message.substr(4));
			currentRoom->setDescription(description);
			response += "\n\n      Line '" + message.substr(4) + "' added to description";
		} else if(message.substr(0,7) == "remove ") {
			response += "\n\n      CURRENTLY EDITING ROOM DESCRIPTION\n---------------------------------------------";
			try {
		        int selectedLineNumber = boost::lexical_cast<int>(message.substr(7,1));

			    if(selectedLineNumber < 0 || (unsigned)selectedLineNumber >= description.size()) {
		    		response += "\n\n      Could not find line number " + message.substr(7,1) + ", removal failed";
			    } else {
				    std::string temp = description[selectedLineNumber];
					description.erase(description.begin()+selectedLineNumber);
					currentRoom->setDescription(description);
					response += std::string("\n\n      Line '") + temp + "' removed from description.";
				}
			} catch (boost::bad_lexical_cast) {
		        response += "\n\n      Please enter a valid line number";
		    }
		} else if(message.substr(0,4) == "set ") {
			response += "\n\n      CURRENTLY EDITING ROOM DESCRIPTION\n---------------------------------------------";
		    try {
		        int selectedLineNumber = boost::lexical_cast<int>(message.substr(4,1));

			    if(selectedLineNumber < 0 || (unsigned)selectedLineNumber >= description.size()) {
			    	response += "\n\n      Could not find line number " + message.substr(4,1) + ", set failed";
			    } else {
			    	std::string desc = "";
			    	if( message.size() >= 6) {
			    		desc = message.substr(6);
			    	}

				    description[selectedLineNumber] = desc;
				    currentRoom->setDescription(description);
					response += std::string("\n\n      Line ") + message.substr(4,1) +
					" description set to " + desc + "'.";
				}
			} catch (boost::bad_lexical_cast) {
		        response += "\n\n      Please enter a valid line number";
		    }
		} else if(message == "back") {
			response += "\n\n      CURRENTLY EDITING ROOM\n---------------------------------------------";
			player->playerCharacter.setStatus("EditCurrentRoom");
			response += printEditCurrentRoomWindow(description, doors, currentRoom->getRoomId(), resets, resetsInRoomPosition) + "\n   ";
			message = "";
			return response;
		} else {
			response += "\n\n      CURRENTLY EDITING ROOM DESCRIPTION\n---------------------------------------------";
		}

		message = "";
		response += printEditRoomDescriptionWindow(description);
		return response;
	}




	if(player->playerCharacter.getStatus() == "EditRoomDoors") {
		if(message.substr(0,4) == "add ") {
			response += "\n\n      CURRENTLY EDITING ROOM DOORS\n---------------------------------------------";
			try {
				if(message.find("-d") == std::string::npos) {
					response += "\n\n      Invalid Format.";
				} else {
					message = message.substr(4);

					std::vector <std::string> addDoorMessage;
					boost::iter_split(addDoorMessage,message, boost::first_finder("-d"));

				    boost::trim_if(addDoorMessage[0], boost::is_any_of("\t "));
				    boost::trim_if(addDoorMessage[1], boost::is_any_of("\t "));

				    std::vector <std::string> doorDirAndDestinationId;
				    boost::split(doorDirAndDestinationId, addDoorMessage[0], boost::is_any_of("\t "), boost::token_compress_on);
				    std::vector <std::string> doorDescription{addDoorMessage[1]};

				    if(doorDirAndDestinationId.size() != 2) {
				    	response += "\n\n      Invalid Format." + addDoorMessage[0] + " " + addDoorMessage[1];
				    }
				    else {
				    	int selectedRoomId = boost::lexical_cast<int>(doorDirAndDestinationId[1]);

					    if(rooms->find(selectedRoomId) == rooms->end()) {
				    		response += "\n\n      Could not find room id " + doorDirAndDestinationId[1] + ", add door failed";
					    } else {
						    Door temp = Door{doorDirAndDestinationId[0], doorDescription, selectedRoomId};
							currentRoom->addDoor(temp);
							doors = currentRoom->doors;

							response += "\n\n      Door: '" + temp.getDir() + "' to Room: '" + std::to_string(temp.getDestinationId()) + "' Desc: '" + temp.getDesc() + "' added to room";
						}
				    }
				}
			} catch (boost::bad_lexical_cast) {
				response += "\n\n      Please enter a valid room Id";
			}
		} else if(message.substr(0,7) == "remove ") {
			response += "\n\n      CURRENTLY EDITING ROOM DOORS\n---------------------------------------------";
			try {
		        int selectedLineNumber = boost::lexical_cast<int>(message.substr(7,1));

			    if(selectedLineNumber < 0 || (unsigned)selectedLineNumber >= description.size()) {
		    		response += "\n\n      Could not find line number " + message.substr(7,1) + ", removal failed";
			    } else {
				    Door temp = doors[selectedLineNumber];
					doors.erase(doors.begin()+selectedLineNumber);
					response += "        door: " + temp.getDir() + " to Room: " + std::to_string(temp.getDestinationId()) + "' removed";
					currentRoom->doors = doors;
				}
			} catch (boost::bad_lexical_cast) {
		        response += "\n\n      Please enter a valid line number";
		    }
		} else if(message == "back") {
			response += "\n\n      CURRENTLY EDITING ROOM\n---------------------------------------------";
			player->playerCharacter.setStatus("EditCurrentRoom");
			response += printEditCurrentRoomWindow(description, doors, currentRoom->getRoomId(), resets, resetsInRoomPosition) + "\n   ";
			message = "";
			return response;
		} else {
			response += "\n\n      CURRENTLY EDITING ROOM DOORS\n---------------------------------------------";
		}

		message = "";
		response += printEditRoomDoorsWindow(doors);
		return response;
	}

	std::cout << "G" << std::endl;

	message = "";
	return (*players)[playerId].getUsername() + "> " + "Cannot find " + message + ", no match. \n\n";
}

void Editor::setMessage(const std::string& s) {
	message = s;
}

networking::Connection Editor::getConnection() const {
	return this->connection;
}

int Editor::getId() const {
	return this->connection.playerId;
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

			response += "\n\n" + currentNpc->npcCharacter.getShortDesc() + ":";
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
			response += currentObject->getShortDesc() + ":\n\n";
			for(auto& extraPair : currentObject->getExtra()) {
				for(auto& keyword : extraPair.second) {
					if(lookMessage.find(keyword) != std::string::npos) {
						for(auto& descriptionText : extraPair.first) {
				  			response += descriptionText + "\n";
						}
					}
				}
			}
			response += "\n";
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
					response += "\n";
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
			auto playerInventory = (*players)[playerId].playerCharacter.getInventory();
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
				response += "\n";
				return response;
			}
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

		std::vector <std::string> takeMessage;
	    boost::trim_if(messageText, boost::is_any_of("\t "));
	    boost::split(takeMessage, messageText, boost::is_any_of("\t "), boost::token_compress_on);

		std::string response = "";
		std::string takeString = "take";

		int currentRoomId = (*playerLocations)[playerId];
		Room* currentRoom = &(*rooms)[currentRoomId];

		//add dummy object to room to test
		//currentRoom->addObject((*objects)[std::stoi(messageText)],1); // mithril/axe
		Object* currentObject = currentRoom->findObject(messageText);

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
					int currentObjectId = 0;
					for(auto& object : *objects) {
						for(auto& keyword : object.second.getKeywords()) {
							if(keyword.find(takeMessage[0]) != std::string::npos) {
								(*players)[playerId].playerCharacter.addObjectToInventory(object.second,1);
								break;
							}
						}
					}

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

				player->playerCharacter.addObjectToInventory(*currentObject, 1);
				currentRoom->removeObject(currentObject->getId());
				std::cout << "player inventory: " << player->playerCharacter.getInventoryDesc() << "\n";
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
			equipObjectRet = player->playerCharacter.equipObject(*currentObject, armorFlag);
			int currentArmor = player->playerCharacter.getArmor();
			player->playerCharacter.setArmor(currentArmor + 10); //maybe change this later
			//std::cout << "line 425 commands\n";
		} else if (itemtype == weaponFlag){ // need to change to work with midgaard
			equipObjectRet = player->playerCharacter.equipObject(*currentObject, weaponFlag);
			int currentAttack = player->playerCharacter.getThac0();
			player->playerCharacter.setThac0(currentAttack + 10); //maybe change this later
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
		auto offenseSpells = context.getOffenseSpells();
		auto defenseSpells = context.getDefenseSpells();

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
  			return (*players)[playerId].getUsername()+ "> " + "Inventory:\n" + player.playerCharacter.getInventoryDesc() + "\n\n";
		}else if (lsMessage == "equipment"){
			return (*players)[playerId].getUsername()+ "> " + "Equipment:\n" + player.playerCharacter.getEquipmentDesc() + "\n\n";
  		}else if (lsMessage == "spells"){
  			std::ostringstream offenseResponse;
  			std::ostringstream defenseResponse;
 			offenseResponse << "Offense:\n";
  			int counter = 0;

  			for(auto& offenseObject : (*offenseSpells)){
  				if(counter>2){
  					offenseResponse << "\n";
  					counter = 0;
  				}
  				counter++;
  				offenseResponse << std::setw(20) << std::left << offenseObject.getName();
  			}
  			counter = 0;
  			offenseResponse << "\n\n";
  			defenseResponse << "Defense:\n";
  			for(auto& defenseObject : (*defenseSpells)){
  				if(counter>2){
  					defenseResponse << "\n";
  					counter = 0;
  				}
  				counter++;
  				defenseResponse << std::setw(20) << std::left << defenseObject.getName();
  			}
  			defenseResponse << "\n\n";
  			return (*players)[playerId].getUsername()+ "> " + "Spells:\n" + offenseResponse.str() + defenseResponse.str() + "\n\n";


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
		return (*players)[this->playerId].getUsername()+ "> " + message.substr(3) + "\n";
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
		int currentObjectId = 0;
		if(stealMessage.size() == 2) {
			Npc* currentNpc = currentRoom->findNpc(stealMessage[1]);
			std::cout << stealMessage.size() << std::endl;
			if(currentNpc != NULL) {
				std::cout << "wewwr" << std::endl;
				response += "\n Steal: " + stealMessage[0] + " From: " + stealMessage[1] + "\n\n";
				std::cout << "wsfsdfer" << std::endl;
				//Npc will use a currentNpc->findObjectId(objectTargetPair[0]) method which returns the object ID	of the object in inventory
				//Will change removeObjectfromInventory() to take in the objectID (maybe pass in selected index "eg. steal apple '1'");
				if(currentNpc->npcCharacter.removeObjectFromInventory(stealMessage[0])) {

					for(auto& object : *objects) {
						for(auto& keyword : object.second.getKeywords()) {
							if(stealMessage[0].find(keyword) != std::string::npos) {
								currentObjectId = object.first;
								break;
							}
						}
					}


					player->playerCharacter.addObjectToInventory((*objects)[currentObjectId], 1);
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

	   	//command for testing purposes/no error checking
		(*playerLocations)[playerId] = std::stoi(teleportMessage);

		return (*players)[playerId].getUsername() + "> " + message + "\n\n" + printMiniMap(rooms, std::stoi(teleportMessage)) + (*rooms)[std::stoi(teleportMessage)].getFullRoomDesc() + getPlayersInRoomDesc(players, playerLocations, std::stoi(teleportMessage));
	}

	int TeleportCommand::getId() const {
		return this->connection.playerId;
	}

	networking::Connection TeleportCommand::getConnection() const {
		return this->connection;
	}

	SummonCommand::SummonCommand(networking::Connection connection_, const std::string& message_)
	: connection{connection_}, message{message_} {}

	std::string SummonCommand::execute(Context& context) {
		auto players = context.getPlayers();
		auto playerLocations = context.getPlayerLocations();
		auto rooms = context.getRooms();
		auto objects = context.getObjects();

		int playerId = connection.playerId;

		std::string teleportMessage = message.substr(6);
		std::transform(teleportMessage.begin(), teleportMessage.end(), teleportMessage.begin(), ::tolower);
	    boost::trim_if(teleportMessage, boost::is_any_of("\t "));

	    //command for testing purposes/no error checking
	    int objectId = std::stoi(teleportMessage);

	    if(objects->find(objectId) != objects->end()) {
	    	(*rooms)[(*playerLocations)[playerId]].addObject((*objects)[objectId],1);
	    	return (*players)[playerId].getUsername() + "> " + message + "\n\n" + "success";
	    }

		return (*players)[playerId].getUsername() + "> " + message + "\n\n" + "failed"; //+ printMiniMap(rooms, std::stoi(teleportMessage)) + (*rooms)[std::stoi(teleportMessage)].getFullRoomDesc() + getPlayersInRoomDesc(players, playerLocations, std::stoi(teleportMessage));
	}

	int SummonCommand::getId() const {
		return this->connection.playerId;
	}

	networking::Connection SummonCommand::getConnection() const {
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

namespace MagicCommands{
	//CastCommand
	CastCommand::CastCommand(std::vector<networking::Connection>& clients_,networking::Connection connection_, const std::string& message_)
	: clients{clients_},connection{connection_}, message{message_} {}

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
    	std::string castedSpell = "";
    	int i;
    	for (i = 0; i < castMessage.size()-1; ++i){//castMessage[size] = target
    		castedSpell += castMessage[i] + " ";
    	}
    	std::string targetName = castMessage[i];
    	boost::trim_if(castedSpell, boost::is_any_of("\t "));

		int currentRoomId = (*playerLocations)[playerId];
		Room* currentRoom = &(*rooms)[currentRoomId];
		Spells* castedDefenseSpell = getCastedSpell(castedSpell, (*defenseSpells));
		Spells* castedOffenseSpell = getCastedSpell(castedSpell, (*offenseSpells));
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
			return (*players)[playerId].getUsername() + "> " + "Cannot cast " + castedSpell + ", no match\n\n";
		}

		int targetId = currentRoom->findPlayerId(targetName);
		std::cout << "line 496\n";
		//if findPlayerId can't find the player it will return 0
		//might need to change this
		if(targetId == 0){
			return (*players)[playerId].getUsername() + "> " + "Target " + targetName + " not found\n\n";
		}

		for(networking::Connection client: clients){
			if(client.playerId == targetId){
				this->Targetconnection = client;
			}
		}
		std::cout << "line 496\n";
		auto target = &(*players)[targetId].playerCharacter;
		int currentTargetHealth= target->getCurrentHealth();
		auto player = &(*players)[playerId].playerCharacter;
		int currentPlayerMana = player->getCurrentMana();
		int spellMana = currentSpell->getMana();
		std::cout << "line 496\n";


		if(targetId == playerId && castedOffenseSpell != nullptr){
			return (*players)[playerId].getUsername() + "> " + "Cannot cast " + castMessage[0] + " on yourself!\n\n";
		}

		std::cout << "line 496\n";
		if(currentTargetHealth == 0){
			return (*players)[playerId].getUsername() + "> " + "Target " + targetName + " has already been defeated!\n\n";
		}

		if(!checkMana(spellMana, currentPlayerMana)){
			return (*players)[playerId].getUsername() + "> " + "Not enough mana to cast " + castedSpell + "\n\n";
		}

		player->setCurrentMana(currentPlayerMana - spellMana);
		std::string hitChar = replaceTargetName(currentSpell->getHitChar(), targetName);
		int playerLevel = player->getLevel();
		int currentPlayerExp = player->getExp();
		player->setExp(currentPlayerExp + (playerLevel*2 + 10)); //need leveling up method in player

		this->sourceName=(*players)[playerId].getUsername();
		this->spellName = castedSpell;
		this->spellType = currentSpell->getType();
		if(currentSpell->getType() == "defense"){
			int dmg = (playerLevel*2 + 50);
			this->spellDamage = std::to_string(dmg);
			int finalHealth = currentTargetHealth + dmg;
			if(finalHealth > target->getMaxHealth()){
				finalHealth = target->getMaxHealth();
			}
			target->setCurrentHealth(finalHealth);
		}
		else{
			int dmg = (playerLevel*2 + 50);
			this->spellDamage = std::to_string(dmg);
			int finalHealth = currentTargetHealth - dmg;
			if(finalHealth <= 0){
				finalHealth = 0;
			}
			target->setCurrentHealth(finalHealth);
			//todo: if target dies -- increase xp/lvl up
		}


		return (*players)[playerId].getUsername() + "> " + castedSpell + " has been cast on " + targetName + "\n\t" + hitChar + "\n\n";

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

	//will replace every instance of $N to targetName
	std::string CastCommand::replaceTargetName(std::string hitString, const std::string& targetName){
  		boost::replace_all(hitString, "$N", targetName); // <#include <boost/algorithm/string/replace.hpp>
		return hitString;
	}

	std::string CastCommand::getSourceName() const {
		return this->sourceName;
	}

	std::string CastCommand::getSpellName() const{
		return this->spellName;
	}

	std::string CastCommand::getSpellDamage() const{
		return this->spellDamage;
	}

	std::string CastCommand::getSpellType() const{
		return this->spellType;
	}

	int CastCommand::getId() const {
		return this->connection.playerId;
	}

	int CastCommand::getTargetId() const {
		return this->targetId;
	}

	networking::Connection CastCommand::getConnection() const {
		return this->connection;
	}

	networking::Connection CastCommand::getTargetConnection() const {
		return this->Targetconnection;
	}

	/*ConfuseCommand*/
	ConfuseCommand::ConfuseCommand(std::vector<networking::Connection>& clients_,networking::Connection connection_, const std::string& message_)
	: clients{clients_},connection{connection_}, message{message_} {}
    std::string ConfuseCommand::execute(Context& context) {
        auto players = context.getPlayers();
        auto playerLocations = context.getPlayerLocations();
        auto rooms = context.getRooms();
        auto objects = context.getObjects();
        int playerId = connection.playerId;
				this->sourceName=(*players)[playerId].getUsername();
        std::string confuseMessage = message.substr(7);
        std::transform(confuseMessage.begin(), confuseMessage.end(), confuseMessage.begin(), ::tolower);
        boost::trim_if(confuseMessage, boost::is_any_of("\t "));

				std::vector <std::string> castMessage;
		    	boost::trim_if(confuseMessage, boost::is_any_of("\t "));
		    	boost::split(castMessage, confuseMessage, boost::is_any_of("\t "), boost::token_compress_on);
		    	std::string castedSpell = "";
		    	int i;
		    	for (i = 0; i < castMessage.size()-1; ++i){//castMessage[size] = target
		    		castedSpell += castMessage[i] + " ";
		    	}
		    	std::string targetName = castMessage[i];
		    	boost::trim_if(castedSpell, boost::is_any_of("\t "));

					this->spellName = castedSpell;
					this->spellDamage=" ";
					this->spellType="confuse";


				int currentRoomId = (*playerLocations)[playerId];
        Room* currentRoom = &(*rooms)[currentRoomId];
        //std::string targetName = "";
        int targetId = 0;
        //finding targetID
        for(auto& target : (*players)){
            if((target.second).getUsername() == confuseMessage){
                targetId = target.first;
            }
        }

        if(targetId == 0){
            return (*players)[playerId].getUsername() + "> " + "Cannot confuse " + confuseMessage + ", no match\n\n";
        }

				for(networking::Connection client: clients){
					if(client.playerId == targetId){
						this->Targetconnection = client;
					}
				}

        auto target = &(*players)[targetId];
        auto player = &(*players)[playerId].playerCharacter;


        int spellMana = ( ((*players)[targetId].playerCharacter.getMaxMana()/2) +10);
        int currentPlayerMana = player->getCurrentMana();
        if(!checkMana(spellMana, currentPlayerMana)){
					return (*players)[playerId].getUsername() + "> " + "Not enough mana to cast confuse on " + confuseMessage + "\n\n";
				}

        if(currentRoomId == (*playerLocations)[targetId] ){
            std::cout << "target : " << targetId << "is in room: " << currentRoomId << "\n";
            auto target = &(*players)[targetId];
            target->setIsConfuse(true);
            player->setCurrentMana(currentPlayerMana - spellMana);
            return (*players)[playerId].getUsername() + "> " + "Confuse has been cast on " + confuseMessage + "\n\n";
        }
        else{
            return (*players)[playerId].getUsername() + "> " + "Target " + confuseMessage + "is not in this room!\n\n";
        }
    }

		int ConfuseCommand::getId() const {
        return this->connection.playerId;
    }

    bool ConfuseCommand::checkMana(const int spellMana, const int playerMana){
		if(spellMana <= playerMana){
			return true;
		}
		else{
			return false;
		}
	}


		int ConfuseCommand::getTargetId() const {
			return this->targetId;
		}

    networking::Connection ConfuseCommand::getConnection() const {
        return this->connection;
    }

		networking::Connection ConfuseCommand::getTargetConnection() const {
			return this->Targetconnection;
		}

		std::string ConfuseCommand::getSourceName() const {
			return this->sourceName;
		}

		std::string ConfuseCommand::getSpellName() const{
			return this->spellName;
		}

		std::string ConfuseCommand::getSpellDamage() const{
			return this->spellDamage;
		}

		std::string ConfuseCommand::getSpellType() const{
			return this->spellType;
		}
}
