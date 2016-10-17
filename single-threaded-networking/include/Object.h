// Object.h

#ifndef OBJECT_H
#define OBJECT_H

#include <vector>
#include <string>

class Object {
private:
	int id;
	int cost = 0;
	int weight = 0;

	std::string itemType;

	std::vector<std::string> attributes;
	std::vector<std::string> keyWords;
	std::vector<std::string> longDesc;
	std::vector<std::string> shortDesc;
	std::vector<std::string> wearFlags;
	std::vector<std::string> extra;

public:
	// Object constructor
	Object(int id, std::string itemType);
	
	// Object copy constructor
	Object(const Object &ob);

	// Getter and setter for ID:
  	int getID() const;
  	void setID(int id);

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

	// Getter and setter for keyWords:
	std::vector<std::string> getKeyWords() const;
	void setKeyWords(const std::vector<std::string>& keyWords);
  	void addKeyWord(const std::string& keyWord);

  	// Getter and setter for longDesc:
  	std::vector<std::string> getLongDesc() const;
	void setLongDesc(const std::vector<std::string>& longDesc);
	void addLongDesc(const std::string& longDesc);

  	// Getter and setter for shortDesc:
  	std::vector<std::string> getShortDesc() const;
	void setShortDesc(const std::vector<std::string>& shortDesc);
	void addShortDesc(const std::string& shortDesc);

	// Getter and setter or wearFlags:
	  std::vector<std::string> getWearFlags() const;
	void setWearFlags(const std::vector<std::string>& wearFlags);
	void addWearFlag(const std::string& wearFlags);

  	// Getter and setter for extra:
  	std::vector<std::string> getExtra() const;
	void setExtra(const std::vector<std::string>& exta);
	void addExtra(const std::string& extra);
		
	void copy_vec(std::vector<std::string>& output, const std::vector<std::string>& Alist );
};

#endif