#ifndef YamlParseBuild_H
#define YamlParseBuild_H

#include "Npc.h"
#include "Object.h"
#include "Room.h"
#include "Door.h"
#include "Resets.h"
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
	std::pair<int,Object> parseObjects(const YAML::Node& node);
	std::pair<int,Room> parseRooms(const YAML::Node& node);
	std::unique_ptr<Reset> parseResets(const YAML::Node& node);
	Door parseDoors(const YAML::Node& node);
	//std::vector<std::unique_ptr<Reset>> parseBuildResets(const std::string& pathToFile);
	// std::pair<int,Room> parseRooms(const std::string& nodename);
	// std::pair<int,Door> parseDoors(const std::string& nodename);

	void buildNpcs(std::unordered_map<int,Npc>& buildAllNpcs);
	void buildObjects(std::unordered_map<int,Object>& buildAllObjects);
	void buildRooms(std::unordered_map<int,Room>& buildAllRooms);
	void buildResets(std::vector< std::unique_ptr< Reset > >&  resets);
	void buildDoors(const YAML::Node& door_node, std::vector<Door>& doorsV);

	//std::unordered_map<int,Room> buildRooms(); //doors will be built here as well


	//helper methods - maybe seperate this into another class?
	std::vector<std::string> setStringVectorHelper(const YAML::Node& descNode);
	
};

#endif