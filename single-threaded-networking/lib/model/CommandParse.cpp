#include "CommandParse.h"


using namespace networking;

CommandParse::CommandParse() {}

std::unordered_map<std::string, std::string> commands {{"Create","create "},{"Look","look "},{"Go","go "},{"Read","read "},{"Attack","attack "},{"Say","say "},{"ListCommands","ls "},};



std::deque<Message>
CommandParse::parseCommands(const std::deque<Message>& clientMessageQueue, std::vector<Connection>& clients) {



    std::deque<Message> outgoing;

    for (auto& message : clientMessageQueue) {

      std::string messageText = message.text;

      if (boost::istarts_with(messageText,commands["Create"])) {
        std::string messageText = message.connection.playerIdConnectedToClientConnection + ">asdfasdfasdf Kieran " + /*handleCreateCommand(message)*/ + "\n";
        outgoing.push_back(Message{message.connection, messageText});
      }
      else if (boost::istarts_with(messageText,commands["Look"])) {
        std::string messageText = message.connection.playerIdConnectedToClientConnection + "> " + /*handleCreateCommand(message)*/ + "\n";
        outgoing.push_back(Message{message.connection, messageText});
      }
      else if (boost::istarts_with(messageText,commands["Go"])) {
        std::string messageText = message.connection.playerIdConnectedToClientConnection + "> " + /*handleCreateCommand(message)*/ + "\n";
        outgoing.push_back(Message{message.connection, messageText});
      }
      else if (boost::istarts_with(messageText,commands["Read"])) {
        std::string messageText = message.connection.playerIdConnectedToClientConnection + "> " + /*handleCreateCommand(message)*/ + "\n";
        outgoing.push_back(Message{message.connection, messageText});
      }
      else if (boost::istarts_with(messageText,commands["Attack"])) {
        std::string messageText = message.connection.playerIdConnectedToClientConnection + "> " + /*handleCreateCommand(message)*/ + "\n";
        outgoing.push_back(Message{message.connection, messageText});
      }
      else if (boost::istarts_with(messageText,commands["Say"])) {
        std::for_each(clients.begin(), clients.end(), [&message,&outgoing] (Connection& c)
          { if(c.currentState == ConnectionState::AUTHORIZED) { outgoing.push_back(Message{c,std::string(message.connection.playerIdConnectedToClientConnection + "> " + message.text.substr(4) + "\n")}); } });
      }
      else if (boost::iequals(messageText, commands["ListCommands"])) {
        std::string messageText = message.connection.playerIdConnectedToClientConnection + "> " + /*handleCreateCommand(message)*/ + "\n";
        outgoing.push_back(Message{message.connection, messageText});
      }
      else {
        //Will output all other message types sent for now for testing purposes
        std::for_each(clients.begin(), clients.end(), [&message,&outgoing] (Connection& c)
          { if(c.currentState == ConnectionState::AUTHORIZED) { outgoing.push_back(Message{c,std::string(message.connection.playerIdConnectedToClientConnection + "> " + message.text + "\n")}); } });
      }
    }
    return outgoing;
  }
