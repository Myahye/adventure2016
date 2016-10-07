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
std::unordered_map<Connection,std::deque<Message>, ConnectionHash> pendingOutgoingQueue;
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
  pendingOutgoingQueue[c] = std::deque<Message>();
  clients.push_back(c);
}


void
onDisconnect(Connection c) {
  printf("Connection lost: %lu\n", c.id);
  auto eraseBegin = std::remove(std::begin(clients), std::end(clients), c);
  clients.erase(eraseBegin, std::end(clients));
  pendingOutgoingQueue.erase(c);
}

// Modified by Lawrence Yu - Reads and processes incoming messages from clients since last update call
// and returns a message queue containing the proper messages to send to clients
std::deque<Message>
processMessagesAndBuildOutgoing(Server &server, bool &quit) {

  std::unordered_map<Connection, Message, ConnectionHash> outgoing;
  std::deque<Message> outgoingQueue;

  for(auto client : clients) {
    outgoing[client] = {client,""};
  }

  for (auto& client : clients) {
    if(pendingOutgoingQueue[client].size() != 0) {
      if (pendingOutgoingQueue[client].back().text == "quit") {
        server.disconnect(client);
      } else if (pendingOutgoingQueue[client].back().text == "shutdown") {
        printf("Shutting down.\n");
        quit = true;
      } else if (boost::istarts_with(pendingOutgoingQueue[client].back().text,commands["Create"])) {
        outgoing[client].text += std::to_string(client.id) + "> " + handleCreateCommand(pendingOutgoingQueue[client].back()) + "\n";
        pendingOutgoingQueue[client].pop_back();
      } else if (boost::istarts_with(pendingOutgoingQueue[client].back().text,commands["Look"])) {
        outgoing[client].text += std::to_string(client.id) + "> " + handleLookCommand(pendingOutgoingQueue[client].back()) + "\n";
        pendingOutgoingQueue[client].pop_back();
      } else if (boost::istarts_with(pendingOutgoingQueue[client].back().text,commands["Go"])) {
        outgoing[client].text += std::to_string(client.id) + "> " + handleGoCommand(pendingOutgoingQueue[client].back()) + "\n";
        pendingOutgoingQueue[client].pop_back();
      } else if (boost::istarts_with(pendingOutgoingQueue[client].back().text,commands["Read"])) {
        outgoing[client].text += std::to_string(client.id) + "> " + handleReadCommand(pendingOutgoingQueue[client].back()) + "\n";
        pendingOutgoingQueue[client].pop_back();
      } else if (boost::istarts_with(pendingOutgoingQueue[client].back().text,commands["Attack"])) {
        outgoing[client].text += std::to_string(client.id) + "> " + handleAttackCommand(pendingOutgoingQueue[client].back()) + "\n";
        pendingOutgoingQueue[client].pop_back();
      } else if (boost::istarts_with(pendingOutgoingQueue[client].back().text,commands["Say"])) {
        std::for_each(outgoing.begin(), outgoing.end(), [client] (auto &m) { m.second.text += std::to_string(m.first.id) + "> " + pendingOutgoingQueue[client].back().text.substr(4) + "\n"; });
        pendingOutgoingQueue[client].pop_back();
      } else if (boost::iequals(pendingOutgoingQueue[client].back().text, commands["ListCommands"])) {
        outgoing[client].text += std::to_string(client.id) + "> " + handleListCommandsCommand() + "\n";
        pendingOutgoingQueue[client].pop_back();
      } else {
        printf("%s\n", pendingOutgoingQueue[client].back().text.c_str());
        //Will output all other messageIterator types sent for now for testing purposes
        std::for_each(outgoing.begin(), outgoing.end(), [client] (auto &m) { m.second.text += std::to_string(m.first.id) + "> " + pendingOutgoingQueue[client].back().text + "\n"; });
        pendingOutgoingQueue[client].pop_back();
      }
    }
  }

  for(auto client : clients) {
    outgoingQueue.push_back(outgoing[client]);
  }

  return outgoingQueue;
}

// Can only send to one specific id/client or all clients no in between for now how to fix?
// how to differentiate between different users on same client (I guess user id username/password would fix this)

void
addToPendingOutgoingQueue(const auto& incoming) {
  for (auto message : incoming) {
    pendingOutgoingQueue[message.connection].push_front({message.connection,message.text});
  }
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
    addToPendingOutgoingQueue(incoming);
    auto outgoing = processMessagesAndBuildOutgoing(server, done);

    server.send(outgoing);
    sleep(1);
  }

  return 0;
}

