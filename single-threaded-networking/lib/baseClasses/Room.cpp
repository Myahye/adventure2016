#include "Room.h"
//include "CustomError.h"

Room::Room()
:mName{"Empty Room"},
            mRoomId{static_cast<unsigned int>(0)} {}

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

std::vector <std::string> Room::getDescV() const {
  return this->mDesc;
}

std::vector<std::pair<std::vector<std::string>, std::vector<std::string> > > Room::getExtendedDesc() const {
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
    //std::cout << "Door in room goes to: " << door.getDir() <<"\n";
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
void Room::setExtendedDesc(const std::vector<std::pair<std::vector<std::string>, std::vector<std::string> > >& new_extended_desc) {
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
void Room::addVectorDoors(std::vector<Door>& new_vector_doors){
  for (auto& door : new_vector_doors){
    addDoor(door);
  }
}
//New function added in to test
void Room::printClass(int n) const{
  std::cout << "\n\n---------------------------------------";
  std::cout << "Room: "<< n << "\n";
  std::cout << "Room id: " << mRoomId << std::endl;
  std::cout << "\tRoom Name: " << mName << std::endl;
  std::cout << "\tDesc: " << std::endl;
  printVector(mDesc);
  std::cout << "\tExtended Description: " << std::endl;
  for (auto& eachDesc : mExtendedDesc){
    std::cout << "\t\t Description: " << std::endl;
    printVector(eachDesc.first);
    std::cout << "\t\tKeywords: " << std::endl;
    printVector(eachDesc.second);
  }
  for(auto& i : doors) {
    std::cout << "\tDoor dir: "<< i.getDir() << "\n";
    std::cout << "\tDoor Door_id: " << i.getDoorId() << std::endl;
    std::cout << "\tDoor destinationId: " << i.getDestinationId() << std::endl;
    printVector(i.getDescV());
    printVector(i.getKeywords());
  }
  //std::cout << "\tthac0: " << thac0 << std::endl;
}
void Room::printVector(const std::vector<std::string>& vec) const{
  for (auto& element : vec){
    std::cout << "\t\t" << element << std::endl;
  }
}
//--------------------------------------Lawrence Yu
Npc* Room::addNpc(Npc& npc, unsigned int limit) {
  if(npcsInRoom[npc.npcCharacter.getId()].size() >= limit) {
    //std::cout << "WOW" << std::endl;
    return NULL;
  } else {
    //TEST CODE FOR DUPLICATES
    // auto desc = npc.getDesc();
    // desc += " " + std::to_string(npcsInRoom[npc.npcCharacter.getId()].size());
    // npc.setDesc({desc});
    // auto key = npc.npcCharacter.getKeywords();
    // key.push_back(npc.npcCharacter.getKeywords()[0] + " " + std::to_string(npcsInRoom[npc.npcCharacter.getId()].size()));
    // npc.setKeywords(key);
    // npcsInRoom[npc.npcCharacter.getId()].push_back(npc);
    // std::cout << "Room id: " << mRoomId << "Npc id: " << npc.npcCharacter.getId() << std::endl;
    //std::cout << "sd" << npc.npcCharacter.getId() << std::endl;
    npcsInRoom[npc.npcCharacter.getId()].push_back(npc);
    //std::cout << npcsInRoom[npc.npcCharacter.getId()].back().getId() << std:: endl;
    return &npcsInRoom[npc.npcCharacter.getId()].back();
  }
}
bool Room::removeNpc(const int npcId) {
  if(!npcsInRoom[npcId].empty()) {
    //change to end() - selected npc number later
    //if(npcIdVectorPair.second.size() >= selectednpcnumber) {
    npcsInRoom[npcId].erase(npcsInRoom[npcId].end()/*-num*/);
    //}
    if(npcsInRoom[npcId].empty()) {
      npcsInRoom.erase(npcId);
    }
    return true;
  }
  return false;
}

void Room::addObject(const Object& object, unsigned int limit) {
  if(objectsInRoom[object.getId()].size() == limit) {
    return;
  } else {
    objectsInRoom[object.getId()].push_back(object);
       //   std::cout << "Room id: " << mRoomId << "Npc id: " << npc.npcCharacter.getId() << std::endl;
  }
}
bool Room::removeObject(const int objectId) {
  if(!objectsInRoom[objectId].empty()) {
    //change to end() - selected npc number later
    //if(npcIdVectorPair.second.size() >= selectednpcnumber) {
    objectsInRoom[objectId].erase(objectsInRoom[objectId].end()/*-num*/);
    //}
    if(objectsInRoom[objectId].empty()) {
      objectsInRoom.erase(objectId);
    }
    return true;
  }
  return false;
}

void Room::addPlayer(const int playerId, const std::string& username) {
  playersInRoom[playerId] = username;
      //   std::cout << "Room id: " << mRoomId << "Npc id: " << npc.npcCharacter.getId() << std::endl;
}
bool Room::removePlayer(const int playerId) {

  auto it = playersInRoom.erase(playerId);

  if(it == 0) {
    return false;
  }
  return true;
}

Npc* Room::findNpc(const std::string& name) {
  Npc* currentlySelectedNpc = NULL;

  auto it = std::find_if(npcsInRoom.begin(),npcsInRoom.end(),
    [&currentlySelectedNpc,&name,this] (const std::pair<int,std::vector<Npc>>& npcIdVectorPair) {
     currentlySelectedNpc = checkNpcKeywords(name, npcIdVectorPair);
     return currentlySelectedNpc != NULL;
    });
  if(it != npcsInRoom.end()) {
    return currentlySelectedNpc;
  }
  return NULL;
}
Object* Room::findObject(const std::string& name) {
  Object* currentlySelectedObject = NULL;

  auto it = std::find_if(objectsInRoom.begin(),objectsInRoom.end(),
    [&currentlySelectedObject,&name,this] (const std::pair<int,std::vector<Object>>& objectIdVectorPair) { currentlySelectedObject = checkObjectKeywords(name, objectIdVectorPair); return currentlySelectedObject != NULL; });

  if(it != objectsInRoom.end()) {
    return currentlySelectedObject;
  }
  return NULL;
}

int Room::findPlayerId(const std::string& name) {
  auto player = find_if(playersInRoom.begin(),playersInRoom.end(),
  [&name] (const auto& player) {
    return player.second == name;
  });

  if (player != playersInRoom.end()) {
    return player->first;
  }
  return 0;
}


Npc* Room::checkNpcKeywords(const std::string& message, const std::pair<int,std::vector<Npc>>& npcIdVectorPair) {

  //check duplicates eg. dupl_object 1, dupl_object 2, dupl_object 3
  int i = 0;
  for(auto& currentNpc : npcIdVectorPair.second) {
    for(auto currentKeyword : currentNpc.npcCharacter.getKeywords()) {
      if(message.find(currentKeyword) != std::string::npos) {
        //need to change this later
        return &this->npcsInRoom[currentNpc.npcCharacter.getId()][i];
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
      response += "     " + npc.npcCharacter.getLongDesc();
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

