#include "NPC.h"

//NPC Constructor
NPC::NPC (int const id, std::string const shortdesc):
	id{id}, shortdesc{shortdesc}{};

//Clonning
NPC::NPC(const NPC &npc){
	this->armor =npc.armor;
	this->id    =npc.id;
	this->exp   =npc.exp;
	this->gold	=npc.gold;
	this->level	=npc.level;
	this->thac0	=npc.thac0;

	this->damage		=npc.damage;
	this->hit				=npc.hit;
	this->shortdesc	=npc.shortdesc;

	/*clean all vectors of the objects before copy*/
	clear_vec(description);
	clear_vec(keywords);
	clear_vec(longdesc);

	/*------copy vectors------*/
	copy_vec(this->description,npc.description);
	copy_vec(this->keywords,npc.keywords);
	copy_vec(this->longdesc,npc.longdesc);
}

NPC& NPC::operator =(const NPC& npc){
	this->armor =npc.armor;
	this->id    =npc.id;
	this->exp   =npc.exp;
	this->gold	=npc.gold;
	this->level	=npc.level;
	this->thac0	=npc.thac0;

	this->damage		=npc.damage;
	this->hit				=npc.hit;
	this->shortdesc	=npc.shortdesc;

	/*clean all vectors of the objects before copy*/
	clear_vec(description);
	clear_vec(keywords);
	clear_vec(longdesc);

	/*------copy vectors------*/
	copy_vec(this->description,npc.description);
	copy_vec(this->keywords,npc.keywords);
	copy_vec(this->longdesc,npc.longdesc);
	return *this;
}

//Getter and Setter for Armor
int NPC::getArmor() const {
	return armor;
}
void NPC::setArmor(int const armor) {
	this->armor = armor;
}

//Getter and Setter for	Damage
std::string NPC::getDamage() const {
	return damage;
}
void NPC::setDamage(const std::string& damage) {
	this->damage = damage;
}

//Getter and Setter for	Description
std::vector<std::string> NPC::getDesc() const {
	return description;
}
void NPC::setDesc(const std::vector<std::string>& description) {
	this->description = description;
}
void NPC::printDesc() const{
    for (auto &desc : description){
        std::cout << desc << std::endl;
    }
}

//Getter and Setter for Exp
int NPC::getExp() const {
	return exp;
}
void NPC::setExp(int const exp) {
	this->exp = exp;
}

//Getter and Setter for Gold
int NPC::getGold() const {
	return gold;
}
void NPC::setGold(int const gold) {
	this->gold = gold;
}

//Getter and Setter for Hit
std::string NPC::getHit() const {
	return hit;
}
void NPC::setHit(const std::string& hit) {
	this->hit = hit;
}

//Getter and Setter for Id
int NPC::getId() const {
	return id;
}
void NPC::setId(int const id) {
	this->id = id;
}

//Getter and Setter for Keywords
std::vector<std::string> NPC::getKeywords() const {
	return keywords;
}
void NPC::setKeywords(const std::vector<std::string>& keywords) {
	this->keywords = keywords;
}
void NPC::printKeywords() const{
    for (auto &word : keywords){
        std::cout << word << std::endl;
    }
}

//Getter and Setter for Level
int NPC::getLevel() const {
	return level;
}
void NPC::setLevel(int const level) {
	this->level = level;
}

//Getter and Setter for Longdesc
std::vector<std::string> NPC::getLongDesc() const {
	return longdesc;
}
void NPC::setLongDesc(const std::vector<std::string>& longdesc) {
	this->longdesc = longdesc;
}
void NPC::printLongDesc() const{
    for (auto &desc : longdesc){
        std::cout << desc << std::endl;
    }
}

//Getter and Setter for Shordesc
std::string NPC::getShortDesc() const {
	return shortdesc;
}
void NPC::setShortDesc(const std::string& shortdesc) {
	this->shortdesc = shortdesc;
}

//Getter and Setter for Thac0
int NPC::getThac0() const {
	return thac0;
}
void NPC::setThac0(int const thac0) {
	this->thac0 = thac0;
}

void NPC::copy_vec(std::vector<std::string>& output, const std::vector<std::string> Alist ){
  for(auto& i:Alist)
    output.push_back(i);
}

void NPC::clear_vec(std::vector<std::string> Alist){
  Alist.clear();
  Alist.shrink_to_fit(); // reduces the size of an already expanded vector back to 0 p.s. I THINK
}
