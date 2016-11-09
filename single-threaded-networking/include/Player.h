#ifndef PLAYER_H
#define PLAYER_H

#include "Character.h"

class Player {
    std::string username;
    std::string password;
public:
    Character playerCharacter;

    // Constructor
    Player ();
    Player (int const id, std::string const username, std::string const password);

    //username
    std::string getUsername() const;
    void setUsername(std::string& username);

    //password
    std::string getPassword() const;
    void setPassword(std::string& password);

};

#endif /* PLAYER_H */
