#ifndef Room_h
#define Room_h

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include "Door.h"
#include "Npc.h"
#include "Object.h"
//#include "CustomError.h"


class Room {

private:
    std::vector<std::string> mDesc;
    std::pair< std::vector<std::string>, std::vector<std::string> > mExtendedDesc;
    std::string mName;
    unsigned int mRoomId;
    std::vector<Door> doors;

    //--------------------------------------Lawrence Yu
    std::unordered_map<int,std::vector<Npc>> npcsInRoom;
    std::unordered_map<int,std::vector<Object>> objectsInRoom;

    Npc* checkNpcKeywords(const std::string& message, const std::pair<int,std::vector<Npc>>& npcIdVectorPair);
    Object* checkObjectKeywords(const std::string& message, const std::pair<int,std::vector<Object>>& objectIdVectorPair);

public:

    // Default constructor
    Room();
    //Temp constructor for testing and first iteration
    Room(int& id, std::vector<std::string>& description, std::vector<Door> &new_doors);
    // Parameterized constructor
    Room(std::vector<std::string>& new_desc, std::pair< std::vector<std::string>, std::vector<std::string> >& new_extended_desc, std::string& new_name, int& new_room_id, std::vector<Door>& new_doors);

    // Accessors
    std::string getDesc() const;
    std::pair< std::vector<std::string>, std::vector<std::string> > getExtendedDesc() const;
    std::string getName() const;
    int getRoomId() const;
    std::vector<Door> getDoors() const;
    int numberOfDoors() const;
    int getRoomInDir(std::string direction) const;

    // Mutators
    void setDescription(std::vector<std::string>& new_desc);
    void setExtendedDesc(std::pair< std::vector<std::string>, std::vector<std::string> >& new_extended_desc);
    void setName(std::string& new_name);
    void setRoomId(const int new_room_id);
    bool addDoor(const Door& new_door);

    //New function added in to test
    void printClass(int n) const;

    //--------------------------------------Lawrence Yu
    Npc* addNpc(Npc& npc, unsigned int limit);
    bool removeNpc(const std::string& npcName);

    void addObject(const Object& object, unsigned int limit);
    bool removeObject(const std::string& objectName);

    Npc* findNpc(const std::string& message);
    Object* findObject(const std::string& message);

    std::unordered_map<int,std::vector<Npc>> getNpcsInRoom() const;
    std::unordered_map<int,std::vector<Object>> getObjectsInRoom() const;

    std::string getNpcsInRoomDesc() const;
    std::string getObjectsInRoomDesc() const;
    std::string getDoorsInRoomDesc() const;
    std::string getFullRoomDesc() const;

};
#endif /* room_h */