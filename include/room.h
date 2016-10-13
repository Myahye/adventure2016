#ifndef room_h
#define room_h

#include <iostream>
#include <string>
#include <vector>
#include "Door.h"

using namespace std;

class Room {
private:
    string mDesc;
    vector<Door> doors;
    string mExtendedDesc;
    string mName;
    unsigned int mRoomId;
    //  Class Npc have not been created yet
    //    static vector<Npc> npcs;
    //  Class Object have not been created yet
    //    static vector<Object> npcs;
public:
    // Default constructor
    Room();
    
    // Parameterized constructor
    Room(string& new_desc, string& new_extended_desc, string& new_name, int& new_room_id, vector<Door> new_doors);
    
    // Accessors
    string getDesc() const;
    string getExtendedDesc() const;
    string getName() const;
    int getRoomId() const;
    vector<Door> getDoors();
    int numberOfDoors();
    
    // Mutators
    void setDescription(string& new_desc);
    void setExtendedDesc(string& new_extended_desc);
    void setName(string& new_name);
    void setRoomId(int& new_room_id);
    void addDoor(Door& new_door);
};
#endif /* room_h */
