#include "ModelInterface.h"
#include <boost/algorithm/string/predicate.hpp>
#include <iostream>

using namespace networking;

ModelInterface::ModelInterface() {
  std::chrono::seconds zeroSecond(0);
  std::chrono::milliseconds halfSecond(5000);
  this->combatPrevious = std::chrono::system_clock::now();
  this->combatLag = zeroSecond;
  this->MS_PER_COMBAT_UPDATE = halfSecond;

  this->nonCombatPrevious = std::chrono::system_clock::now();
  this->nonCombatLag = zeroSecond;
  this->MS_PER_NONCOMBAT_UPDATE = halfSecond;
}

std::unordered_map<std::string, std::string> commands {{"Create","create "},{"Look","look "},{"Walk","walk "},{"Read","read "},{"Go","go "},{"Attack","attack "},{"Say","say "},{"ListCommands","ls "},};

std::deque<Message>
ModelInterface::updateGame(const std::deque<Message>& clientMessages, std::vector<Connection>& clients){
  std::deque<Message> outgoing;

  buildCommands(clientMessages, clients);
  if(tickIsUpForCombatTimer()){
    //dequeConcatenate(outgoing, executeCombatCommands(clientMessages, clients));
  }
  if(tickIsUpForNonCombatTimer()){
  std::cout << "Here" << std::endl;

  std::deque<Message> tmpMsgQue = mclientMessages;
  mclientMessages.clear();

  std::deque<Message> right = parseCommands(tmpMsgQue, mclients);
  outgoing = dequeConcatenate(outgoing, right);
  //dequeConcatenate(outgoing, executeNonCombatCommands(clientMessages, clients));
  }
  return outgoing;
}

//Temporary parameter names
std::deque<networking::Message>
ModelInterface::dequeConcatenate(std::deque<networking::Message> left, const std::deque<networking::Message> right){
  for(Message message : right){
    left.push_back(message);
  }
  return left;
}


//Implement command building in here
//This currently breaks the "one from each user" cycle
//Will work once
void
ModelInterface::buildCommands(const std::deque<networking::Message>& clientMessages, std::vector<networking::Connection>& clients) {
  this->mclients = clients;
  for(Message message : clientMessages){
    //mclientMessages2[message.connection.id]
    this->mclientMessages.push_back(message);
  }

}
bool
ModelInterface::tickIsUpForCombatTimer(){
    this->combatCurrent = std::chrono::system_clock::now();
    this->combatElapsed = this->combatCurrent - this->combatPrevious;
    this->combatPrevious = this->combatCurrent;
    this->combatLag += this->combatElapsed;

    if (this->combatLag >= this->MS_PER_COMBAT_UPDATE){
      this->combatLag -= this->MS_PER_COMBAT_UPDATE;
      std::cout << "tick Is Up For Combat Timer" << std::endl;
      return true;
    }
    //std::cout << "tickIsUpForCombatTimer: " << false << std::endl;
    return false;
}

bool
ModelInterface::tickIsUpForNonCombatTimer(){
  this->nonCombatCurrent = std::chrono::system_clock::now();
  this->nonCombatElapsed = this->nonCombatCurrent - this->nonCombatPrevious;
  this->nonCombatPrevious = this->nonCombatCurrent;
  this->nonCombatLag += this->nonCombatElapsed;

  if (this->nonCombatLag >= this->MS_PER_NONCOMBAT_UPDATE){
    this->nonCombatLag -= this->MS_PER_NONCOMBAT_UPDATE;
    std::cout << "tick Is Up For Non-Combat Timer" << std::endl;
    return true;
  }
  //std::cout << "tickIsUpForNonCombatTimer: " << false << std::endl;
  return false;
}

std::deque<Message>
ModelInterface::parseCommands(const std::deque<Message>& clientMessages, std::vector<Connection>& clients) {
  std::cout << "parseCommands" << std::endl;
  std::deque<Message> outgoing;

  for (auto& message : clientMessages) {

    std::string messageText = message.text;

    if (boost::istarts_with(messageText,commands["Create"])) {
      messageText = std::to_string(message.connection.playerIDConnectedToClientConnection) + "> " + /*handleCreateCommand(message)*/ + "\n";
      outgoing.push_back(Message{message.connection, messageText});
    }
    else if (boost::istarts_with(messageText,commands["Look"])) {
      messageText = this->model.lookCommand(message.connection.playerIDConnectedToClientConnection, message.text);
      outgoing.push_back(Message{message.connection, messageText});
    }
    else if (boost::istarts_with(messageText,commands["Go"])) {
      messageText = this->model.movePlayer(message.connection.playerIDConnectedToClientConnection, message.text.substr(3));
      outgoing.push_back(Message{message.connection, messageText});
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
    else {
      messageText = "That is an invalid command\n\n";
      outgoing.push_back(Message{message.connection, messageText});
      //Will output all other message types sent for now for testing purposes
      // std::for_each(clients.begin(), clients.end(), [&message,&outgoing] (Connection& c)
      //   { if(c.currentState == ConnectionState::AUTHORIZED) { outgoing.push_back(Message{c,std::string(std::to_string(message.connection.playerIDConnectedToClientConnection) + "> " + message.text + "\n")}); } });
    }
  }
  this->model.reset();
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
