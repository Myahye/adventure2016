#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "yamlParse.h"
#include "room.h"
using namespace std;

int main() {
    string desc ="You stand in a grassy field nothing to get too excited about.  The field ";
    string ext_desc = "The field extends toward the north and the west.  To the east you see Took Hill";
    string name_room = "Grassy Field";
    int id_room = 1128;
    Room temp(desc, ext_desc, name_room, id_room);
    cout << temp.getName() <<endl;
    cout << temp.getDesc() <<endl;
    cout << temp.getRoomId() <<endl;
    cout << temp.getExtendedDesc() <<endl;
    yamlParse();
    
	return 0;
}
