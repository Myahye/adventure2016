// Object.cpp
#include "Object.h"

// Constructor:
Object::Object(int id, std::string itemType)
: id{id},
  itemType{itemType} {};

/*
Object::Object(const Object &ob){
  this->id=ob.id;
  this->cost=ob.cost;
  this->weight=ob.weight;
  this->itemType=ob.itemType;

  copy_vec(attributes);
  copy_vec(keyWords);
  copy_vec(longDesc);
  copy_vec(shortDesc);
  copy_vec(wearFlags);
  copy_vec(extra);
}
*/

// Getter and setter for ID:
int Object::getID() const {
  return id;
}

void Object::setID(int id) {
  this->id = id;
}


// Getter and setter for cost:
int Object::getCost() const {
  return cost;
}

void Object::setCost(int cost) {
  this->cost = cost;
}


// Getter and setter for weight:
int Object::getWeight() const {
  return weight;
}

void Object::setWeight(int weight) {
  this->weight = weight;
}


// Getter and setter for itemType:
std::string Object::getItemType() const {
  return itemType;
}

void Object::setItemType(const std::string& itemType) {
  this->itemType = itemType;
}


// Getter and setter for Attributes:
std::vector<std::string> Object::getAttributes() const {
  return attributes;
}

void Object::setAttributes(const std::vector<std::string>& attributes) {
  this->attributes = attributes;
}

void Object::addAttribute(const std::string& attribute) {
  this->attributes.push_back(attribute);
}


// Getter and setter for keyWords:
std::vector<std::string> Object::getKeyWords() const {
  return keyWords;
}

void Object::setKeyWords(const std::vector<std::string>& keyWords) {
  this->keyWords = keyWords;
}

void Object::addKeyWord(const std::string& keyWord) {
  this->keyWords.push_back(keyWord);
}


// Getter and setter for longDesc:
std::vector<std::string> Object::getLongDesc() const {
  return longDesc;
}

void Object::setLongDesc(const std::vector<std::string>& longDesc) {
  this->longDesc = longDesc;
}

void Object::addLongDesc(const std::string& longDesc) {
  this->longDesc.push_back(longDesc);
}


// Getter and setter for shortDesc:
std::vector<std::string> Object::getShortDesc() const {
  return shortDesc;
}

void Object::setShortDesc(const std::vector<std::string>& shortDesc) {
  this->shortDesc = shortDesc;
}

void Object::addShortDesc(const std::string& shortDesc) {
  this->shortDesc.push_back(shortDesc);
}


// Getter and setter or wearFlags:
std::vector<std::string> Object::getWearFlags() const {
  return wearFlags;
}

void Object::setWearFlags(const std::vector<std::string>& wearFlags) {
  this->wearFlags = wearFlags;
}

void Object::addWearFlag(const std::string& wearFlags) {
  this->wearFlags.push_back(wearFlags);
}


// Getter and setter for extra:
std::vector<std::string> Object::getExtra() const {
  return extra;
}

void Object::setExtra(const std::vector<std::string>& extra) {
  this->extra = extra;
}

void Object::addExtra(const std::string& extra) {
  this->extra.push_back(extra);
}
