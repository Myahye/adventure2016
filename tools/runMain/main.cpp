//
//  main.cpp
//  Player
//
//  Created by JUN DA LI on 2016/10/12.
//  Copyright © 2016年 JUN DA LI. All rights reserved.
//

#include "Player.h"

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    int pid = 123;
    string Damage = "5d6";
    string Hit ="6d7";
    string shortdesc = "this is test main";
    string shortdesc2 = "reset info";
    string str[]={"hello","world","this","find","gank","pink","that","when","how","cpp"};
    vector<string> desc(str,str+10);
    string str1[]={"hello","find","gank","pink","cpp"};
    vector<string> keywords(str1,str1+5);
    string str2[]={"hello, ","lonely ","cpp"};
    vector<string> longdesc(str2,str2+3);
    
//    intial a Player naming temp 1
    Player temp1 = Player(pid, shortdesc);
    cout << "Player temp1" << endl;
    cout << "Player ID: " << temp1.getId() << endl;
    cout << "shortdesc: " << temp1.getShortDesc() << endl;

    
//    set and get Armor
    temp1.setArmor(111);
    cout << "Aromor: " << temp1.getArmor() << endl;
    
//    set and get Damage
    temp1.setDamage(Damage);
    cout << "Damage: " << temp1.getDamage() << endl;
    
//    set and get Desc
    temp1.setDesc(desc);
//    cout << "description: " << temp1.getDesc() << endl;
    
//    set and get Exp
    temp1.setExp(222);
    cout << "Exp: " << temp1.getExp() << endl;
    
//    set and get Gold
    temp1.setGold(333);
    cout << "Gold: " << temp1.getGold() << endl;
    
//    set and get hit
    temp1.setHit(Hit);
    cout << "Hit: " << temp1.getHit() << endl;
    
//    set and get Player ID
    temp1.setId(456);
    cout << "Player ID: " << temp1.getId() << endl;

//    set and get keywords
    temp1.setKeywords(keywords);
//    cout << "keywords: " << temp1.getKeywords() << endl;
    
//    set and get Player ID
    temp1.setLevel(5);
    cout << "Level: " << temp1.getLevel() << endl;
    
//    set and get LongDesc
    temp1.setLongDesc(longdesc);
//    cout << "long description: " << temp1.getLongDesc() << endl;
    
//    set and get shortdesc
    temp1.setShortDesc(shortdesc2);
    cout << "shortdesc: " << temp1.getShortDesc() << endl;
    
//    set and get Thac0
    temp1.setThac0(5);
    cout << "Thac0: " << temp1.getThac0() << endl;
    
    return 0;
}
