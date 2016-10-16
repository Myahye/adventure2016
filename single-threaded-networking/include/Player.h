#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <vector>
#include <string>

class Player {
private:
    int armor;
    int exp;
    int gold;
    int level;
    int thac0;
    int pid;

    std::string damage;
    std::string hit;
    std::string username;
    std::string password;

    std::vector<std::string> description;
    std::vector<std::string> keywords;
    std::vector<std::string> longdesc;
public:


    // Constructor
    Player (int const pid, std::string const username, std::string const password);
    //username
    std::string getUsername() const;
    void setUsername(const std::string& username);

    //password
    std::string getPassword() const;
    void setPassword(const std::string& password);

    //Armor
    int getArmor() const;
    void setArmor(int const armor);

    //Damage
    std::string getDamage() const;
    void setDamage(const std::string& damage);

    //Description
    std::vector<std::string> getDesc() const;
    void setDesc(const std::vector<std::string>& description);
    void printDesc() const;

    //Experience
    int getExp() const;
    void setExp(int const exp);

    //Gold
    int getGold() const;
    void setGold(int const gold);

    //Hit
    std::string getHit() const;
    void setHit(const std::string& hit);

    //Player ID
    int getId() const;
    void setId(int const pid);

    //Keywords
    std::vector<std::string> getKeywords() const;
    void setKeywords(const std::vector<std::string>& keywords);
    void printKeywords() const;

    //Levels
    int getLevel() const;
    void setLevel(int const level);

    //Long Description
    std::vector<std::string> getLongDesc() const;
    void setLongDesc(const std::vector<std::string>& longdesc);
    void printLongDesc() const;

    //Thac0
    int getThac0() const;
    void setThac0(int const thac0);
};

#endif /* PLAYER_H */
