#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "yamlParse.h"
#include "room.h"
#include "door.h"
using namespace std;

int main() {
    vector<Room> rooms;
    Door door1;
    vector<Door> doors;
    doors.push_back(door1);
    string desc ="You stand in a grassy field nothing to get too excited about.  The field ";
    string ext_desc = "The field extends toward the north and the west.  To the east you see Took Hill";
    string name_room = "Grassy Field";
    int id_room = 1128;
    Room temp(desc, ext_desc, name_room, id_room, doors);
    cout << temp.getName() <<endl;
    cout << temp.getDesc() <<endl;
    cout << temp.getRoomId() <<endl;
    cout << temp.getExtendedDesc() <<endl;
    vector<Door> retDoors = temp.getDoors();
    for(Door d : retDoors){
        cout << "Door desc: " << d.getDesc() <<endl;
    }
    
	return 0;
}
