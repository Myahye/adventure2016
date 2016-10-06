#include "room.h"

// Constructor
Room::Room(){
    name = "NO_NAME";
    room_id = 0;
}

// Parameterized constructor
Room::Room(string new_desc, string new_extended_desc, string new_name, int new_room_id){
    desc = new_desc;
    extended_desc = new_extended_desc;
    name = new_name;
    room_id = new_room_id;
}

// Accessors
string Room::GetDesc() const{
    return this->desc;
}

string Room::GetExtendedDesc() const{
    return this->extended_desc;
    
}
string Room::GetName() const{
    return this->name;
}

int Room::getRoomId() const{
    return this->room_id;
    
}

// Mutators
bool Room::SetDescription(string new_desc){
    this->desc = new_desc;
    return this->desc == new_desc;
    
}
bool Room::SetExtendeeDesc(string new_extended_desc){
    this->extended_desc = new_extended_desc;
    return this->extended_desc == new_extended_desc;
}
bool Room::SetName(string new_name){
    this->name = new_name;
    return this->name == new_name;
    
}
bool Room::SetRoomId(int new_room_id){
    this->room_id = new_room_id;
    return this->room_id == new_room_id;
}
