#ifndef NPC_CPP
#define NPC_CPP

#include "Npc.h"

//Npc Constructor
Npc::Npc():
	shortdesc{""} {};

Npc::Npc (std::string const shortdesc):
	shortdesc{shortdesc} {};

std::string Npc::getShortDesc() const {
	return shortdesc;
}
void Npc::setShortDesc(const std::string& shortdesc) {
	this->shortdesc = shortdesc;
}

//--------------------------------------Lawrence Yu
void Npc::addObjectToInventory(const Object& object, unsigned int limit) {
  if(npcInventory[object.getId()].size() == limit) {
  	//std::cout << "object id: " << object.getId()<< "size: " << npcInventory[object.getId()].size() << std::endl;
  } else {
    npcInventory[object.getId()].push_back(object);
          //std::cout << "Object id: " << object.getId() << " Npc id: " << id << " Inventory size: " << npcInventory.size() <<std::endl;
  }
}

bool Npc::removeObjectFromInventory(const std::string& objectName) {
  int objectId = 0;

  for(auto& objectIdVectorPair : npcInventory) {
    for(auto& keyword : objectIdVectorPair.second[0].getKeywords()) {
      if(objectName.find(keyword) != std::string::npos) {
        objectId = objectIdVectorPair.first;
        //change to begin()+ selected npc number later
        //if(objectIdVectorPair.second.size() >= selectednpcnumber) {
          npcInventory[objectId].erase(objectIdVectorPair.second.begin());
        //}
          std::cout << "objeect id: " << objectId << "size: " << npcInventory[objectId].size() << std::endl;
        if(npcInventory[objectId].empty()) {
          npcInventory.erase(objectId);
        }
        return true;
      }
    }
  }
  return false;
}

bool Npc::equipObject(const Object& object, int slot) {
  if(npcInventory.find(object.getId()) == npcInventory.end()) {
  	return false;
  }

  if(npcEquipment.find(slot) != npcEquipment.end()) {
    npcInventory[npcEquipment[slot].getId()].push_back(npcEquipment[slot]);
    npcEquipment[slot] = object;
    npcInventory[object.getId()].pop_back();
    //std::cout << "objz: " << object.getId() << std::endl;
    return true;
  } else {
    npcEquipment[slot] = object;
	//std::cout << "IW" << std::endl;

    npcInventory[object.getId()].pop_back();
    if(npcInventory[object.getId()].empty()) {
    	npcInventory.erase(object.getId());
    }

    //std::cout << "IWOEFJ|" << std::endl;
    return true;
          // std::cout << this << "Object id: " << npcEquipment[slot].getId() << " Npc id: " << id << " Equipment Desc: " << npcEquipment[slot].getShortDesc() << " Equipment size: " << npcEquipment.size() <<std::endl;
  }
}
bool Npc::unEquipObject(int slot) {
  //remove if id == object and pickedupflag==yes
  if(npcEquipment.find(slot) != npcEquipment.end()) {
  	npcEquipment.erase(slot);
  	return true;
  }
  return false;
}

std::unordered_map<int,std::vector<Object>> Npc::getInventory() const {
  return this->npcInventory;
}

std::unordered_map<int,Object> Npc::getEquipment() const {
  return this->npcEquipment;
}

std::string Npc::getEquipmentDesc() const {
  std::string response = "";
  for_each(npcEquipment.begin(), npcEquipment.end(), [&response](const auto& currentEquip){response += currentEquip.second.getShortDesc() + ", ";});
    std::cout << "npe equip: " << npcEquipment.size() << std::endl;	
  return response;
}
std::string Npc::getInventoryDesc() const {
	std::string response = "";
	  std::cout << "npe inv: " << npcInventory.size() << std::endl;
	std::for_each(npcInventory.begin(), npcInventory.end(), [&response](const auto& currentItem){response += currentItem.second[0].getShortDesc() + " (Quantity: " + std::to_string(currentItem.second.size()) + "), ";});	
  return response;
}

//THE FORMULAS NEED TO BE CHANGED (COPIED FROM PLAYER)
int Npc::newHealth(const int lvl){
    return DEFAULT_NPC_HEALTH+lvl*lvl*2;
}

int Npc::newMana(const int lvl){
    return 95+lvl*lvl*1.5;
}

#endif