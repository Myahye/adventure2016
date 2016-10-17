// main.cpp
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Object.h"

#include <assert.h>

void printVectorContent(const std::vector<std::string>& test) {
	for(auto x : test) {
		std::cout << x << std::endl;
	}
	std::cout << std::endl;
}

void testObjectClass() {
	// Create Object
	Object treasure(12345, "Treasure chest");
	assert(treasure.getID() == 12345);
	assert(treasure.getItemType() == "Treasure chest");
	std::cout << "Object: " << treasure.getItemType() << " with ID: " << treasure.getID() << std::endl; 
	std::cout << std::endl;

	// Cost and weight tests:
	treasure.setCost(1000);
	assert(treasure.getCost() == 1000);
	treasure.setWeight(100);
	assert(treasure.getWeight() == 100);
	std::cout << "Cost: " << treasure.getCost() << " Weight: " << treasure.getWeight() << std::endl;
	std::cout << std::endl;

	// Attributes tests:
	assert(treasure.getAttributes().size() == 0);
	std::vector<std::string>testAttributes;
	testAttributes.push_back("Test attribute 1");
	testAttributes.push_back("Test attribute 2");
	treasure.setAttributes(testAttributes);
	assert(treasure.getAttributes().size() == 2);
	treasure.addAttribute("Test Attribute 3");
	assert(treasure.getAttributes().size() == 3);
	std::cout << "Attributes: " << std::endl;
	printVectorContent(treasure.getAttributes());

	// Keywords tests:
	assert(treasure.getKeyWords().size() == 0);
	std::vector<std::string>testKeywords;
	testKeywords.push_back("Test keyword 1");
	treasure.setKeyWords(testKeywords);
	assert(treasure.getKeyWords().size() == 1);
	treasure.addKeyWord("Test keyword 2");
	treasure.addKeyWord("Test keyword 3");
	assert(treasure.getKeyWords().size() == 3);
	std::cout << "KeyWords: " << std::endl;
	printVectorContent(treasure.getKeyWords());

	// LongDesc tests:
	assert(treasure.getLongDesc().size() == 0);
	std::vector<std::string>testLongDesc;
	testLongDesc.push_back("Test long description 1");
	testLongDesc.push_back("Test long description 2");
	treasure.setLongDesc(testLongDesc);
	assert(treasure.getLongDesc().size() == 2);
	treasure.addLongDesc("Test long description 3");
	assert(treasure.getLongDesc().size() == 3);
	std::cout << "LongDesc: " << std::endl;
	printVectorContent(treasure.getLongDesc());

	// ShortDesc tests:
	assert(treasure.getShortDesc().size() == 0);
	std::vector<std::string>testShortDesc;
	testShortDesc.push_back("Test short description 1");
	testShortDesc.push_back("Test short description 2");
	treasure.setShortDesc(testShortDesc);
	assert(treasure.getShortDesc().size() == 2);
	treasure.addShortDesc("Test short description 3");
	assert(treasure.getShortDesc().size() == 3);
	std::cout << "ShortDesc: " << std::endl;
	printVectorContent(treasure.getShortDesc());

	// WearFlags tests:
	assert(treasure.getWearFlags().size() == 0);
	std::vector<std::string>testWearFlags;
	testWearFlags.push_back("Test wear flag 1");
	treasure.setWearFlags(testWearFlags);
	assert(treasure.getWearFlags().size() == 1);
	treasure.addWearFlag("Test wear flag 2");
	treasure.addWearFlag("Test wear flag 3");
	treasure.addWearFlag("Test wear flag 4");
	treasure.addWearFlag("Test wear flag 5");
	assert(treasure.getWearFlags().size() == 5);
	std::cout << "WearFlags: " << std::endl;
	printVectorContent(treasure.getWearFlags());

	// Extra tests:
	assert(treasure.getExtra().size() == 0);
	std::vector<std::string> testExtra;
	testExtra.push_back("Test extra 1");
	treasure.setExtra(testExtra);
	assert(treasure.getExtra().size() == 1);
	treasure.addExtra("Test extra 2");
	assert(treasure.getExtra().size() == 2);
	std::cout << "Extra: " << std::endl;
	printVectorContent(treasure.getExtra());

	std::cout << "Finished Object class tests!" << std::endl;
}

int main() {
	testObjectClass();
	return 0;
}
