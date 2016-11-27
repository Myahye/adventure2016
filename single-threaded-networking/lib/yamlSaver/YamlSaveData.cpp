#include "YamlSaveData.h"

//YamlSaveData::YamlSaveData() {}

/*void updateUserData(Player& player){
	YAML::Node& users_node = base_node["USERS"];
}*/

/*void YamlSaveData::saveUserData(std::unordered_map<int,Player>& players){
	YAML::Emitter emitter;

	emitter << YAML::BeginSeq;
	emitter << YAML::Key << "id" << YAML::Value << player.playerCharacter.getId().as<std::string>();
	emitter << YAML::BeginMap;
	emitter << YAML::Key << "username" << YAML::Value << player.getUsername().as<std::string>();
	emitter << YAML::Key << "password" << YAML::Value << player.getUsername().as<std::string>();
	emitter << YAML::EndMap;

	std::ofstream fout("../data/users1.yml");
	fout << emitter.c_str();
}*/

void YamlSaveData::saveUserData(const std::unordered_map<int,Player>& players){
	YAML::Emitter emitter;
	emitter << YAML::BeginSeq;
	for (auto& eachPlayer : players){
		emitter << YAML::BeginMap;
		emitter << YAML::Key << "id" << YAML::Value << std::to_string(eachPlayer.second.playerCharacter.getId());
		emitter << YAML::Key << "username" << YAML::Value << eachPlayer.second.getUsername();
		emitter << YAML::Key << "password" << YAML::Value << eachPlayer.second.getPassword();
		emitter << YAML::Key << "armor" << YAML::Value << std::to_string(eachPlayer.second.playerCharacter.getArmor());
		emitter << YAML::Key << "exp" << YAML::Value << std::to_string(eachPlayer.second.playerCharacter.getExp());
		emitter << YAML::Key << "gold" << YAML::Value << std::to_string(eachPlayer.second.playerCharacter.getGold());
		emitter << YAML::Key << "level" << YAML::Value << std::to_string(eachPlayer.second.playerCharacter.getLevel());
		emitter << YAML::Key << "health" << YAML::Value << std::to_string(eachPlayer.second.playerCharacter.getMaxHealth());
		emitter << YAML::Key << "mana" << YAML::Value << std::to_string(eachPlayer.second.playerCharacter.getMaxMana());
		emitter << YAML::Key << "thac0" << YAML::Value << std::to_string(eachPlayer.second.playerCharacter.getThac0());
		emitter << YAML::Key << "damage" << YAML::Value << eachPlayer.second.playerCharacter.getDamage();
		emitter << YAML::Key << "hit" << YAML::Value << eachPlayer.second.playerCharacter.getHit();
		
		std::vector<std::string> keywordsV = eachPlayer.second.playerCharacter.getKeywords();
		emitVectorStrings("keywords", emitter, keywordsV);
		
		std::vector<std::string> descriptionV = eachPlayer.second.playerCharacter.getDescriptionV();
		emitVectorStrings("description", emitter, descriptionV);
		
		std::vector<std::string> longdescV = eachPlayer.second.playerCharacter.getLongDescV();
		emitVectorStrings("longdesc", emitter, longdescV);
		
		emitter << YAML::Key << "shortdesc" << YAML::Value << eachPlayer.second.playerCharacter.getShortDesc();
		
		emitter << YAML::Key << "inventory";
		emitter << YAML::BeginMap;
		std::unordered_map<int, std::vector<Object> > inventoryMap = eachPlayer.second.playerCharacter.getInventory();
		for (auto& eachVectorObject : inventoryMap){
			emitVectorObjects(emitter, eachVectorObject.second);
		}
		emitter << YAML::EndMap;
		emitter << YAML::Key << "equipment";
		emitter << YAML::BeginMap;
		std::unordered_map<int, Object> equipmentMap = eachPlayer.second.playerCharacter.getEquipment();
		emitMapObjects(emitter, equipmentMap);
		emitter << YAML::EndMap;
		emitter << YAML::EndMap;
	}
	emitter << YAML::EndSeq;
	std::ofstream fout("../data/users1.yml");
	fout << emitter.c_str();
}

void YamlSaveData::emitVectorStrings(std::string name, YAML::Emitter& emitter, std::vector<std::string>& stringV){
	emitter << YAML::Key << name;
	emitter << YAML::Value << YAML::BeginSeq;
	for (auto& eachString : stringV){
		emitter << eachString;
	}
	emitter << YAML::EndSeq;
}

void YamlSaveData::emitVectorObjects(YAML::Emitter& emitter, std::vector<Object>& objectV){
	for (auto& eachObject : objectV){
		std::vector<std::string> attributesV = eachObject.getAttributes();
		emitVectorStrings("attributes", emitter, attributesV);
		emitter << YAML::Key << "cost" << YAML::Value << std::to_string(eachObject.getCost());

		std::vector<std::pair<std::vector<std::string>, std::vector<std::string> > > extraV = eachObject.getExtra();
		emitObjectExtra("desc", "keywords", emitter, extraV);

		emitter << YAML::Key << "id" << YAML::Value << std::to_string(eachObject.getId());
		emitter << YAML::Key << "item_type" << YAML::Value << eachObject.getItemType();

		std::vector<std::string> keywordsV = eachObject.getKeywords();
		emitVectorStrings("keywords", emitter, keywordsV);

		std::vector<std::string> longdescV = eachObject.getLongDesc();
		emitVectorStrings("longdesc", emitter, longdescV);

		emitter << YAML::Key << "shortdesc" << YAML::Value << eachObject.getShortDesc();

		std::vector<std::string> wearflagsV = eachObject.getWearFlags();
		emitVectorStrings("wear_flags", emitter, wearflagsV);

		emitter << YAML::Key << "weight" << YAML::Value << std::to_string(eachObject.getWeight());
	}
}

void YamlSaveData::emitMapObjects(YAML::Emitter& emitter, std::unordered_map<int, Object>& objectM){
	for (auto& eachObject : objectM){
		std::vector<std::string> attributesV = eachObject.second.getAttributes();
		emitVectorStrings("attributes", emitter, attributesV);
		emitter << YAML::Key << "cost" << YAML::Value << std::to_string(eachObject.second.getCost());

		std::vector<std::pair<std::vector<std::string>, std::vector<std::string> > > extraV = eachObject.second.getExtra();
		emitObjectExtra("desc", "keywords", emitter, extraV);

		emitter << YAML::Key << "id" << YAML::Value << std::to_string(eachObject.second.getId());
		emitter << YAML::Key << "item_type" << YAML::Value << eachObject.second.getItemType();

		std::vector<std::string> keywordsV = eachObject.second.getKeywords();
		emitVectorStrings("keywords", emitter, keywordsV);

		std::vector<std::string> longdescV = eachObject.second.getLongDesc();
		emitVectorStrings("longdesc", emitter, longdescV);

		emitter << YAML::Key << "shortdesc" << YAML::Value << eachObject.second.getShortDesc();

		std::vector<std::string> wearflagsV = eachObject.second.getWearFlags();
		emitVectorStrings("wear_flags", emitter, wearflagsV);

		emitter << YAML::Key << "weight" << YAML::Value << std::to_string(eachObject.second.getWeight());
	}
}

void YamlSaveData::emitObjectExtra(std::string pair_one, std::string pair_two, YAML::Emitter& emitter, std::vector< std::pair< std::vector<std::string>, std::vector<std::string> > >& extraV){
	for (auto& eachPair : extraV){
		emitVectorStrings(pair_one, emitter, eachPair.first);
			emitVectorStrings(pair_two, emitter, eachPair.second);
	}
}

void YamlSaveData::updateOrAddPlayer(std::unordered_map<int,Player>& players, Player& player){
	players.erase(player.playerCharacter.getId());
	players.insert(std::make_pair(player.playerCharacter.getId(), player));
}