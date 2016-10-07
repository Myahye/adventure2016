//
//  Door.cpp
//  Door
//
//  Created by JUN DA LI on 16/10/5.
//
//

#include <iostream>
#include <string>
#include "door.h"
#include <fstream>

using namespace std;

Door::Door(){
    desc = "none";
    dir = "none";
    keywords = "none";
    Door_id = 0;
    to = 0;
}

Door::Door(string new_desc, string new_dir, string new_keywords, int new_door_id, int new_to){
    desc = new_desc;
    dir = new_dir;
    keywords = new_keywords;
    Door_id = new_door_id;
    to = new_to;
}

string Door::getDesc() const{
    return this -> desc;
//    for (auto el : element["description"]){
//        cout << el.as<string>() << "\n";
//    }
}

string Door::getDir() const{
    return this -> dir;
//    for (auto el : element){
//        cout << el.as<string>() << "\n";
//    }
}

string Door::getKeywords() const{
    return this -> keywords;
//    for (auto el : element["keywords"]){
//        cout << el.as<string>() << "\n";
//    }
}

int Door::getDoorId() const {
    return this -> Door_id;
}

//Needs to be changed
int Door::getTo() const{
    return this -> to;
}

bool Door::setDesc(string new_desc){
    this -> desc = new_desc;
    return this -> desc == new_desc;
}

bool Door::setDir(string new_dir)
{
    this -> dir = new_dir;
    return this -> dir == new_dir;
}

bool Door::setKeywords(string new_keywords){
    this -> keywords = new_keywords;
    return this -> keywords == new_keywords;
}

bool Door::setDoorId(int new_door_id){
    this -> Door_id = new_door_id;
    return this -> Door_id == new_door_id;
}
