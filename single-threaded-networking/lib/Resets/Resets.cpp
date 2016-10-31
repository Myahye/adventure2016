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
    		auto it1 = rooms->find(this->id);
	  		if(it1 != rooms->end()) {
    			currentlySelectedNpc = (*rooms)[this->room].addNpc(npc, this->limit);
    		}
  		}
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
	//Get currentlySelectedNpc
	Npc* ResetNpc::getCurrentlySelectedNpc() {
		return this->currentlySelectedNpc;
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
    		auto it1 = rooms->find(this->id);
	  		if(it1 != rooms->end()) {
    			(*rooms)[this->room].addObject(object, this->limit);
    		}
  		}
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
	//Get currentlySelectedNpc
	Npc* ResetObject::getCurrentlySelectedNpc() {
		return this->currentlySelectedNpc;
	}

//-----------------------------------------ResetGive

	//Reset Constructor
	ResetGive::ResetGive(const std::string& action, int const id, unsigned int const limit, int const room, const std::string& comment)
		: action{action}, id{id}, limit{limit}, room{room}, comment{comment} {};
	//Execute
	void ResetGive::execute(Context& context) {
		if(context.getCurrentlySelectedNpc() != NULL) {
			currentlySelectedNpc = context.getCurrentlySelectedNpc();
			auto objects = context.getObjects();

	  		auto it = objects->find(this->id);
		  	if(it != objects->end()) {
	    		Object object = (*objects)[this->id];
	    		// object npcClone = clone(npc); 
	    		currentlySelectedNpc->addObjectToInventory(object, this->limit);
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
	Npc* ResetGive::getCurrentlySelectedNpc() {
		return this->currentlySelectedNpc;
	}

//-----------------------------------------ResetEquip

	//Reset Constructor
	ResetEquip::ResetEquip(const std::string& action, int const id, int const slot, const std::string& comment)
		: action{action}, id{id}, slot{slot}, comment{comment} {};
	//Execute
	void ResetEquip::execute(Context& context) {
		if(context.getCurrentlySelectedNpc() != NULL) {
			currentlySelectedNpc = context.getCurrentlySelectedNpc();
			auto objects = context.getObjects();

	  		auto it = objects->find(this->id);
		  	if(it != objects->end()) {
	    		Object object = (*objects)[this->id];
	    		// object npcClone = clone(npc); 
	    		if(currentlySelectedNpc->getNpcEquipment().find(slot) == currentlySelectedNpc->getNpcEquipment().end()) {
	    			currentlySelectedNpc->addObjectToInventory(object,1);
	    			currentlySelectedNpc->equipObject(object, this->slot);
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
	Npc* ResetEquip::getCurrentlySelectedNpc() {
		return this->currentlySelectedNpc;
	}

}

#endif