#include "YamlParseBuild.h"
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
	Npc npcClass{node["id"].as<int>()};
	if(node["armor"]){
		npcClass.npcCharacter.setArmor(node["armor"].as<int>());
	}
	if(node["exp"]){
		npcClass.npcCharacter.setExp(node["exp"].as<int>());
	}
	if(node["gold"]){
		npcClass.npcCharacter.setGold(node["gold"].as<int>());
	}
	if(node["level"]){
		npcClass.npcCharacter.setLevel(node["level"].as<int>());
	}
	if(node["thac0"]){
		npcClass.npcCharacter.setThac0(node["thac0"].as<int>());
	}
	if(node["damage"]){
		std::string damage = node["damage"].as<std::string>();
		npcClass.npcCharacter.setDamage(damage);
	}
	if(node["hit"]){
		std::string hit = node["hit"].as<std::string>();
		npcClass.npcCharacter.setHit(hit);
	}
	if(node["description"]){
		std::vector<std::string> descV = setStringVectorHelper(node["description"]);
		npcClass.npcCharacter.setDescription(descV);
	}
	if(node["shortdesc"]){
		std::string shortdesc = node["shortdesc"].as<std::string>();
		npcClass.npcCharacter.setShortDesc(shortdesc);
	}
	if(node["keywords"]){
		std::vector<std::string> keywordsV = setStringVectorHelper(node["keywords"]);
		npcClass.npcCharacter.setKeywords(keywordsV);
	}
	if(node["longdesc"]){
		std::vector<std::string> longdescV = setStringVectorHelper(node["longdesc"]);
		npcClass.npcCharacter.setLongDesc(longdescV);
	}
	return std::make_pair(npcClass.npcCharacter.getId(),npcClass);
}

void YamlParseBuild::buildNpcs(std::unordered_map<int,Npc>& buildAllNpcs){
	const YAML::Node&  NPC_node = fileNode["NPCS"];
	//std::unordered_map<int,Npc> buildAllNpcs;
	std::transform(NPC_node.begin(),NPC_node.end(), std::inserter( buildAllNpcs, buildAllNpcs.end() ),
					[this](const YAML::Node& node) { return this->parseNpcs(node); }); //if we dont use [this] error:invalid use of non static member function
	//return buildAllNpcs;

}

std::pair<int,Player> YamlParseBuild::parsePlayers(const YAML::Node& node){
	Player playerClass{
		node["id"].as<int>(),
		node["username"].as<std::string>(),
		node["password"].as<std::string>()
	};
	if(node["armor"]){
		playerClass.playerCharacter.setArmor(node["armor"].as<int>());
	}
	if(node["exp"]){
		playerClass.playerCharacter.setExp(node["exp"].as<int>());
	}
	if(node["gold"]){
		playerClass.playerCharacter.setGold(node["gold"].as<int>());
	}
	if(node["level"]){
		playerClass.playerCharacter.setLevel(node["level"].as<int>());
	}
	if(node["health"]){
		playerClass.playerCharacter.setMaxHealth(node["health"].as<int>());
	}
	if(node["mana"]){
		playerClass.playerCharacter.setMaxMana(node["mana"].as<int>());
	}
	if(node["thac0"]){
		playerClass.playerCharacter.setThac0(node["thac0"].as<int>());
	}
	if(node["damage"]){
		std::string damage = node["damage"].as<std::string>();
		playerClass.playerCharacter.setDamage(damage);
	}
	if(node["hit"]){
		std::string hit = node["hit"].as<std::string>();
		playerClass.playerCharacter.setHit(hit);
	}
	if(node["description"]){
		std::vector<std::string> descV = setStringVectorHelper(node["description"]);
		playerClass.playerCharacter.setDescription(descV);
	}
	if(node["shortdesc"]){
		std::string shortdesc = node["shortdesc"].as<std::string>();
		playerClass.playerCharacter.setShortDesc(shortdesc);
	}
	if(node["keywords"]){
		std::vector<std::string> keywordsV = setStringVectorHelper(node["keywords"]);
		playerClass.playerCharacter.setKeywords(keywordsV);
	}
	if(node["longdesc"]){
		std::vector<std::string> longdescV = setStringVectorHelper(node["longdesc"]);
		playerClass.playerCharacter.setLongDesc(longdescV);
	}
	if(node["inventory"]){
		std::unordered_map<int,std::vector<Object> > inventory;
		playerClass.playerCharacter.setInventory(inventory);
		std::vector<Object> objectsV;
		buildObjectsForPlayerInventory(node["inventory"], objectsV);
		for (auto& eachObject : objectsV){
			playerClass.playerCharacter.addObjectToInventory(eachObject, 10); // number 10 needs to be changed
		}
	}
	if(node["equipment"]){
		std::unordered_map<std::string,Object> equipment;
		buildObjectsForPlayerEquipment(node["equipment"], equipment);
		playerClass.playerCharacter.setEquipment(equipment);
	}

	return std::make_pair(playerClass.playerCharacter.getId(),playerClass);
}

void YamlParseBuild::buildPlayers(std::unordered_map<int,Player>& buildAllPlayers){
	//std::unordered_map<int,Npc> buildAllNpcs;
	std::transform(fileNode.begin(), fileNode.end(), std::inserter( buildAllPlayers, buildAllPlayers.end() ),
					[this](const YAML::Node& node) { return this->parsePlayers(node); }); //if we dont use [this] error:invalid use of non static member function
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
	const YAML::Node& Object_Node = fileNode["OBJECTS"];

	//std::unordered_map<int,Object> buildAllObjects;

	std::transform(Object_Node.begin(),Object_Node.end(), std::inserter( buildAllObjects, buildAllObjects.end() ),
					[this](const YAML::Node& node) { return this->parseObjects(node); });
	//return buildAllObjects;
}

void YamlParseBuild::buildObjectsForPlayerEquipment(const YAML::Node& object_node, std::unordered_map<std::string,Object>& inventoryObjects){

	// std::transform(object_node.begin(),object_node.end(), std::inserter( inventoryObjects, inventoryObjects.end() ),
	// 				[this](const YAML::Node& node) { return this->parseObjects(node); });
}

Object YamlParseBuild::parseObjectsForPlayerInventory(const YAML::Node& node){

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
	return objectClass;
}

void YamlParseBuild::buildObjectsForPlayerInventory(const YAML::Node& inventory_node, std::vector<Object>& objectsV){
	std::transform(inventory_node.begin(),inventory_node.end(), std::inserter( objectsV, objectsV.end() ),
					[this](const YAML::Node& node) { return this->parseObjectsForPlayerInventory(node); });
}



std::unique_ptr<Reset> YamlParseBuild::parseResets(const YAML::Node& node){
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
			return std::make_unique<Resets::ResetEquip>(node["action"].as<std::string>(), node["id"].as<int>(), node["slot"].as<std::string>(), node["comment"].as<std::string>());
		}
		else {
			return std::make_unique<Resets::ResetEquip>(node["action"].as<std::string>(), node["id"].as<int>(), node["slot"].as<std::string>(), "");
		}
	} else if(node["action"].as<std::string>() == "door") {
			return std::make_unique<Resets::ResetEquip>("", 0, "", "");
	} else if(node["action"].as<std::string>() == "put") {
			return std::make_unique<Resets::ResetEquip>("", 0, "", "");
	}
	return NULL;
}

void YamlParseBuild::buildResets(std::vector< std::unique_ptr< Reset > >&  resets){
	const YAML::Node&  Reset_Node = fileNode["RESETS"];
	//std::unordered_map<int,Object> buildAllObjects;

	std::transform(Reset_Node.begin(),Reset_Node.end(), std::back_inserter(resets),
					[this](const YAML::Node& node) { return this->parseResets(node); });
}



Door YamlParseBuild::parseDoors(const YAML::Node& node){
	Door doorObject;
	if (node["dir"]){
		std::string direction = node["dir"].as<std::string>();
		doorObject.setDir(direction);
	}
	if(node["desc"]){
		std::vector<std::string> descV = setStringVectorHelper(node["desc"]);
		doorObject.setDesc(descV);
	}
	if(node["keywords"]){
		std::vector<std::string> keywordsV = setStringVectorHelper(node["keywords"]);
		doorObject.setKeywords(keywordsV);
	}
	if(node["to"]){
		doorObject.setDestinationId(node["to"].as<int>());
	}
	return doorObject;
}

void YamlParseBuild::buildDoors(const YAML::Node& door_node, std::vector<Door>& doorsV){
	//std::unordered_map<int,Object> buildAllObjects;

	std::transform(door_node.begin(),door_node.end(), std::inserter( doorsV, doorsV.end() ),
					[this](const YAML::Node& node) { return this->parseDoors(node); });
	//return buildAllObjects;
}

std::pair<int,Room> YamlParseBuild::parseRooms(const YAML::Node& node){
	Room roomObject;

	int roomId = node["id"].as<int>();
	if(node["id"]){
		roomObject.setRoomId(node["id"].as<int>());
	}
	if(node["desc"]){
		std::vector<std::string> descV = setStringVectorHelper(node["desc"]);
		roomObject.setDescription(descV);
	}
	if(node["doors"]){
		std::vector<Door> doorsV;
		buildDoors(node["doors"], doorsV);
		for (auto& eachDoor : doorsV){
			eachDoor.setDoorId(roomId);

			roomObject.addDoor(eachDoor);
		}
	}
	if(node["extended_descriptions"]){
		const YAML::Node& extended_desc_node = node["extended_descriptions"];
		std::vector < std::pair< std::vector<std::string>, std::vector<std::string> > > extendedDescV;
		std::pair< std::vector<std::string>, std::vector<std::string> > extendedDescP;
		std::vector<std::string> descV;
		std::vector<std::string> keywordsV;
		for (auto &j : extended_desc_node){
			descV = setStringVectorHelper(j["desc"]);
			keywordsV = setStringVectorHelper(j["keywords"]);
			extendedDescP = std::make_pair(descV, keywordsV);
			extendedDescV.push_back(extendedDescP);
		}
		//std::cout << "size: " << extraDescV.size() << std::endl;
		//std::cout << "size: " << extraKeywordsV.size() << std::endl;
		roomObject.setExtendedDesc(extendedDescV);
	}
	if(node["name"]){
		std::string roomName = node["name"].as<std::string>();
		roomObject.setName(roomName);
	}
	return std::make_pair(roomObject.getRoomId(),roomObject);
}

void YamlParseBuild::buildRooms (std::unordered_map<int,Room>& buildAllRooms){
	const YAML::Node& room_node = fileNode["ROOMS"];
	std::transform(room_node.begin(),room_node.end(), std::inserter( buildAllRooms, buildAllRooms.end() ),
					[this](const YAML::Node& node) { return this->parseRooms(node); });
}

Spells YamlParseBuild::parseSpells(const YAML::Node& node, bool typeFlag){
								//the parameter is either 'defense', 'offesnse' or 'others'
	Spells spellsObject;

	if(node["Name"]){
		std::string name = node["Name"].as<std::string>();
		spellsObject.setName(name);
	}
	if(node["Effect"]){
		std::string effect = node["Effect"].as<std::string>();
		spellsObject.setEffect(effect);
	}
	if(node["Hitchar"]){
		std::string hitchar = node["Hitchar"].as<std::string>();
		spellsObject.setHitChar(hitchar);
	}
	if(node["Hitroom"]){
		std::string hitroom = node["Hitroom"].as<std::string>();
		spellsObject.setHitRoom(hitroom);
	}
	if(node["Hitvict"]){
		std::string hitvict = node["Hitvict"].as<std::string>();
		spellsObject.setHitVict(hitvict);
	}
	if(node["Wearoff"]){
		std::string wearoff = node["Wearoff"].as<std::string>();
		spellsObject.setWearOff(wearoff);
	}
	if(node["Dammsg"]){
		std::string dammsg = node["Dammsg"].as<std::string>();
		spellsObject.setDamMsg(dammsg);
	}
	if(node["Immchar"]){
		std::string immchar = node["Immchar"].as<std::string>();
		spellsObject.setImmChar(immchar);
	}
	if(node["Duration"]){
		spellsObject.setDuration(node["Duration"].as<int>());
	}
	
	if(node["Mana"]){
		spellsObject.setMana(node["Mana"].as<int>());
	}
	if(node["Minlevel"]){
		spellsObject.setMinLevel(node["Minlevel"].as<int>());
	}
	
	if(typeFlag){
		std::string defenseString = "defense";
		spellsObject.setType(defenseString);
	}
	else{
		std::string offenseString = "offense";
		spellsObject.setType(offenseString);
	}

	return spellsObject;
}

void YamlParseBuild::buildSpells(std::vector<Spells>& spellsV, bool typeFlag){
	if(typeFlag){
		const YAML::Node& defense_node = fileNode["defense"];	
		std::transform(defense_node.begin(),defense_node.end(), std::inserter(spellsV, spellsV.end()), 
					[this,typeFlag](const YAML::Node& node) { return this->parseSpells(node,typeFlag); });
	}
	else{
		const YAML::Node& offense_node = fileNode["offense"];	
		std::transform(offense_node.begin(),offense_node.end(), std::inserter(spellsV, spellsV.end()), 
					[this,typeFlag](const YAML::Node& node) { return this->parseSpells(node,typeFlag); });
	}
}

//helper classes for yamlParse
std::vector<std::string> YamlParseBuild::setStringVectorHelper( const YAML::Node& vectorNode){
	std::vector<std::string> stringsV;
	for(auto& it : vectorNode){
		stringsV.push_back((it).as<std::string>());
	}

	return stringsV;
}