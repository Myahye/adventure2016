//#include <iostream>
#include "Door.h"
//#include <fstream>

using namespace std;

Door::Door() {
    this->desc = "none";
    this->dir = "none";
    this->keywords = "none";
    this->Door_id = 0;
    this->destinationId = 0;
}
Door::Door(std::string dir) {
    this->desc = "none";
    this->dir = dir;
    this->keywords = "none";
    this->Door_id = 0;
    this->destinationId = 0;
}
Door::Door(std::string dir, std::string description, int destinationId) {
    this->desc = description;
    this->dir = dir;
    this->keywords = "none";
    this->Door_id = 0;
    this->destinationId = destinationId;
}
Door::Door(std::string& new_desc, std::string& new_dir, std::string& new_keywords, int& new_door_id, int& new_destinationId)
        : desc{new_desc}
        , dir{new_dir}
        , keywords{new_keywords}
        , Door_id{static_cast<unsigned int>(new_door_id)}
        , destinationId{static_cast<unsigned int>(new_destinationId)} {}

std::string Door::getDesc() const {
    return this -> desc;
}

std::string Door::getDir() const {
    return this -> dir;
}

std::string Door::getKeywords() const {
    return this -> keywords;
}

int Door::getDoorId() const {
    return this -> Door_id;
}

//Needs destinationId be changed
int Door::getDestinationId() const {
    return this -> destinationId;
}

void Door::setDesc(std::string& new_desc) {
    this -> desc = new_desc;
}

void Door::setDir(std::string& new_dir) {
    this -> dir = new_dir;
}

void Door::setKeywords(std::string& new_keywords) {
    this -> keywords = new_keywords;
}

void Door::setDoorId(int new_door_id) {
    this -> Door_id = new_door_id;
}
