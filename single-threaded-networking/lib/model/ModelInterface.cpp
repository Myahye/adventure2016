#include "ModelInterface.h"
#include <boost/algorithm/string/predicate.hpp>
#include <iostream>

using namespace networking;

ModelInterface::ModelInterface() {}

//load config file to map commands["Create"] = getcreatecommandstringfromfile etc.
std::unordered_map<std::string, std::string> commands {{"Flee","flee"},{"Create","create"},{"Look","look"},{"Walk","walk"},{"Read","read"},{"Go","go"},{"Attack","attack"},{"Say","say"},{"ListCommands","ls"},{"Status","status"}, {"Take","take"}};

void
ModelInterface::buildCommands(const std::deque<Message>& clientMessages, std::vector<Connection>& clients) {

  for (auto& message : clientMessages) {

    std::string messageText = message.text;

    if (boost::istarts_with(messageText,commands["Create"])) {
      //this->basicCommandQueue.push_back(std::make_unique<Commands::LookCommand>(message.connection,message.text));
    } else if (boost::istarts_with(messageText,commands["Look"])) {
      this->basicCommandQueue.push_back(std::make_unique<Commands::LookCommand>(message.connection,message.text));
    } else if (boost::istarts_with(messageText,commands["Go"])) {
      this->basicCommandQueue.push_back(std::make_unique<Commands::GoCommand>(message.connection,message.text));
    } else if (boost::istarts_with(messageText,commands["Read"])) {
      //this->basicCommandQueue.push_back(std::make_unique<Commands::ReadCommand>(message.connection,message.text));
    } else if (boost::istarts_with(messageText,commands["Attack"])) {
      //this->combatCommandQueue.push_back(std::make_unique<Commands::AttackCommand>(message.connection,message.text));
    } else if (boost::istarts_with(messageText,commands["Flee"])){
      this->basicCommandQueue.push_back(std::make_unique<Commands::FleeCommand>(message.connection,message.text));
    }else if (boost::istarts_with(messageText,commands["Say"])) {
      //this->basicCommandQueue.push_back(std::make_unique<Commands::SayCommand>(message.connection,message.text));
    } else if (boost::istarts_with(messageText, commands["ListCommands"])) {
      //this->basicCommandQueue.push_back(std::make_unique<Commands::AttackCommand>(message.connection,message.text));
    } else if (boost::istarts_with(messageText, commands["Take"])) {
      this->basicCommandQueue.push_back(std::make_unique<Commands::TakeCommand>(message.connection,message.text));
    } else if (boost::istarts_with(messageText,commands["Status"])) {
      this->basicCommandQueue.push_back(std::make_unique<Commands::StatusCommand>(message.connection,message.text));
    } else {
      this->basicCommandQueue.push_back(std::make_unique<Commands::InvalidCommand>(message.connection,message.text));
    }
  }
}

std::deque<Message>
ModelInterface::updateGame(){

  std::deque<Message> outgoing;
  auto context = this->model.getContext();

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

  //move out later
  this->model.reset();

  return outgoing;

}

std::string
ModelInterface::getCurrentRoomDescription(const int& playerId) {
  return this->model.getCurrentRoomDescription(playerId);
}

int
ModelInterface::createPlayer(const std::string& username, const std::string& password) {
  return(this->model.createPlayer(username, password));
}

std::vector<std::tuple<int,std::string,std::string>>
ModelInterface::getPlayerCredentialsVector() const {
  return(this->model.getPlayerCredentialsVector());
}


void ModelInterface::playerDisconnected(Connection c) {
  this->model.playerDisconnected(c.playerId);
}

void ModelInterface::playerConnect(Connection c) {
  this->model.playerConnect(c.playerId);
}

