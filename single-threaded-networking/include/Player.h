#ifndef PLAYER_H
#define PLAYER_H

#include "Character.h"

class Player {
    std::string username;
    std::string password;
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
};

#endif /* PLAYER_H */