#include "CommandParse.h"

using namespace networking;

CommandParse::CommandParse() {}

std::unordered_map<std::string, std::string> commands {{"Create","Create "},{"Look","Look "},{"Go","Go "},{"Read","Read "},{"Attack","Attack "},{"Say","Say "},{"ListCommands","commands"},};


std::deque<Message>
CommandParse::parseCommands(const auto& clientMessageQueue, std::vector<Connection> clients) {

    std::deque<Message> outgoing;

    for (auto& message : clientMessageQueue) {
      if (boost::istarts_with(message.text,"Create")) {
        std::string messageText = std::to_string(message.connection.id) + "> " + handleCreateCommand(message) + "\n";
        outgoing.push_back({message.connection, messageText});
      } else if (boost::istarts_with(message.text,commands["Look"])) {
        std::string messageText = std::to_string(message.connection.id) + "> " + handleCreateCommand(message) + "\n";
        outgoing.push_back({message.connection, messageText});
      } else if (boost::istarts_with(message.text,commands["Go"])) {
        std::string messageText = std::to_string(message.connection.id) + "> " + handleCreateCommand(message) + "\n";
        outgoing.push_back({message.connection, messageText});
      } else if (boost::istarts_with(message.text,commands["Read"])) {
        std::string messageText = std::to_string(message.connection.id) + "> " + handleCreateCommand(message) + "\n";
        outgoing.push_back({message.connection, messageText});
      } else if (boost::istarts_with(message.text,commands["Attack"])) {
        std::string messageText = std::to_string(message.connection.id) + "> " + handleCreateCommand(message) + "\n";
        outgoing.push_back({message.connection, messageText});
      } else if (boost::istarts_with(message.text,commands["Say"])) {
        std::for_each(clients.begin(), clients.end(), [&message,&outgoing] (Connection& c) { outgoing.push_back({c,std::string(std::to_string(message.connection.id) + "> " + message.text.substr(4) + "\n")}); });
      } else if (boost::iequals(message.text, commands["ListCommands"])) {
        std::string messageText = std::to_string(message.connection.id) + "> " + handleCreateCommand(message) + "\n";
        outgoing.push_back({message.connection, messageText});
      } else {
        //Will output all other message types sent for now for testing purposes
        std::for_each(clients.begin(), clients.end(), [&message,&outgoing] (Connection& c) { outgoing.push_back({c,std::string(std::to_string(message.connection.id) + "> " + message.text + "\n")}); });
      }
    }
    return outgoing;
  }
