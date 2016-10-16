#include "ServerHelper.h"


using namespace networking;

ServerHelper::ServerHelper() {}

std::unordered_map<std::string, std::string> commands {{"Create","create "},{"Look","look "},{"Walk","walk "},{"Read","read "},{"Attack","attack "},{"Say","say "},{"ListCommands","ls "},};

std::deque<Message>
ServerHelper::parseCommands(const std::deque<Message>& clientMessageQueue, std::vector<Connection>& clients) {

    std::deque<Message> outgoing;

    for (auto& message : clientMessageQueue) {

      std::string messageText = message.text;

      if (boost::istarts_with(message.text,commands["Create"])) {
        std::string messageText = std::to_string(message.connection.id) + ">asdfasdfasdf Kieran " + /*handleCreateCommand(message)*/ + "\n";
        outgoing.push_back({message.connection, messageText});
      }
      else if (boost::istarts_with(message.text,commands["Look"])) {
        std::string messageText = std::to_string(message.connection.id) + "> " + /*handleCreateCommand(message)*/ + "\n";
        outgoing.push_back({message.connection, messageText});
      }
      else if (boost::istarts_with(message.text,commands["Walk"])) {
        std::string messageText = std::to_string(message.connection.id) + "> " + /*handleCreateCommand(message)*/ + "\n";
        outgoing.push_back({message.connection, messageText});
      }
      else if (boost::istarts_with(message.text,commands["Read"])) {
        std::string messageText = std::to_string(message.connection.id) + "> " + /*handleCreateCommand(message)*/ + "\n";
        outgoing.push_back({message.connection, messageText});
      }
      else if (boost::istarts_with(message.text,commands["Attack"])) {
        std::string messageText = std::to_string(message.connection.id) + "> " + /*handleCreateCommand(message)*/ + "\n";
        outgoing.push_back({message.connection, messageText});
      }
      else if (boost::istarts_with(message.text,commands["Say"])) {
        std::for_each(clients.begin(), clients.end(), [&message,&outgoing] (Connection& c)
          { outgoing.push_back({c,std::string(std::to_string(message.connection.id) + "> " + message.text.substr(4) + "\n")}); });
      }
      else if (boost::iequals(message.text, commands["ListCommands"])) {
        std::string messageText = std::to_string(message.connection.id) + "> " + /*handleCreateCommand(message)*/ + "\n";
        outgoing.push_back({message.connection, messageText});
      }
      else {
        //Will output all other message types sent for now for testing purposes
        std::for_each(clients.begin(), clients.end(), [&message,&outgoing] (Connection& c)
          { outgoing.push_back({c,std::string(std::to_string(message.connection.id) + "> " + message.text + "\n")}); });
      }
    }
    return outgoing;
  }
