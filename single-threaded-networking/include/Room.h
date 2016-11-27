#ifndef Room_h
#define Room_h

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include "Door.h"
#include "Npc.h"
#include "Player.h"

//#include "CustomError.h"


class Room {

private:
    std::vector<std::string> mDesc;
    std::vector<std::pair<std::vector<std::string>, std::vector<std::string> > > mExtendedDesc;
    std::string mName;
    unsigned int mRoomId;
    std::vector<Door> doors;

    //--------------------------------------Lawrence Yu
    std::unordered_map<int,std::vector<Npc>> npcsInRoom;
    std::unordered_map<int,std::vector<Object>> objectsInRoom;
    
    //Maybe change to not use pointers
    Npc* checkNpcKeywords(const std::string& message, const std::pair<int,std::vector<Npc>>& npcIdVectorPair);
    Object* checkObjectKeywords(const std::string& message, const std::pair<int,std::vector<Object>>& objectIdVectorPair);
    //Player* checkPlayerUsername(const std::string& message, const std::pair<int,Player*>& player);

public:
std::unordered_map<int, std::string> playersInRoom;
    // Default constructor
    Room();
    //Temp constructor for testing and first iteration
    Room(int& id, std::vector<std::string>& description, std::vector<Door> &new_doors);
    // Parameterized constructor
    Room(std::vector<std::string>& new_desc, std::pair< std::vector<std::string>, std::vector<std::string> >& new_extended_desc, std::string& new_name, int& new_room_id, std::vector<Door>& new_doors);

    // Accessors
    std::string getDesc() const;
<<<<<<< HEAD
    std::vector <std::string> getDescV() const;
    std::vector< std::pair<std::vector<std::string>, std::vector<std::string> > > getExtendedDesc() const;
=======
    std::vector<std::pair<std::vector<std::string>, std::vector<std::string> > > getExtendedDesc() const;
>>>>>>> Fix none doors
    std::string getName() const;
    int getRoomId() const;
    std::vector<Door> getDoors() const;
    int numberOfDoors() const;
    int getRoomInDir(std::string direction) const;

    // Mutators
    void setDescription(std::vector<std::string>& new_desc);
<<<<<<< HEAD
    void setExtendedDesc(const std::vector< std::pair<std::vector<std::string>, std::vector<std::string> > >& new_extended_desc);
=======
    void setExtendedDesc(std::vector<std::pair<std::vector<std::string>, std::vector<std::string> > > & new_extended_desc);
>>>>>>> Fix none doors
    void setName(std::string& new_name);
    void setRoomId(const int new_room_id);
    bool addDoor(const Door& new_door);
    void addVectorDoors(std::vector<Door>& new_vector_doors);
    //New function added in to test
    void printClass(int n) const;
    void printVector(const std::vector<std::string>& vec) const;
    
    //--------------------------------------Lawrence Yu
    Npc* addNpc(Npc& npc, unsigned int limit);
    bool removeNpc(const int npcId);

    void addObject(const Object& object, unsigned int limit);
    bool removeObject(const int objectId);

    Npc* findNpc(const std::string& name);
    Object* findObject(const std::string& name);

    std::unordered_map<int,std::vector<Npc>> getNpcsInRoom() const;
    std::unordered_map<int,std::vector<Object>> getObjectsInRoom() const;

    std::string getNpcsInRoomDesc() const;
    std::string getObjectsInRoomDesc() const;
    std::string getDoorsInRoomDesc() const;
    std::string getFullRoomDesc() const;

    void addVectorDoors(const std::vector<Door>& doors_);

};
#endif /* room_h */