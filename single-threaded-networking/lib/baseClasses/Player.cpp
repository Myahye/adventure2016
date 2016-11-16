#include "Player.h"

//Player constructor
Player::Player (int const pid, std::string const username, std::string const password):
    pid{pid}, username{username}, password{password}{};
Player::Player ():
    pid{0}, username{""}, password{""}{};

std::string
Player::getUsername() const {
    return username;
}
void
Player::setUsername(std::string& username) {
    this->username = username;
}

//Getter and setter for Shortdesc
std::string
Player::getPassword() const {
    return password;
}
void
Player::setPassword(std::string& password) {
    this->password = password;
}

int
Player::getHealth() const{
    return health;
}

void
Player::setHealth(int const health){
    this->health = health;
}

int
Player::getMana() const{
    return mana;
}

void
Player::setMana(int const manaa){
    this->mana = manaa;
}

//Getter and setter for Armor
int
Player::getArmor() const {
    return armor;
}
void
Player::setArmor(int const armor) {
    this->armor = armor;
}

//Getter and setter for Damage
std::string Player::getDamage() const {
    return damage;
}
void Player::setDamage(std::string& damage) {
    this->damage = damage;
}

//Getter and setter for Desc
std::vector<std::string> Player::getDesc() const {
    return description;
}
void Player::setDesc(std::vector<std::string>& description) {
    this->description = description;
}

//Getter and setter for Exp
int Player::getExp() const {
    return exp;
}
void Player::setExp(int const XP) {
    int baseXP = 95;
    exp += XP;
    if((baseXP*level)<=exp){
        level+=1;
        setNewStats();
    }
}

/*helper functions to level up*/
void Player::setNewStats(){
    setNewHealth(level);
    setNewMana(level);
}

void Player::setNewHealth(int const lvl){
    health=100+lvl*lvl*2;
}

void Player::setNewMana(int const lvl){
    mana=95+lvl*lvl*1.5;
}


//Getter and setter for Gold
int Player::getGold() const {
    return gold;
}
void Player::setGold(int const gold) {
    this->gold = gold;
}

//Getter and setter for Hit
std::string Player::getHit() const {
    return hit;
}
void Player::setHit(std::string& hit) {
    this->hit = hit;
}

//Getter and setter for Player ID
int Player::getId() const {
    return pid;
}
void Player::setId(int const pid) {
    this->pid = pid;
}

//Getter and setter for Keywords
std::vector<std::string> Player::getKeywords() const {
    return keywords;
}
void Player::setKeywords(std::vector<std::string>& keywords) {
    this->keywords = keywords;
}

//Getter and setter for Level
int Player::getLevel() const {
    return level;
}
void Player::setLevel(int const level) {
    this->level = level;
}

//Getter and setter for LongDesc
std::vector<std::string> Player::getLongDesc() const {
    return longdesc;
}
void Player::setLongDesc(std::vector<std::string>&  longdesc) {
    this->longdesc = longdesc;
}

//Getter and setter for Thac0
int Player::getThac0() const {
    return thac0;
}
void Player::setThac0(int const thac0) {
    this->thac0 = thac0;
}


//-------------------------------Mohamed Yahye
void Player::addObjectToInventory(const Object& object, unsigned int limit) {
  if(playerInventory[object.getId()].size() == limit) {
  	//std::cout << "object id: " << object.getId()<< "size: " << playerInventory[object.getId()].size() << std::endl;
    std::cout << "limit reached\n";
  } else {
    playerInventory[object.getId()].push_back(object);
    std::cout << "Object id: " << object.getId() << " Player id: " << pid << " Inventory size: " << playerInventory.size() <<std::endl;
  }
}

bool Player::removeObjectFromInventory(const std::string& objectName) {
  int objectId = 0;

  for(auto& objectIdVectorPair : playerInventory) {
    for(auto& keyword : objectIdVectorPair.second[0].getKeywords()) {
      if(objectName.find(keyword) != std::string::npos) {
        objectId = objectIdVectorPair.first;
        //change to begin()+ selected Player number later
        //if(objectIdVectorPair.second.size() >= selectedPlayernumber) {
          playerInventory[objectId].erase(objectIdVectorPair.second.begin());
        //}
          std::cout << "objeect id: " << objectId << "size: " << playerInventory[objectId].size() << std::endl;
        if(playerInventory[objectId].empty()) {
          playerInventory.erase(objectId);
        }
        return true;
      }
    }
  }
  return false;
}

//maybe change it so int slot is string item_type and thats ur slots!
bool Player::equipObject(const Object& object, int slot) {
  if(playerInventory.find(object.getId()) == playerInventory.end()) {
  	return false;
  }

  if(playerEquipment.find(slot) != playerEquipment.end()) {
    playerInventory[playerEquipment[slot].getId()].push_back(playerEquipment[slot]);
    playerEquipment[slot] = object;
    playerInventory[object.getId()].pop_back();
    //std::cout << "objz: " << object.getId() << std::endl;
    return true;
  } else {
    playerEquipment[slot] = object;
	//std::cout << "IW" << std::endl;

    playerInventory[object.getId()].pop_back();
    if(playerInventory[object.getId()].empty()) {
    	playerInventory.erase(object.getId());
    }

    //std::cout << "IWOEFJ|" << std::endl;
    return true;
          // std::cout << this << "Object id: " << PlayerEquipment[slot].getId() << " Player id: " << id << " Equipment Desc: " << PlayerEquipment[slot].getShortDesc() << " Equipment size: " << PlayerEquipment.size() <<std::endl;
  }
}
bool Player::unEquipObject(int slot) {
  //remove if id == object and pickedupflag==yes
  if(playerEquipment.find(slot) != playerEquipment.end()) {
  	playerEquipment.erase(slot);
  	return true;
  }
  return false;
}

std::unordered_map<int,std::vector<Object>> Player::getPlayerInventory() const {
  return this->playerInventory;
}

std::unordered_map<int,Object> Player::getPlayerEquipment() const {
  return this->playerEquipment;
}

std::string Player::getPlayerEquipmentDesc() const {
  std::string response = "";
  for_each(playerEquipment.begin(), playerEquipment.end(), [&response](const auto& currentEquip){response += currentEquip.second.getShortDesc() + ", ";});
    std::cout << "player equip: " << playerEquipment.size() << std::endl;	
  return response;
}
std::string Player::getPlayerInventoryDesc() const {
	std::string response = "";
	 std::cout << "player inv: " << playerInventory.size() << std::endl;
	std::for_each(playerInventory.begin(), playerInventory.end(), [&response](const auto& currentItem){response += currentItem.second[0].getShortDesc() + " (Quantity: " + std::to_string(currentItem.second.size()) + "), ";});	
  return response;
}


