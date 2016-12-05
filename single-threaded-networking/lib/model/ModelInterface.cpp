#include "ModelInterface.h"
#include <boost/algorithm/string/predicate.hpp>
#include <iostream>

using namespace networking;

ModelInterface::ModelInterface() {}

//load config file to map commands["Create"] = getcreatecommandstringfromfile etc.

std::unordered_map<std::string, std::string> commands {{"Create","create"},{"Look","look"},{"Walk","walk"},{"Read","read"},{"Go","go"},{"Attack","attack"},{"Say","say"},{"ListCommands","ls"},{"Status","status"}, {"Take","take"}, {"Flee","flee"},{"Equip","equip"},{"Steal","steal"},{"Teleport","teleport"},{"Swap", "swap"},{"Cast", "cast"},{"Summon","summon"}};

std::unordered_map<int,Editor> activeEditors;

void
ModelInterface::buildCommands(const std::deque<Message>& clientMessages, std::vector<Connection>& clients) {

  for (auto& message : clientMessages) {

    std::string messageText = message.text;

    auto context = this->model.getContext();
    auto players = context.getPlayers();

    if((*players)[message.connection.playerId].playerCharacter.getStatus() != "Online" && (*players)[message.connection.playerId].playerCharacter.getSwappedStatus() != true) {
      activeEditors[message.connection.playerId].setMessage(message.text);
      std::cout << "georigoerg" << std::endl;
    } else if (boost::istarts_with(messageText,commands["Create"])) {
      activeEditors[message.connection.playerId] = Editor{message.connection,message.text};
      (*players)[message.connection.playerId].playerCharacter.setStatus("WorldBuilding");
    } else if (boost::istarts_with(messageText,commands["Look"])) {
      this->basicCommandQueue.push_back(std::make_unique<Commands::LookCommand>(message.connection,message.text));
    } else if (boost::istarts_with(messageText,commands["Go"])) {
      this->basicCommandQueue.push_back(std::make_unique<Commands::GoCommand>(message.connection,message.text));
    } else if (boost::istarts_with(messageText,commands["Read"])) {
      //this->basicCommandQueue.push_back(std::make_unique<Commands::ReadCommand>(message.connection,message.text));
    } else if (boost::istarts_with(messageText,commands["Attack"])) {
      this->combatManager.buildCombatCommand(message.connection,message.text);
    } else if (boost::istarts_with(messageText,commands["Flee"])){
      this->basicCommandQueue.push_back(std::make_unique<Commands::FleeCommand>(message.connection,message.text));
    } else if (boost::istarts_with(messageText,commands["Say"])) {
      createSayCommandForGroup(this->basicCommandQueue, clients, message.text, message.connection.playerId);
    } else if (boost::istarts_with(messageText, commands["ListCommands"])) {
      this->basicCommandQueue.push_back(std::make_unique<Commands::ListCommand>(message.connection,commands,message.text));
    } else if (boost::istarts_with(messageText, commands["Take"])) {
      this->basicCommandQueue.push_back(std::make_unique<Commands::TakeCommand>(message.connection,message.text));
    } else if (boost::istarts_with(messageText,commands["Equip"])) {
      this->basicCommandQueue.push_back(std::make_unique<Commands::EquipCommand>(message.connection,message.text));
    } else if (boost::istarts_with(messageText,commands["Status"])) {
      this->basicCommandQueue.push_back(std::make_unique<Commands::StatusCommand>(message.connection,message.text));
    } else if (boost::istarts_with(messageText,commands["Swap"])) {
      this->basicCommandQueue.push_back(std::make_unique<Commands::SwapCommand>(message.connection, message.text));
    } else if (boost::istarts_with(messageText,commands["Cast"])) {
      this->basicCommandQueue.push_back(std::make_unique<Commands::CastCommand>(message.connection,message.text));
    } else if (boost::istarts_with(messageText,commands["Steal"])) {
      this->basicCommandQueue.push_back(std::make_unique<Commands::StealCommand>(message.connection,message.text));
    } else if (boost::istarts_with(messageText,commands["Teleport"])) {
      this->basicCommandQueue.push_back(std::make_unique<Commands::TeleportCommand>(message.connection,message.text));
    } else if (boost::istarts_with(messageText,commands["Summon"])) {
      this->basicCommandQueue.push_back(std::make_unique<Commands::SummonCommand>(message.connection,message.text));
    } else {
      this->basicCommandQueue.push_back(std::make_unique<Commands::InvalidCommand>(message.connection,message.text));
    }
  }
}


std::deque<Message>
ModelInterface::updateGame(){

  std::deque<Message> outgoing;
  auto context = this->model.getContext();

  for(auto& basicCommand : basicCommandQueue) {
    std::string response = basicCommand->execute(context);
    Message message{basicCommand->getConnection(),response};
    basicCommandQueue.pop_front();
    outgoing.push_back(message);
  }

  for(auto& editor : activeEditors) {
    std::string response = editor.second.execute(context, model.getResets());
    if(response != "") {
      Message message{editor.second.getConnection(),response};
      outgoing.push_back(message);
    }
  }

  return outgoing;

}

std::deque<Message>
ModelInterface::updateCombat(std::vector<Connection>& clients){

  auto context = this->model.getContext();
  std::deque<Message> outgoing = this->combatManager.updateCombat(clients, context);

  return outgoing;

}

void ModelInterface::resetWorld() {
  this->model.reset();
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

Message
ModelInterface::createAlertMessage(Connection connection, std::string name){
  std::cout<<"6.1 connection == "<<connection.playerId<<std::endl;
  std::string response = "ALERT > You have been attacked by " + name + "\n\n";
  Message sourceMessage{connection,response};
  return sourceMessage;
}

void
ModelInterface::createSayCommandForGroup(std::deque<std::unique_ptr<Command>>& basicCommandQueue, std::vector<Connection> clients, std::string messageText, int playerId){
  std::for_each(clients.begin(), clients.end(), [&messageText,&basicCommandQueue,&playerId,this] (Connection& c)
        { if(c.currentState == ConnectionState::AUTHORIZED) {
            this->basicCommandQueue.push_back(std::make_unique<Commands::SayCommand>(c,messageText, playerId));
          }
        });
}
