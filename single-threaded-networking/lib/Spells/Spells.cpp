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

	OffenseSpell::OffenseSpell(networking::connection, int new_duration,int new_mana, int new_minLevel, std::string& new_name)
	: connection{connection}, duration{new_duration}, mana{new_mana}, minlevel{new_minLevel}, name{new_name} {};
	std::string OffenseSpell::getName() const {
		return this->name;
	}
	std::vector<std::string> OffenseSpell::getEffect() const {
		return this->effect;
	}
	void OffenseSpell::setEffect(std::vector<std::string>& new_effect) {
		this->effect = new_effect;
	}
	std::vector<std::string> OffenseSpell::getDammsg() const {
		return this->dammsg;
	}
	void OffenseSpell::setDammsg(std::vector<std::string>& new_dammsg){
		this->dammsg = dammsg;
	}

	std::vector<std::string> OffenseSpell::getMsgChar() const {
		return this->hitchar;
	}

	void OffenseSpell::setMsgChar(std::vector<std::string>& new_hitChar) {
		this->hitchar = new_hitChar;
	}

	std::vector<std::string> OffenseSpell::getMsgRoom() const {
		return this->hitroom;

	}
	void OffenseSpell::setMsgRoom(std::vector<std::string>& new_hitRoom) {
		this->hitroom = new_hitRoom
	}

	std::vector<std::string> OffenseSpell::getMsgVict() const {
		return this->hitvict;
	}
	void OffenseSpell::setMsgVict(std::vector<std::string>& new_hitVict){
		this->hitvict = new_hitVict;
	}

	std::vector<std::string> OffenseSpell::getImmchar() const {
		return	this->immchar;	
	}
	void OffenseSpell::setImmchar(std::vector<std::string>& new_immChar) {
		this->immchar = new_immchar;
	}

	std::vector<std::string> OffenseSpell::getWearoff() const {
		return	this->wearoff;	
	}

	void OffenseSpell::setWearoff(std::vector<std::string>& new_wearOff) {
		this->wearoff = new_wearOff;
	}
	networking::Connection getConnection() const {
		return this->connection;
	}

	

	ObjectSpell::ObjectSpell(networking::connection, int new_duration,int new_mana, int new_minLevel, std::string& new_name)
	: connection{connection}, duration{new_duration}, mana{new_mana}, minlevel{new_minLevel}, name{new_name} {};
	std::string ObjectSpell::getName() const {
		return this->name;
	}
	std::vector<std::string> ObjectSpell::getEffect() const {
		return this->effect;
	}
	void ObjectSpell::setEffect(std::vector<std::string>& new_effect) {
		this->effect = new_effect;
	}
	std::vector<std::string> ObjectSpell::getDammsg() const {
		return this->dammsg;
	}
	void ObjectSpell::setDammsg(std::vector<std::string>& new_dammsg){
		this->dammsg = new_dammsg;
	}

	std::vector<std::string> ObjectSpell::getMsgChar() const {
		return this->hitchar;
	}

	void ObjectSpell::setMsgChar(std::vector<std::string>& new_msgChar) {
		this->msgChar = new_msgChar;
	}

	std::vector<std::string> ObjectSpell::getMsgRoom() const {
		return this->hitroom;

	}
	void ObjectSpell::setMsgRoom(std::vector<std::string>& new_msgRoom) {
		this->msgRoom = new_msgRoom
	}

	std::vector<std::string> ObjectSpell::getMsgVict() const {
		return this->hitvict;
	}
	void ObjectSpell::setMsgVict(std::vector<std::string>& new_msgVict){
		this->msgVict = new_msgVict;
	}

	networking::Connection getConnection() const {
		return this->connection;
	}

}