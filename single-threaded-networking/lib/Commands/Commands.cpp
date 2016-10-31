#include "Commands.h"

namespace Commands {

	LookCommand::LookCommand(int playerId_, const std::string& message_, int roomId_)
	: playerId{playerId_}, message{message_}, roomId{roomId_} {}

	std::string LookCommand::execute(Context& context) {
		// std::string response = this->players[playerId].getUsername() + "> " + command;
		// std::string message = command.substr(5);
		// std::transform(message.begin(), message.end(), message.begin(), ::tolower);

		// int currentRoomId = this->playerLocation[playerId];

		// if(message == "room") {
		// 	return response + getCurrentRoomDescription(playerId);
		// }

		// //-------------------------------------------------look "cardinal direction"

		// //will move this to room class later as if isDirection return door.getDesc()
		// auto doorsInRoom = this->rooms[currentRoomId].getDoors();

		// for(auto currentDoor : doorsInRoom) {
		// 	if(message == currentDoor.getDir()) {
		//   		response += "\n\n" + currentDoor.getDesc() += "\n";

		//   		return response;
		// 	}
		// }

		// //-------------------------------------------------look "Npc keyword"

		// //will move this to room class later as if isNpc return npc.getfulldesc()
		// auto npcsInRoom = this->rooms[currentRoomId].getNpcsInRoom();
		// for(auto currentNpc : npcsInRoom) {
		// 	if(checkNpcKeywords(message, currentNpc)) {

		//   		//change for look toddler 1 look toddler 2 look toddler 3 later since it only checks the description of the first duplicate npc?
		//   		response += "\n\n" + currentNpc.second[0].getDesc();
		//   		response += "\n     Wearing: "  + currentNpc.second[0].getNpcEquipmentDesc();
		//   		response += "\n     Carrying: " + currentNpc.second[0].getNpcInventoryDesc() + "\n\n";

		//   		return response;
		// 	}
		// }

		// //-------------------------------------------------look "Object keyword"

		// //will move this to room class later as if isobject return object.getfulldesc()
		// for(auto objectIdVectorPair : this->rooms[currentRoomId].getObjectsInRoom()) {
		// 	if(checkObjectKeywords(message, objectIdVectorPair)) {
		// 		response += "\n";
		//   		//change for look object 1 look object 2 look object 3 later since it only checks the description of the first duplicate object?
		//   		for(auto descriptionText : objectIdVectorPair.second[0].getExtra().first) {
		//     		response += descriptionText + "\n";
		//   		}
		//   		return response;
		// 	}
		// }

		// return this->players[playerId].getUsername() + "> " + "Cannot find " + message + ", no match. \n\n";
	}

	GoCommand::GoCommand(int playerId_, const std::string& message_, int roomId_) {

	}

}