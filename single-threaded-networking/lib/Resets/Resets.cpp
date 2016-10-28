#ifndef RESET_CPP
#define RESET_CPP

#include "Resets.h"

namespace Resets {

//-----------------------------------------ResetNPC

	//Reset Constructor
	ResetNPC::ResetNPC(const std::string& action, int const id, int const limit, int const room, const std::string& comment)
		: action{action}, id{id}, limit{limit}, room{room}, comment{comment} {};
	//Execute
	void ResetNPC::execute(Context& context) {
		auto npcs = context.getNPCs();
		auto rooms = context.getRooms();

  		auto it = npcs->find(this->id);
	  	if(it != npcs->end()) {
    		NPC npc = (*npcs)[this->id];
    		// NPC npcClone = clone(npc); 
    		auto it1 = rooms->find(this->id);
	  		if(it1 != rooms->end()) {
    			currentlySelectedNPC = (*rooms)[this->room].addNPC(npc, this->limit);
    		}
  		}
	}
	//New function added in to test
	void ResetNPC::printClass(int n) {
		std::cout << "\n\n";
		std::cout << "Reset: "<< n << "\n";
		std::cout << "ID: " << id << std::endl;
		std::cout << "\taction: " << action << std::endl;
		std::cout << "\tcomment: " << comment << std::endl;
		std::cout << "\tid: " << id << std::endl;
		std::cout << "\tlimit: " << limit << std::endl;
		std::cout << "\troom: " << room << std::endl;
	}
	//Get currentlySelectedNPC
	NPC* ResetNPC::getCurrentlySelectedNPC() {
		return this->currentlySelectedNPC;
	}

//-----------------------------------------ResetObject

	//Reset Constructor
	ResetObject::ResetObject(const std::string& action, int const id, int const limit, int const room, const std::string& comment)
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
	//Get currentlySelectedNPC
	NPC* ResetObject::getCurrentlySelectedNPC() {
		return this->currentlySelectedNPC;
	}

//-----------------------------------------ResetGive

	//Reset Constructor
	ResetGive::ResetGive(const std::string& action, int const id, int const limit, int const room, const std::string& comment)
		: action{action}, id{id}, limit{limit}, room{room}, comment{comment} {};
	//Execute
	void ResetGive::execute(Context& context) {
		if(context.getCurrentlySelectedNPC() != NULL) {
			currentlySelectedNPC = context.getCurrentlySelectedNPC();
			auto objects = context.getObjects();

	  		auto it = objects->find(this->id);
		  	if(it != objects->end()) {
	    		Object object = (*objects)[this->id];
	    		// object npcClone = clone(npc); 
	    		currentlySelectedNPC->addObjectToInventory(object, this->limit);
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
	//Get currentlySelectedNPC
	NPC* ResetGive::getCurrentlySelectedNPC() {
		return this->currentlySelectedNPC;
	}

//-----------------------------------------ResetEquip

}

#endif