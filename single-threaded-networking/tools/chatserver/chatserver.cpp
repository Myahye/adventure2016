/////////////////////////////////////////////////////////////////////////////
//                         Single Threaded Networking
//
// This file is distributed under the MIT License. See the LICENSE file
// for details.
/////////////////////////////////////////////////////////////////////////////

// - Can only send to one specific id/client or all clients no in between for now how to fix?
// - how to differentiate between different users on
//   same client (I guess user id username/password would fix this) *probably not a problem as 
//   there is a unique id for each running client
// - sign on/ sign off (cmp276)
// - have a user/pass list on server when user types in username and pass compare with list then 
//   recognize the client id as that user (channel 1 -> Derek123, Channel2 ->moman601)
// - 

#include "Server.h"

#include <sstream>

#include <unistd.h>

#include <boost/algorithm/string/predicate.hpp>


using namespace networking;


std::vector<Connection> clients;
std::unordered_map<std::string, std::string> commands {{"Create","Create "},{"Look","Look "},{"Go","Go "},{"Read","Read "},{"Attack","Attack "},{"Say","Say "},{"ListCommands","commands"},};

//gsl::string_span<> works: tested with g++ 6.2.0 *removed
std::string handleCreateCommand(const Message &message) {
  return "Create command not yet implemented.";
}

std::string handleLookCommand(const Message &message) {
  return "Look command not yet implemented.";
}

std::string handleGoCommand(const Message &message) {
  return "Go command not yet implemented.";
}

std::string handleReadCommand(const Message &message) {
  return "Read command not yet implemented.";
}

std::string handleAttackCommand(const Message &message) {
  return "Attack command not yet implemented.";
}

std::string handleListCommandsCommand() {
  std::string commandsList = "A list of commands:\n\n";

  for(auto command : commands) {
    commandsList += "  " + command.second + "\n";
  }

  return commandsList;
}

void
onConnect(Connection c) {
  printf("New connection found: %lu\n", c.id);
  clients.push_back(c);
}


void
onDisconnect(Connection c) {
  printf("Connection lost: %lu\n", c.id);
  auto eraseBegin = std::remove(std::begin(clients), std::end(clients), c);
  clients.erase(eraseBegin, std::end(clients));
}

// Modified by Lawrence Yu - Reads and processes incoming messages from clients since last update call
// and returns a message queue containing the proper messages to send to clients
std::deque<Message>
processMessagesAndBuildOutgoing(Server &server,
                const std::deque<Message> &incoming,
                bool &quit) {

  std::deque<Message> outgoing;

  for (auto client : clients) {
    outgoing.push_back({client, ""});
  }

  for (auto& message : incoming) {
    if (message.text == "quit") {
      server.disconnect(message.connection);
    } else if (message.text == "shutdown") {
      printf("Shutting down.\n");
      quit = true;
    } else if (boost::istarts_with(message.text,commands["Create"])) {
      auto selectedClient = std::find_if(outgoing.begin(), outgoing.end(), [message] (const Message &m) { return m.connection == message.connection; });
      selectedClient->text += std::to_string(message.connection.id) + "> " + handleCreateCommand(message) + "\n";
    } else if (boost::istarts_with(message.text,commands["Look"])) {
      auto selectedClient = std::find_if(outgoing.begin(), outgoing.end(), [message] (const Message &m) { return m.connection == message.connection; });
      selectedClient->text += std::to_string(message.connection.id) + "> " + handleLookCommand(message) + "\n";
    } else if (boost::istarts_with(message.text,commands["Go"])) {
      auto selectedClient = std::find_if(outgoing.begin(), outgoing.end(), [message] (const Message &m) { return m.connection == message.connection; });
      selectedClient->text += std::to_string(message.connection.id) + "> " + handleGoCommand(message) + "\n";
    } else if (boost::istarts_with(message.text,commands["Read"])) {
      auto selectedClient = std::find_if(outgoing.begin(), outgoing.end(), [message] (const Message &m) { return m.connection == message.connection; });
      selectedClient->text += std::to_string(message.connection.id) + "> " + handleReadCommand(message) + "\n";
    } else if (boost::istarts_with(message.text,commands["Attack"])) {
      auto selectedClient = std::find_if(outgoing.begin(), outgoing.end(), [message] (const Message &m) { return m.connection == message.connection; });
      selectedClient->text += std::to_string(message.connection.id) + "> " + handleAttackCommand(message) + "\n";
    } else if (boost::istarts_with(message.text,commands["Say"])) {
      std::for_each(outgoing.begin(), outgoing.end(), [message] (Message &m) { m.text += std::to_string(message.connection.id) + "> " + message.text.substr(4) + "\n"; });
    } else if (boost::iequals(message.text, commands["ListCommands"])) {
      auto selectedClient = std::find_if(outgoing.begin(), outgoing.end(), [message] (const Message &m) { return m.connection == message.connection; });
      selectedClient->text += std::to_string(message.connection.id) + "> " + handleListCommandsCommand() + "\n";
    } else {
      //Will output all other message types sent for now for testing purposes
      std::for_each(outgoing.begin(), outgoing.end(), [message] (Message &m) { m.text += std::to_string(message.connection.id) + "> " + message.text + "\n"; });
    }
  }
  return outgoing;
}

// Can only send to one specific id/client or all clients no in between for now how to fix?
// how to differentiate between different users on same client (I guess user id username/password would fix this)

std::deque<Message>
buildOutgoing(const std::string& log) {
  std::deque<Message> outgoing;
  for (auto client : clients) {
    //if id == id to send to specific id only
    outgoing.push_back({client, log});
  }
  return outgoing;
}


int
main(int argc, char* argv[]) {
  if (argc < 2) {
    printf("Usage:\n%s <port>\ne.g. %s 4002\n", argv[0], argv[0]);
    return 1;
  }

  bool done = false;
  unsigned short port = std::stoi(argv[1]);
  Server server{port, onConnect, onDisconnect};

  while (!done) {
    try {
      server.update();
    } catch (std::exception& e) {
      printf("Exception from Server update:\n%s\n\n", e.what());
      done = true;
    }

    auto incoming = server.receive();
    auto outgoing = processMessagesAndBuildOutgoing(server, incoming, done);

    server.send(outgoing);
    usleep(100000);
  }

  return 0;
}

