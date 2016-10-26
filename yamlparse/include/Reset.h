#ifndef RESET_H
#define RESET_H

#include <string>
#include <iostream>

class Reset{
private:
	std::string action;
	std::string comment;
	int id;
	int limit;
	int room;
	int slot;

public:
	//Reset Constructor
	Reset(const std::string& action, int const id);

	//Action
	std::string getAction() const;
	void setAction(const std::string& action);

	//Comment
	std::string getComment() const;
	void setComment(const std::string& comment);

	//ID
	int getId() const;
	void setId(int const id);
	
	//Limit
	int getLimit() const;
	void setLimit(int const limit);

	//Room
	int getRoom() const;
	void setRoom(int const room);

	//Slot
	int getSlot() const;
	void setSlot(int const slot);

	//New function added in to test
	void printClass(int n) const;
};

#endif