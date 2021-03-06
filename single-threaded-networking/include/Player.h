#ifndef PLAYER_H
#define PLAYER_H

#include "Character.h"

class Player {
private:

public:
    Character playerCharacter;
    std::string username;
    std::string password;
    std::string status = "Offline";
    bool isConfuse = false;
    int isConfuseTimer=0;

    Character* swapTarget;

    // Constructor
    Player ();
    Player (int const id, std::string const username, std::string const password);

    //username
    std::string getUsername() const;
    void setUsername(std::string& username);

    //password
    std::string getPassword() const;
    void setPassword(std::string& password);

    void setCharacter(const Character& character);

    void attack(const std::string& name);

    bool getIsConfuse();
    void setIsConfuse(const bool& isConfuse);

    void setSwapTarget(Character& swapTarget);
};

#endif /* PLAYER_H */
