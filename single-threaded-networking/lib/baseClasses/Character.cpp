#ifndef CHARACTER_CPP
#define CHARACTER_CPP

#include "Character.h"

// Constructors:
Character::Character(bool isPlayer){
  setId(0);
  setCharacterType(isPlayer);
}

Character::Character (const int id, bool isPlayer){
  setId(id);
  setCharacterType(isPlayer);
}

bool Character::checkCharacterType(){
  return isPlayer;
}
void Character::setCharacterType(bool isPlayer){
  this->isPlayer = isPlayer;
}

int Character::getArmor() const{
  return armor;
}
void Character::setArmor(const int armor){
  this->armor = armor;
}

int Character::getExp() const{
  return exp;
}
void Character::setExp(const int exp){
  this->exp = exp;
}

int Character::getGold() const{
  return gold;
}
void Character::setGold(const int gold){
  this->gold = gold;
}

int Character::getId() const{
  return id;
}
void Character::setId(const int id){
  this->id = id;
}

int Character::getLevel() const{
  return level;
}
void Character::setLevel(const int level){
  this->level = level;
}

int Character::getMaxHealth() const{
  return maxHealth;
}
void Character::setMaxHealth(const int maxHealth){
  this->maxHealth = maxHealth;
}

int Character::getMaxMana() const{
  return maxMana;
}
void Character::setMaxMana(const int maxMana){
  this->maxMana = maxMana;
}

int Character::getCurrentHealth() const{
  return currentHealth;
}
void Character::setCurrentHealth(const int currentHealth){
  this->currentHealth = currentHealth;
}

int Character::getCurrentMana() const{
  return currentMana;
}
void Character::setCurrentMana(const int currentMana){
  this->currentMana = currentMana;
}

int Character::getThac0() const {
  return thac0;
}
void Character::setThac0(int const thac0) {
  this->thac0 = thac0;
}

std::string Character::getDamage() const{
  return damage;
}
void Character::setDamage(const std::string& damage){
  this->damage = damage;
}

std::string Character::getHit() const{
  return hit;
}
void Character::setHit(const std::string& hit){
  this->hit = hit;
}

std::string Character::getDescription() const{
  std::string descString = "";

  for_each(description.begin(), description.end(), [&descString](const std::string& i){descString += i + "\n";} );
  return descString;
}
std::vector<std::string> Character::getDescriptionV() const{
  return description;
}

void Character::setDescription(const std::vector<std::string>& description){
  this->description = description;
}

std::string Character::getShortDesc() const {
    return shortdesc;
}
void Character::setShortDesc(const std::string& shortdesc) {
    this->shortdesc = shortdesc;
}

std::vector<std::string> Character::getKeywords() const{
  return keywords;
}
void Character::setKeywords(const std::vector<std::string>& keywords){
  this->keywords = keywords;
}

std::string Character::getLongDesc() const{
  std::string descString = "";

  std::for_each(longdesc.begin(), longdesc.end(), [&descString](const std::string& i){descString += i + "\n";} );
  return descString;
}
std::vector<std::string> Character::getLongDescV() const{
  return this->longdesc;
}

void Character::setLongDesc(const std::vector<std::string>& longdesc){
  this->longdesc = longdesc;
}
void Character::addObjectToInventory(const Object& object, unsigned int limit){
    if(inventory[object.getId()].size() >= limit) {
      //std::cout << "object id: " << object.getId()<< "size: " << inventory[object.getId()].size() << std::endl;
    } else {
      inventory[object.getId()].push_back(object);
        //std::cout << "Object id: " << object.getId() << " Npc id: " << id << " Inventory size: " << inventory.size() <<std::endl;
    }
}
bool Character::removeObjectFromInventory(const std::string& objectName) {
    int objectId = 0;

    for(auto& objectIdVectorPair : inventory) {
      for(auto& keyword : objectIdVectorPair.second[0].getKeywords()) {
          if(objectName.find(keyword) != std::string::npos) {
            objectId = objectIdVectorPair.first;
            //change to begin()+ selected npc number later
            //if(objectIdVectorPair.second.size() >= selectednpcnumber) {
              inventory[objectId].erase(objectIdVectorPair.second.begin());
            //}
              std::cout << "objeect id: " << objectId << "size: " << inventory[objectId].size() << std::endl;
            if(inventory[objectId].empty()) {
                inventory.erase(objectId);
            }
            return true;
          }
      }
    }
    return false;
}
bool Character::equipObject(const Object& object, int slot) {
    if(inventory.find(object.getId()) == inventory.end()) {
      return false;
    }

    if(equipment.find(slot) != equipment.end()) {
      inventory[equipment[slot].getId()].push_back(equipment[slot]);
      equipment[slot] = object;
      inventory[object.getId()].pop_back();
      //std::cout << "objz: " << object.getId() << std::endl;
      return true;
    } else {
      equipment[slot] = object;
    //std::cout << "IW" << std::endl;

      inventory[object.getId()].pop_back();
      if(inventory[object.getId()].empty()) {
        inventory.erase(object.getId());
      }

      //std::cout << "IWOEFJ|" << std::endl;
      return true;
          // std::cout << this << "Object id: " << equipment[slot].getId() << " Npc id: " << id << " Equipment Desc: " << equipment[slot].getShortDesc() << " Equipment size: " << equipment.size() <<std::endl;
    }
}

bool Character::unEquipObject(int slot) {
    //remove if id == object and pickedupflag==yes
    if(equipment.find(slot) != equipment.end()) {
      equipment.erase(slot);
      return true;
    }
    return false;
}

/*int Character::getInventoryLimit() const{
  return this->inventoryLimit;
}

>>>>>>> ed94bd4713f19d14f892e1663b3b12855e711df1
void Character::setInventoryLimit(const int inventoryLimit){
  this->inventoryLimit = inventoryLimit;
}*/

std::unordered_map<int,std::vector<Object>> Character::getInventory() const{
  return this->inventory;
}
void Character::setInventory(std::unordered_map<int, std::vector<Object>>& inventory){
  this->inventory = inventory;
}

std::unordered_map<int,Object> Character::getEquipment() const{
  return this->equipment;
}
void Character::setEquipment(std::unordered_map<int, Object>& equipment){
  this->equipment = equipment;
}

std::string Character::getEquipmentDesc() const {
    std::string response = "";
    for_each(equipment.begin(), equipment.end(), [&response](const auto& currentEquip){response += currentEquip.second.getShortDesc() + ", ";});

    std::cout << "npe equip: " << equipment.size() << std::endl;
    return response;
}
std::string Character::getInventoryDesc() const {
  std::string response = "";
  std::cout << "npe inv: " << inventory.size() << std::endl;

  std::for_each(inventory.begin(), inventory.end(), [&response](const auto& currentItem){response += currentItem.second[0].getShortDesc() + " (Quantity: " + std::to_string(currentItem.second.size()) + "), ";});
  return response;
}

bool Character::getSwappedStatus() const{
  return isSwapped;
}
void Character::setSwappedStatus(bool swap){
  this->isSwapped = swap;
}

#endif
