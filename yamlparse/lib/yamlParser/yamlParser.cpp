#include "yamlParser.h"

yamlParser::yamlParser() {};

std::unordered_map<int,NPC> yamlParser::parseBuildNpcs(const std::string& pathToFile){
	YAML::Node config = YAML::LoadFile(pathToFile);
	const YAML::Node&  NPC_node= config["NPCS"];
	//initialize our map we will return
	std::unordered_map<int,NPC> buildAllNpcs;


	//iterate through all NPC Nodes
	for (auto it = NPC_node.begin(); it != NPC_node.end(); ++it) {
		const YAML::Node& element = *it;
		//constructing class
		std::string shortdesc = element["shortdesc"].as<std::string>();
		NPC npcClass{element["id"].as<int>(), shortdesc};
		
		//intergers
		npcClass.setArmor(element["armor"].as<int>());
		npcClass.setExp(element["exp"].as<int>());
		npcClass.setGold(element["gold"].as<int>());
		npcClass.setLevel(element["level"].as<int>());
		npcClass.setThac0(element["thac0"].as<int>());
		
		//strings
		std::string damage = element["damage"].as<std::string>();
		std::string hit = element["hit"].as<std::string>();
		npcClass.setDamage(damage);
		npcClass.setHit(hit);

		//vectors
		std::vector<std::string> descV = setDescHelper(element["description"]);
		std::vector<std::string> keywordsV = setDescHelper(element["keywords"]);
		std::vector<std::string> longdescV = setDescHelper(element["longdesc"]);

		npcClass.setDesc(descV); //change up
		npcClass.setKeywords(keywordsV);
		npcClass.setLongDesc(longdescV);
		
		//Add NPC to map
  		//allNPC[npcClass.getId()] = npcClass;
  		buildAllNpcs.insert(std::make_pair(npcClass.getId(),npcClass));
	}

	return buildAllNpcs;
}


std::unordered_map<int,Object> yamlParser::parseBuildObjects(const std::string& pathToFile){
	YAML::Node config = YAML::LoadFile(pathToFile);
	const YAML::Node&  object_node= config["OBJECTS"];
	//initialize our map we will return
	std::unordered_map<int,Object> buildAllObjects;


	//iterate through all NPC Nodes
	for (auto it = object_node.begin(); it != object_node.end(); ++it) {
		const YAML::Node& element = *it;
		//constructing class
		Object objectClass{element["id"].as<int>(), element["item_type"].as<std::string>()};
		
		//intergers
		objectClass.setCost(element["cost"].as<int>());
		objectClass.setWeight(element["weight"].as<int>());
		
		//strings
		std::string item_type = element["item_type"].as<std::string>();
		//std::string shortdesc = element["shortdesc"].as<std::string>();
		objectClass.setItemType(item_type);
		//objectClass.setShortDesc(shortdesc);

		//vectors
		std::vector<std::string> attributesV = setDescHelper(element["attributes"]);
		std::vector<std::string> keywordsV = setDescHelper(element["keywords"]);
		std::vector<std::string> longdescV = setDescHelper(element["longdesc"]);
		std::vector<std::string> wearFlagsV = setDescHelper(element["wear_flags"]);

		objectClass.setAttributes(attributesV); //change up
		objectClass.setKeyWords(keywordsV);
		objectClass.setLongDesc(longdescV);
		objectClass.setWearFlags(wearFlagsV);
		
		//Add object to map
  		//allNPC[npcClass.getId()] = npcClass;
  		buildAllObjects.insert(std::make_pair(objectClass.getID(),objectClass));
	}

	return buildAllObjects;
}

//helper classes for yamlParseNPC
std::vector<std::string> yamlParser::setDescHelper( const YAML::Node& descNode){
	std::vector<std::string> allDescStrings;
	for(auto it = descNode.begin(); it != descNode.end(); it++){
		allDescStrings.push_back((*it).as<std::string>());
	}

	return allDescStrings;
}

std::vector<std::string> yamlParser::setKeywordsHelper(const YAML::Node& keywordsNode){
	std::vector<std::string> allKeywords;
	for(auto it = keywordsNode.begin(); it != keywordsNode.end(); it++){
		allKeywords.push_back((*it).as<std::string>());
	}

	return allKeywords;
}

std::vector<std::string> yamlParser::setLongDescHelper(const YAML::Node& longDescNode){
	std::vector<std::string> allLongDesc;
	for(auto it = longDescNode.begin(); it != longDescNode.end(); it++){
		allLongDesc.push_back((*it).as<std::string>());
	}

	return allLongDesc;
}
