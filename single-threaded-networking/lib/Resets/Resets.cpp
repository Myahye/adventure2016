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
    		Character npc = (*npcs)[this->id];
    		// Npc npcClone = clone(npc); 
    		auto it1 = rooms->find(this->room);
	  		if(it1 != rooms->end()) {
	  			//this->printClass(1);
    			currentlySelectedNpc = (*rooms)[this->room].addNpc(npc, this->limit);
    			//std::cout << npc.getId() << std:: endl;
    			if(currentlySelectedNpc == NULL) {
    				//std::cout << "ff" << currentlySelectedNpc->getId() << std:: endl;
    				currentlySelectedNpc = NULL;
    			}
    		}
  		}
	}
	//Get currentlySelectedNpc
	Character* ResetNpc::getCurrentlySelectedNpc() {
		return this->currentlySelectedNpc;
	}

	//New function added in to test
	void ResetNpc::printClass(int n) {
		std::cout << "\n\n";
		std::cout << "Reset: "<< n << "\n";
		std::cout << "ID: " << id << std::endl;
		std::cout << "\taction: " << action << std::endl;
		std::cout << "\tcomment: " << comment << std::endl;
		std::cout << "\tid: " << id << std::endl;
		std::cout << "\tlimit: " << limit << std::endl;
		std::cout << "\troom: " << room << std::endl;
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
	Character* ResetObject::getCurrentlySelectedNpc() {
		return this->currentlySelectedNpc;
	}

	//New function added in to test
	void ResetObject::printClass(int n) {
		std::cout << "\n\n";
		std::cout << "Reset: "<< n << "\n";
		std::cout << "ID: " << id << std::endl;
		std::cout << "\taction: " << action << std::endl;
		std::cout << "\tcomment: " << comment << std::endl;
		std::cout << "\tid: " << id << std::endl;
		std::cout << "\tlimit: " << limit << std::endl;
		std::cout << "\troom: " << room << std::endl;
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
			// 	std::cout << currentlySelectedNpc->getId() << std::endl;
			// }
			auto objects = context.getObjects();

	  		auto it = objects->find(this->id);
		  	if(it != objects->end()) {
	    		Object object = (*objects)[this->id];
	    		// object npcClone = clone(npc); 
	    		currentlySelectedNpc->getCharacterType().addObjectToInventory(object, this->limit);
	  		}
  		}
	}

	//New function added in to test
	void ResetGive::printClass(int n) {
		std::cout << "\n\n";
		std::cout << "Reset: "<< n << "\n";
		std::cout << "ID: " << id << std::endl;
		std::cout << "\taction: " << action << std::endl;
		std::cout << "\tcomment: " << comment << std::endl;
		std::cout << "\tid: " << id << std::endl;
		std::cout << "\tlimit: " << limit << std::endl;
		std::cout << "\troom: " << room << std::endl;
	}
	//Get currentlySelectedNpc
	Character* ResetGive::getCurrentlySelectedNpc() {
		return this->currentlySelectedNpc;
	}

//-----------------------------------------ResetEquip

	//Reset Constructor
	ResetEquip::ResetEquip(const std::string& action, int const id, int const slot, const std::string& comment)
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
	    		if (currentlySelectedNpc->getId() > 0) {
		    		if(currentlySelectedNpc->getCharacterType().getEquipment().find(this->slot) == currentlySelectedNpc->getCharacterType().getEquipment().end()) {
		    			//this->printClass(1);
		    			currentlySelectedNpc->getCharacterType().addObjectToInventory(object,1);
		    			currentlySelectedNpc->getCharacterType().equipObject(object, this->slot);
		    		}
	    		}
	  		}
  		}
	}

	//New function added in to test
	void ResetEquip::printClass(int n) {
		std::cout << "\n\n";
		std::cout << "Reset: "<< n << "\n";
		std::cout << "ID: " << id << std::endl;
		std::cout << "\taction: " << action << std::endl;
		std::cout << "\tcomment: " << comment << std::endl;
		std::cout << "\tid: " << id << std::endl;
		std::cout << "\tslot: " << slot<< std::endl;
	}
	//Get currentlySelectedNpc
	Character* ResetEquip::getCurrentlySelectedNpc() {
		return this->currentlySelectedNpc;
	}


	///ADD DOOR RESET

}

#endif