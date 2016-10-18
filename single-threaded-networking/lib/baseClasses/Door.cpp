#include "Door.h"

Door::Door() {
    this->desc = "none";
    this->dir = "none";
    this->keywords = "none";
    this->Door_id = 0;
    this->destinationId = 0;
}
//Temp constructor for testing and first iteration
Door::Door(std::string dir) {
    this->desc = "none";
    this->dir = dir;
    this->keywords = "none";
    this->Door_id = 0;
    this->destinationId = 0;
}
//Temp constructor for testing and first iteration
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

//Accessor methods
std::string
Door::getDesc() const {
    return this -> desc;
}
std::string
Door::getDir() const {
    return this -> dir;
}
std::string
Door::getKeywords() const {
    return this -> keywords;
}
int
Door::getDoorId() const {
    return this -> Door_id;
}
int
Door::getDestinationId() const {
    return this -> destinationId;
}

//Mutator methods
void
Door::setDesc(const std::string& new_desc) {
    this -> desc = new_desc;
}
void
Door::setDir(const std::string& new_dir) {
    this -> dir = new_dir;
}
void
Door::setKeywords(const std::string& new_keywords) {
    this -> keywords = new_keywords;
}
void
Door::setDoorId(const int new_door_id) {
    this -> Door_id = new_door_id;
}
