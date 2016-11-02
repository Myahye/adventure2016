#include "NPC.h"

NPC::NPC() {
	setId(0);
}

NPC::NPC(int const id, const std::string& shortdesc) {
	setId(id);
	setShortdesc(shortdesc);
}

std::string NPC::getShortdesc() {
	return shortdesc;
}

void NPC::setShortdesc(const std::string& shortdesc) {
	this->shortdesc = shortdesc;
}

/* Lawrence Yu -----------------------------------------------------
void Npc::addObjectToInventory(const Object& object, unsigned int limit) {
  if(npcInventory[object.getId()].size() == limit) {
    return;
  } else {
    npcInventory[object.getId()].push_back(object);
          //std::cout << "Object id: " << object.getId() << " Npc id: " << id << " Inventory size: " << npcInventory.size() <<std::endl;
  }
}
void Npc::removeObjectFromInventory(int objectId) {
  // //remove if id == object and pickedupflag==yes
  // npcInventory.erase(
  //   std::remove_if(npcInventory.begin(), npcInventory.end(),
  //       [objectId](Object& object) { return (object.getId() == objectId); }),
  //   npcInventory.end());
}

void Npc::equipObject(const Object& object, int slot) {
  if(npcEquipment.find(slot) != npcEquipment.end()) {
    return;
  } else {
    npcEquipment[slot] = object;
          // std::cout << this << "Object id: " << npcEquipment[slot].getId() << " Npc id: " << id << " Equipment Desc: " << npcEquipment[slot].getShortDesc() << " Equipment size: " << npcEquipment.size() <<std::endl;
  }
}
void Npc::unEquipObject(int objectId) {
  //remove if id == object and pickedupflag==yes
  npcEquipment.erase(objectId);
}

std::unordered_map<int,std::vector<Object>> Npc::getNpcInventory() const {
  return this->npcInventory;
}

std::unordered_map<int,Object> Npc::getNpcEquipment() const {
  return this->npcEquipment;
}

std::string Npc::getNpcEquipmentDesc() const {
  std::string response = "";
  for_each(npcEquipment.begin(), npcEquipment.end(), [&response](const auto& currentEquip){response += currentEquip.second.getShortDesc() + ", ";});	
  return response;
}
std::string Npc::getNpcInventoryDesc() const {
	std::string response = "";
	std::for_each(npcInventory.begin(), npcInventory.end(), [&response](const auto& currentItem){response += currentItem.second[0].getShortDesc() + " (Quantity: " + std::to_string(currentItem.second.size()) + "), ";});	
  return response;
}
*/