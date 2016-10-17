#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Room.h"
#include "Door.h"
#include "Player.h"
#include "NPC.h"
using namespace std;

void NPC_clone_test(){
  cout << "/*-------------------------------------------------*/" <<endl;

  NPC victor(125,"Victor is a merchant");
  victor.setArmor(50);
  victor.setExp(1000);
  victor.setGold(9999);
  victor.setLevel(5);
  victor.setThac0(3);

  victor.setDamage("1ds5+5");
  victor.setHit("h55");
  victor.setShortDesc("the merchant of venice");

  std::vector<std::string> toADD;
  toADD.push_back("comment 1");
  toADD.push_back("comment 2");
  victor.setDesc(toADD);

  cout<<"NPC DETAILS: "<<endl;
  cout<<"Armor      : "<<victor.getArmor()<<endl;
  cout<<"EXP        : "<<victor.getExp()<<endl;
  cout<<"GOLD       : "<<victor.getGold()<<endl;
  cout<<"ID         : "<<victor.getId()<<endl;
  cout<<"Level      : "<<victor.getLevel()<<endl;
  cout<<"thac0      : "<<victor.getThac0()<<endl;
  cout<<"damage     : "<<victor.getDamage()<<endl;
  cout<<"hit        : "<<victor.getHit()<<endl;
  cout<<"shortdesc  : "<<victor.getShortDesc()<<endl;

  victor.printDesc();
  cout << "/*-------------------------------------------------*/" <<endl;

  /*create rache from victor with Constructor*/
  NPC rache(victor);
  rache.setShortDesc("rache is a copy of victor with Constructor");
  cout<<"NPC DETAILS: "<<endl;
  cout<<"Armor      : "<<rache.getArmor()<<endl;
  cout<<"EXP        : "<<rache.getExp()<<endl;
  cout<<"GOLD       : "<<rache.getGold()<<endl;
  cout<<"ID         : "<<rache.getId()<<endl;
  cout<<"Level      : "<<rache.getLevel()<<endl;
  cout<<"thac0      : "<<rache.getThac0()<<endl;
  cout<<"damage     : "<<rache.getDamage()<<endl;
  cout<<"hit        : "<<rache.getHit()<<endl;
  cout<<"shortdesc  : "<<rache.getShortDesc()<<endl;

  rache.printDesc();

  cout << "/*-------------------------------------------------*/" <<endl;
  /*create rachel from victor*/
  NPC rachel(0,"Blank");
  rachel=victor;
  rachel.setShortDesc("rachel is a copy of victor with = operator");

  cout<<"NPC DETAILS: "<<endl;
  cout<<"Armor      : "<<rachel.getArmor()<<endl;
  cout<<"EXP        : "<<rachel.getExp()<<endl;
  cout<<"GOLD       : "<<rachel.getGold()<<endl;
  cout<<"ID         : "<<rachel.getId()<<endl;
  cout<<"Level      : "<<rachel.getLevel()<<endl;
  cout<<"thac0      : "<<rachel.getThac0()<<endl;
  cout<<"damage     : "<<rachel.getDamage()<<endl;
  cout<<"hit        : "<<rachel.getHit()<<endl;
  cout<<"shortdesc  : "<<rachel.getShortDesc()<<endl;

  rachel.printDesc();
  cout << "/*-------------------------------------------------*/" <<endl;

}


int main() {
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


  NPC_clone_test();
	return 0;
}
