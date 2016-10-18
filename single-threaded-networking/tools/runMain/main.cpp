
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

	//shortDesc tests:
	treasure.setShortDesc("OH hello there U migh be wondering why the red suit");
	assert(treasure.getShortDesc()=="OH hello there U migh be wondering why the red suit");
	cout <<"shortDesc: "<<treasure.getShortDesc()<<endl;
	cout<<endl;

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

void testObjectClone(){
	Object b1(11,"A box");
	b1.setCost(50);
	b1.setWeight(100);
	b1.addExtra("Extra are as follows");
	b1.addExtra("Knock knock, open up the door, it's real");
	b1.addExtra("Wit the non-stop, pop pop and stainless steel");
	b1.addExtra("Go hard gettin busy wit it");
	b1.addExtra("But I got such a good heart");
	cout<< "Object 1 id : "<<b1.getID()<<" Object 1 is: "<<b1.getItemType()<<endl;
	cout<<"Cost: "<<b1.getCost()<<" weight: "<<b1.getWeight()<<endl;
	cout<<"EXTRA: "<<endl;
	cout<<endl;
	printVectorContent(b1.getExtra());
	cout<<endl;

	/*lets copy this shit*/

	cout<<"OBJECT 2 COPY OF OBJECT 1"<<endl;
	Object b2(b1);
	b2.addExtra("I'll make a motherfucker wonder if he did it");
	b2.addExtra("Damn right and I'll do it again");
	b2.addExtra("Cuz I am right so I gots to win");

	cout<< "Object 2 id : "<<b2.getID()<<" Object 2 is: "<<b2.getItemType()<<endl;
	cout<<"Cost: "<<b2.getCost()<<" weight: "<<b2.getWeight()<<endl;
	cout<<"EXTRA: "<<endl;
	cout<<endl;
	printVectorContent(b2.getExtra());
	cout<<endl;

	cout<<"OBJECT 3 copy of OBJECT 1 WITH operator overloading"<<endl;
	Object b3(1,"Blank");
	b3=b2;

	b3.addExtra("Break break wit the enemy");
	b3.addExtra("But no matter how many cats I break bread wit");
	b3.addExtra("I'll break who you sendin me");

	cout<< "Object 3 id : "<<b3.getID()<<" Object 3 is: "<<b3.getItemType()<<endl;
	cout<<"Cost: "<<b3.getCost()<<" weight: "<<b3.getWeight()<<endl;
	cout<<"EXTRA: "<<endl;
	cout<<endl;
	printVectorContent(b3.getExtra());
	cout<<endl;

}

int main() {
	testObjectClass();
	//testObjectClone();
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
