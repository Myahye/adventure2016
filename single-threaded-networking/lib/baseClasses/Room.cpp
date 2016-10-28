#include "Room.h"
//include "CustomError.h"

Room::Room()
:mDesc{"No Description"}, mExtendedDesc{"No extended description"}, mName{"Empty Room"},
            mRoomId{static_cast<unsigned int>(0)}, doors{Door()} {}

//Temp constructor for testing and first iteration
Room::Room(int& id, std::vector<std::string>& description, std::vector<Door>& new_doors) 
:mDesc{description}, mExtendedDesc{"No extended description"}, mName{"Empty Room"},
            mRoomId{static_cast<unsigned int>(id)}, doors{new_doors} {}

// Parameterized constructor
Room::Room(std::vector<std::string>& new_desc, std::vector<std::string>& new_extended_desc, std::string& new_name,
             int& new_room_id, std::vector<Door>& new_doors)
            :mDesc{new_desc}, mExtendedDesc{new_extended_desc}, mName{new_name},
            mRoomId{static_cast<unsigned int>(new_room_id)}, doors{new_doors} {
}

// Accessors
std::vector<std::string> Room::getDesc() const {
    return this->mDesc;
}
std::vector<std::string> Room::getExtendedDesc() const {
    return this->mExtendedDesc;
}
std::string Room::getName() const {
    return this->mName;
}
int Room::getRoomId() const {
    return this->mRoomId;
}
std::vector<Door> Room::getDoors() const {
    return doors;
}
int Room::numberOfDoors() const{
    return doors.size();
}
int Room::getRoomInDir(std::string direction) const {
  // std::cout << "In getRoomInDir" << "\n";
  for(Door door : doors){
    std::cout << "Door in room goes to: " << door.getDir() <<"\n";
    if(door.getDir() == direction){
      return door.getDestinationId();
    }
  }
  //This will need to be changed as it doesnt work with multiple languages
  return -1;
}

// Mutators
void Room::setDescription(std::vector<std::string>& new_desc) {
    this->mDesc = new_desc;
}
void Room::setExtendedDesc(std::vector<std::string>& new_extended_desc) {
    this->mExtendedDesc = new_extended_desc;
}
void Room::setName(std::string& new_name) {
    this->mName = new_name;

}
void Room::setRoomId(const int new_room_id) {
    this->mRoomId = new_room_id;
}
//Change bool to error
bool Room::addDoor(const Door& new_door) {
  if(!std::any_of(doors.begin(), doors.end(), [new_door](const Door& door) {return new_door.getDir() == door.getDir();})){
    doors.push_back(new_door);
    return true;
  }else{
    //didnt work becuse there is already a door in that dir
    return false;
  }
}
//New function added in to test
void Room::printClass(int n) const{
  std::cout << "\n\n---------------------------------------";
  std::cout << "Room: "<< n << "\n";
  std::cout << "Room id: " << mRoomId << std::endl;
  std::cout << "\nRoom Name: " << mName << std::endl;
  for(auto i : mDesc) {
    std::cout << "\tShort Desc: " << i << std::endl;
  }
  for(auto i : mExtendedDesc) {
    std::cout << "\tExtended Desc: " << i << std::endl;
  }
  for(auto i : doors) {
    std::cout << "   Door dir: "<< i.getDir() << "\n";
    for(auto k : i.getDesc()) {
      std::cout << "   Door desc: " << k << std::endl;
    }
    for(auto k : i.getKeywords()) {
      std::cout << "   Door keywords: " << k << std::endl;
    }
    std::cout << "   Door Door_id: " << i.getDoorId() << std::endl;
    std::cout << "   Door destinationId: " << i.getDestinationId() << std::endl;
  }
  //std::cout << "\tthac0: " << thac0 << std::endl;
}

//--------------------------------------Lawrence Yu
NPC* Room::addNPC(const NPC& npc, int limit) {
  if(npcsInRoom[npc.getId()].size() == limit) {
    return NULL;
  } else {
    npcsInRoom[npc.getId()].push_back(npc);
    return &npcsInRoom[npc.getId()].back();
       //   std::cout << "Room id: " << mRoomId << "NPC id: " << npc.getId() << std::endl;
  }
}
void Room::addObject(const Object& object, int limit) {
  if(objectsInRoom[object.getID()].size() == limit) {
    return;
  } else {
    objectsInRoom[object.getID()].push_back(object);
       //   std::cout << "Room id: " << mRoomId << "NPC id: " << npc.getId() << std::endl;
  }
}
bool Room::removeNPC(int npcID) {
  //remove if id == npc and hp == 0
}
bool Room::removeObject(int objectID) {
  //remove if id == object and pickedupflag==yes
}
std::unordered_map<int,std::vector<NPC>> Room::getNPCsInRoom() const {
  return npcsInRoom;
}
std::unordered_map<int,std::vector<Object>> Room::getObjectsInRoom() const {
  return objectsInRoom;
}

