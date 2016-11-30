#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <assert.h>
#include <algorithm>
#include <unordered_map>

#include "Room.h"
#include "Door.h"
#include "Npc.h"
#include "Player.h"
#include "YamlSaveData.h"
#include "Model.h"
using namespace std;

void refactoringTest(){
    Player player(1234, "abc", "123");
    Npc npc(123);

    npc.npcCharacter.setArmor(1);
    npc.npcCharacter.setExp(2);
    npc.npcCharacter.setGold(3);
    npc.npcCharacter.setLevel(4);
    npc.npcCharacter.setMaxHealth(5);
    npc.npcCharacter.setMaxMana(6);
    npc.npcCharacter.setCurrentHealth(7);
    npc.npcCharacter.setCurrentMana(8);
    npc.npcCharacter.setThac0(9);
    npc.npcCharacter.setDamage("npc damage");
    npc.npcCharacter.setHit("npc Hit");
    vector<string> descV;
    descV.push_back("111111");
    descV.push_back("222222");
    npc.npcCharacter.setDescription(descV);
    npc.npcCharacter.setShortDesc("npc shortDesc");

    player.playerCharacter.setArmor(10000);
    player.playerCharacter.setExp(20000);
    player.playerCharacter.setGold(30000);
    player.playerCharacter.setLevel(40000);
    player.playerCharacter.setMaxHealth(50000);
    player.playerCharacter.setMaxMana(60000);
    player.playerCharacter.setCurrentHealth(70000);
    player.playerCharacter.setCurrentMana(80000);
    player.playerCharacter.setThac0(90000);
    player.playerCharacter.setDamage("player damage");
    player.playerCharacter.setHit("player Hit");
    vector<string> descV2;
    descV2.push_back("000000");
    descV2.push_back("999999");
    player.playerCharacter.setDescription(descV2);
    player.playerCharacter.setShortDesc("player shortDesc");

    cout << "===Before swapping==="<< endl;
    cout << "npc armor: " << npc.npcCharacter.getArmor() << endl;
    cout << "npc exp: " << npc.npcCharacter.getExp() << endl;
    cout << "npc gold: " << npc.npcCharacter.getGold() << endl;
    cout << "npc level: " << npc.npcCharacter.getLevel() << endl;
    cout << "npc max health: " << npc.npcCharacter.getMaxHealth() << endl;
    cout << "npc max mana: " << npc.npcCharacter.getMaxMana() << endl;
    cout << "npc current health: " << npc.npcCharacter.getCurrentHealth() << endl;
    cout << "npc current mana: " << npc.npcCharacter.getCurrentMana() << endl;
    cout << "npc thac0: " << npc.npcCharacter.getThac0() << endl;
    cout << "npc damage: " << npc.npcCharacter.getDamage() << endl;
    cout << "npc hit: " << npc.npcCharacter.getHit() << endl;
    cout << "npc description: " << npc.npcCharacter.getDescription() << endl;
    cout << "npc shortdesc: " << npc.npcCharacter.getShortDesc() << endl;

    cout << "Player armor: " << player.playerCharacter.getArmor() << endl;
    cout << "Player username: " << player.getUsername() << endl;
    cout << "Player exp: " << player.playerCharacter.getExp() << endl;
    cout << "Player gold: " << player.playerCharacter.getGold() << endl;
    cout << "Player level: " << player.playerCharacter.getLevel() << endl;
    cout << "Player max health: " << player.playerCharacter.getMaxHealth() << endl;
    cout << "Player max mana: " << player.playerCharacter.getMaxMana() << endl;
    cout << "Player current health: " << player.playerCharacter.getCurrentHealth() << endl;
    cout << "Player current mana: " << player.playerCharacter.getCurrentMana() << endl;
    cout << "Player thac0: " << player.playerCharacter.getThac0() << endl;
    cout << "Player damage: " << player.playerCharacter.getDamage() << endl;
    cout << "Player hit: " << player.playerCharacter.getHit() << endl;
    cout << "Player description: " << player.playerCharacter.getDescription() << endl;
    cout << "Player shortdesc: " << player.playerCharacter.getShortDesc() << endl;

    cout << endl << endl;

    swap(player.playerCharacter,npc.npcCharacter);

    cout << "===After swapping==="<< endl;
    cout << "npc armor: " << npc.npcCharacter.getArmor() << endl;
    cout << "npc exp: " << npc.npcCharacter.getExp() << endl;
    cout << "npc gold: " << npc.npcCharacter.getGold() << endl;
    cout << "npc level: " << npc.npcCharacter.getLevel() << endl;
    cout << "npc max health: " << npc.npcCharacter.getMaxHealth() << endl;
    cout << "npc max mana: " << npc.npcCharacter.getMaxMana() << endl;
    cout << "npc current health: " << npc.npcCharacter.getCurrentHealth() << endl;
    cout << "npc current mana: " << npc.npcCharacter.getCurrentMana() << endl;
    cout << "npc thac0: " << npc.npcCharacter.getThac0() << endl;
    cout << "npc damage: " << npc.npcCharacter.getDamage() << endl;
    cout << "npc hit: " << npc.npcCharacter.getHit() << endl;
    cout << "npc description: " << npc.npcCharacter.getDescription() << endl;
    cout << "npc shortdesc: " << npc.npcCharacter.getShortDesc() << endl;
    
    cout << "Player armor: " << player.playerCharacter.getArmor() << endl;
    cout << "Player username: " << player.getUsername() << endl;
    cout << "Player exp: " << player.playerCharacter.getExp() << endl;
    cout << "Player gold: " << player.playerCharacter.getGold() << endl;
    cout << "Player level: " << player.playerCharacter.getLevel() << endl;
    cout << "Player max health: " << player.playerCharacter.getMaxHealth() << endl;
    cout << "Player max mana: " << player.playerCharacter.getMaxMana() << endl;
    cout << "Player current health: " << player.playerCharacter.getCurrentHealth() << endl;
    cout << "Player current mana: " << player.playerCharacter.getCurrentMana() << endl;
    cout << "Player thac0: " << player.playerCharacter.getThac0() << endl;
    cout << "Player damage: " << player.playerCharacter.getDamage() << endl;
    cout << "Player hit: " << player.playerCharacter.getHit() << endl;
    cout << "Player description: " << player.playerCharacter.getDescription() << endl;
    cout << "Player shortdesc: " << player.playerCharacter.getShortDesc() << endl;

    cout << endl << endl;


}

void yamlTest(){
    std::vector<std::string> filepaths = {"../data/shire.yml", "../data/Midgaard.yml", "../data/users.yml",  "../data/spells.yml"};
    Model model1(filepaths);
    //model.yamlParseAndBuildExistingPlayers("../data/users.yml");
    //YamlSaveData ysd;
    
    //ysd.saveUserData(model.getPlayerMap());
}

int main() {
    //refactoringTest();
    yamlTest();
    return 0;
}