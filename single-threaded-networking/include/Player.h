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

    //username
    std::string getUsername() const;
    void setUsername(std::string& username);

    //password
    std::string getPassword() const;
    void setPassword(std::string& password);

    int newHealth(const int lvl);
    int newMana(const int lvl);

    //void setNewStats();
};

#endif /* PLAYER_H */
