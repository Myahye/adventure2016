// Object.cpp
#include "Object.h"

// Constructor:
Object::Object(int id, std::string itemType)
: id{id}, 
  itemType{itemType} {};


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

void Object::setItemType(std::string& itemType) {
  this->itemType = itemType;
}


// Getter and setter for Attributes:
std::vector<std::string> Object::getAttributes() const {
  return attributes;
}

void Object::setAttributes(std::vector<std::string>& attributes) {
  this->attributes = attributes;
}

void Object::addAttribute(std::string& attribute) {
  this->attributes.push_back(attribute);
}


// Getter and setter for keyWords:
std::vector<std::string> Object::getKeyWords() const {
  return keyWords;
}

void Object::setKeyWords(std::vector<std::string>& keyWords) {
  this->keyWords = keyWords;
}

void Object::addKeyWord(std::string& keyWord) {
  this->keyWords.push_back(keyWord);
}


// Getter and setter for longDesc:
std::vector<std::string> Object::getLongDesc() const {
  return longDesc;
}

void Object::setLongDesc(std::vector<std::string>& longDesc) {
  this->longDesc = longDesc;
}

void Object::addLongDesc(std::string& longDesc) {
  this->longDesc.push_back(longDesc);
}


// Getter and setter for shortDesc:
std::vector<std::string> Object::getshortDesc() const {
  return shortDesc;
}

void Object::setShortDesc(std::vector<std::string>& shortDesc) {
  this->shortDesc = shortDesc;
}

void Object::addShortDesc(std::string& shortDesc) {
  this->shortDesc.push_back(shortDesc);
}


// Getter and setter or wearFlags:
std::vector<std::string> Object::getWearFlags() const {
  return wearFlags;
}

void Object::setWearFlags(std::vector<std::string>& wearFlags) {
  this->wearFlags = wearFlags;
}

void Object::addWearFlag(std::string& wearFlags) {
  this->wearFlags.push_back(wearFlags);
}


// Getter and setter for extra:
std::vector<std::string> Object::getExtra() const {
  return extra;
} 

void Object::setExtra(std::vector<std::string>& extra) {
  this->extra = extra;
}

void Object::addExtra(std::string& extra) {
  this->extra.push_back(extra);
}