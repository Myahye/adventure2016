#include "model.h"
//#include "NPC.h"

model::model() {};

void model::yamlParseNPC(std::string pathToFile){
	YAML::Node config = YAML::LoadFile(pathToFile);
	const YAML::Node&  NPC_node= config["NPCS"];
	//iterate through all NPC Nodes
	// NPC npcob(NPC_node[0]["id"].as<int>(), NPC_node[0]["shortdesc"].as<std::string>());
	// cout << "npcob id :  " << npcob.getId() << "\n";
	// cout << "line 11\n";
	for (auto it = NPC_node.begin(); it != NPC_node.end(); ++it) {
		const YAML::Node& element = *it;
		NPC npcClass{element["id"].as<int>(), element["shortdesc"].as<std::string>()};
		npcClass.setArmor(element["armor"].as<int>());
		npcClass.setDamage(element["damage"].as<std::string>());
		npcClass.setExp(element["exp"].as<int>());
		npcClass.setGold(element["gold"].as<int>());
		npcClass.setHit(element["hit"].as<std::string>());
		npcClass.setId(element["id"].as<int>());
		npcClass.setLevel(element["armor"].as<int>());
		npcClass.setShortDesc(element["shortdesc"].as<std::string>());
		npcClass.setThac0(element["thac0"].as<int>());

		//vectors
		npcClass.setDesc(setDescHelper(element["description"])); //change up
		// npcClass.setKeywords(setKeywordsHelper(element["keywords"]));
		// npcClass.setLongDesc(setLongDescHelper(element["longdesc"]));
		
		//Add NPC to map
  		allNPC[npcClass.getId()] = npcClass;
	}

}

//helper classes for yamlParseNPC
vector<std::string> model::setDescHelper( const YAML::Node& descNode){
	vector<std::string> allDescStrings;
	for(auto it = descNode.begin(); it != descNode.end(); it++){
		allDescStrings.push_back(*it);
	}

	return allDescStrings;
}

// vector<std::string> model::setKeywordsHelper(const YAML::Node& keywordsNode){
// 	vector<std::string> allKeywords;
// 	for(auto it = keywordsNode.begin(); it != keywordsNode.end(); it++){
// 		allKeywords.push_back(*it);
// 	}

// 	return allKeywords;
// }

// vector<std::string> model::setLongDescHelper(const YAML::Node& longDescNode){
// 	vector<std::string> allLongDesc;
// 	for(auto it = longDescNode.begin(); it != longDescNode.end(); it++){
// 		allLongDesc.push_back(*it);
// 	}

// 	return allLongDesc;
// }