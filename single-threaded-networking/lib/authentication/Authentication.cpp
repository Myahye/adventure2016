

#include "Authentication.h"
#include <boost/algorithm/string.hpp>
#include <boost/regex.hpp>

#include <iostream>

namespace Authentication {

  bool findExistingUsername(const std::string& username, std::unordered_map <std::string,Player>& players) {
    return (players.find(username) != players.end());
  }

  bool currentlyLoggedIn(const std::string& username, std::vector <Connection>& clients) {
    auto client = std::find_if(clients.begin(), clients.end(), [username] (Connection c) { return c.playerIdConnectedToClientConnection == username; });
    if(client != clients.end()) {
      return client->currentState == ConnectionState::AUTHORIZED;
    }
  }

  std::string authorizeClient(Message& message, Server& server, std::vector <Connection>& clients, std::unordered_map <std::string,Player>& players) {
    if (message.text == "1" && message.connection.currentState == ConnectionState::UNAUTHORIZED) {

      server.setClientCurrentState(message.connection, ConnectionState::REGISTERING);

      return "Please enter a new username and password ex. 'Bob Bobpassword': \n";
    } else if (message.text == "2" && message.connection.currentState == ConnectionState::UNAUTHORIZED) {

      server.setClientCurrentState(message.connection, ConnectionState::LOGIN);

      return "Please enter your username and password ex. 'Bob Bobpassword': \n";
    } else if (message.connection.currentState == ConnectionState::REGISTERING) {
      return handleRegistration(message, server, clients, players);
    } else if (message.connection.currentState == ConnectionState::LOGIN) {
      return handleLogin(message, server, clients, players);
    } else {
      return "Sorry that is not a valid command, please enter '1' to register a new character, enter '2' to login to an existing character, or enter 'quit' to quit\n";
    }
  }

  std::string handleLogin(Message& message, Server& server, std::vector <Connection>& clients, std::unordered_map <std::string,Player>& players) {
    std::vector < std::string > playerCredentials;
    boost::trim_if(message.text, boost::is_any_of("\t "));
    boost::split(playerCredentials, message.text, boost::is_any_of("\t "), boost::token_compress_on);

    if (playerCredentials.size() != 2) {
      return "Please enter your username and password in a 'username SPACE password' format, no extra spaces are allowed in your username or password: \n";
    } else if (playerCredentials[0].size() > 10) {
      return "Please enter a username that is less than 10 characters long: \n";
    } else if (playerCredentials[1].size() > 10) {
      return "Please enter a password that is less than 10 characters long: \n";
    } else if (playerCredentials[0].find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ01234567890_") != std::string::npos) {
      return "Sorry that is an invalid username. Please only enter alphanumeric characters: \n";
    } else if (playerCredentials[1].find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ01234567890_") != std::string::npos) {
      return "Sorry that is an invalid password. Please only enter alphanumeric characters: \n";
    } else if (currentlyLoggedIn(playerCredentials[0], clients)) {
      return "Player is currently logged in. Please enter a different username:\n";
    } else if (findExistingUsername(playerCredentials[0], players)) {

      if (players[playerCredentials[0]].password != playerCredentials[1]) {
        return "Sorry wrong password, please try again: \n";
      }

      server.setPlayerConnectedToClient(message.connection, playerCredentials[0]);
      server.setClientCurrentState(message.connection, ConnectionState::AUTHORIZED);

      auto client = std::find_if(clients.begin(), clients.end(), [message](Connection c) { return c == message.connection; });
      client-> playerIdConnectedToClientConnection = playerCredentials[0];
      client-> currentState = ConnectionState::AUTHORIZED;

      for (auto & player: players) {
        std::cout << "Player: " << player.first << " username: " << player.second.username << " password: " << player.second.password << "\n";
      }

      return "The adventurer " + playerCredentials[0] + " wakes up in a dimly lit room.\n";
    } else {
      return "Sorry that player does not exist, please enter an existing username: \n";
    }
  }

  std::string handleRegistration(Message& message, Server& server, std::vector <Connection>& clients, std::unordered_map <std::string,Player>& players) {
    std::vector < std::string > playerCredentials;
    boost::trim_if(message.text, boost::is_any_of("\t "));
    boost::split(playerCredentials, message.text, boost::is_any_of("\t "), boost::token_compress_on);

    if (playerCredentials.size() != 2) {
      return "Please enter your username and password in a 'username SPACE password' format, no extra spaces are allowed in your username or password: \n";
    } else if (playerCredentials[0].size() > 10) {
      return "Please enter a username that is less than 10 characters long: \n";
    } else if (playerCredentials[1].size() > 10) {
      return "Please enter a password that is less than 10 characters long: \n";
    } else if (playerCredentials[0].find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ01234567890_") != std::string::npos) {
      return "Sorry that is an invalid username. Please only enter alphanumeric characters: \n";
    } else if (playerCredentials[1].find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ01234567890_") != std::string::npos) {
      return "Sorry that is an invalid password. Please only enter alphanumeric characters: \n";
    } else if (findExistingUsername(playerCredentials[0], players)) {
      return "Sorry that username is in use. Please enter a different username: \n";
    } else {
      players[playerCredentials[0]] = Player {
        playerCredentials[0], playerCredentials[1], 1, ""
      };

      server.setPlayerConnectedToClient(message.connection, playerCredentials[0]);
      server.setClientCurrentState(message.connection, ConnectionState::AUTHORIZED);

      auto client = std::find_if(clients.begin(), clients.end(), [message](Connection c) {return c == message.connection; });
      client-> playerIdConnectedToClientConnection = playerCredentials[0];
      client-> currentState = ConnectionState::AUTHORIZED;

      for (auto & player: players) {
        std::cout << "Player: " << player.first << " username: " << player.second.username << " password: " << player.second.password << "\n";
      }

      return "The adventurer " + playerCredentials[0] + " wakes up in a dimly lit room.\n";
    }
  }
}