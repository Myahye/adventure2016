#include "CommandParse.h"

CommandParse::CommandParse() {}

std::unordered_map<std::string, std::string> commands {{"Create","Create "},{"Look","Look "},{"Go","Go "},{"Read","Read "},{"Attack","Attack "},{"Say","Say "},{"ListCommands","commands"},};


std::deque<Message2>
CommandParse::parseCommands(const auto& clientMessage2Queue, std::vector<Connection2> clients) {

    std::deque<Message2> outgoing;

    for (auto& Message2 : clientMessage2Queue) {
      if (boost::istarts_with(Message2.text,"Create")) {
        std::string Message2Text = std::to_string(Message2.Connection2.id) + "> " + handleCreateCommand(Message2) + "\n";
        outgoing.push_back({Message2.Connection2, Message2Text});
      } else if (boost::istarts_with(Message2.text,commands["Look"])) {
        std::string Message2Text = std::to_string(Message2.Connection2.id) + "> " + handleCreateCommand(Message2) + "\n";
        outgoing.push_back({Message2.Connection2, Message2Text});
      } else if (boost::istarts_with(Message2.text,commands["Go"])) {
        std::string Message2Text = std::to_string(Message2.Connection2.id) + "> " + handleCreateCommand(Message2) + "\n";
        outgoing.push_back({Message2.Connection2, Message2Text});
      } else if (boost::istarts_with(Message2.text,commands["Read"])) {
        std::string Message2Text = std::to_string(Message2.Connection2.id) + "> " + handleCreateCommand(Message2) + "\n";
        outgoing.push_back({Message2.Connection2, Message2Text});
      } else if (boost::istarts_with(Message2.text,commands["Attack"])) {
        std::string Message2Text = std::to_string(Message2.Connection2.id) + "> " + handleCreateCommand(Message2) + "\n";
        outgoing.push_back({Message2.Connection2, Message2Text});
      } else if (boost::istarts_with(Message2.text,commands["Say"])) {
        std::for_each(clients.begin(), clients.end(), [&Message2,&outgoing] (Connection2& c) { outgoing.push_back({c,std::string(std::to_string(Message2.Connection2.id) + "> " + Message2.text.substr(4) + "\n")}); });
      } else if (boost::iequals(Message2.text, commands["ListCommands"])) {
        std::string Message2Text = std::to_string(Message2.Connection2.id) + "> " + handleCreateCommand(Message2) + "\n";
        outgoing.push_back({Message2.Connection2, Message2Text});
      } else {
        //Will output all other Message2 types sent for now for testing purposes
        std::for_each(clients.begin(), clients.end(), [&Message2,&outgoing] (Connection2& c) { outgoing.push_back({c,std::string(std::to_string(Message2.Connection2.id) + "> " + Message2.text + "\n")}); });
      }
    }
    return outgoing;
  }
