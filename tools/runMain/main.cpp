#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "yamlParse.h"
#include "room.h"

int main() {
    string desc ="You stand in a grassy field nothing to get too excited about.  The field ";
    string ext_desc = "The field extends toward the north and the west.  To the east you see Took Hill";
    string name_room = "Grassy Field";
    int id_room = 1128;
    Room temp(desc, ext_desc, name_room, id_room);
    std::cout << temp.GetName() <<endl;
    std::cout << temp.GetDesc() <<endl;
    std::cout << temp.getRoomId() <<endl;
    std::cout << temp.GetExtendedDesc() <<endl;
    yamlParse();
    
	return 0;
}
