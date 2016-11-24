#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <vector>
#include <string>
#include "CombatManager.h"

class Player {
private:
    int armor = 0;
    int exp = 0;
    int gold = 0;
    int level = 1;
    int thac0;
    int pid = 0;
    int health=100;
    int mana=100;

    Player& victim;
    CombatManager& view;


    std::string damage;
    std::string hit;
    std::string username;
    std::string password;

    std::vector<std::string> description;
    std::vector<std::string> keywords;
    std::vector<std::string> longdesc;

    void setNewHealth(int const level);
    void setNewMana(int const level);
    void setNewStats();
    int nextLvl(int const XP,int const level) const;

public:

    // Constructor
    Player (int const pid, std::string const username, std::string const password, CombatManager& view);
    Player ();

    void setFighting(Player& victim);
    void stopFighting(Player& victim);
    Player& getVictim();

    void applyDamage(const int damage);

    //username
    std::string getUsername() const;
    void setUsername(std::string& username);

    int getHealth() const;
    void setHealth(int const health);

    int getMana() const;
    void setMana(int const mana);

    //password
    std::string getPassword() const;
    void setPassword(std::string& password);

    //Armor
    int getArmor() const;
    void setArmor(int const armor);

    //Damage
    std::string getDamage() const;
    void setDamage(std::string& damage);

    //Description
    std::vector<std::string> getDesc() const;
    void setDesc(std::vector<std::string>& description);

    //Experience
    int getExp() const;
    void setExp(int const XP);

    //Gold
    int getGold() const;
    void setGold(int const gold);

    //Hit
    std::string getHit() const;
    void setHit(std::string& hit);

    //Player ID
    int getId() const;
    void setId(int const pid);

    //Keywords
    std::vector<std::string> getKeywords() const;
    void setKeywords(std::vector<std::string>& keywords);

    //Levels
    int getLevel() const;
    void setLevel(int const level);

    //Long Description
    std::vector<std::string> getLongDesc() const;
    void setLongDesc(std::vector<std::string>& longdesc);

    //Thac0
    int getThac0() const;
    void setThac0(int const thac0);
};

#endif /* PLAYER_H */
