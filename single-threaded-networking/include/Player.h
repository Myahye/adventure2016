#ifndef PLAYER_H
#define PLAYER_H

#include "CharacterType.h"

class Player : public CharacterType{

    std::string username;
    std::string password;

public:
    const int DEFAULT_PLAYER_LEVEL = 1;
    const int DEFAULT_PLAYER_HEALTH = 100;
    const int DEFAULT_PLAYER_MANA = 100;
    // Constructor
    Player ();
    Player (std::string const username, std::string const password);

    ~Player();

    //username
    std::string getUsername() const;
    void setUsername(std::string& username);

    //password
    std::string getPassword() const;
    void setPassword(std::string& password);
/*
    void addObjectToInventory(const Object& object, unsigned int limit);
    bool removeObjectFromInventory(const std::string& objectName);
    bool equipObject(const Object& object, int slot);
    bool unEquipObject(int slot);
    std::unordered_map<int,std::vector<Object>> getInventory() const;
    std::unordered_map<int,Object> getEquipment() const;
    std::string getInventoryDesc() const;
    std::string getEquipmentDesc() const;*/

   
};

#endif /* PLAYER_H */
