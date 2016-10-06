#ifndef room_h
#define room_h

#include <iostream>
#include <string>
#include <vector>
//#include "Door.h"

using namespace std;

class Room {
private:
    string desc;
//  Class Door have not been created yet
    //    static vector<Door> doors;
    string extended_desc;
    string name;
    unsigned int room_id;
//  Class Npc have not been created yet
    //    static vector<Npc> npcs;
//  Class Object have not been created yet
    //    static vector<Object> npcs;
public:
    // Default constructor
    Room();
    
    // Parameterized constructor
    Room(string new_desc, string new_extended_desc, string new_name, int new_room_id);
    
    // Accessors
    string GetDesc() const;
    string GetExtendedDesc() const;
    string GetName() const;
    int getRoomId() const;
    
    // Mutators
    bool SetDescription(string new_desc);
    bool SetExtendeeDesc(string new_extended_desc);
    bool SetName(string new_name);
    bool SetRoomId(int new_room_id);
    
};
#endif /* room_h */
