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
    Player (int, string);
    
    //Armor
    int getArmor() const;
    void setArmor(int);
    
    //Damage
    string getDamage() const;
    void setDamage(string);
    
    //Description
    vector<string> getDesc() const;
    void setDesc(vector<string>);
    
    //Experience
    int getExp() const;
    void setExp(int);
    
    //Gold
    int getGold() const;
    void setGold(int);
    
    //Hit
    string getHit() const;
    void setHit(string);
    
    //Player ID
    int getId() const;
    void setId(int);
    
    //Keywords
    vector<string> getKeywords() const;
    void setKeywords(vector<string>);
    
    //Level
    int getLevel() const;
    void setLevel(int);
    
    //Long Description
    vector<string> getLongDesc() const;
    void setLongDesc(vector<string>);
    
    //Short Description
    string getShortDesc() const;
    void setShortDesc(string);
    
    //Thac0
    int getThac0() const;
    void setThac0(int);
};

#endif /* Player_h */
