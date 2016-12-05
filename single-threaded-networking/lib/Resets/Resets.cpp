#ifndef RESET_CPP
#define RESET_CPP

#include "Resets.h"

namespace Resets {

//-----------------------------------------ResetNpc
	//Reset Constructor
	ResetNpc::ResetNpc(const std::string& action, int const id, unsigned int const limit, int const room, const std::string& comment)
		: action{action}, id{id}, limit{limit}, room{room}, comment{comment} {};
	//Execute
	void ResetNpc::execute(Context& context) {
		auto npcs = context.getNpcs();
		auto rooms = context.getRooms();

  		auto it = npcs->find(this->id);
	  	if(it != npcs->end()) {
    		Npc npc = (*npcs)[this->id];
    		// Npc npcClone = clone(npc); 
    		auto it1 = rooms->find(this->room);
	  		if(it1 != rooms->end()) {
	  			//this->printClass(1);
    			currentlySelectedNpc = (*rooms)[this->room].addNpc(npc, this->limit);
    			//std::cout << npc.getId() << std:: endl;
    			if(currentlySelectedNpc == NULL) {
    				//std::cout << "ff" << currentlySelectedNpc->npcCharacter.getId() << std:: endl;
    				currentlySelectedNpc = NULL;
    			}
    		}
  		}
	}
	//Get currentlySelectedNpc
	Npc* ResetNpc::getCurrentlySelectedNpc() {
		return this->currentlySelectedNpc;
	}

	//New function added in to test
	std::string ResetNpc::printClass() {
		return std::string("Reset ") + action + " " + std::to_string(id)  + " to Room: " + std::to_string(room) + ", limit: " + std::to_string(limit) + " comment: " + comment + "\n";
	}

	int ResetNpc::getRoom() {
		return room;
	}

//-----------------------------------------ResetObject

	//Reset Constructor
	ResetObject::ResetObject(const std::string& action, int const id, unsigned int const limit, int const room, const std::string& comment)
		: action{action}, id{id}, limit{limit}, room{room}, comment{comment} {};
	//Execute
	void ResetObject::execute(Context& context) {
		auto objects = context.getObjects();
		auto rooms = context.getRooms();

  		auto it = objects->find(this->id);
	  	if(it != objects->end()) {
    		Object object = (*objects)[this->id];
    		// objects npcClone = clone(npc); 
    		auto it1 = rooms->find(this->room);
	  		if(it1 != rooms->end()) {
    			(*rooms)[this->room].addObject(object, this->limit);
    		}
  		}
	}

	//Get currentlySelectedNpc
	Npc* ResetObject::getCurrentlySelectedNpc() {
		return this->currentlySelectedNpc;
	}

	//New function added in to test
	std::string ResetObject::printClass() {
		return std::string("Reset ") + action + " " + std::to_string(id)  + " to Room: " + std::to_string(room) + ", limit: " + std::to_string(limit) + " comment: " + comment + "\n";
	}

	int ResetObject::getRoom() {
		return room;
	}

//-----------------------------------------ResetGive

	//Reset Constructor
	ResetGive::ResetGive(const std::string& action, int const id, unsigned int const limit, int const room, const std::string& comment)
		: action{action}, id{id}, limit{limit}, room{room}, comment{comment} {};
	//Execute
	void ResetGive::execute(Context& context) {
		  		currentlySelectedNpc = NULL;
		// if(id == 3000) {
		// 	printClass(1);
		// }
		if(context.getCurrentlySelectedNpc() != NULL) {
			currentlySelectedNpc = context.getCurrentlySelectedNpc();
			// if(id == 3000) {
			// 	std::cout << currentlySelectedNpc->npcCharacter.getId() << std::endl;
			// }
			auto objects = context.getObjects();

	  		auto it = objects->find(this->id);
		  	if(it != objects->end()) {
	    		Object object = (*objects)[this->id];
	    		// object npcClone = clone(npc); 
	    		currentlySelectedNpc->npcCharacter.addObjectToInventory(object, this->limit);
	  		}
  		}
	}

	//New function added in to test
	std::string ResetGive::printClass() {
		return "";
	}
	//Get currentlySelectedNpc
	Npc* ResetGive::getCurrentlySelectedNpc() {
		return this->currentlySelectedNpc;
	}

	int ResetGive::getRoom() {
		return room;
	}

//-----------------------------------------ResetEquip

	//Reset Constructor
	ResetEquip::ResetEquip(const std::string& action, int const id, const std::string& slot, const std::string& comment)
		: action{action}, id{id}, slot{slot}, comment{comment} {};
	//Execute
	void ResetEquip::execute(Context& context) {
		currentlySelectedNpc = NULL;
		if(context.getCurrentlySelectedNpc() != NULL) {
			currentlySelectedNpc = context.getCurrentlySelectedNpc();
			auto objects = context.getObjects();

	  		auto it = objects->find(this->id);
		  	if(it != objects->end()) {
	    		Object object = (*objects)[this->id];
	    		// object npcClone = clone(npc); 
	    		//std::cout << "E: " << currentlySelectedNpc->getId() << std::endl;
	    		if (currentlySelectedNpc->npcCharacter.getId() > 0) {
		    		if(currentlySelectedNpc->npcCharacter.getEquipment().find(this->slot) == currentlySelectedNpc->npcCharacter.getEquipment().end()) {
		    			//this->printClass(1);
		    			currentlySelectedNpc->npcCharacter.addObjectToInventory(object,1);
		    			currentlySelectedNpc->npcCharacter.equipObject(object, this->slot);
		    		}
	    		}
	  		}
  		}
	}

	//New function added in to test
	std::string ResetEquip::printClass() {
		return "";
	}
	//Get currentlySelectedNpc
	Npc* ResetEquip::getCurrentlySelectedNpc() {
		return this->currentlySelectedNpc;
	}

	int ResetEquip::getRoom() {
		return -1;
	}


	///ADD DOOR RESET

}

#endif