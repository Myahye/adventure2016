#include "Spell.h"
namespace Spells{
	DefenseSpell::DefenseSpellSpell(networking::connection_, int duration_,
									int mana_, int minLevel_, std::string& name_)
									: connection{connection_}, duration{duration_},
									mana{mana_}, minLevel{minLevel_}, name{name_} {};
	std::string DefenseSpell::getName() const {
		return this->name;
	}
	std::vector<string> DefenseSpell::getEffect() const {
		return this->effect;
	}
	void DefenseSpell::setEffect(std::vector<string> effect_) {
		this->effect = effect_;
	}
	std::vector<string> DefenseSpell::getDammsg() const {
		return this->dammsg;
	}
	void DefenseSpell::setDammsg(std::vector<string> dammsg_){
		this->dammsg = dammsg_;
	}

	std::vector<string> DefenseSpell::getHitChar() const {
		return this->hitChar;
	}

	void DefenseSpell::setHitChar(std::vector<string> hitChar_) {
		this->hitChar = hitChar_;
	}

	std::vector<string> DefenseSpell::getHitRoom() const {
		return this->hitRoom;

	}
	void DefenseSpell::setHitRoom(std::vector<string> hitRoom_) {
		this->hitRoom = hitRoom_
	}

	std::vector<string> DefenseSpell::getHitVict() const {
		return this->hitVict;
	}
	void DefenseSpell::setHitVict(std::vector<string> hitVict_){
		this->hitVict = hitVict_;
	}

	std::vector<string> DefenseSpell::getWearoff() const {
		return	this->wearOff;	
	}

	void DefenseSpell::setWearoff(std::vector<string> wearOff_) {
		this-wearOff = wearOff_;
	}
	networking::Connection getConnection() const {
		return this->connection;
	}




}