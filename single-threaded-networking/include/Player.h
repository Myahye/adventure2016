#ifndef PLAYER_H
#define PLAYER_H

#include "Character.h"

class Player {
    std::string username;
    std::string password;
    std::string status = "Offline";
    bool isConfuse = false;
    int isConfuseTimer=0;

public:
    // Constructor
    Player ();
    Player (int const id, std::string const username, std::string const password);

    Character playerCharacter;

    //username
    std::string getUsername() const;
    void setUsername(std::string& username);

    //password
    std::string getPassword() const;
    void setPassword(std::string& password);

    void setCharacter(const Character& character);
    std::string getStatus() const;
    void setStatus(std::string s);

    void attack(const std::string& name);


    bool getIsConfuse();
    void setIsConfuse(const bool& isConfuse);

};

#endif /* PLAYER_H */
