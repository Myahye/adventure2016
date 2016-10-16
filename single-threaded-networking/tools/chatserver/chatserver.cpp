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

#include <chrono>

#include <iostream>

#include "CommandParse.h"
#include "Authentication.h"


using namespace networking;

std::vector<Connection> clients;
std::unordered_map<Connection,std::deque<Message>, ConnectionHash> clientMessageQueues;
//std::unordered_map<std::string, std::string> commands {{"Create","Create"},{"Look","Look "},{"Go","Go "},{"Read","Read "},{"Attack","Attack "},{"Say","Say "},{"ListCommands","commands"},};

//gsl::string_span<> works: tested with g++ 6.2.0 *removed
// std::string handleCreateCommand(const Message &message) {
//   std::cout << "In handleCreateCommand" << "s\n";
//   return "Create command not yet implemented.";
// }

// std::string handleLookCommand(const Message &message) {
//   return "Look command not yet implemented.";
// }

// std::string handleGoCommand(const Message &message) {
//   return "Go command not yet implemented.";
// }

// std::string handleReadCommand(const Message &message) {
//   return "Read command not yet implemented.";
// }

// std::string handleAttackCommand(const Message &message) {
//   return "Attack command not yet implemented.";
// }

// std::string handleListCommandsCommand() {
//   std::string commandsList = "A list of commands:\n\n";

//   for(auto& command : commands) {
//     commandsList += "  " + command.second + "\n";
//   }

//   return commandsList;
// }

void
onConnect(Connection c) {
  printf("New connection found: %lu\n", c.id);
  clientMessageQueues[c] = std::deque<Message>();
  clients.push_back(c);
}


void
onDisconnect(Connection c) {
  printf("Connection lost: %lu\n", c.id);
  auto eraseBegin = std::remove(std::begin(clients), std::end(clients), c);
  clients.erase(eraseBegin, std::end(clients));
  clientMessageQueues.erase(c);
}

// Modified by Lawrence Yu - Reads and processes incoming messages from clients since last update call
// and returns a message queue containing the proper messages to send to clients
std::deque<Message>
pullFromClientMessageQueues(Server &server, bool &quit) {

  std::unordered_map<Connection, Message, ConnectionHash> outgoingMap;
  std::deque<Message> outgoingQueue;

  for(auto& client : clients) {
    outgoingMap[client] = {client,""};
  }

  for (auto& client : clients) {
    if(!clientMessageQueues[client].empty()) {
      if (clientMessageQueues[client].back().text == "quit") {
        server.disconnect(client);
      } else if (clientMessageQueues[client].back().text == "shutdown") {
        printf("Shutting down.\n");
        quit = true;
      } else {
        outgoingQueue.push_back(clientMessageQueues[client].back());
        clientMessageQueues[client].pop_back();
      }
    }
  }

  // for(auto& client : clients) {
  //   outgoingQueue.push_back(outgoingMap[client]);
  // }

  return outgoingQueue;
}

void
addToClientMessageQueues(const auto& incoming) {
  for (auto& message : incoming) {
    clientMessageQueues[message.connection].push_front({message.connection,message.text});
  }
}

// std::deque<Message>
// parseCommandsDummy(const auto& clientMessageQueue) {
//   std::deque<Message> outgoing;
//   for (auto& message : clientMessageQueue) {
//     if (boost::istarts_with(message.text,commands["Create"])) {
//       std::cout << "In Create" << "\n";
//       std::string messageText = std::to_string(message.connection.id) + "> " + handleCreateCommand(message) + "\n";
//       outgoing.push_back({message.connection, messageText});
//     } else if (boost::istarts_with(message.text,commands["Look"])) {
//       std::string messageText = std::to_string(message.connection.id) + "> " + handleCreateCommand(message) + "\n";
//       outgoing.push_back({message.connection, messageText});
//     } else if (boost::istarts_with(message.text,commands["Go"])) {
//       std::string messageText = std::to_string(message.connection.id) + "> " + handleCreateCommand(message) + "\n";
//       outgoing.push_back({message.connection, messageText});
//     } else if (boost::istarts_with(message.text,commands["Read"])) {
//       std::string messageText = std::to_string(message.connection.id) + "> " + handleCreateCommand(message) + "\n";
//       outgoing.push_back({message.connection, messageText});
//     } else if (boost::istarts_with(message.text,commands["Attack"])) {
//       std::string messageText = std::to_string(message.connection.id) + "> " + handleCreateCommand(message) + "\n";
//       outgoing.push_back({message.connection, messageText});
//     } else if (boost::istarts_with(message.text,commands["Say"])) {
//       std::for_each(clients.begin(), clients.end(), [&message,&outgoing] (Connection& c) { outgoing.push_back({c,std::string(std::to_string(message.connection.id) + "> " + message.text.substr(4) + "\n")}); });
//     } else if (boost::iequals(message.text, commands["ListCommands"])) {
//       std::string messageText = std::to_string(message.connection.id) + "> " + handleCreateCommand(message) + "\n";
//       outgoing.push_back({message.connection, messageText});
//     } else {
//       std::cout << "In else" << "s\n";

//       //Will output all other message types sent for now for testing purposes
//       std::for_each(clients.begin(), clients.end(), [&message,&outgoing] (Connection& c) { outgoing.push_back({c,std::string(std::to_string(message.connection.id) + "> " + message.text + "\n")}); });
//     }
//   }
//   return outgoing;
// }

std::deque<Message> processMessages(CommandParse& commandParse, std::deque<Message>& commands, Server& server) {

  std::deque<Message> outgoing;

  for(auto& message : commands) {
    if(message.connection.currentState != ConnectionState::AUTHORIZED) {
      server.send(std::deque<Message>{Message{message.connection, Authentication::authorizeClient(message, server, clients, commandParse)}});
    } else {
      outgoing.push_back(message);
    }
  }

  return commandParse.parseCommands(outgoing, clients);
}

int
main(int argc, char* argv[]) {
  if (argc < 2) {
    printf("Usage:\n%s <port>\ne.g. %s 4002\n", argv[0], argv[0]);
    return 1;
  }

  std::chrono::time_point<std::chrono::system_clock> start, end;

 // std::time_t end_time = std::chrono::system_clock::to_time_t(end);

 // std::cout << "finished computation at " << std::ctime(&end_time)
   //         << "elapsed time: " << elapsed_seconds.count() << "s\n";

  bool done = false;
  unsigned short port = std::stoi(argv[1]);
  Server server{port, onConnect, onDisconnect};

  CommandParse commandParse{};

  start = std::chrono::system_clock::now();
  while (!done) {
    try {
      server.update();
    } catch (std::exception& e) {
      printf("Exception from Server update:\n%s\n\n", e.what());
      done = true;
    }

    auto incoming = server.receive();
    addToClientMessageQueues(incoming);


    //model::initWorld(pathtoyaml);
    end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    if(elapsed_seconds.count() >= 1.0){
       // std::cout
       //     << "elapsed time: " << elapsed_seconds.count() << "s\n";
      std::deque<Message> commands = pullFromClientMessageQueues(server,done);
      //auto response = parseCommandsDummy(commands);
      std::deque<Message> response = processMessages(commandParse, commands, server);
      server.send(response);
      start = std::chrono::system_clock::now();
    }

    //auto outgoing = processMessagesAndBuildOutgoing(server, done);
    //server.send(outgoing);

  }

  return 0;
}
