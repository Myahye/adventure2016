#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include <string>

class Player {
private:
    int armor;
    int exp;
    int gold;
    int pid;
    int level;
    int thac0;
    
    std::string damage;
    std::string hit;
    std::string shortdesc;
    
    std::vector<std::string> description;
    std::vector<std::string> keywords;
    std::vector<std::string> longdesc;
public:
    // Constructor
    Player (int pid, std::string shortdesc);
    
    //Armor
    int getArmor() const;
    void setArmor(int armor);
    
    //Damage
    std::string getDamage() const;
    void setDamage(std::string& damage);
    
    //Description
    std::vector<std::string> getDesc() const;
    void setDesc(std::vector<std::string>& description);
    
    //Experience
    int getExp() const;
    void setExp(int exp);
    
    //Gold
    int getGold() const;
    void setGold(int gold);
    
    //Hit
    std::string getHit() const;
    void setHit(std::string& hit);
    
    //Player ID
    int getId() const;
    void setId(int pid);
    
    //Keywords
    std::vector<std::string> getKeywords() const;
    void setKeywords(std::vector<std::string>& keywords);
    
    //Levels
    int getLevel() const;
    void setLevel(int level);
    
    //Long Description
    std::vector<std::string> getLongDesc() const;
    void setLongDesc(std::vector<std::string>& longdesc);
    
    //Short Description
    std::string getShortDesc() const;
    void setShortDesc(std::string& shortdesc);
    
    //Thac0
    int getThac0() const;
    void setThac0(int);
};

#endif /* PLAYER_H */
