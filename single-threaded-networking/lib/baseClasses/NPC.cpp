#include "NPC.h"

//NPC Constructor
NPC::NPC():
id{0}, shortdesc{""} {};

NPC::NPC (int const id, std::string const shortdesc):
	id{id}, shortdesc{shortdesc} {};

//Getter and Setter for Armor
int NPC::getArmor() const {
	return armor;
}
void NPC::setArmor(int const armor) {
	this->armor = armor;
}

//Getter and Setter for	Damage
std::string NPC::getDamage() const {
	return damage;
}
void NPC::setDamage(const std::string& damage) {
	this->damage = damage;
}

//Getter and Setter for	Description
std::string NPC::getDesc() const {
	std::string descString = "";
	for_each(description.begin(), description.end(), [&descString](const std::string& i){descString += i + "\n";} );	
	return descString;
}
void NPC::setDesc(const std::vector<std::string>& description) {
	this->description = description;
}


//Getter and Setter for Exp
int NPC::getExp() const {
	return exp;
}
void NPC::setExp(int const exp) {
	this->exp = exp;
}

//Getter and Setter for Gold
int NPC::getGold() const {
	return gold;
}
void NPC::setGold(int const gold) {
	this->gold = gold;
}

//Getter and Setter for Hit
std::string NPC::getHit() const {
	return hit;
}
void NPC::setHit(const std::string& hit) {
	this->hit = hit;
}

//Getter and Setter for Id
int NPC::getId() const {
	return id;
}
void NPC::setId(int const id) {
	this->id = id;
}

//Getter and Setter for Keywords
std::vector<std::string> NPC::getKeywords() const {
	return keywords;
}
void NPC::setKeywords(const std::vector<std::string>& keywords) {
	this->keywords = keywords;
}


//Getter and Setter for Level
int NPC::getLevel() const {
	return level;
}
void NPC::setLevel(int const level) {
	this->level = level;
}

//Getter and Setter for Longdesc
std::string NPC::getLongDesc() const {
	std::string descString = "";
	std::for_each(longdesc.begin(), longdesc.end(), [&descString](const std::string& i){descString += i + "\n";} );	
	return descString;
}
void NPC::setLongDesc(const std::vector<std::string>& longdesc) {
	this->longdesc = longdesc;
}

//Getter and Setter for Shordesc
std::string NPC::getShortDesc() const {
	return shortdesc;
}
void NPC::setShortDesc(const std::string& shortdesc) {
	this->shortdesc = shortdesc;
}

//Getter and Setter for Thac0
int NPC::getThac0() const {
	return thac0;
}
void NPC::setThac0(int const thac0) {
	this->thac0 = thac0;
}

//--------------------------------------Lawrence Yu
void NPC::addObjectToInventory(const Object& object, int limit) {
  if(npcInventory[object.getId()].size() == limit) {
    return;
  } else {
    npcInventory[object.getId()].push_back(object);
          //std::cout << "Object id: " << object.getId() << " NPC id: " << id << " Inventory size: " << npcInventory.size() <<std::endl;
  }
}
void NPC::removeObjectFromInventory(int objectId) {
  // //remove if id == object and pickedupflag==yes
  // npcInventory.erase(
  //   std::remove_if(npcInventory.begin(), npcInventory.end(),
  //       [objectId](Object& object) { return (object.getId() == objectId); }),
  //   npcInventory.end());
}

void NPC::equipObject(const Object& object, int slot) {
  if(npcEquipment.find(slot) != npcEquipment.end()) {
    return;
  } else {
    npcEquipment[slot] = object;
          std::cout << this << "Object id: " << npcEquipment[slot].getId() << " NPC id: " << id << " Equipment Desc: " << npcEquipment[slot].getShortDesc() << " Equipment size: " << npcEquipment.size() <<std::endl;
  }
}
void NPC::unEquipObject(int objectId) {
  //remove if id == object and pickedupflag==yes
  npcEquipment.erase(objectId);
}

std::unordered_map<int,std::vector<Object>> NPC::getNpcInventory() const {
  return this->npcInventory;
}

std::unordered_map<int,Object> NPC::getNpcEquipment() const {
  return this->npcEquipment;
}

std::string NPC::getNpcEquipmentDesc() const {
  std::string response = "";
  for_each(npcEquipment.begin(), npcEquipment.end(), [&response](const auto& currentEquip){response += currentEquip.second.getShortDesc() + ", ";});	
  return response;
}
std::string NPC::getNpcInventoryDesc() const {
	std::string response = "";
	std::for_each(npcInventory.begin(), npcInventory.end(), [&response](const auto& currentItem){response += currentItem.second[0].getShortDesc() + " (Quantity: " + std::to_string(currentItem.second.size()) + "), ";});	
  return response;
}


