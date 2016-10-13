// Object.cpp

#include <iostream>
#include <vector>
#include <string>
// #include "Object.h"

class Object {
private:
  int id;
  int cost;
  int weight;

  std::string itemType;

  // Need to change vector type
  std::vector<std::string> extra;

  std::vector<std::string> Attributes;
  std::vector<std::string> KeyWords;
  std::vector<std::string> longDesc;
  std::vector<std::string> shortDesc;
  std::vector<std::string> wearFlags;
public:
  // Constructors:
  Object(int id, std::string itemType) {
    this->id = id;
    this->itemType = itemType;
  }

  Object(int id, std::string itemType, int cost, int weight) {
    this->id = id;
    this->itemType = itemType;
    this->cost = cost;
    this->weight = weight;
  }


  // Deconstructor:
  ~Object() {

  }

  // Getters:
  int getID() {
    return this->id;
  }

  int getCost() {
    return this->cost;
  }

  int getWeight() {
    return this->weight;
  }

  std::string getItemType() {
    return this->itemType;
  }

  // Setters:
  void setID(int id) {
    this->id = id;
  }

  void setCost(int cost) {
    this->cost = cost;
  }

  void setWeight(int weight) {
    this->weight = weight;
  }

  void setItemType(std::string itemType) {
    this->itemType = itemType;
  }

  void addAttribute(std::string attribute) {
    this->Attributes.push_back(attribute);
    //Attributes.push_back(attribute);
  }

  void addKeyWord(std::string keyWord) {
    this->KeyWords.push_back(keyWord);
  }

  void addLongDesc(std::string longDesc) {
    this->longDesc.push_back(longDesc);
  }

  void addShortDesc(std::string shortDesc) {
    this->shortDesc.push_back(shortDesc);
  }

  void addWearFlag(std::string wearFlags) {
    this->wearFlags.push_back(wearFlags);
  }

  void addExtra(std::string extra) {
    this->extra.push_back(extra);
  }

  // Function implementations:
  void print_object() {
    /* code */
    std::cout<<"object Id is : "<< id<< std::endl;
    std::cout<<"object cost is: "<< cost<<std::endl;
    std::cout<<"object attribute is "<<std::endl;
    print_vec(Attributes);
    std::cout<<"object type is: "<< itemType <<std::endl;
    std::cout<<"object KeyWords is "<<std::endl;
    print_vec(KeyWords);
    std::cout<<"object longDesc is "<<std::endl;
    print_vec(longDesc);
    std::cout<<"object shortDesc is "<<std::endl;
    print_vec(shortDesc);
    std::cout<<"object wearFlags is "<<std::endl;
    print_vec(wearFlags);
    std::cout<<"object extra is "<<std::endl;
    print_vec(extra);
    }

  void print_vec(const std::vector<std::string>& Alist){
    for(auto& i:Alist)
      std::cout <<"    - "<<i<< std::endl;
  }
};

int main(void){
  Object box(1100,"light",5000,8);

  std::cout << "This is a object test file" << std::endl;
  //box.print_object();
  box.addAttribute("magic");
  box.addKeyWord("rainbow");
  box.addKeyWord("staff");
  box.addLongDesc("-The rainbow staff lies here.");
  box.addShortDesc("the rainbow staff");
  box.addWearFlag("take");
  box.addWearFlag("ears");
  box.print_object();
  return 0;

}
