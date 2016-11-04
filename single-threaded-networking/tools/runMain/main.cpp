#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Room.h"
#include "Door.h"
#include "Player.h"
#include "CharacterImp.h"
#include "Character.h"

using namespace std;

void characterTest() {
    // Character test:
    Character* character = new Character();
    cout << "Initial character values: "<< endl;
    cout << "ID: " << character->getId() << endl;

    character->setId(12345);
    cout << "ID: " << character->getId() << endl;

    character->setArmor(100);
    cout << "Armor: " << character->getArmor() << endl;

    character->setExp(2000);
    cout << "Exp: " << character->getExp() << endl;

    character->setGold(1000);
    cout << "Gold: " << character->getGold() << endl;

    character->setLevel(5);
    cout << "Level: " << character->getLevel() << endl;

    character->setThac0(25);
    cout << "Thac0: " << character->getThac0() << endl;

    character->setDamage("1d6+4");
    cout << "Damage: " << character->getDamage() << endl;

    vector<string> testDescription;
    testDescription.push_back("Test description 1");
    testDescription.push_back("Test description 2");
    testDescription.push_back("Test description 3");
    character->setDescription(testDescription);
    cout << "Description: " << endl; 
    cout << character->getDescription();

    character->setHit("10");
    cout << "Hit: " << character->getHit() << endl;

    vector<string> testKeywords;
    testKeywords.push_back("Test keywords 1");
    testKeywords.push_back("Test keywords 2");
    testKeywords.push_back("Test keywords 3");
    character->setKeywords(testKeywords);
    cout << "keywords: " << endl;
    cout << character->getKeywords().at(0) << endl;
    cout << character->getKeywords().at(1) << endl;
    cout << character->getKeywords().at(2) << endl;

    vector<string> testLongdesc;
    testLongdesc.push_back("Test longdesc 1");
    testLongdesc.push_back("Test longdesc 2");
    testLongdesc.push_back("Test longdesc 3");
    character->setLongdesc(testLongdesc);
    cout << "Longdesc: " << endl;
    cout << character->getLongdesc() << endl;
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
