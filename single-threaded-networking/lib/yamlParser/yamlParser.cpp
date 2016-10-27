#include "yamlParser.h"
//#include <utility>

YamlParser::YamlParser() {};

//Parses and builds Npc's from yaml file
std::unordered_map<int,NPC> YamlParser::parseBuildNpcs(const std::string& pathToFile){
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


//Parses and builds Object's from yaml file
std::unordered_map<int,Object> YamlParser::parseBuildObjects(const std::string& pathToFile){
	YAML::Node config = YAML::LoadFile(pathToFile);
	const YAML::Node&  object_node= config["OBJECTS"];
	//initialize our map we will return
	std::unordered_map<int,Object> buildAllObjects;


	//iterate through all NPC Nodes
	for (auto& it : object_node) {
		//constructing class
		Object objectClass{it["id"].as<int>(), it["item_type"].as<std::string>()};
		
		//integers
		objectClass.setCost(it["cost"].as<int>());
		objectClass.setWeight(it["weight"].as<int>());
		
		//strings
		std::string item_type = it["item_type"].as<std::string>();
		std::string shortdesc = it["shortdesc"].as<std::string>();
		objectClass.setItemType(item_type);
		objectClass.setShortDesc(shortdesc);

		//vectors
		std::vector<std::string> attributesV = setStringVectorHelper(it["attributes"]);
		std::vector<std::string> keywordsV = setStringVectorHelper(it["keywords"]);
		std::vector<std::string> longdescV = setStringVectorHelper(it["longdesc"]);
		std::vector<std::string> wearFlagsV = setStringVectorHelper(it["wear_flags"]);
		std::vector<std::string> extraDescV =setStringVectorHelper(it["extra"]["desc"]);
		std::vector<std::string> extraKeywordsV =setStringVectorHelper(it["extra"]["keywords"]);

		objectClass.setAttributes(attributesV); //change up
		objectClass.setKeywords(keywordsV);
		objectClass.setLongDesc(longdescV);
		objectClass.setWearFlags(wearFlagsV);
		
		//pair
		std::pair< std::vector<std::string>, std::vector<std::string> > extraP(extraDescV, extraKeywordsV);
		extraP = std::make_pair(extraDescV, extraKeywordsV);
		
		objectClass.setExtra(extraP);

		//Add object to map
  		//allNPC[npcClass.getId()] = npcClass;
  		buildAllObjects.insert(std::make_pair(objectClass.getID(),objectClass));
	}

	return buildAllObjects;
}


//Parses and builds Room's from yaml file
std::unordered_map<int,Room> YamlParser::parseBuildRooms(const std::string& pathToFile){
	YAML::Node config = YAML::LoadFile(pathToFile);
	const YAML::Node&  room_node= config["ROOMS"];

	//initialize our map we will return
	std::unordered_map<int,Room> buildAllRooms;

	for (auto& currentRoom : room_node) {
		
		//declaring vector of doors in room
		std::vector<Door> doors;

		//integers
		int roomId = currentRoom["id"].as<int>();
		
		//strings
		std::string roomName = currentRoom["name"].as<std::string>();

		//vectors
		std::vector<std::string> descV = setStringVectorHelper(currentRoom["desc"]);
		std::vector<std::string> extendedDescV = setStringVectorHelper(currentRoom["extended_descriptions"]);

		//iterate through all door Nodes
		for (auto& currentDoor : currentRoom["doors"]) {
		
			//integers
			int doorDestinationId = currentDoor["to"].as<int>();
			
			//strings
			std::string doorDir = currentDoor["dir"].as<std::string>();

			//vectors
			std::vector<std::string> descV = setStringVectorHelper(currentDoor["desc"]);
			std::vector<std::string> keywordsV = setStringVectorHelper(currentDoor["keywords"]);

			//use parameterized constructor
			Door doorClass{doorDir, descV, keywordsV, roomId, doorDestinationId}; //going off assumption roomId is doorId

			doors.push_back(doorClass);
		}
		
		//use parameterized constructor
		Room roomClass{descV, extendedDescV, roomName, roomId, doors};

		//Add object to map
  		buildAllRooms.insert(std::make_pair(roomClass.getRoomId(),roomClass));
	}

	return buildAllRooms;
}


std::vector<Reset> YamlParser::parseBuildResets(const std::string& pathToFile){
	
	YAML::Node config = YAML::LoadFile(pathToFile);
	const YAML::Node& reset_node = config["RESETS"];

	//initialize our map we will return
	std::vector<Reset> buildAllResets;

	for (auto& currentReset : reset_node) {

		Reset reset{currentReset["action"].as<std::string>(), currentReset["id"].as<int>()};

		if (currentReset["limit"]){
			reset.setLimit(currentReset["limit"].as<int>());
		}
		if (currentReset["room"]){
			reset.setRoom(currentReset["room"].as<int>());
		}
		if (currentReset["slot"]){
			reset.setSlot(currentReset["slot"].as<int>());
		}
		if (currentReset["comment"]){
			std::string comment = currentReset["comment"].as<std::string>();
			reset.setComment(comment);
		}
		
		buildAllResets.push_back(reset);
	}
	return buildAllResets;
}


//helper classes for yamlParse
std::vector<std::string> YamlParser::setStringVectorHelper( const YAML::Node& vectorNode){
	std::vector<std::string> stringsV;
	for(auto& it : vectorNode){
		stringsV.push_back((it).as<std::string>());
	}

	return stringsV;
}
