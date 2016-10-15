//#include <iostream>
#include "Door.h"
//#include <fstream>

using namespace std;

Door::Door() {
    this->desc = "none";
    this->dir = "none";
    this->keywords = "none";
    this->Door_id = 0;
    this->to = 0;
}
Door::Door(string dir) {
    this->desc = "none";
    this->dir = dir;
    this->keywords = "none";
    this->Door_id = 0;
    this->to = 0;
}
Door::Door(string& new_desc, string& new_dir, string& new_keywords, int& new_door_id, int& new_to)
        : desc{new_desc}
        , dir{new_dir}
        , keywords{new_keywords}
        , Door_id{static_cast<unsigned int>(new_door_id)}
        , to{static_cast<unsigned int>(new_to)} {}

string Door::getDesc() const {
    return this -> desc;
}

string Door::getDir() const {
    return this -> dir;
}

string Door::getKeywords() const {
    return this -> keywords;
}

int Door::getDoorId() const {
    return this -> Door_id;
}

//Needs to be changed
int Door::getTo() const {
    return this -> to;
}

void Door::setDesc(string& new_desc) {
    this -> desc = new_desc;
}

void Door::setDir(string& new_dir) {
    this -> dir = new_dir;
}

void Door::setKeywords(string& new_keywords) {
    this -> keywords = new_keywords;
}

void Door::setDoorId(int new_door_id) {
    this -> Door_id = new_door_id;
}
