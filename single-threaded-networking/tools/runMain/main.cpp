#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Room.h"
#include "Door.h"
#include "Player.h"
#include "Npc.h"
#include "Model.h"

using namespace std;

int main() {
    // vector<Room> rooms;
    // Door door1("south");
    // Door door2("west");
    // Door door3("north");
    // vector<Door> doors;
    // doors.push_back(door1);
    // doors.push_back(door2);
    // string desc ="You stand in a grassy field nothing to get too excited about.  The field ";
    // string ext_desc = "The field extends toward the north and the west.  To the east you see Took Hill";
    // string name_room = "Grassy Field";
    // int id_room = 1128;
    // Room roomTest(desc, ext_desc, name_room, id_room, doors);
    // cout << roomTest.getName() <<endl;
    // cout << roomTest.getDesc() <<endl;
    // cout << roomTest.getRoomId() <<endl;
    // cout << roomTest.getExtendedDesc() <<endl;
    // vector<Door> retDoors = roomTest.getDoors();
    // if(!retDoors.empty()){
    //   for(Door d : retDoors){
    //       cout << "Door dir: " << d.getDir() <<endl;
    //   }
    // }else{
    //   cout << "No doors in room." <<endl;
    // }

    // cout << "Add test door1 " << door1.getDir() << " second time: " << roomTest.addDoor(door1) <<endl;
    // cout << "Add test door3 " << door3.getDir() << " first time: " << roomTest.addDoor(door3) <<endl;
    // retDoors = roomTest.getDoors();
    // if(!retDoors.empty()){
    //   for(Door d : retDoors){
    //       cout << "Door dir: " << d.getDir() <<endl;
    //   }
    // }else{
    //   cout << "No doors in room." <<endl;
    // }

    // Player player1{1, "Kieran", "1234"};
    // cout << "Player1 ID: " << player1.getId() << ", username: " << player1.getUsername() << ", password: " << player1.getPassword() <<endl;
    std::vector<std::string> filepath = {"../data/shire.yml","../data/midgaard.yml","../data/spells.yml"};
    Model testModelParse(filepath);
    testModelParse.printAll();
	return 0;
}
