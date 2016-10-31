#include "Npc.h"

//Npc Constructor
Npc::Npc():
id{0}, shortdesc{""} {};

Npc::Npc (int const id, std::string const shortdesc):
	id{id}, shortdesc{shortdesc} {};

//Getter and Setter for Armor
int Npc::getArmor() const {
	return armor;
}
void Npc::setArmor(int const armor) {
	this->armor = armor;
}

//Getter and Setter for	Damage
std::string Npc::getDamage() const {
	return damage;
}
void Npc::setDamage(const std::string& damage) {
	this->damage = damage;
}

//Getter and Setter for	Description
std::string Npc::getDesc() const {
	std::string descString = "";
	for_each(description.begin(), description.end(), [&descString](const std::string& i){descString += i + "\n";} );	
	return descString;
}
void Npc::setDesc(const std::vector<std::string>& description) {
	this->description = description;
}


//Getter and Setter for Exp
int Npc::getExp() const {
	return exp;
}
void Npc::setExp(int const exp) {
	this->exp = exp;
}

//Getter and Setter for Gold
int Npc::getGold() const {
	return gold;
}
void Npc::setGold(int const gold) {
	this->gold = gold;
}

//Getter and Setter for Hit
std::string Npc::getHit() const {
	return hit;
}
void Npc::setHit(const std::string& hit) {
	this->hit = hit;
}

//Getter and Setter for Id
int Npc::getId() const {
	return id;
}
void Npc::setId(int const id) {
	this->id = id;
}

//Getter and Setter for Keywords
std::vector<std::string> Npc::getKeywords() const {
	return keywords;
}
void Npc::setKeywords(const std::vector<std::string>& keywords) {
	this->keywords = keywords;
}


//Getter and Setter for Level
int Npc::getLevel() const {
	return level;
}
void Npc::setLevel(int const level) {
	this->level = level;
}

//Getter and Setter for Longdesc
std::string Npc::getLongDesc() const {
	std::string descString = "";
	std::for_each(longdesc.begin(), longdesc.end(), [&descString](const std::string& i){descString += i + "\n";} );	
	return descString;
}
void Npc::setLongDesc(const std::vector<std::string>& longdesc) {
	this->longdesc = longdesc;
}

//Getter and Setter for Shordesc
std::string Npc::getShortDesc() const {
	return shortdesc;
}
void Npc::setShortDesc(const std::string& shortdesc) {
	this->shortdesc = shortdesc;
}

//Getter and Setter for Thac0
int Npc::getThac0() const {
	return thac0;
}
void Npc::setThac0(int const thac0) {
	this->thac0 = thac0;
}

//--------------------------------------Lawrence Yu
void Npc::addObjectToInventory(const Object& object, unsigned int limit) {
  if(npcInventory[object.getId()].size() == limit) {
    return;
  } else {
    npcInventory[object.getId()].push_back(object);
          //std::cout << "Object id: " << object.getId() << " Npc id: " << id << " Inventory size: " << npcInventory.size() <<std::endl;
  }
}
bool Npc::removeObjectFromInventory(int objectId) {
  if(npcInventory[objectId].size() != 0) {
    npcInventory[objectId].pop_back();
    return true;
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
    return true;
  } else {
    npcEquipment[slot] = object;
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


