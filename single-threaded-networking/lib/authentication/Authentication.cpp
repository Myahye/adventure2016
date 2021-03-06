#include "Authentication.h"
#include <boost/algorithm/string.hpp>
#include <boost/regex.hpp>

namespace Authentication {

  int
  findExistingPlayer(const std::string& username, const std::vector<std::tuple<int,std::string,std::string>>& players) {
    auto player = std::find_if(players.begin(), players.end(), [username] (auto credentials) { return std::get<1>(credentials) == username; });
    if(player != players.end()) {
      return std::get<0>(*player);
    } else {
      return 0;
    }
  }

  bool
  currentlyLoggedIn(int playerId, const std::vector<Connection>& clients) {
    auto player = std::find_if(clients.begin(), clients.end(), [playerId] (Connection c) { return c.playerId == playerId; });
    if (player != clients.end()) {
      return player->currentState == ConnectionState::AUTHORIZED;
    } else {
      return false;
	  }
  }

  bool
  correctPassword(int playerId, const std::string& password, const std::vector<std::tuple<int,std::string,std::string>>& players) {
  	auto player = std::find_if(players.begin(), players.end(), [playerId] (auto credentials) { return std::get<0>(credentials) == playerId; });
  	return std::get<2>(*player) == password;
  }

  std::string
  authorizeClient(Message& message, Server& server, std::vector <Connection>& clients, ModelInterface& modelInterface) {

  	std::vector<std::tuple<int,std::string,std::string>> players = modelInterface.getPlayerCredentialsVector();

    if (message.text == "1" && message.connection.currentState == ConnectionState::UNAUTHORIZED) {

      server.setClientCurrentState(message.connection, ConnectionState::REGISTERING);

      return "Please enter a new username and password ex. 'Bob Bobpassword': \n";
    } else if (message.text == "2" && message.connection.currentState == ConnectionState::UNAUTHORIZED) {

      server.setClientCurrentState(message.connection, ConnectionState::LOGIN);

      return "Please enter your username and password ex. 'Bob Bobpassword': \n";
    } else if (message.connection.currentState == ConnectionState::REGISTERING) {
      return handleRegistration(message, server, clients, players, modelInterface);
    } else if (message.connection.currentState == ConnectionState::LOGIN) {
      return handleLogin(message, server, clients, players, modelInterface);
    } else {
      return "Sorry that is not a valid command, please enter '1' to register a new character, enter '2' to login to an existing character, or enter 'quit' to quit\n";
    }
  }

  std::string
  handleLogin(Message& message, Server& server, std::vector <Connection>& clients, const std::vector<std::tuple<int,std::string,std::string>>& players, ModelInterface& modelInterface) {
    std::vector <std::string> playerCredentials;
    boost::trim_if(message.text, boost::is_any_of("\t "));
    boost::split(playerCredentials, message.text, boost::is_any_of("\t "), boost::token_compress_on);

    int playerId = 0;

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
    } else if ((playerId = findExistingPlayer(playerCredentials[0], players)) != 0) {

      if (currentlyLoggedIn(playerId, clients)) {
      	return "Player is currently logged in. Please enter a different username:\n";
      } else if (!correctPassword(playerId, playerCredentials[1], players)) {
        return "Sorry wrong password, please try again: \n";
      }
     
      server.setPlayerId(message.connection, playerId);
      server.setClientCurrentState(message.connection, ConnectionState::AUTHORIZED);

      auto client = std::find_if(clients.begin(), clients.end(), [message](Connection c) { return c == message.connection; });
      client-> playerId = playerId;
      client-> currentState = ConnectionState::AUTHORIZED;
      
      modelInterface.playerConnect(*client);

      return "Welcome back " + playerCredentials[0] + "," + modelInterface.getCurrentRoomDescription(playerId);
    } else {
      return "Sorry that player does not exist, please enter an existing username: \n";
    }
  }

  std::string
  handleRegistration(Message& message, Server& server, std::vector <Connection>& clients, const std::vector<std::tuple<int,std::string,std::string>>& players, ModelInterface& modelInterface) {
    std::vector <std::string> playerCredentials;
    boost::trim_if(message.text, boost::is_any_of("\t "));
    boost::split(playerCredentials, message.text, boost::is_any_of("\t "), boost::token_compress_on);

    int playerId = 0;

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
    } else if ((playerId = findExistingPlayer(playerCredentials[0], players)) != 0) {
      return "Sorry that username is in use. Please enter a different username: \n";
    } else {
      playerId = modelInterface.createPlayer(playerCredentials[0],playerCredentials[1]);

      server.setPlayerId(message.connection,playerId);
      server.setClientCurrentState(message.connection, ConnectionState::AUTHORIZED);

      auto client = std::find_if(clients.begin(), clients.end(), [message](Connection c) {return c == message.connection; });
      client-> playerId = playerId;
      client-> currentState = ConnectionState::AUTHORIZED;
      
      modelInterface.playerConnect(*client);
      
      return "Your name is " + playerCredentials[0] + "," + modelInterface.getCurrentRoomDescription(playerId);
    }
  }
}
