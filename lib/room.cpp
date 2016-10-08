#include "room.h"

// Constructor
Room::Room(){
    string desc ="No Description";
    string ext_desc = "No extended description";
    string name_room = "Empty Room";
    int id_room = 1128;
    Room(desc, ext_desc, name_room, id_room);
}

// Parameterized constructor
Room::Room(string& new_desc, string& new_extended_desc, string& new_name, int& new_room_id):
mDesc{new_desc},mExtendedDesc{new_extended_desc},
mName{new_name},mRoomId{static_cast<unsigned int>(new_room_id)}{
}

// Accessors
string Room::getDesc() const{
    return this->mDesc;
}

string Room::getExtendedDesc() const{
    return this->mExtendedDesc;
    
}
string Room::getName() const{
    return this->mName;
}

int Room::getRoomId() const{
    return this->mRoomId;
}

// Mutators
void Room::setDescription(string& new_desc){
    this->mDesc = new_desc;
    
}
void Room::setExtendedDesc(string& new_extended_desc){
    this->mExtendedDesc = new_extended_desc;
}
void Room::setName(string& new_name){
    this->mName = new_name;
    
}
void Room::setRoomId(int& new_room_id){
    this->mRoomId = new_room_id;
}
