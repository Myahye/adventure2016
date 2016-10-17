#ifndef Room_h
#define Room_h

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Door.h"
using namespace std;
#include "CustomError.h"

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

    Room(int id, std::string description, vector<Door> new_doors);

    // Parameterized constructor
    Room(string& new_desc, string& new_extended_desc, string& new_name, int& new_room_id, vector<Door> new_doors);

    // Accessors
    string getDesc() const;
    string getExtendedDesc() const;
    string getName() const;
    int getRoomId() const;
    vector<Door> getDoors();
    int numberOfDoors();
    int getRoomInDir(std::string direction);
    // Mutators
    void setDescription(string& new_desc);
    void setExtendedDesc(string& new_extended_desc);
    void setName(string& new_name);
    void setRoomId(int& new_room_id);
    bool addDoor(Door& new_door);
};
#endif /* room_h */
