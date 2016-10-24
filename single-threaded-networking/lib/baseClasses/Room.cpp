#include "Room.h"
//#include "CustomError.h"

Room::Room() {
    std::vector<Door> doors;
    Door door1;
    doors.push_back(door1);
    string desc ="No Description";
    string ext_desc = "No extended description";
    string name_room = "Empty Room";
    int id_room = 1128;
    Room(desc, ext_desc, name_room, id_room, doors);
}

//Temp constructor for testing and first iteration
Room::Room(int& id, std::vector<std::string>& description, std::vector<Door>& new_doors) {
    std::vector<std::string> exended_description ;
    string name_room = "Empty Room";
    int id_room = id;
    Room(description, exended_description, name_room, id_room, new_doors);
}

// Parameterized constructor
Room::Room(std::vector<std::string>& new_desc, std::vector<std::string>& new_extended_desc, string& new_name,
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
string Room::getName() const {
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
  std::cout << "In getRoomInDir" << endl;
  for(Door door : doors){
    std::cout << "Door in room goes to: " << door.getDir() <<endl;
    if(door.getDir() == direction){
      return door.getDestinationId();
    }
  }
  //This will need to be changed as it doesnt work with multiple languages
  throw custom_errors::NoSuchDoorException();
  return 0;
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
