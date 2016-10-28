#include "Context.h"

Context::Context() {}

Context::Context(std::unordered_map<int,Room>* rooms_, std::unordered_map<int,NPC>* NPCs_, std::unordered_map<int,Object>* objects_)
:rooms{rooms_},NPCs{NPCs_},objects{objects_} {}

std::unordered_map<int,Room>* Context::getRooms() {
	return this->rooms;
}

std::unordered_map<int,NPC>* Context::getNPCs() {
	return this->NPCs;
}

std::unordered_map<int,Object>* Context::getObjects() {
	return this->objects;
}

void Context::setCurrentlySelectedNPC(NPC* npc) {
	this->currentlySelectedNPC = npc;
}

NPC* Context::getCurrentlySelectedNPC() {
	return this->currentlySelectedNPC;
}