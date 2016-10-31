#include "yamlParser.h"
//#include <utility>

YamlParser::YamlParser() {};

//Parses and builds Npc's from yaml file
std::unordered_map<int,Npc> YamlParser::parseBuildNpcs(const std::string& pathToFile){
	YAML::Node config = YAML::LoadFile(pathToFile);
	const YAML::Node&  Npc_node= config["NPCS"];
	//initialize our map we will return
	std::unordered_map<int,Npc> buildAllNpcs;


	//iterate through all Npc Nodes
	for (auto& it : Npc_node) {
		//constructing class
		std::string shortdesc = it["shortdesc"].as<std::string>();
		Npc npcClass{it["id"].as<int>(), shortdesc};
		
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
		
		//Add Npc to map
  		//allNpc[npcClass.getId()] = npcClass;
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


	//iterate through all Npc Nodes
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

		objectClass.setAttributes(attributesV); //change up
		objectClass.setKeywords(keywordsV);
		objectClass.setLongDesc(longdescV);
		objectClass.setWearFlags(wearFlagsV);
		
		const YAML::Node& extra_node = it["extra"];

		std::vector<std::string> extraDescV;
		std::vector<std::string> extraKeywordsV;	
		
		for (auto &j : extra_node){
			extraDescV = setStringVectorHelper(j["desc"]);
			extraKeywordsV = setStringVectorHelper(j["keywords"]);
		}
		//std::cout << "size: " << extraDescV.size() << std::endl;
		//std::cout << "size: " << extraKeywordsV.size() << std::endl;
		std::pair< std::vector<std::string>, std::vector<std::string> > extraP;

		extraP = std::make_pair(extraDescV, extraKeywordsV);
		objectClass.setExtra(extraP);

  		buildAllObjects.insert(std::make_pair(objectClass.getId(),objectClass));
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

//maybe change to take in npc,object,room maps as parameters and pass in pointers to rooms/npc/objects to the constructors of resetNPC etc.
//change to use unique_ptr and move ownership to vector
std::vector<std::unique_ptr<Reset>> YamlParser::parseBuildResets(const std::string& pathToFile){
	
	YAML::Node config = YAML::LoadFile(pathToFile);
	const YAML::Node& reset_node = config["RESETS"];

	//initialize our map we will return
	std::vector<std::unique_ptr<Reset>> buildAllResets;

	std::unique_ptr<Reset> reset;

	for (auto& currentReset : reset_node) {
		if(currentReset["action"].as<std::string>() == "npc") {
			if (currentReset["comment"]){
				reset = std::make_unique<Resets::ResetNpc>(currentReset["action"].as<std::string>(), currentReset["id"].as<int>(), currentReset["limit"].as<int>(), currentReset["room"].as<int>(), currentReset["comment"].as<std::string>());
			}
			else {
				reset = std::make_unique<Resets::ResetNpc>(currentReset["action"].as<std::string>(), currentReset["id"].as<int>(), currentReset["limit"].as<int>(), currentReset["room"].as<int>(), "");
			}
		} else if(currentReset["action"].as<std::string>() == "object") {
			if (currentReset["comment"]){
				reset = std::make_unique<Resets::ResetObject>(currentReset["action"].as<std::string>(), currentReset["id"].as<int>(), 1, currentReset["room"].as<int>(), currentReset["comment"].as<std::string>());
			}
			else {
				reset = std::make_unique<Resets::ResetObject>(currentReset["action"].as<std::string>(), currentReset["id"].as<int>(), 1, currentReset["room"].as<int>(), "");
			}
		} else if(currentReset["action"].as<std::string>() == "give") {
			if (currentReset["comment"]){
				reset = std::make_unique<Resets::ResetGive>(currentReset["action"].as<std::string>(), currentReset["id"].as<int>(), 1, 0, currentReset["comment"].as<std::string>());
			}
			else {
				reset = std::make_unique<Resets::ResetGive>(currentReset["action"].as<std::string>(), currentReset["id"].as<int>(), 1, 0, "");
			}
		} else if(currentReset["action"].as<std::string>() == "equip") {
			if (currentReset["comment"]){
				reset = std::make_unique<Resets::ResetEquip>(currentReset["action"].as<std::string>(), currentReset["id"].as<int>(), currentReset["slot"].as<int>(), currentReset["comment"].as<std::string>());
			}
			else {
				reset = std::make_unique<Resets::ResetEquip>(currentReset["action"].as<std::string>(), currentReset["id"].as<int>(), currentReset["slot"].as<int>(), "");
			}
		}
		buildAllResets.push_back(std::move(reset));

		// Reset reset{currentReset["action"].as<std::string>(), currentReset["id"].as<int>()};

		// if (currentReset["limit"]){
		// 	reset.setLimit(currentReset["limit"].as<int>());
		// }
		// if (currentReset["room"]){
		// 	reset.setRoom(currentReset["room"].as<int>());
		// }
		// if (currentReset["slot"]){
		// 	reset.setSlot(currentReset["slot"].as<int>());
		// }
		// if (currentReset["comment"]){
		// 	std::string comment = currentReset["comment"].as<std::string>();
		// 	reset.setComment(comment);
		// }
		
		// buildAllResets.push_back(reset);
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
