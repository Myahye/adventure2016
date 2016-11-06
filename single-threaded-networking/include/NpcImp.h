// NpcImp.h
#ifndef NPC_IMP_H
#define NPC_IMP_H

#include <iostream>
#include <vector>
#include <string>
// #include "Object.h"
#include <unordered_map>
#include <algorithm>

#include "CharacterImp.h"

class NpcImp : public CharacterImp {
protected:

public:
	// Constructor
	NpcImp();
	NpcImp(int const id);

	void attack();

};

#endif