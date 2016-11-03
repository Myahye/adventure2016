#include "YamlParser.h"
//#include <utility>
YamlParseBuild::YamlParseBuild() {};

void YamlParseBuild::loadFile(const std::string& pathToFile){
	this->fileNode = YAML::LoadFile(pathToFile);
}

const YAML::Node& YamlParseBuild::returnNodeByName(const std::string& nodename){
	return fileNode[nodename];
}


/*********Parses and builds Npc's from yaml file****************/
std::pair<int,Npc> YamlParseBuild::parseNpcs(const YAML::Node& node){
	std::string shortdesc = node["shortdesc"].as<std::string>();
	Npc npcClass{node["id"].as<int>(), shortdesc};
	if(node["armor"]){
		npcClass.setArmor(node["armor"].as<int>());
	}
	else if(node["exp"]){
		npcClass.setExp(node["exp"].as<int>());
	}
	else if(node["gold"]){
		npcClass.setGold(node["gold"].as<int>());
	}
	else if(node["level"]){
		npcClass.setLevel(node["level"].as<int>());
	}
	else if(node["thac0"]){
		npcClass.setThac0(node["thac0"].as<int>());
	}
	else if(node["damage"]){
		std::string damage = node["damage"].as<std::string>();
		npcClass.setDamage(damage);
	}
	else if(node["hit"]){
		std::string hit = node["hit"].as<std::string>();
		npcClass.setHit(hit);
	}
	else if(node["description"]){
		std::vector<std::string> descV = setStringVectorHelper(node["description"]);
		npcClass.setDesc(descV); 
	}
	else if(node["keywords"]){
		std::vector<std::string> keywordsV = setStringVectorHelper(node["keywords"]);
		npcClass.setKeywords(keywordsV);
	}
	else if(node["longdesc"]){
		std::vector<std::string> longdescV = setStringVectorHelper(node["longdesc"]);
		npcClass.setLongDesc(longdescV);
	}
	return std::make_pair(npcClass.getId(),npcClass);
}

void YamlParseBuild::buildNpcs(std::unordered_map<int,Npc>& buildAllNpcs){
	const YAML::Node&  NPC_node = fileNode["NPCS"];
	//std::unordered_map<int,Npc> buildAllNpcs;
	std::transform(NPC_node.begin(),NPC_node.end(), std::inserter( buildAllNpcs, buildAllNpcs.end() ), 
					[this](const YAML::Node& node) { return this->parseNpcs(node); }); //if we dont use [this] error:invalid use of non static member function
	//return buildAllNpcs;
																  
}



/*********Parses and builds Object's from yaml file****************/
std::pair<int,Object> YamlParseBuild::parseObjects(const YAML::Node& node){

	//Object objectClass{node["id"].as<int>(), node["item_type"].as<std::string>()};
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
		std::vector < std::pair< std::vector<std::string>, std::vector<std::string> > > extraV;
		std::pair< std::vector<std::string>, std::vector<std::string> > extraP;
		std::vector<std::string> extraDescV;
		std::vector<std::string> extraKeywordsV;	
		
		for (auto &j : extra_node){
			extraDescV = setStringVectorHelper(j["desc"]);
			extraKeywordsV = setStringVectorHelper(j["keywords"]);
			extraP = std::make_pair(extraDescV, extraKeywordsV);
			extraV.push_back(extraP);
		}
		//std::cout << "size: " << extraDescV.size() << std::endl;
		//std::cout << "size: " << extraKeywordsV.size() << std::endl;
		objectClass.setExtra(extraV);
	}
	return std::make_pair(objectClass.getId(),objectClass);
}

void YamlParseBuild::buildObjects(std::unordered_map<int,Object>& buildAllObjects){
	const YAML::Node&  Object_Node = fileNode["OBJECTS"];
	//std::unordered_map<int,Object> buildAllObjects;
	
	std::transform(Object_Node.begin(),Object_Node.end(), std::inserter( buildAllObjects, buildAllObjects.end() ), 
					[this](const YAML::Node& node) { return this->parseObjects(node); });
	//return buildAllObjects;
}
//maybe change to take in npc,object,room maps as parameters and pass in pointers to rooms/npc/objects to the constructors of resetNPC etc.
//change to use unique_ptr and move ownership to vector
/*
std::vector<std::unique_ptr<Reset>> YamlParseBuild::parseBuildResets(const std::string& pathToFile){
	
	YAML::Node config = YAML::LoadFile(pathToFile);
	const YAML::Node& reset_node = config["RESETS"];

	//initialize our map we will return
	std::vector<std::unique_ptr<Reset>> buildAllResets;

	std::unique_ptr<Reset> reset;

	for (auto& node : reset_node) {
		if(node["action"].as<std::string>() == "npc") {
			if (node["comment"]){
				reset = std::make_unique<Resets::ResetNpc>(node["action"].as<std::string>(), node["id"].as<int>(), node["limit"].as<int>(), node["room"].as<int>(), node["comment"].as<std::string>());
			}
			else {
				reset = std::make_unique<Resets::ResetNpc>(node["action"].as<std::string>(), node["id"].as<int>(), node["limit"].as<int>(), node["room"].as<int>(), "");
			}
		} else if(node["action"].as<std::string>() == "object") {
			if (node["comment"]){
				reset = std::make_unique<Resets::ResetObject>(node["action"].as<std::string>(), node["id"].as<int>(), 1, node["room"].as<int>(), node["comment"].as<std::string>());
			}
			else {
				reset = std::make_unique<Resets::ResetObject>(node["action"].as<std::string>(), node["id"].as<int>(), 1, node["room"].as<int>(), "");
			}
		} else if(node["action"].as<std::string>() == "give") {
			if (node["comment"]){
				reset = std::make_unique<Resets::ResetGive>(node["action"].as<std::string>(), node["id"].as<int>(), 1, 0, node["comment"].as<std::string>());
			}
			else {
				reset = std::make_unique<Resets::ResetGive>(node["action"].as<std::string>(), node["id"].as<int>(), 1, 0, "");
			}
		} else if(node["action"].as<std::string>() == "equip") {
			if (node["comment"]){
				reset = std::make_unique<Resets::ResetEquip>(node["action"].as<std::string>(), node["id"].as<int>(), node["slot"].as<int>(), node["comment"].as<std::string>());
			}
			else {
				reset = std::make_unique<Resets::ResetEquip>(node["action"].as<std::string>(), node["id"].as<int>(), node["slot"].as<int>(), "");
			}
		}
		buildAllResets.push_back(std::move(reset));

		// Reset reset{node["action"].as<std::string>(), node["id"].as<int>()};

		// if (node["limit"]){
		// 	reset.setLimit(node["limit"].as<int>());
		// }
		// if (node["room"]){
		// 	reset.setRoom(node["room"].as<int>());
		// }
		// if (node["slot"]){
		// 	reset.setSlot(node["slot"].as<int>());
		// }
		// if (node["comment"]){
		// 	std::string comment = node["comment"].as<std::string>();
		// 	reset.setComment(comment);
		// }
		
		// buildAllResets.push_back(reset);
	}
	return buildAllResets;
}



std::unique_ptr<Reset> YamlParseBuild::parseResets(const YAML::Node& node){
		std::unique_ptr<Reset> reset;


		if(node["action"].as<std::string>() == "npc") {
			if (node["comment"]){
				reset = std::make_unique<Resets::ResetNpc>(node["action"].as<std::string>(), node["id"].as<int>(), node["limit"].as<int>(), node["room"].as<int>(), node["comment"].as<std::string>());
			}
			else {
				reset = std::make_unique<Resets::ResetNpc>(node["action"].as<std::string>(), node["id"].as<int>(), node["limit"].as<int>(), node["room"].as<int>(), "");
			}
		} else if(node["action"].as<std::string>() == "object") {
			if (node["comment"]){
				reset = std::make_unique<Resets::ResetObject>(node["action"].as<std::string>(), node["id"].as<int>(), 1, node["room"].as<int>(), node["comment"].as<std::string>());
			}
			else {
				reset = std::make_unique<Resets::ResetObject>(node["action"].as<std::string>(), node["id"].as<int>(), 1, node["room"].as<int>(), "");
			}
		} else if(node["action"].as<std::string>() == "give") {
			if (node["comment"]){
				reset = std::make_unique<Resets::ResetGive>(node["action"].as<std::string>(), node["id"].as<int>(), 1, 0, node["comment"].as<std::string>());
			}
			else {
				reset = std::make_unique<Resets::ResetGive>(node["action"].as<std::string>(), node["id"].as<int>(), 1, 0, "");
			}
		} else if(node["action"].as<std::string>() == "equip") {
			if (node["comment"]){
				reset = std::make_unique<Resets::ResetEquip>(node["action"].as<std::string>(), node["id"].as<int>(), node["slot"].as<int>(), node["comment"].as<std::string>());
			}
			else {
				reset = std::make_unique<Resets::ResetEquip>(node["action"].as<std::string>(), node["id"].as<int>(), node["slot"].as<int>(), "");
			}
		}
		return std::move(reset);

		// Reset reset{node["action"].as<std::string>(), node["id"].as<int>()};

		// if (node["limit"]){
		// 	reset.setLimit(node["limit"].as<int>());
		// }
		// if (node["room"]){
		// 	reset.setRoom(node["room"].as<int>());
		// }
		// if (node["slot"]){
		// 	reset.setSlot(node["slot"].as<int>());
		// }
		// if (node["comment"]){
		// 	std::string comment = node["comment"].as<std::string>();
		// 	reset.setComment(comment);
		// }
		
		// buildAllResets.push_back(reset);
}

void YamlParseBuild::buildResets(std::vector< std::unique_ptr< Reset > >&  resets){
	const YAML::Node&  Reset_Node = fileNode["RESETS"];
	//std::unordered_map<int,Object> buildAllObjects;
	
	std::transform(Reset_Node.begin(),Reset_Node.end(), std::back_inserter(resets), 
					[this](const YAML::Node& node) { return this->parseResets(node); });
	//return buildAllObjects;
}
*/


/*std::pair<int,Room> YamlParseBuild::parseRooms(const YAML::Node& node){
	Room roomObject;

	if(node["desc"]){
		std::vector<std::string> descV = setStringVectorHelper(node["desc"]);
		roomObject.setDesc(descV);
	}
	else if(node["doors"]){
		std::vector<Door> doorsV;
		buildDoors(node["doors"], doorsV);
		roomObject.addVectorDoors(doorsV);
	}
}


Door YamlParseBuild::parseDoors(const YAML::Node& node){
	Door doorObject;

	if(node["desc"]){
		std::vector<std::string> descV = setStringVectorHelper(node["desc"]);
		doorObject.setDesc(descV);
	}
	if(node["dir"]){
		doorObject.setDir(node["dir"].as<std::string>());
	}
	if(node["keywords"]){
		std::vector<std::string> keywordsV = setStringVectorHelper(node["keywords"]);
		doorObject.setDesc(keywordsV);
	}
	if(node["to"]){
		doorObject.setDoorId(node["to"].as<int>());
	}
	return doorObject;
}

void YamlParseBuild::buildDoors(const YAML::Node&  door_node, std::vector<Door>& doorsV){
	//std::unordered_map<int,Object> buildAllObjects;
	
	std::transform(door_node.begin(),door_node.end(), std::inserter( doorsV, doorsV.end() ), 
					[this](const YAML::Node& node) { return this->parseDoors(node); });
	//return buildAllObjects;
}
*/
//helper classes for yamlParse
std::vector<std::string> YamlParseBuild::setStringVectorHelper( const YAML::Node& vectorNode){
	std::vector<std::string> stringsV;
	for(auto& it : vectorNode){
		stringsV.push_back((it).as<std::string>());
	}

	return stringsV;
}
