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

#include <chrono>

#include <iostream>


using namespace networking;

std::vector<Connection> clients;
std::unordered_map<Connection,std::deque<Message>, ConnectionHash> clientMessageQueues;

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
  return outgoingQueue;
}

void
addToClientMessageQueues(const auto& incoming) {
  for (auto& message : incoming) {
    clientMessageQueues[message.connection].push_front({message.connection,message.text});
  }
}

int
main(int argc, char* argv[]) {
  if (argc < 2) {
    printf("Usage:\n%s <port>\ne.g. %s 4002\n", argv[0], argv[0]);
    return 1;
  }

  std::chrono::time_point<std::chrono::system_clock> start, end;
 
  bool done = false;
  unsigned short port = std::stoi(argv[1]);
  Server server{port, onConnect, onDisconnect};

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

    end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    if(elapsed_seconds.count() >= 3.0){
       std::cout 
           << "elapsed time: " << elapsed_seconds.count() << "s\n";
      auto commands = pullFromClientMessageQueues(server,done);

      start = std::chrono::system_clock::now();
    }
  }

  return 0;
}

