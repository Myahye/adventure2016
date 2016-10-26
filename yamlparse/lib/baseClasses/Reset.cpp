#ifndef RESET_CPP
#define RESET_CPP

#include "Reset.h"

//Reset Constructor
Reset::Reset(const std::string& action, int const id):
	action{action}, id{id}{};

//Getter and Setter for Action
std::string Reset::getAction() const {
	return action;
}
void Reset::setAction(const std::string& action) {
	this->action = action;
}

//Getter and Setter for	Comment
std::string Reset::getComment() const {
	return comment;
}
void Reset::setComment(const std::string& comment) {
	this->comment = comment;
}

//Getter and Setter for	ID
int Reset::getId() const {
	return id;
}
void Reset::setId(int const id){
	this->id = id;
}

//Getter and Setter for Limit
int Reset::getLimit() const {
	return limit;
}
void Reset::setLimit(int const limit){
	this->limit = limit;
}

//Getter and Setter for Room
int Reset::getRoom() const{
	return room;
}
void Reset::setRoom(int const room){
	this->room = room;
}

//Getter and Setter for Slot
int Reset::getSlot() const{
	return slot;
}
void Reset::setSlot(int const slot){
	this->slot = slot;
}

//New function added in to test
void Reset::printClass(int n) const{
	std::cout << "\n\n";
	std::cout << "Reset: "<< n << "\n";
	std::cout << "ID: " << id << std::endl;
	std::cout << "\taction: " << action << std::endl;
	std::cout << "\tcomment: " << comment << std::endl;
	std::cout << "\tid: " << id << std::endl;
	std::cout << "\tlimit: " << limit << std::endl;
	std::cout << "\troom: " << room << std::endl;
}
#endif