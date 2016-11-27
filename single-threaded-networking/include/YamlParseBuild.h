#ifndef YamlParseBuild_H
#define YamlParseBuild_H

#include "Npc.h"
#include "Player.h"
#include "Object.h"
#include "Room.h"
#include "Door.h"
#include "Resets.h"
#include "Spells.h"

#include "yaml-cpp/yaml.h"
#include <unordered_map>


class YamlParseBuild{
private:
	YAML::Node fileNode;
public:
	YamlParseBuild();
	void loadFile(const std::string& filename);
	const YAML::Node& returnNodeByName(const std::string& nodename);
	
	std::pair<int,Npc> parseNpcs(const YAML::Node& node);
	std::pair<int,Player> parsePlayers(const YAML::Node& node);
	std::pair<int,Object> parseObjects(const YAML::Node& node);
	Object parseObjectsForPlayerInventory(const YAML::Node& node);
	std::pair<int,Room> parseRooms(const YAML::Node& node);
	std::unique_ptr<Reset> parseResets(const YAML::Node& node);
	Door parseDoors(const YAML::Node& node);
	Spells parseSpells(const YAML::Node& node, bool typeFlag);

	//std::vector<std::unique_ptr<Reset>> parseBuildResets(const std::string& pathToFile);
	// std::pair<int,Room> parseRooms(const std::string& nodename);
	// std::pair<int,Door> parseDoors(const std::string& nodename);

	void buildNpcs(std::unordered_map<int,Npc>& buildAllNpcs);
	void buildPlayers(std::unordered_map<int,Player>& buildAllPlayers);
	void buildObjects(std::unordered_map<int,Object>& buildAllObjects);
	void buildObjectsForPlayerEquipment(const YAML::Node& object_node, std::unordered_map<int,Object>& inventoryObjects);
	void buildObjectsForPlayerInventory(const YAML::Node& inventory_node, std::vector<Object>& objectsV);
	void buildRooms(std::unordered_map<int,Room>& buildAllRooms);
	void buildResets(std::vector< std::unique_ptr< Reset > >&  resets);
	void buildDoors(const YAML::Node& door_node, std::vector<Door>& doorsV);
	void buildSpells(std::vector<Spells>& spellsV, bool typeFlag);
	//std::unordered_map<int,Room> buildRooms(); //doors will be built here as well


	//helper methods - maybe seperate this into another class?
	std::vector<std::string> setStringVectorHelper(const YAML::Node& descNode);
	
};

#endif
