#include "room.h"

// Constructor
Room::Room(){
    name = "NO_NAME";
    room_id = 0;
}

// Parameterized constructor
Room::Room(string new_desc, string new_extended_desc, string new_name, int new_room_id, vector<Door> _doors){
    desc = new_desc;
    extended_desc = new_extended_desc;
    name = new_name;
    room_id = new_room_id;
    doors = _doors;
}

// Accessors
string Room::getDesc() const{
    return this->desc;
}

string Room::getExtendedDesc() const{
    return this->extended_desc;

}
string Room::getName() const{
    return this->name;
}

int Room::getRoomId() const{
    return this->room_id;

}

vector<Door> Room::getDoors(){
  return doors;

}

int Room::numberOfDoors(){
  return doors.size();
}

// Mutators
bool Room::addDoor(Door new_door){
  for(Door door : doors){
    if(new_door.getDir() == door.getDir()){return false;}
  }
  doors.push_back(new_door);
  return true;

}

bool Room::setDescription(string new_desc){
    this->desc = new_desc;
    return this->desc == new_desc;

}
bool Room::setExtendeeDesc(string new_extended_desc){
    this->extended_desc = new_extended_desc;
    return this->extended_desc == new_extended_desc;
}
bool Room::setName(string new_name){
    this->name = new_name;
    return this->name == new_name;

}
bool Room::setRoomId(int new_room_id){
    this->room_id = new_room_id;
    return this->room_id == new_room_id;
}
