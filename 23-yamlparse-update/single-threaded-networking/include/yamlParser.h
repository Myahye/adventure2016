#ifndef YamlParseandBuild_H
#define YamlParseandBuild_H

#include "NPC.h"
#include "Object.h"
#include "Room.h"
#include "Door.h"
#include "Resets.h"
#include "yaml-cpp/yaml.h"
#include <unordered_map>


class YamlParseandBuild{
private:
	YAML::Node fileNode;
public:
	YamlParseandBuild();
	void loadFile(const std::string& filename);
	const YAML::Node& returnNodeByName(const std::string& nodename);
	
	std::pair<int,Npc> parseNpcs(const YAML::Node& node);
	std::pair<int,Object> parseObjects(const YAML::Node& node);
	std::unique_ptr<Reset> parseResets(const YAML::Node& node);

	//std::vector<std::unique_ptr<Reset>> parseBuildResets(const std::string& pathToFile);
	// std::pair<int,Room> parseRooms(const std::string& nodename);
	// std::pair<int,Door> parseDoors(const std::string& nodename);

	void buildNpcs(std::unordered_map<int,Npc>& buildAllNpcs);
	void buildObjects(std::unordered_map<int,Object>& buildAllObjects);
	void buildResets(std::vector< std::unique_ptr< Reset > >&  resets);

	//std::unordered_map<int,Room> buildRooms(); //doors will be built here as well


	//helper methods - maybe seperate this into another class?
	std::vector<std::string> setStringVectorHelper(const YAML::Node& descNode);
	
};

#endif