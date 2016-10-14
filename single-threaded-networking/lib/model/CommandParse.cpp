#include "CommandParse.h"


using namespace networking;

CommandParse::CommandParse() {}

std::unordered_map<std::string, std::string> commands {{"Create","create "},{"Look","look "},{"Go","go "},{"Read","read "},{"Attack","attack "},{"Say","say "},{"ListCommands","ls "},};

void CommandParse::test(){
  throw std::runtime_error(std::string("failed custom msg "));
}

std::deque<Message>
CommandParse::parseCommands(const std::deque<Message>& clientMessageQueue, std::vector<Connection>& clients) {



    std::deque<Message> outgoing;

    for (auto& message : clientMessageQueue) {

      std::string messageText = message.text;
      std::transform(messageText.begin(), messageText.end(), messageText.begin(), ::tolower);

      if (boost::istarts_with(messageText,commands["Create"])) {
        std::string messageText = std::to_string(message.connection.id) + ">asdfasdfasdf Kieran " + /*handleCreateCommand(message)*/ + "\n";
        outgoing.push_back({message.connection, messageText});
      }
      else if (boost::istarts_with(messageText,commands["Look"])) {
        std::string messageText = std::to_string(message.connection.id) + "> " + /*handleCreateCommand(message)*/ + "\n";
        outgoing.push_back({messageText, messageText});
      }
      else if (boost::istarts_with(messageText,commands["Go"])) {
        std::string messageText = std::to_string(message.connection.id) + "> " + /*handleCreateCommand(message)*/ + "\n";
        outgoing.push_back({message.connection, messageText});
      }
      else if (boost::istarts_with(messageText,commands["Read"])) {
        std::string messageText = std::to_string(message.connection.id) + "> " + /*handleCreateCommand(message)*/ + "\n";
        outgoing.push_back({message.connection, messageText});
      }
      else if (boost::istarts_with(messageText,commands["Attack"])) {
        std::string messageText = std::to_string(message.connection.id) + "> " + /*handleCreateCommand(message)*/ + "\n";
        outgoing.push_back({message.connection, messageText});
      }
      else if (boost::istarts_with(messageText,commands["Say"])) {
        std::for_each(clients.begin(), clients.end(), [&message,&outgoing] (Connection& c)
          { outgoing.push_back({c,std::string(std::to_string(message.connection.id) + "> " + message.text.substr(4) + "\n")}); });
      }
      else if (boost::iequals(messageText, commands["ListCommands"])) {
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
