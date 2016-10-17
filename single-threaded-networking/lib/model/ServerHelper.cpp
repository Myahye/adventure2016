#include "ServerHelper.h"
#include <iostream>

using namespace networking;

ServerHelper::ServerHelper() {}

std::unordered_map<std::string, std::string> commands {{"Create","create "},{"Look","look "},{"Walk","walk "},{"Read","read "},{"Go","go "},{"Attack","attack "},{"Say","say "},{"ListCommands","ls "},};

std::deque<Message>
ServerHelper::parseCommands(const std::deque<Message>& clientMessageQueue, std::vector<Connection>& clients) {


      std::deque<Message> outgoing;

      for (auto& message : clientMessageQueue) {

        std::string messageText = message.text;

        if (boost::istarts_with(messageText,commands["Create"])) {
          std::string messageText = std::to_string(message.connection.playerIDConnectedToClientConnection) + ">asdfasdfasdf Kieran " + /*handleCreateCommand(message)*/ + "\n";
          outgoing.push_back(Message{message.connection, messageText});
        }
        else if (boost::istarts_with(messageText,commands["Look"])) {
          std::string messageText = std::to_string(message.connection.playerIDConnectedToClientConnection) + "> " + /*handleCreateCommand(message)*/ + "\n";
          outgoing.push_back(Message{message.connection, messageText});
        }
        else if (boost::istarts_with(messageText,commands["Go"])) {
          std::string messageText = std::to_string(message.connection.playerIDConnectedToClientConnection) + "> " + this->model.movePlayer(message.connection.playerIDConnectedToClientConnection, message.text.substr(3)) + "\n";
          outgoing.push_back(Message{message.connection, messageText});
        }
        else if (boost::istarts_with(messageText,commands["Read"])) {
          std::string messageText = std::to_string(message.connection.playerIDConnectedToClientConnection) + "> " + /*handleCreateCommand(message)*/ + "\n";
          outgoing.push_back(Message{message.connection, messageText});
        }
        else if (boost::istarts_with(messageText,commands["Attack"])) {
          std::string messageText = std::to_string(message.connection.playerIDConnectedToClientConnection) + "> " + /*handleCreateCommand(message)*/ + "\n";
          outgoing.push_back(Message{message.connection, messageText});
        }
        else if (boost::istarts_with(messageText,commands["Say"])) {
          std::for_each(clients.begin(), clients.end(), [&message,&outgoing] (Connection& c)
            { if(c.currentState == ConnectionState::AUTHORIZED) { outgoing.push_back(Message{c,std::string(std::to_string(message.connection.playerIDConnectedToClientConnection) + "> " + message.text.substr(4) + "\n")}); } });
        }
        else if (boost::iequals(messageText, commands["ListCommands"])) {
          std::string messageText = std::to_string(message.connection.playerIDConnectedToClientConnection) + "> " + /*handleCreateCommand(message)*/ + "\n";
          outgoing.push_back(Message{message.connection, messageText});
        }
        else {
          //Will output all other message types sent for now for testing purposes
          std::for_each(clients.begin(), clients.end(), [&message,&outgoing] (Connection& c)
            { if(c.currentState == ConnectionState::AUTHORIZED) { outgoing.push_back(Message{c,std::string(std::to_string(message.connection.playerIDConnectedToClientConnection) + "> " + message.text + "\n")}); } });
        }
      }
      return outgoing;
    }

  int ServerHelper::createPlayer(const std::string& username, const std::string& password) {

      return(this->model.createPlayer(username, password));

      // playersCreated[assignedIDs] = Player {
      //     username, password, 1, "", assignedIDs
      // };
      // assignedIDs++;
      // for (auto & player: playersCreated) {
      //     std::cout << "Player: " << player.second.playerID << " username: " << player.second.username << " password: " << player.second.password << "\n";
      // }
      // return assignedIDs - 1;
    }

    std::vector<std::tuple<int,std::string,std::string>> ServerHelper::getPlayerCredentialsVector() const {

      return(this->model.getPlayerCredentialsVector());

      // std::vector<std::tuple<int,std::string,std::string>> vector;
      //
      // for(auto player: playersCreated) {
      //   vector.push_back(std::make_tuple(player.first,player.second.username,player.second.password));
      // }
      //
      // return vector;
    }