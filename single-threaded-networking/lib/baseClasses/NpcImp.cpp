// NpcImp.cpp
#include "NpcImp.h"

// Constructor
NpcImp::NpcImp():
CharacterImp(0) {};

NpcImp::NpcImp(int const id):
CharacterImp(id) {};

void NpcImp::attack() {
	std::cout << "Npc attacking.. " << std::endl;
}