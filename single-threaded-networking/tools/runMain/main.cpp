
// main.cpp
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Object.h"
#include <assert.h>

using namespace std;

void printVectorContent(const vector<string>& test) {
	for(auto x : test) {
		cout << x << endl;
	}
	cout << endl;
}

void testObjectClass() {
	// Create Object
	Object treasure(12345, "Treasure chest");
	assert(treasure.getID() == 12345);
	assert(treasure.getItemType() == "Treasure chest");
	cout << "Object: " << treasure.getItemType() << " with ID: " << treasure.getID() << endl; 
	cout << endl;

	// Cost and weight tests:
	treasure.setCost(1000);
	assert(treasure.getCost() == 1000);
	treasure.setWeight(100);
	assert(treasure.getWeight() == 100);
	cout << "Cost: " << treasure.getCost() << " Weight: " << treasure.getWeight() << endl;
	cout << endl;

	// Attributes tests:
	assert(treasure.getAttributes().size() == 0);
	vector<string>testAttributes;
	testAttributes.push_back("Test attribute 1");
	testAttributes.push_back("Test attribute 2");
	treasure.setAttributes(testAttributes);
	assert(treasure.getAttributes().size() == 2);
	treasure.addAttribute("Test Attribute 3");
	assert(treasure.getAttributes().size() == 3);
	cout << "Attributes: " << endl;
	printVectorContent(treasure.getAttributes());

	// Keywords tests:
	assert(treasure.getKeyWords().size() == 0);
	vector<string>testKeywords;
	testKeywords.push_back("Test keyword 1");
	treasure.setKeyWords(testKeywords);
	assert(treasure.getKeyWords().size() == 1);
	treasure.addKeyWord("Test keyword 2");
	treasure.addKeyWord("Test keyword 3");
	assert(treasure.getKeyWords().size() == 3);
	cout << "KeyWords: " << endl;
	printVectorContent(treasure.getKeyWords());

	// LongDesc tests:
	assert(treasure.getLongDesc().size() == 0);
	vector<string>testLongDesc;
	testLongDesc.push_back("Test long description 1");
	testLongDesc.push_back("Test long description 2");
	treasure.setLongDesc(testLongDesc);
	assert(treasure.getLongDesc().size() == 2);
	treasure.addLongDesc("Test long description 3");
	assert(treasure.getLongDesc().size() == 3);
	cout << "LongDesc: " << endl;
	printVectorContent(treasure.getLongDesc());

	// ShortDesc tests:
	assert(treasure.getShortDesc().size() == 0);
	vector<string>testShortDesc;
	testShortDesc.push_back("Test short description 1");
	testShortDesc.push_back("Test short description 2");
	treasure.setShortDesc(testShortDesc);
	assert(treasure.getShortDesc().size() == 2);
	treasure.addShortDesc("Test short description 3");
	assert(treasure.getShortDesc().size() == 3);
	cout << "ShortDesc: " << endl;
	printVectorContent(treasure.getShortDesc());

	// WearFlags tests:
	assert(treasure.getWearFlags().size() == 0);
	vector<string>testWearFlags;
	testWearFlags.push_back("Test wear flag 1");
	treasure.setWearFlags(testWearFlags);
	assert(treasure.getWearFlags().size() == 1);
	treasure.addWearFlag("Test wear flag 2");
	treasure.addWearFlag("Test wear flag 3");
	treasure.addWearFlag("Test wear flag 4");
	treasure.addWearFlag("Test wear flag 5");
	assert(treasure.getWearFlags().size() == 5);
	cout << "WearFlags: " << endl;
	printVectorContent(treasure.getWearFlags());

	// Extra tests:
	assert(treasure.getExtra().size() == 0);
	vector<string> testExtra;
	testExtra.push_back("Test extra 1");
	treasure.setExtra(testExtra);
	assert(treasure.getExtra().size() == 1);
	treasure.addExtra("Test extra 2");
	assert(treasure.getExtra().size() == 2);
	cout << "Extra: " << endl;
	printVectorContent(treasure.getExtra());

	cout << "Finished Object class tests!" << endl;
}

int main() {
	testObjectClass();

	/*

    vector<Room> rooms;
    Door door1("south");
    Door door2("west");
    Door door3("north");
    vector<Door> doors;
    doors.push_back(door1);
    doors.push_back(door2);
    string desc ="You stand in a grassy field nothing to get too excited about.  The field ";
    string ext_desc = "The field extends toward the north and the west.  To the east you see Took Hill";
    string name_room = "Grassy Field";
    int id_room = 1128;
    Room roomTest(desc, ext_desc, name_room, id_room, doors);
    cout << roomTest.getName() <<endl;
    cout << roomTest.getDesc() <<endl;
    cout << roomTest.getRoomId() <<endl;
    cout << roomTest.getExtendedDesc() <<endl;
    vector<Door> retDoors = roomTest.getDoors();
    if(!retDoors.empty()){
      for(Door d : retDoors){
          cout << "Door dir: " << d.getDir() <<endl;
      }
    }else{
      cout << "No doors in room." <<endl;
    }

    cout << "Add test door1 " << door1.getDir() << " second time: " << roomTest.addDoor(door1) <<endl;
    cout << "Add test door3 " << door3.getDir() << " first time: " << roomTest.addDoor(door3) <<endl;
    retDoors = roomTest.getDoors();
    if(!retDoors.empty()){
      for(Door d : retDoors){
          cout << "Door dir: " << d.getDir() <<endl;
      }
    }else{
      cout << "No doors in room." <<endl;
    }

    Player player1{1, "Kieran", "1234"};
    cout << "Player1 ID: " << player1.getId() << ", username: " << player1.getUsername() << ", password: " << player1.getPassword() <<endl;
	
	*/

	return 0;
}
