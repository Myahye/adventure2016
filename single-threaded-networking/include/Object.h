// Object.h

#ifndef OBJECT_H
#define OBJECT_H

#include <iostream>
#include <vector>
#include <string>
#include <utility> //std::pair
#include <algorithm>

class Object {
private:
	int id = 0;
	int cost = 0;
	int weight = 0;

	std::string itemType;
	std::string shortDesc;

	std::vector<std::string> attributes;
	std::vector<std::string> keywords;
	std::vector<std::string> longDesc;
	//std::vector<std::string> shortDesc;
	std::vector<std::string> wearFlags;
	std::vector<std::pair<std::vector<std::string>, std::vector<std::string> > > extra;

public:
	Object();
	// Object constructor
	Object(int id, std::string itemType);

	// Object copy constructor
	Object(const Object &ob);

	//Object overloaed
	Object& operator =(const Object& ob);

	// Getter and setter for Id:
  	int getId() const;
  	void setId(int id);

  	// Getter and setter for cost:
  	int getCost() const;
  	void setCost(int cost);

  	// Getter and setter for weight:
  	int getWeight() const;
  	void setWeight(int weight);

  	// Getter and setter or itemType:
  	std::string getItemType() const;
  	void setItemType(const std::string& itemType);

  	// Getter and setter for attributes:
	std::vector<std::string> getAttributes() const;
	void setAttributes(const std::vector<std::string>& attributes);
	void addAttribute(const std::string& attribute);

	// Getter and setter for keywords:
	std::vector<std::string> getKeywords() const;
	void setKeywords(const std::vector<std::string>& keywords);
  	void addKeyword(const std::string& keyword);

  	// Getter and setter for longDesc:
  	std::vector<std::string> getLongDesc() const;
  	std::string getLongDescStr() const;
	void setLongDesc(const std::vector<std::string>& longDesc);
	void addLongDesc(const std::string& longDesc);

  	// Getter and setter for shortDesc:
  	std::string getShortDesc() const;
	void setShortDesc(const std::string& shortDesc);

	// Getter and setter or wearFlags:
	  std::vector<std::string> getWearFlags() const;
	void setWearFlags(const std::vector<std::string>& wearFlags);
	void addWearFlag(const std::string& wearFlags);

  	// Getter and setter for extra:
	std::vector< std::pair<std::vector<std::string>, std::vector<std::string> > > getExtra() const;
	void setExtra(const std::vector< std::pair<std::vector<std::string>, std::vector<std::string> > >& extra);
/*	void addExtraDesc(const std::string& desc);
	void addExtraKeyword(const std::string& keyword);*/

	void copy_vec(std::vector<std::string>& output, const std::vector<std::string> Alist );
	void clear_vec(std::vector<std::string> Alist);

	//New function added in to test
	void printClass(int n) const;
	void printVector(const std::vector<std::string>& vec) const;
};

#endif