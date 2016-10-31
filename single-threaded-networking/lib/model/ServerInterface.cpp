#include "ServerInterface.h"
#include <boost/algorithm/string/predicate.hpp>
#include <iostream>

using namespace networking;

ServerHelper::ServerHelper() {}

std::unordered_map<std::string, std::string> commands {{"Create","create "},{"Look","look "},{"Walk","walk "},{"Read","read "},{"Go","go "},{"Attack","attack "},{"Say","say "},{"ListCommands","ls "},};

std::deque<Message>
ServerHelper::parseCommands(const std::deque<Message>& clientMessages, std::vector<Connection>& clients) {
  std::deque<Message> outgoing;

  std::deque<std::unique_ptr<Command>> commandQueue;

  for (auto& message : clientMessages) {

    std::string messageText = message.text;

    if (boost::istarts_with(messageText,commands["Create"])) {
      messageText = std::to_string(message.connection.playerIDConnectedToClientConnection) + "> " + /*handleCreateCommand(message)*/ + "\n";
      outgoing.push_back(Message{message.connection, messageText});
    }
    else if (boost::istarts_with(messageText,commands["Look"])) {
      commandQueue.push_back(std::make_unique<Commands::LookCommand>(message.connection,message.text));

      // messageText = this->model.lookCommand(message.connection.playerIDConnectedToClientConnection, message.text);
      // outgoing.push_back(Message{message.connection, messageText});
    }
    else if (boost::istarts_with(messageText,commands["Go"])) {
      commandQueue.push_back(std::make_unique<Commands::GoCommand>(message.connection,message.text.substr(3)));

      // messageText = this->model.movePlayer(message.connection.playerIDConnectedToClientConnection, message.text.substr(3));
      // outgoing.push_back(Message{message.connection, messageText});
    }
    else if (boost::istarts_with(messageText,commands["Read"])) {
      messageText = std::to_string(message.connection.playerIDConnectedToClientConnection) + "> " + /*handleCreateCommand(message)*/ + "\n";
      outgoing.push_back(Message{message.connection, messageText});
    }
    else if (boost::istarts_with(messageText,commands["Attack"])) {
      messageText = std::to_string(message.connection.playerIDConnectedToClientConnection) + "> " + /*handleCreateCommand(message)*/ + "\n";
      outgoing.push_back(Message{message.connection, messageText});
    }
    else if (boost::istarts_with(messageText,commands["Say"])) {
      std::for_each(clients.begin(), clients.end(), [&message,&outgoing,this] (Connection& c)
        { if(c.currentState == ConnectionState::AUTHORIZED) { outgoing.push_back(Message{c,std::string(this->model.dummySayCommand(message.connection.playerIDConnectedToClientConnection,message.text))}); } });
    }
    else if (boost::iequals(messageText, commands["ListCommands"])) {
      messageText = std::to_string(message.connection.playerIDConnectedToClientConnection) + "> " + /*handleCreateCommand(message)*/ + "\n";
      outgoing.push_back(Message{message.connection, messageText});
    } 
    else if (boost::iequals(messageText, commands["Steal"])) {
      messageText = this->model.stealCommand(message.connection.playerIDConnectedToClientConnection, message.text);
      outgoing.push_back(Message{message.connection, messageText});
    }
    else {
      messageText = "That is an invalid command\n\n";
      outgoing.push_back(Message{message.connection, messageText});
      //Will output all other message types sent for now for testing purposes
      // std::for_each(clients.begin(), clients.end(), [&message,&outgoing] (Connection& c)
      //   { if(c.currentState == ConnectionState::AUTHORIZED) { outgoing.push_back(Message{c,std::string(std::to_string(message.connection.playerIDConnectedToClientConnection) + "> " + message.text + "\n")}); } });
    }
  }

  auto context = this->model.getContext();

  for(auto& command : commandQueue) {
    std::string response = command->execute(context);
    Message message{command->getConnection(),response};
    outgoing.push_back(message);
  }


  this->model.reset();
  return outgoing;
}

std::string
ServerHelper::getCurrentRoomDescription(const int& playerID) {
  return this->model.getCurrentRoomDescription(playerID);
}

int
ServerHelper::createPlayer(const std::string& username, const std::string& password) {
  return(this->model.createPlayer(username, password));
}

std::vector<std::tuple<int,std::string,std::string>>
ServerHelper::getPlayerCredentialsVector() const {
  return(this->model.getPlayerCredentialsVector());
}
