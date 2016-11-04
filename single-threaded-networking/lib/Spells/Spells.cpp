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

	OffenseSpell::OffenseSpell(networking::connection, int duration,int mana, int minLevel, std::string& name)
	: connection{connection}, duration{duration}, Mana{mana}, Minlevel{minLevel}, Name{name} {};
	std::string OffenseSpell::getName() const {
		return this->Name;
	}
	std::vector<string> OffenseSpell::getEffect() const {
		return this->Effect;
	}
	void OffenseSpell::setEffect(std::vector<string> effect) {
		this->Effect = effect;
	}
	std::vector<string> OffenseSpell::getDammsg() const {
		return this->dammsg;
	}
	void OffenseSpell::setDammsg(std::vector<string> dammsg){
		this->Dammsg = dammsg;
	}

	std::vector<string> OffenseSpell::getHitChar() const {
		return this->Hitchar;
	}

	void OffenseSpell::setHitChar(std::vector<string> hitChar) {
		this->Hitchar = hitChar;
	}

	std::vector<string> OffenseSpell::getHitRoom() const {
		return this->HitRoom;

	}
	void OffenseSpell::setHitRoom(std::vector<string> hitRoom) {
		this->HitRoom = hitRoom
	}

	std::vector<string> OffenseSpell::getHitVict() const {
		return this->Hitvict;
	}
	void OffenseSpell::setHitVict(std::vector<string> hitVict){
		this->Hitvict = hitVict;
	}

	std::vector<string> OffenseSpell::getImmchar() const {
		return	this->Immchar;	
	}

	void OffenseSpell::setImmchar(std::vector<string> immchar) {
		this->Immchar = immchar;

	std::vector<string> OffenseSpell::getWearoff() const {
		return	this->Wearoff;	
	}

	void OffenseSpell::setWearoff(std::vector<string> wearOff) {
		this->Wearoff = wearOff;
	}
	networking::Connection getConnection() const {
		return this->connection;
	}

	ObjectSpell::ObjectSpell(networking::connection, int duration,int mana, int minLevel, std::string& name)
	: connection{connection}, duration{duration}, Mana{mana}, Minlevel{minLevel}, Name{name} {};
	std::string ObjectSpell::getName() const {
		return this->Name;
	}
	std::vector<string> ObjectSpell::getEffect() const {
		return this->Effect;
	}
	void ObjectSpell::setEffect(std::vector<string> effect) {
		this->Effect = effect;
	}
	std::vector<string> ObjectSpell::getDammsg() const {
		return this->dammsg;
	}
	void ObjectSpell::setDammsg(std::vector<string> dammsg){
		this->Dammsg = dammsg;
	}

	std::vector<string> ObjectSpell::getHitChar() const {
		return this->Hitchar;
	}

	void ObjectSpell::setHitChar(std::vector<string> hitChar) {
		this->Hitchar = hitChar;
	}

	std::vector<string> ObjectSpell::getHitRoom() const {
		return this->HitRoom;

	}
	void ObjectSpell::setHitRoom(std::vector<string> hitRoom) {
		this->HitRoom = hitRoom
	}

	std::vector<string> ObjectSpell::getHitVict() const {
		return this->Hitvict;
	}
	void ObjectSpell::setHitVict(std::vector<string> hitVict){
		this->Hitvict = hitVict;
	}

	// std::vector<string> ObjectSpell::getImmchar() const {
	// 	return	this->Immchar;	
	// }

	// void ObjectSpell::setImmchar(std::vector<string> immchar) {
	// 	this->Immchar = immchar;

	// std::vector<string> ObjectSpell::getWearoff() const {
	// 	return	this->Wearoff;	
	// }

	// void ObjectSpell::setWearoff(std::vector<string> wearOff) {
	// 	this->Wearoff = wearOff;
	}
	networking::Connection getConnection() const {
		return this->connection;
	}

}