

#include "YamlParseAndBuild.h"
YamlParseandBuild::YamlParseandBuild() {};

void YamlParseandBuild::loadFile(const std::string& pathToFile){
	this->fileNode = YAML::LoadFile(pathToFile);
}


/*********Parses and builds Npc's from yaml file****************/
std::pair<int,Npc> YamlParseandBuild::parseNpcs(const YAML::Node& node){
	std::string shortdesc = node["shortdesc"].as<std::string>();
	Npc npcClass{node["id"].as<int>(), shortdesc};
	if(node["armor"]){
		npcClass.setArmor(node["armor"].as<int>());
	}
	if(node["exp"]){
		npcClass.setExp(node["exp"].as<int>());
	}
	if(node["gold"]){
		npcClass.setGold(node["gold"].as<int>());
	}
	if(node["level"]){
		npcClass.setLevel(node["level"].as<int>());
	}
	if(node["thac0"]){
		npcClass.setThac0(node["thac0"].as<int>());
	}
	if(node["damage"]){
		std::string damage = node["damage"].as<std::string>();
		npcClass.setDamage(damage);
	}
	if(node["hit"]){
		std::string hit = node["hit"].as<std::string>();
		npcClass.setHit(hit);
	}
	if(node["description"]){
		std::vector<std::string> descV = setStringVectorHelper(node["description"]);
		npcClass.setDesc(descV); 
	}
	if(node["keywords"]){
		std::vector<std::string> keywordsV = setStringVectorHelper(node["keywords"]);
		npcClass.setKeywords(keywordsV);
	}
	if(node["longdesc"]){
		std::vector<std::string> longdescV = setStringVectorHelper(node["longdesc"]);
		npcClass.setLongDesc(longdescV);
	}
	return std::make_pair(npcClass.getId(),npcClass);
}

void YamlParseandBuild::buildNpcs(std::unordered_map<int,Npc>& buildAllNpcs){
	const YAML::Node&  NPC_node = fileNode["NPCS"];
	std::transform(NPC_node.begin(),NPC_node.end(), std::inserter( buildAllNpcs, buildAllNpcs.end() ), 
					[this](const YAML::Node& node) { return this->parseNpcs(node); }); //if we dont use [this] error:invalid use of non static member function
																  
}

//Parses and builds Room's from yaml file
void YamlParseandBuild::parseBuildRooms(std::unordered_map<int,Room>& rooms){
	const YAML::Node&  room_node= fileNode["ROOMS"];


	for (auto& currentRoom : room_node) {
		std::vector<Door> doors;

		//integers
		int roomId = currentRoom["id"].as<int>();
		
		//strings
		std::string roomName = currentRoom["name"].as<std::string>();

		//vectors
		std::vector<std::string> descV = setStringVectorHelper(currentRoom["desc"]);
		std::pair< std::vector<std::string>, std::vector<std::string> > extraP;
		if(currentRoom["extended_descriptions"]){
			const YAML::Node& extra_node = currentRoom["extended_descriptions"];

			std::vector<std::string> extraDescV;
			std::vector<std::string> extraKeywordsV;	
			
			for (auto &j : extra_node){
				extraDescV = setStringVectorHelper(j["desc"]);
				extraKeywordsV = setStringVectorHelper(j["keywords"]);
			}
			extraP = std::make_pair(extraDescV, extraKeywordsV);
		}
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
		Room roomClass{descV, extraP, roomName, roomId, doors};

		//Add object to map
  		rooms.insert(std::make_pair(roomClass.getRoomId(),roomClass));
	}
}


/*********Parses and builds Object's from yaml file****************/
std::pair<int,Object> YamlParseandBuild::parseObjects(const YAML::Node& node){

	Object objectClass;
	objectClass.setId(node["id"].as<int>());

	if(node["cost"]){
		objectClass.setCost(node["cost"].as<int>());
	}
	if(node["weight"]){
		objectClass.setWeight(node["weight"].as<int>());
	}
	if(node["item_type"]){
		std::string item_type = node["item_type"].as<std::string>();
		objectClass.setItemType(item_type);
	}
	if(node["shortdesc"]){
		std::string shortdesc = node["shortdesc"].as<std::string>();
		objectClass.setShortDesc(shortdesc);
	}
	if(node["attributes"]){
		std::vector<std::string> attributesV = setStringVectorHelper(node["attributes"]);
		objectClass.setAttributes(attributesV); 
	}
	if(node["keywords"]){
		std::vector<std::string> keywordsV = setStringVectorHelper(node["keywords"]);
		objectClass.setKeywords(keywordsV);
	}
	if(node["longdesc"]){
		std::vector<std::string> longdescV = setStringVectorHelper(node["longdesc"]);
		objectClass.setLongDesc(longdescV);
	}
	if(node["wear_flags"]){
		std::vector<std::string> wearFlagsV = setStringVectorHelper(node["wear_flags"]);
		objectClass.setWearFlags(wearFlagsV);
	}
	if(node["extra"]){
		const YAML::Node& extra_node = node["extra"];
		//need to be vector of pair of vectors
		std::vector<std::string> extraDescV;
		std::vector<std::string> extraKeywordsV;	
		
		for (auto &j : extra_node){
			extraDescV = setStringVectorHelper(j["desc"]);
			extraKeywordsV = setStringVectorHelper(j["keywords"]);
		}
		std::pair< std::vector<std::string>, std::vector<std::string> > extraP;

		extraP = std::make_pair(extraDescV, extraKeywordsV);
		objectClass.setExtra(extraP);
	}
	return std::make_pair(objectClass.getId(),objectClass);
}

void YamlParseandBuild::buildObjects(std::unordered_map<int,Object>& buildAllObjects){
	const YAML::Node&  Object_Node = fileNode["OBJECTS"];
	
	std::transform(Object_Node.begin(),Object_Node.end(), std::inserter( buildAllObjects, buildAllObjects.end() ), 
					[this](const YAML::Node& node) { return this->parseObjects(node); });
}

std::unique_ptr<Reset> YamlParseandBuild::parseResets(const YAML::Node& node){
	if(node["action"].as<std::string>() == "npc") {
		if (node["comment"]){
			return std::make_unique<Resets::ResetNpc>(node["action"].as<std::string>(), node["id"].as<int>(), node["limit"].as<int>(), node["room"].as<int>(), node["comment"].as<std::string>());
		}
		else {
			return std::make_unique<Resets::ResetNpc>(node["action"].as<std::string>(), node["id"].as<int>(), node["limit"].as<int>(), node["room"].as<int>(), "");
		}
	} else if(node["action"].as<std::string>() == "object") {
		if (node["comment"]){
			return std::make_unique<Resets::ResetObject>(node["action"].as<std::string>(), node["id"].as<int>(), 1, node["room"].as<int>(), node["comment"].as<std::string>());
		}
		else {
			return std::make_unique<Resets::ResetObject>(node["action"].as<std::string>(), node["id"].as<int>(), 1, node["room"].as<int>(), "");
		}
	} else if(node["action"].as<std::string>() == "give") {
		if (node["comment"]){
			return std::make_unique<Resets::ResetGive>(node["action"].as<std::string>(), node["id"].as<int>(), 1, 0, node["comment"].as<std::string>());
		}
		else {
			return std::make_unique<Resets::ResetGive>(node["action"].as<std::string>(), node["id"].as<int>(), 1, 0, "");
		}
	} else if(node["action"].as<std::string>() == "equip") {
		if (node["comment"]){
			return std::make_unique<Resets::ResetEquip>(node["action"].as<std::string>(), node["id"].as<int>(), node["slot"].as<int>(), node["comment"].as<std::string>());
		}
		else {
			return std::make_unique<Resets::ResetEquip>(node["action"].as<std::string>(), node["id"].as<int>(), node["slot"].as<int>(), "");
		}
	} else if(node["action"].as<std::string>() == "door") {
			return std::make_unique<Resets::ResetEquip>("", 0, 0, "");
	} else if(node["action"].as<std::string>() == "put") {
			return std::make_unique<Resets::ResetEquip>("", 0, 0, "");
	}
	return NULL;
}

void YamlParseandBuild::buildResets(std::vector< std::unique_ptr< Reset > >&  resets){
	const YAML::Node&  Reset_Node = fileNode["RESETS"];

	std::transform(Reset_Node.begin(),Reset_Node.end(), std::back_inserter(resets), 
					[this](const YAML::Node& node) { return this->parseResets(node); });
}


//helper classes for yamlParse
std::vector<std::string> YamlParseandBuild::setStringVectorHelper( const YAML::Node& vectorNode){
	std::vector<std::string> stringsV;
	for(auto& it : vectorNode){
		stringsV.push_back((it).as<std::string>());
	}

	return stringsV;
}

