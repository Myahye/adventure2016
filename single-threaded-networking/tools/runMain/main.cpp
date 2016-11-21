#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <assert.h>
#include <algorithm>

#include "Room.h"
#include "Door.h"
#include "Npc.h"
#include "Player.h"
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
    Player player(1234, "abc", "123");
    Npc npc(123);

    npc.npcCharacter.setArmor(1);
    npc.npcCharacter.setExp(2);
    npc.npcCharacter.setGold(3);
    npc.npcCharacter.setLevel(4);
    npc.npcCharacter.setMaxHealth(5);
    npc.npcCharacter.setMaxMana(6);
    npc.npcCharacter.setCurrentHealth(7);
    npc.npcCharacter.setCurrentMana(8);
    npc.npcCharacter.setThac0(9);
    npc.npcCharacter.setDamage("npc damage");
    npc.npcCharacter.setHit("npc Hit");
    vector<string> descV;
    descV.push_back("111111");
    descV.push_back("222222");
    npc.npcCharacter.setDescription(descV);
    npc.npcCharacter.setShortDesc("npc shortDesc");

    player.playerCharacter.setArmor(10000);
    player.playerCharacter.setExp(20000);
    player.playerCharacter.setGold(30000);
    player.playerCharacter.setLevel(40000);
    player.playerCharacter.setMaxHealth(50000);
    player.playerCharacter.setMaxMana(60000);
    player.playerCharacter.setCurrentHealth(70000);
    player.playerCharacter.setCurrentMana(80000);
    player.playerCharacter.setThac0(90000);
    player.playerCharacter.setDamage("player damage");
    player.playerCharacter.setHit("player Hit");
    vector<string> descV2;
    descV2.push_back("000000");
    descV2.push_back("999999");
    player.playerCharacter.setDescription(descV2);
    player.playerCharacter.setShortDesc("player shortDesc");

    cout << "===Before swapping==="<< endl;
    cout << "npc armor: " << npc.npcCharacter.getArmor() << endl;
    cout << "npc exp: " << npc.npcCharacter.getExp() << endl;
    cout << "npc gold: " << npc.npcCharacter.getGold() << endl;
    cout << "npc level: " << npc.npcCharacter.getLevel() << endl;
    cout << "npc max health: " << npc.npcCharacter.getMaxHealth() << endl;
    cout << "npc max mana: " << npc.npcCharacter.getMaxMana() << endl;
    cout << "npc current health: " << npc.npcCharacter.getCurrentHealth() << endl;
    cout << "npc current mana: " << npc.npcCharacter.getCurrentMana() << endl;
    cout << "npc thac0: " << npc.npcCharacter.getThac0() << endl;
    cout << "npc damage: " << npc.npcCharacter.getDamage() << endl;
    cout << "npc hit: " << npc.npcCharacter.getHit() << endl;
    cout << "npc description: " << npc.npcCharacter.getDescription() << endl;
    cout << "npc shortdesc: " << npc.npcCharacter.getShortDesc() << endl;

    cout << "Player armor: " << player.playerCharacter.getArmor() << endl;
    cout << "Player username: " << player.getUsername() << endl;
    cout << "Player exp: " << player.playerCharacter.getExp() << endl;
    cout << "Player gold: " << player.playerCharacter.getGold() << endl;
    cout << "Player level: " << player.playerCharacter.getLevel() << endl;
    cout << "Player max health: " << player.playerCharacter.getMaxHealth() << endl;
    cout << "Player max mana: " << player.playerCharacter.getMaxMana() << endl;
    cout << "Player current health: " << player.playerCharacter.getCurrentHealth() << endl;
    cout << "Player current mana: " << player.playerCharacter.getCurrentMana() << endl;
    cout << "Player thac0: " << player.playerCharacter.getThac0() << endl;
    cout << "Player damage: " << player.playerCharacter.getDamage() << endl;
    cout << "Player hit: " << player.playerCharacter.getHit() << endl;
    cout << "Player description: " << player.playerCharacter.getDescription() << endl;
    cout << "Player shortdesc: " << player.playerCharacter.getShortDesc() << endl;

    cout << endl << endl;

    swap(player.playerCharacter,npc.npcCharacter);

    cout << "===After swapping==="<< endl;
    cout << "npc armor: " << npc.npcCharacter.getArmor() << endl;
    cout << "npc exp: " << npc.npcCharacter.getExp() << endl;
    cout << "npc gold: " << npc.npcCharacter.getGold() << endl;
    cout << "npc level: " << npc.npcCharacter.getLevel() << endl;
    cout << "npc max health: " << npc.npcCharacter.getMaxHealth() << endl;
    cout << "npc max mana: " << npc.npcCharacter.getMaxMana() << endl;
    cout << "npc current health: " << npc.npcCharacter.getCurrentHealth() << endl;
    cout << "npc current mana: " << npc.npcCharacter.getCurrentMana() << endl;
    cout << "npc thac0: " << npc.npcCharacter.getThac0() << endl;
    cout << "npc damage: " << npc.npcCharacter.getDamage() << endl;
    cout << "npc hit: " << npc.npcCharacter.getHit() << endl;
    cout << "npc description: " << npc.npcCharacter.getDescription() << endl;
    cout << "npc shortdesc: " << npc.npcCharacter.getShortDesc() << endl;
    
    cout << "Player armor: " << player.playerCharacter.getArmor() << endl;
    cout << "Player username: " << player.getUsername() << endl;
    cout << "Player exp: " << player.playerCharacter.getExp() << endl;
    cout << "Player gold: " << player.playerCharacter.getGold() << endl;
    cout << "Player level: " << player.playerCharacter.getLevel() << endl;
    cout << "Player max health: " << player.playerCharacter.getMaxHealth() << endl;
    cout << "Player max mana: " << player.playerCharacter.getMaxMana() << endl;
    cout << "Player current health: " << player.playerCharacter.getCurrentHealth() << endl;
    cout << "Player current mana: " << player.playerCharacter.getCurrentMana() << endl;
    cout << "Player thac0: " << player.playerCharacter.getThac0() << endl;
    cout << "Player damage: " << player.playerCharacter.getDamage() << endl;
    cout << "Player hit: " << player.playerCharacter.getHit() << endl;
    cout << "Player description: " << player.playerCharacter.getDescription() << endl;
    cout << "Player shortdesc: " << player.playerCharacter.getShortDesc() << endl;

    cout << endl << endl;


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
