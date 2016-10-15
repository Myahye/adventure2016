//
//  Player.h
//  Player
//
//  Created by JUN DA LI on 2016/10/12.
//  Copyright © 2016年 JUN DA LI. All rights reserved.
//

#ifndef Player_h
#define Player_h

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Player {
private:
    int armor, exp, gold, pid, level, thac0;
    string damage, hit, shortdesc;
    vector<string> description, keywords, longdesc;
    
public:
    // create Player
    Player (int new_pid, string new_shortdesc);
    
    //Armor
    int getArmor() const;
    void setArmor(int new_armor);
    
    //Damage
    string getDamage() const;
    void setDamage(string &new_damage);
    
    //Description
    vector<string> getDesc() const;
    void setDesc(vector<string> &new_description);
    
    //Experience
    int getExp() const;
    void setExp(int new_exp);
    
    //Gold
    int getGold() const;
    void setGold(int new_gold);
    
    //Hit
    string getHit() const;
    void setHit(string &new_hit);
    
    //Player ID
    int getId() const;
    void setId(int new_pid);
    
    //Keywords
    vector<string> getKeywords() const;
    void setKeywords(vector<string> &new_keywords);
    
    //Level
    int getLevel() const;
    void setLevel(int new_level);
    
    //Long Description
    vector<string> getLongDesc() const;
    void setLongDesc(vector<string> &new_longdesc);
    
    //Short Description
    string getShortDesc() const;
    void setShortDesc(string &new_shortdesc);
    
    //Thac0
    int getThac0() const;
    void setThac0(int);
};

#endif /* Player_h */
