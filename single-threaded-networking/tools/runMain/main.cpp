#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Room.h"
#include "Door.h"
#include "Player.h"
#include "Person.h"
#include "NPC.h"

using namespace std;

void testNPC() {
    cout << "Testing NPC Class.. " << endl;

    NPC* testNPC = new NPC(12345, "Test NPC");
    cout << testNPC->getShortdesc() << " with id: " << testNPC->getId() << endl;
    
    testNPC->setArmor(100);
    cout << "Armor: " << testNPC->getArmor() << endl;

    testNPC->setExp(2500);
    cout << "Exp: " << testNPC->getExp() << endl;

    testNPC->setGold(500);
    cout << "Gold: " << testNPC->getGold() << endl;

    testNPC->setLevel(15);
    cout << "Level: " << testNPC->getLevel() << endl;

    testNPC->setThac0(10);
    cout << "Thac0: " << testNPC->getThac0() << endl;

    testNPC->setDamage("1d8+16");
    cout << "Damage: " << testNPC->getDamage() << endl;

    testNPC->setHit("19d19+190");
    cout << "Hit: " << testNPC->getHit() << endl;

    vector<string> testDescription;
    testDescription.push_back("This is a test NPC class. ");
    testDescription.push_back("Testing description getter/setter. ");
    testNPC->setDescription(testDescription);
    cout << "Description: " << testNPC->getDescription();

    vector<string> testKeywords;
    testKeywords.push_back("This is a test NPC Class. ");
    testKeywords.push_back("Testing keyword getter/setter. ");
    cout << "Keywords: " << testKeywords.at(0) << endl;
    cout << testKeywords.at(1) << endl;

    vector<string> testLongdesc;
    testLongdesc.push_back("This is a test NPC class. ");
    testLongdesc.push_back("Testing longdesc getter/setter. ");
    testNPC->setLongdesc(testLongdesc);
    cout << "Description: " << testNPC->getLongdesc() << endl;
}

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

	return 0;
}
