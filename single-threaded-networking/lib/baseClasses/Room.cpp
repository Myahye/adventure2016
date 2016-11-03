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
    //for(auto k : i.getDesc()) {
      std::cout << "   Door desc: " << i.getDesc() << std::endl;
   // }
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
  if(npcsInRoom[npc.getId()].size() >= limit) {
    //std::cout << "WOW" << std::endl;
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
    //std::cout << "sd" << npc.getId() << std::endl;
    npcsInRoom[npc.getId()].push_back(npc);
    //std::cout << npcsInRoom[npc.getId()].back().getId() << std:: endl;
    return &npcsInRoom[npc.getId()].back();
  }
}
bool Room::removeNpc(const std::string& npcName) {
  //remove if id == npc and hp == 0
  int npcId = 0;

  for(auto& npcIdVectorPair : npcsInRoom) {
    for(auto& keyword : npcIdVectorPair.second[0].getKeywords()) {
      if(npcName.find(keyword) != std::string::npos) {
        npcId = npcIdVectorPair.first;
        //change to end() - selected npc number later
        //if(npcIdVectorPair.second.size() >= selectednpcnumber) {
          npcsInRoom[npcId].erase(npcIdVectorPair.second.end());
        //}
        if(npcsInRoom[npcId].empty()) {
          npcsInRoom.erase(npcId);
        }
        return true;
      }
    }
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
bool Room::removeObject(const std::string& objectName) {

  int objectId = 0;

  for(auto& objectIdVectorPair : objectsInRoom) {
    for(auto& keyword : objectIdVectorPair.second[0].getKeywords()) {
      if(objectName.find(keyword) != std::string::npos) {
        objectId = objectIdVectorPair.first;
        //change to end() - selected npc number later
        //if(objectIdVectorPair.second.size() >= selectednpcnumber) {
          objectsInRoom[objectId].erase(objectIdVectorPair.second.end());
        //}
        if(objectsInRoom[objectId].empty()) {
          objectsInRoom.erase(objectId);
        }
        return true;
      }
    }
  }
  return false;
}

Npc* Room::findNpc(const std::string& message) {
  Npc* currentlySelectedNpc = NULL;

  auto it = std::find_if(npcsInRoom.begin(),npcsInRoom.end(), 
    [&currentlySelectedNpc,&message,this] (const std::pair<int,std::vector<Npc>>& npcIdVectorPair) { 
     currentlySelectedNpc = checkNpcKeywords(message, npcIdVectorPair); 
     return currentlySelectedNpc != NULL;
    });
  if(it != npcsInRoom.end()) {
    return currentlySelectedNpc;
  }
  return NULL;
}
Object* Room::findObject(const std::string& message) {
  Object* currentlySelectedObject = NULL;

  auto it = std::find_if(objectsInRoom.begin(),objectsInRoom.end(), 
    [&currentlySelectedObject,&message,this] (const std::pair<int,std::vector<Object>>& objectIdVectorPair) { currentlySelectedObject = checkObjectKeywords(message, objectIdVectorPair); return currentlySelectedObject != NULL; });

  if(it != objectsInRoom.end()) {
    return currentlySelectedObject;
  }
  return NULL;
}

std::unordered_map<int,std::vector<Npc>> Room::getNpcsInRoom() const {
  return npcsInRoom;
}
std::unordered_map<int,std::vector<Object>> Room::getObjectsInRoom() const {
  return objectsInRoom;
}

Npc* Room::checkNpcKeywords(const std::string& message, const std::pair<int,std::vector<Npc>>& npcIdVectorPair) {

  //check duplicates eg. dupl_object 1, dupl_object 2, dupl_object 3
  int i = 0;
  for(auto& currentNpc : npcIdVectorPair.second) {
    for(auto currentKeyword : currentNpc.getKeywords()) {
      if(message.find(currentKeyword) != std::string::npos) {
        return &this->npcsInRoom[currentNpc.getId()][i];
      }
    }
    i++;
  }

  return NULL;
}
Object* Room::checkObjectKeywords(const std::string& message, const std::pair<int,std::vector<Object>>& objectIdVectorPair) {

  //check duplicates eg. dupl_object 1, dupl_object 2, dupl_object 3
  int i = 0;
  for(auto currentObject : objectIdVectorPair.second) {
    for(auto currentKeyword : currentObject.getKeywords()) {
      if(message.find(currentKeyword) != std::string::npos) {
        return &this->objectsInRoom[currentObject.getId()][i];
      }
    }
    i++;
    //ONLY WORKS HALF THE TIME FOR SOME REASON
    // auto it = std::find_if(currentObject.getKeywords().begin(), currentObject.getKeywords().end(), [&message] (const std::string& keyword) { return message == keyword;});
    // if(it != currentObject.getKeywords().end()) {
    //   currentlySelectedObject = currentObject;
    //   return true;
    // }
  }

  return NULL;
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
  std::string response = "";
  for(auto objectIdVectorPair : objectsInRoom) {
    for(auto object : objectIdVectorPair.second) {
      response += "     " + object.getLongDescStr();
    }
  }

  if(!response.empty()) {
    response += "\n";
  }

  return response;
}
std::string Room::getDoorsInRoomDesc() const {
  std::string response = "";

  if(!doors.empty()){
    if(doors.size() == 1) {
      return  "There is 1 obvious exit: " + doors[0].getDir() + ".\n";
    }

    response += "There are " + std::to_string(doors.size()) + " obvious exits: ";

    std::for_each(doors.begin(),doors.end()-1,[&response] (const auto& currentDoor) { response += currentDoor.getDir() + ", "; });
    
    response += "and " + doors[doors.size()-1].getDir() + ".\n";
  }

  return response;
}

std::string Room::getFullRoomDesc() const {
  std::string response = getDesc() + "\n";
  response += getNpcsInRoomDesc();
  response += getObjectsInRoomDesc(); 
  response += "     " + getDoorsInRoomDesc() + "\n";
  return response;
}

