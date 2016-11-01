#include "ModelInterface.h"
#include <boost/algorithm/string/predicate.hpp>
#include <iostream>

using namespace networking;

ModelInterface::ModelInterface() {}

std::unordered_map<std::string, std::string> commands {{"Create","create "},{"Look","look "},{"Walk","walk "},{"Read","read "},{"Go","go "},{"Attack","attack "},{"Say","say "},{"ListCommands","ls "},{"Status","status "}, {"Steal","steal "}};

void
ModelInterface::buildCommands(const std::deque<Message>& clientMessages, std::vector<Connection>& clients) {

  std::deque<std::unique_ptr<Command>> commandQueue;
std::cout << "s " << std::endl;
  for (auto& message : clientMessages) {
std::cout << "v " << std::endl;
    std::string messageText = message.text;

    if (boost::istarts_with(messageText,commands["Create"])) {
      // messageText = std::to_string(message.connection.playerIDConnectedToClientConnection) + "> " + handleCreateCommand(message) + "\n";
      // outgoing.push_back(Message{message.connection, messageText});
    }
    else if (boost::istarts_with(messageText,commands["Look"])) {
      this->basicCommandQueue.push_back(std::make_unique<Commands::LookCommand>(message.connection,message.text));

      // messageText = this->model.lookCommand(message.connection.playerIDConnectedToClientConnection, message.text);
      // outgoing.push_back(Message{message.connection, messageText});
    }
    else if (boost::istarts_with(messageText,commands["Go"])) {
      this->basicCommandQueue.push_back(std::make_unique<Commands::GoCommand>(message.connection,message.text.substr(3)));

      // messageText = this->model.movePlayer(message.connection.playerIDConnectedToClientConnection, message.text.substr(3));
      // outgoing.push_back(Message{message.connection, messageText});
    }
    else if (boost::istarts_with(messageText,commands["Read"])) {
      // messageText = std::to_string(message.connection.playerIDConnectedToClientConnection) + "> " + handleCreateCommand(message) + "\n";
      // outgoing.push_back(Message{message.connection, messageText});
    }
    else if (boost::istarts_with(messageText,commands["Attack"])) {
      //this->combatCommandQueue.push_back(std::make_unique<Commands::LookCommand>(message.connection,message.text));
    }
    else if (boost::istarts_with(messageText,commands["Say"])) {
      // std::for_each(clients.begin(), clients.end(), [&message,&outgoing,this] (Connection& c)
      //   { if(c.currentState == ConnectionState::AUTHORIZED) { outgoing.push_back(Message{c,std::string(this->model.dummySayCommand(message.connection.playerIDConnectedToClientConnection,message.text))}); } });
    }
    else if (boost::istarts_with(messageText, commands["ListCommands"])) {
      // messageText = std::to_string(message.connection.playerIDConnectedToClientConnection) + "> " + handleCreateCommand(message) + "\n";
      // outgoing.push_back(Message{message.connection, messageText});
    } 
    else if (boost::istarts_with(messageText, commands["Steal"])) {
      this->basicCommandQueue.push_back(std::make_unique<Commands::LookCommand>(message.connection,message.text));
    }
    else if (boost::istarts_with(messageText,commands["Status"])){
      std::cout << "iowerjgio" << std::endl;
      this->basicCommandQueue.push_back(std::make_unique<Commands::StatusCommand>(message.connection,message.text));
    } else {
      this->basicCommandQueue.push_back(std::make_unique<Commands::InvalidCommand>(message.connection,message.text));
      //Will output all other message types sent for now for testing purposes
      // std::for_each(clients.begin(), clients.end(), [&message,&outgoing] (Connection& c)
      //   { if(c.currentState == ConnectionState::AUTHORIZED) { outgoing.push_back(Message{c,std::string(std::to_string(message.connection.playerIDConnectedToClientConnection) + "> " + message.text + "\n")}); } });
    }
  }
}

std::deque<Message>
ModelInterface::updateGame(){

  std::deque<Message> outgoing;
  auto context = this->model.getContext();

  //buildCommands();

  if(true/*tickIsUpForCombatTimer()*/){
    for(auto& combatCommand : combatCommandQueue) {
      std::string response = combatCommand->execute(context);
      Message message{combatCommand->getConnection(),response};
      combatCommandQueue.pop_front();
      outgoing.push_back(message);
    }
  }

  if(true/*tickIsUpForNonCombatTimer()*/){
    for(auto& basicCommand : basicCommandQueue) {
      std::string response = basicCommand->execute(context);
      Message message{basicCommand->getConnection(),response};
      basicCommandQueue.pop_front();
      outgoing.push_back(message);
    }
  }
std::cout << "AAA " << std::endl;
  this->model.reset();
std::cout << "BBB " << std::endl;
  return outgoing;

}

std::string
ModelInterface::getCurrentRoomDescription(const int& playerID) {
  return this->model.getCurrentRoomDescription(playerID);
}

int
ModelInterface::createPlayer(const std::string& username, const std::string& password) {
  return(this->model.createPlayer(username, password));
}

std::vector<std::tuple<int,std::string,std::string>>
ModelInterface::getPlayerCredentialsVector() const {
  return(this->model.getPlayerCredentialsVector());
}
