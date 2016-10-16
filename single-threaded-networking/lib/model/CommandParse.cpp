#include "CommandParse.h"

#include <iostream>

using namespace networking;

CommandParse::CommandParse() {}

std::unordered_map<std::string, std::string> commands {{"Create","create "},{"Look","look "},{"Go","go "},{"Read","read "},{"Attack","attack "},{"Say","say "},{"ListCommands","ls "},};



std::deque<Message>
CommandParse::parseCommands(const std::deque<Message>& clientMessageQueue, std::vector<Connection>& clients) {

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
        std::string messageText = std::to_string(message.connection.playerIDConnectedToClientConnection) + "> " + /*handleCreateCommand(message)*/ + "\n";
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

  /*********************Modified by Lawrence***********************************************************************/

int CommandParse::createPlayer(const std::string& username, const std::string& password) {
    playersCreated[assignedIDs] = Player {
        username, password, 1, "", assignedIDs
    };
    assignedIDs++;
    for (auto & player: playersCreated) {
        std::cout << "Player: " << player.second.playerID << " username: " << player.second.username << " password: " << player.second.password << "\n";
    }
    return assignedIDs - 1;
  }

  std::vector<std::tuple<int,std::string,std::string>> CommandParse::getPlayerCredentialsVector() const {

    std::vector<std::tuple<int,std::string,std::string>> vector;

    for(auto player: playersCreated) {
      vector.push_back(std::make_tuple(player.first,player.second.username,player.second.password));
    }

    return vector;
  }

  /*********************Modified by Lawrence***********************************************************************/