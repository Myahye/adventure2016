//
//  Door.h
//  Door
//
//  Created by JUN DA LI on 16/10/4.
//
//

#ifndef Door_h
#define Door_h

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Door{
public:
    Door();
    Door(string new_desc, string new_dir, string new_keywords, int new_door_id, int new_to);

    string getDesc() const;
    string getDir() const;
    string getKeywords() const;
    int getDoorId() const;
    int getTo() const;

    bool setDesc(string new_desc);
    bool setDir(string new_dir);
    bool setKeywords(string new_keywords);
    bool setDoorId(int new_door_id);


private:
    string desc;
    string dir;
    string keywords;
    unsigned int Door_id;
    unsigned int to;

};




#endif /* Door_h */
