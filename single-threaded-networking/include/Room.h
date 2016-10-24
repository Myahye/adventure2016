#ifndef Room_h
#define Room_h

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Door.h"
#include "CustomError.h"


class Room {

private:
    std::vector<std::string> mDesc;
    std::vector<Door> doors;
    std::vector<std::string>& mExtendedDesc;
    std::string mName;
    unsigned int mRoomId;

public:

    // Default constructor
    Room();
    //Temp constructor for testing and first iteration
    Room(int& id, std::vector<std::string>& description, std::vector<Door> &new_doors);
    // Parameterized constructor
    Room(std::vector<std::string>& new_desc, std::vector<std::string>& new_extended_desc, std::string& new_name, int& new_room_id, std::vector<Door>& new_doors);

    // Accessors
    std::vector<std::string> getDesc() const;
    std::vector<std::string> getExtendedDesc() const;
    std::string getName() const;
    int getRoomId() const;
    std::vector<Door> getDoors() const;
    int numberOfDoors() const;
    int getRoomInDir(std::string direction) const;

    // Mutators
    void setDescription(std::vector<std::string>& new_desc);
    void setExtendedDesc(std::vector<std::string>& new_extended_desc);
    void setName(std::string& new_name);
    void setRoomId(const int new_room_id);
    bool addDoor(const Door& new_door);
};
#endif /* room_h */
