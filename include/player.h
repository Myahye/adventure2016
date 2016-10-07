#ifndef room_h
#define room_h
#include "door.h"
#include <iostream>
#include <string>
#include <vector>
//#include "Door.h"

using namespace std;

class Player {
private:
    string desc;

    string extended_desc;
    string name;
    unsigned int room_id;
    vector<Door> doors;
//  Class Npc have not been created yet
    //    static vector<Npc> npcs;
//  Class Object have not been created yet
    //    static vector<Object> npcs;
public:
    // Default constructor
    Room();

    // Parameterized constructor
    Room(string new_desc, string new_extended_desc, string new_name, int new_room_id, vector<Door> _doors);

    // Accessors
    string getDesc() const;
    string getExtendedDesc() const;
    string getName() const;
    int getRoomId() const;
    vector<Door> getDoors();
    int numberOfDoors();

    // Mutators
    bool setDescription(string new_desc);
    bool setExtendeeDesc(string new_extended_desc);
    bool setName(string new_name);
    bool setRoomId(int new_room_id);
    bool addDoor(Door new_door);
};
#endif /* room_h */
