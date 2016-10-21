#include "yamlParser.h"
//#include <utility>

yamlParser::yamlParser() {};

std::unordered_map<int,NPC> yamlParser::parseBuildNpcs(const std::string& pathToFile){
	YAML::Node config = YAML::LoadFile(pathToFile);
	const YAML::Node&  NPC_node= config["NPCS"];
	//initialize our map we will return
	std::unordered_map<int,NPC> buildAllNpcs;


	//iterate through all NPC Nodes
	for (auto& it : NPC_node) {
		//constructing class
		std::string shortdesc = it["shortdesc"].as<std::string>();
		NPC npcClass{it["id"].as<int>(), shortdesc};
		
		//intergers
		npcClass.setArmor(it["armor"].as<int>());
		npcClass.setExp(it["exp"].as<int>());
		npcClass.setGold(it["gold"].as<int>());
		npcClass.setLevel(it["level"].as<int>());
		npcClass.setThac0(it["thac0"].as<int>());
		
		//strings
		std::string damage = it["damage"].as<std::string>();
		std::string hit = it["hit"].as<std::string>();
		npcClass.setDamage(damage);
		npcClass.setHit(hit);

		//vectors
		std::vector<std::string> descV = setStringVectorHelper(it["description"]);
		std::vector<std::string> keywordsV = setStringVectorHelper(it["keywords"]);
		std::vector<std::string> longdescV = setStringVectorHelper(it["longdesc"]);

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
	for (auto& it : object_node) {
		//constructing class
		Object objectClass{it["id"].as<int>(), it["item_type"].as<std::string>()};
		
		//intergers
		objectClass.setCost(it["cost"].as<int>());
		objectClass.setWeight(it["weight"].as<int>());
		
		//strings
		std::string item_type = it["item_type"].as<std::string>();
		//std::string shortdesc = it["shortdesc"].as<std::string>();
		objectClass.setItemType(item_type);
		//objectClass.setShortDesc(shortdesc);

		//vectors
		std::vector<std::string> attributesV = setStringVectorHelper(it["attributes"]);
		std::vector<std::string> keywordsV = setStringVectorHelper(it["keywords"]);
		std::vector<std::string> longdescV = setStringVectorHelper(it["longdesc"]);
		std::vector<std::string> wearFlagsV = setStringVectorHelper(it["wear_flags"]);
		std::vector<std::string> extraDescV =setStringVectorHelper(it["extra"]["desc"]);
		std::vector<std::string> extraKeywordsV =setStringVectorHelper(it["extra"]["keywords"]);

		objectClass.setAttributes(attributesV); //change up
		objectClass.setKeyWords(keywordsV);
		objectClass.setLongDesc(longdescV);
		objectClass.setWearFlags(wearFlagsV);
		
		//pair
		std::pair< std::vector<std::string>, std::vector<std::string> > extraP(extraDescV, extraKeywordsV);

		objectClass.setExtra(extraP);

		//Add object to map
  		//allNPC[npcClass.getId()] = npcClass;
  		buildAllObjects.insert(std::make_pair(objectClass.getID(),objectClass));
	}

	return buildAllObjects;
}

//helper classes for yamlParseNPC
std::vector<std::string> yamlParser::setStringVectorHelper( const YAML::Node& vectorNode){
	std::vector<std::string> stringsV;
	for(auto& it : vectorNode){
		stringsV.push_back((it).as<std::string>());
	}

	return stringsV;
}


/*std::vector<std::string> yamlParser::setStringHelper(const YAML::Node& stringNode){
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
}*/
