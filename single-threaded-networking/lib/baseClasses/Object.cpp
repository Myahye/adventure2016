// Object.cpp
#include "Object.h"

// Constructor:
Object::Object()
: id(0), itemType{""} {};

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
  clear_vec(this->keywords);
  clear_vec(this->longDesc);
  clear_vec(this->wearFlags);

  this->extra.clear();
  this->extra.shrink_to_fit();

  /*------copy vectors------*/
  copy_vec(this->attributes,ob.getAttributes());
  copy_vec(this->keywords,ob.getKeywords());
  copy_vec(this->longDesc,ob.getLongDesc());
  copy_vec(this->wearFlags,ob.getWearFlags());

  /*-----------copy extra---------------*/
  for(auto& i:extra){
    extra.push_back(i);
  }
}

Object& Object::operator =(const Object& ob){
  this->id=ob.id;
  this->cost=ob.cost;
  this->weight=ob.weight;
  this->itemType=ob.itemType;
  this->shortDesc=ob.shortDesc;

  /*clean all vectors of the objects before copy*/
  clear_vec(this->attributes);
  clear_vec(this->keywords);
  clear_vec(this->longDesc);
  clear_vec(this->wearFlags);

  extra.clear();
  extra.shrink_to_fit();

  /*------copy vectors------*/
  copy_vec(this->attributes,ob.getAttributes());
  copy_vec(this->keywords,ob.getKeywords());
  copy_vec(this->longDesc,ob.getLongDesc());
  copy_vec(this->wearFlags,ob.getWearFlags());

  /*-----------copy extra---------------*/
  for(auto& i:extra){
    extra.push_back(i);
  }
  
  return *this;
}

// Getter and setter for Id:
int Object::getId() const {
  return id;
}

void Object::setId(int id) {
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


// Getter and setter for keywords:
std::vector<std::string> Object::getKeywords() const {
  return keywords;
}

void Object::setKeywords(const std::vector<std::string>& keywords) {
  this->keywords = keywords;
}

void Object::addKeyword(const std::string& keyword) {
  this->keywords.push_back(keyword);
}


// Getter and setter for longDesc:
std::vector<std::string> Object::getLongDesc() const {
  return this->longDesc;
}
std::string Object::getLongDescStr() const {
  std::string descString = "";
  std::for_each(longDesc.begin(), longDesc.end(), [&descString](const std::string& i){descString += i + "\n";} );  
  return descString;
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
std::vector< std::pair<std::vector<std::string>, std::vector<std::string> > > Object::getExtra() const {
  return extra;
}

void Object::setExtra(const std::vector< std::pair<std::vector<std::string>, std::vector<std::string> > >& extra) {
  this->extra = extra;
}

/*void Object::addExtraDesc(const std::string& desc){
  this->extra.first.push_back(desc);
}

void Object::addExtraKeyword(const std::string& keyword){
  this->extra.second.push_back(keyword);
}*/

void Object::copy_vec(std::vector<std::string>& output, const std::vector<std::string> Alist ){
  for(auto& i:Alist)
    output.push_back(i);
}

void Object::clear_vec(std::vector<std::string> Alist){
  Alist.clear();
  Alist.shrink_to_fit();
}

//New function added in to test
void Object::printClass(int n) const{
  std::cout << "\n\n";
  std::cout << "Object: "<< n << "\n";
  std::cout << "Object Id: " << id << std::endl;
  std::cout << "\tcost: " << cost << std::endl;
  std::cout << "\tweight: " << weight << std::endl;
  std::cout << "\tItem Type: " << itemType << std::endl;
  std::cout << "\tShort Description: " << shortDesc << std::endl;
  std::cout << "\tAttributes: " << std::endl;
  printVector(attributes);
  std::cout << "\tKeywords: " << std::endl;
  printVector(keywords);
  std::cout << "\tLong Descriptions: " << std::endl;
  printVector(longDesc);
  std::cout << "\tWear Flags: " << std::endl;
  printVector(wearFlags);
  std::cout << "\tExtra: " << std::endl;
  for (auto& eachPair : extra){
    std::cout << "\t\tDescription: " << std::endl;
    printVector(eachPair.first);
    std::cout << "\t\tKeywords: " << std::endl;
    printVector(eachPair.second);
  }
/*  std::cout << "\t\tDescription: " << std::endl;
  std::cout << "size of extra desc: " << extra.first.size() << std::endl;
  printVector(extra.first);
  std::cout << "\t\tKeywords: " << std::endl;
  std::cout << "size of extra keywords: " << extra.second.size() << std::endl;
  printVector(extra.second);
*/
}

void Object::printVector(const std::vector<std::string>& vec) const{
  for (auto& element : vec){
    std::cout << "\t\t" << element << std::endl;
  }
}