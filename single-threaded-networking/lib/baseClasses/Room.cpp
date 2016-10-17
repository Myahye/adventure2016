#include "Room.h"
//#include "CustomError.h"

// Constructor
Room::Room() {
    vector<Door> doors;
    Door door1;
    doors.push_back(door1);
    string desc ="No Description";
    string ext_desc = "No extended description";
    string name_room = "Empty Room";
    int id_room = 1128;
    Room(desc, ext_desc, name_room, id_room, doors);
}


Room::Room(int id, std::string description, vector<Door> new_doors) {
    vector<Door> doors;
    string desc =description;
    string ext_desc = "No extended description";
    string name_room = "Empty Room";
    int id_room = id;
    Room(desc, ext_desc, name_room, id_room, new_doors);
}

// Parameterized constructor
Room::Room(string& new_desc, string& new_extended_desc, string& new_name,
             int& new_room_id, vector<Door> new_doors)
            :mDesc{new_desc}, mExtendedDesc{new_extended_desc}, mName{new_name},
            mRoomId{static_cast<unsigned int>(new_room_id)}, doors{new_doors} {
}

// Accessors
string Room::getDesc() const {
    return this->mDesc;
}

string Room::getExtendedDesc() const {
    return this->mExtendedDesc;

}
string Room::getName() const {
    return this->mName;
}

int Room::getRoomId() const {
    return this->mRoomId;
}

vector<Door> Room::getDoors() {
    return doors;
}

int Room::numberOfDoors() {
    return doors.size();
}
// Mutators
void Room::setDescription(string& new_desc) {
    this->mDesc = new_desc;

}
void Room::setExtendedDesc(string& new_extended_desc) {
    this->mExtendedDesc = new_extended_desc;
}
void Room::setName(string& new_name) {
    this->mName = new_name;

}
void Room::setRoomId(int& new_room_id) {
    this->mRoomId = new_room_id;
}

int Room::getRoomInDir(std::string direction){
  std::cout << "In getRoomInDir" << endl;
  for(Door door : doors){
    std::cout << "Door in room goes to: " << door.getDir() <<endl;
    if(door.getDir() == direction){
      return door.getDestinationId();
    }
  }
  throw custom_errors::NoSuchDoorException();
  return 0;
  // if(!std::any_of(doors.begin(), doors.end(), [direction](const Door& door) {if(direction == door.getDir())})){
  //   doors.push_back(new_door);
  //   return true;
  // }else{
  //   //didnt work becuse there is no door in that dir
  //   throw custom_errors::NoSuchDoorException();
  // }
}

//Change bool to error
bool Room::addDoor(Door& new_door) {
  if(!std::any_of(doors.begin(), doors.end(), [new_door](const Door& door) {return new_door.getDir() == door.getDir();})){
    doors.push_back(new_door);
    return true;
  }else{
    //didnt work becuse there is already a door in that dir
    return false;
  }
}