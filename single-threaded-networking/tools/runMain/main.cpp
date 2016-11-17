#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <assert.h>

#include "Room.h"
#include "Door.h"
#include "Character.h"

using namespace std;

/*void NpcTest() {
    // Empty constructor test:
    Npc* defaultNpc = new Npc();
    assert(defaultNpc != NULL);
    assert(defaultNpc->getId() == 0);
    assert(defaultNpc->getShortdesc() == "");

    cout << "Default NPC: " << endl;
    cout << "ID: " << defaultNpc->getId() << endl;
    cout << "shortdesc: " << defaultNpc->getShortdesc() << endl;
    defaultNpc->attack();
    cout << endl;

    // Parameterized constructor test:
    Npc* npc = new Npc(12345, "Test");
    cout << "Parameterized NPC: " << endl;
    cout << "ID: " << npc->getId() << endl;
    cout << "shortdesc: " << npc->getShortdesc() << endl;
    npc->attack();

    npc->setArmor(100);
    assert(npc->getArmor() == 100);
    cout << "Armor: " << npc->getArmor() << endl;

    npc->setExp(1000);
    assert(npc->getExp() == 1000);
    cout << "Exp: " << npc->getExp() << endl;

    npc->setGold(250);
    assert(npc->getGold() == 250);
    cout << "Gold: " << npc->getGold() << endl;

    npc->setLevel(1);
    assert(npc->getLevel() == 1);
    cout << "Level: " << npc->getLevel() << endl;

    npc->setThac0(0);
    assert(npc->getThac0() == 0);
    cout << "Thac0: " << npc->getThac0() << endl;

    npc->setDamage("1d8+4");
    assert(npc->getDamage() == "1d8+4");
    cout << "Damage: " << npc->getDamage() << endl;

    vector<string> testDescription;
    testDescription.push_back("Test description 1..");
    npc->setDescription(testDescription);
    cout << "Description: " << endl;
    cout << npc->getDescription();

    npc->setHit("1d4+4");
    assert(npc->getHit() == "1d4+4");
    cout << "Hit: " << npc->getHit() << endl;

    vector<string> testKeywords;
    testKeywords.push_back("Test keywords 1..");
    testKeywords.push_back("Test keywords 2..");
    npc->setKeywords(testKeywords);
    assert(npc->getKeywords().size() > 0);
    cout << "Keywords: " << endl;
    cout << npc->getKeywords().at(0) << endl;
    cout << npc->getKeywords().at(1) << endl;

    vector<string> testLongdesc;
    testLongdesc.push_back("Test longdesc 1..");
    testLongdesc.push_back("Test longdesc 2..");
    npc->setLongdesc(testLongdesc);
    assert(npc->getLongdesc().size() > 0);
    cout << "Longdesc: " << endl;
    cout << npc->getLongdesc() << endl;
}*/

void refactoringTest(){
    Character playerChar(1234, "abc", "123");
    Character npcChar(123, "short desc");

    playerChar.setArmor(5);
    npcChar.setArmor(1);

    cout << "Player armor: " << playerChar.getArmor() << endl;
    cout << "Player username: " << playerChar.getCharacterType().getUsername() << endl;
    cout << "NPC armor: " << npcChar.getArmor() << endl;
    cout << "NPC shortdesc: " << npcChar.getCharacterType().getShortDesc() << endl;
}

int main() {
    refactoringTest();
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
