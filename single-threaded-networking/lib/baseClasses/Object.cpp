// Object.cpp
#include "Object.h"

// Constructor:
Object::Object(int id, std::string itemType)
: id{id},
  itemType{itemType} {};


Object::Object(const Object &ob){
  this->id=ob.id;
  this->cost=ob.cost;
  this->weight=ob.weight;
  this->itemType=ob.itemType;
  this->shortDesc=ob.shortDesc;
  /*clean all vectors of the objects before copy*/
  clear_vec(this->attributes);
  clear_vec(this->keyWords);
  clear_vec(this->longDesc);
  clear_vec(this->wearFlags);
  clear_vec(this->extra);

  /*------copy vectors------*/
  copy_vec(this->attributes,ob.getAttributes());
  copy_vec(this->keyWords,ob.getKeyWords());
  copy_vec(this->longDesc,ob.getLongDesc());
  copy_vec(this->wearFlags,ob.getWearFlags());
  copy_vec(this->extra, ob.getExtra());
}

Object& Object::operator =(const Object& ob){
  this->id=ob.id;
  this->cost=ob.cost;
  this->weight=ob.weight;
  this->itemType=ob.itemType;
  this->shortDesc=ob.shortDesc;

  /*clean all vectors of the objects before copy*/
  clear_vec(this->attributes);
  clear_vec(this->keyWords);
  clear_vec(this->longDesc);
  clear_vec(this->wearFlags);
  clear_vec(this->extra);

  /*------copy vectors------*/
  copy_vec(this->attributes,ob.getAttributes());
  copy_vec(this->keyWords,ob.getKeyWords());
  copy_vec(this->longDesc,ob.getLongDesc());
  copy_vec(this->wearFlags,ob.getWearFlags());
  copy_vec(this->extra, ob.getExtra());

  return *this;
}

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
std::string Object::getShortDesc() const {
  return shortDesc;
}

void Object::setShortDesc(const std::string& shortDesc) {
  this->shortDesc = shortDesc;
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

void Object::copy_vec(std::vector<std::string>& output, const std::vector<std::string> Alist ){
  for(auto& i:Alist)
    output.push_back(i);
}

void Object::clear_vec(std::vector<std::string> Alist){
  Alist.clear();
  Alist.shrink_to_fit();
}
