#include "Room.h"
//include "CustomError.h"

Room::Room()
:mDesc{"No Description"}, mExtendedDesc{std::make_pair(std::vector<std::string>{"No extended description"},std::vector<std::string>{""})}, mName{"Empty Room"},
            mRoomId{static_cast<unsigned int>(0)}, doors{Door()} {}

//Temp constructor for testing and first iteration
Room::Room(int& id, std::vector<std::string>& description, std::vector<Door>& new_doors) 
:mDesc{description}, mExtendedDesc{std::make_pair(std::vector<std::string>{"No extended description"},std::vector<std::string>{""})}, mName{"Empty Room"},
            mRoomId{static_cast<unsigned int>(id)}, doors{new_doors} {}

// Parameterized constructor
Room::Room(std::vector<std::string>& new_desc, std::pair< std::vector<std::string>, std::vector<std::string> >& new_extended_desc, std::string& new_name,
             int& new_room_id, std::vector<Door>& new_doors)
            :mDesc{new_desc}, mExtendedDesc{new_extended_desc}, mName{new_name},
            mRoomId{static_cast<unsigned int>(new_room_id)}, doors{new_doors} {
}

// Accessors
std::string Room::getDesc() const {
  std::string response = "";
  for_each(mDesc.begin(), mDesc.end(), [&response](const std::string& descriptionText){response += descriptionText + "\n";} ); 
  return response;
}
std::pair< std::vector<std::string>, std::vector<std::string> > Room::getExtendedDesc() const {
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
void Room::setExtendedDesc(std::pair< std::vector<std::string>, std::vector<std::string> >& new_extended_desc) {
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
  // for(auto i : mExtendedDesc) {
  //   std::cout << "\tExtended Desc: " << i.first.size() << std::endl;
  // }
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
Npc* Room::addNpc(Npc& npc, unsigned int limit) {
  if(npcsInRoom[npc.getId()].size() == limit) {
    return NULL;
  } else {
    //TEST CODE FOR DUPLICATES
    // auto desc = npc.getDesc();
    // desc += " " + std::to_string(npcsInRoom[npc.getId()].size());
    // npc.setDesc({desc});
    // auto key = npc.getKeywords();
    // key.push_back(npc.getKeywords()[0] + " " + std::to_string(npcsInRoom[npc.getId()].size()));
    // npc.setKeywords(key);
    // npcsInRoom[npc.getId()].push_back(npc);
    // std::cout << "Room id: " << mRoomId << "Npc id: " << npc.getId() << std::endl;
    npcsInRoom[npc.getId()].push_back(npc);
    return &npcsInRoom[npc.getId()].back();
  }
}
bool Room::removeNpc(int npcId) {
  //remove if id == npc and hp == 0
  if(npcsInRoom[npcId].size() != 0) {
    npcsInRoom[npcId].pop_back();
    return true;
  }
  return false;
}

void Room::addObject(const Object& object, unsigned int limit) {
  if(objectsInRoom[object.getId()].size() == limit) {
    return;
  } else {
    objectsInRoom[object.getId()].push_back(object);
       //   std::cout << "Room id: " << mRoomId << "Npc id: " << npc.getId() << std::endl;
  }
}
bool Room::removeObject(int objectId) {
  //remove if id == object and pickedupflag==yes
  if(objectsInRoom[objectId].size() != 0) {
    objectsInRoom[objectId].pop_back();
    return true;
  }
  return false;
}

Npc Room::findNpc(const std::string& message) {
  Npc currentlySelectedNpc;

  auto it = std::find_if(npcsInRoom.begin(),npcsInRoom.end(), 
    [&currentlySelectedNpc,&message,this] (const std::pair<int,std::vector<Npc>>& npcIdVectorPair) { return checkNpcKeywords(currentlySelectedNpc, message, npcIdVectorPair); });
  if(it != npcsInRoom.end()) {
    return currentlySelectedNpc;
  }
  return Npc();
}
Object Room::findObject(const std::string& message) {
  Object currentlySelectedObject;

  auto it = std::find_if(objectsInRoom.begin(),objectsInRoom.end(), 
    [&message,&currentlySelectedObject,this] (const std::pair<int,std::vector<Object>>& objectIdVectorPair) { return checkObjectKeywords(currentlySelectedObject, message, objectIdVectorPair); });

  if(it != objectsInRoom.end()) {
    return currentlySelectedObject;
  }
  return Object();
}

std::unordered_map<int,std::vector<Npc>> Room::getNpcsInRoom() const {
  return npcsInRoom;
}
std::unordered_map<int,std::vector<Object>> Room::getObjectsInRoom() const {
  return objectsInRoom;
}

bool Room::checkNpcKeywords(Npc& currentlySelectedNpc, const std::string& message, const std::pair<int,std::vector<Npc>>& npcIdVectorPair) {

  //check duplicates eg. dupl_object 1, dupl_object 2, dupl_object 3
  for(auto currentNpc : npcIdVectorPair.second) {
    for(auto currentKeyword : currentNpc.getKeywords()) {
      if(message == currentKeyword) {
        currentlySelectedNpc = currentNpc;
        return true;
      }
    }
  }

  return false;
}
bool Room::checkObjectKeywords(Object& currentlySelectedObject, const std::string& message, const std::pair<int,std::vector<Object>>& objectIdVectorPair) {

  //check duplicates eg. dupl_object 1, dupl_object 2, dupl_object 3
  for(auto currentObject : objectIdVectorPair.second) {
    for(auto currentKeyword : currentObject.getKeywords()) {
      if(message == currentKeyword) {
        currentlySelectedObject = currentObject;
        return true;
      }
    }
    //ONLY WORKS HALF THE TIME FOR SOME REASON
    // auto it = std::find_if(currentObject.getKeywords().begin(), currentObject.getKeywords().end(), [&message] (const std::string& keyword) { return message == keyword;});
    // if(it != currentObject.getKeywords().end()) {
    //   currentlySelectedObject = currentObject;
    //   return true;
    // }
  }

  return false;
}

std::string Room::getNpcsInRoomDesc() const {
  std::string response = "";
  for(auto npcIdVectorPair : npcsInRoom) {
    for(auto npc : npcIdVectorPair.second) {
      response += "     " + npc.getLongDesc();
    }
  } 

  if(!response.empty()) {
    response += "\n";
  }

  return response;
}
std::string Room::getObjectsInRoomDesc() const {
  std::string response = "     ";
  for(auto objectIdVectorPair : objectsInRoom) {
    for(auto object : objectIdVectorPair.second) {
      response += object.getLongDescStr();
    }
  }

  if(!response.substr(5).empty()) {
    return response += "\n";
  } else {
    return "";
  }
}
std::string Room::getDoorsInRoomDesc() const {
  std::string response = "";

  if(doors.size() == 1) {
    return  "There is 1 obvious exit: " + doors[0].getDir() + ".\n";
  }

  response += "There are " + std::to_string(doors.size()) + " obvious exits: ";

  std::for_each(doors.begin(),doors.end()-1,[&response] (const auto& currentDoor) { response += currentDoor.getDir() + ", "; });
  
  response += "and " + doors[doors.size()-1].getDir() + ".\n";

  return response;
}

std::string Room::getFullRoomDesc() const {
  std::string response = getDesc() + "\n";
  response += getNpcsInRoomDesc();
  response += getObjectsInRoomDesc(); 
  response += "     " + getDoorsInRoomDesc() + "\n";
  return response;
}

