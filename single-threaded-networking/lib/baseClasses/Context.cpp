#include "Context.h"

Context::Context() {}

Context::Context(std::unordered_map<int,Room>* rooms_, std::unordered_map<int,Npc>* Npcs_, std::unordered_map<int,Object>* objects_, std::unordered_map<int,Player>* players_, std::unordered_map<int,int>* playerLocations_, std::vector<Spells>* offenseSpells_, std::vector<Spells>* defenseSpells_)
:rooms{rooms_},Npcs{Npcs_},objects{objects_},players{players_},playerLocations{playerLocations_},offenseSpells{offenseSpells_},defenseSpells{defenseSpells_} {}

std::unordered_map<int,Room>* Context::getRooms() {
	return this->rooms;
}

std::unordered_map<int,Npc>* Context::getNpcs() {
	return this->Npcs;
}

std::unordered_map<int,Object>* Context::getObjects() {
	return this->objects;
}

std::unordered_map<int,Player>* Context::getPlayers() {
	return this->players;
}

std::unordered_map<int,int>* Context::getPlayerLocations() {
	return this->playerLocations;
}

void Context::setCurrentlySelectedNpc(Npc* npc) {
	this->currentlySelectedNpc = npc;
}

Npc* Context::getCurrentlySelectedNpc() {
	return this->currentlySelectedNpc;
}

std::vector<Spells>* Context::getOffenseSpells() {
	return this->offenseSpells;
}

std::vector<Spells>* Context::getDefenseSpells() {
	return this->defenseSpells;
}