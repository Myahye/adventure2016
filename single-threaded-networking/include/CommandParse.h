#ifndef commandparse_h
#define commandparse_h
//include "model.h"
#include <boost/asio.hpp>
#include <boost/algorithm/string/predicate.hpp>
#include <deque>
#include <functional>
#include <memory>
#include <string>
#include <unordered_map>
//#include "Server.h"
struct Connection2 {
  uintptr_t id;

  bool
  operator==(Connection2 other) const {
    return id == other.id;
  }
};
struct Message2 {
  Connection2 connection;
  std::string text;
};

class CommandParse {

private:



public:

  //CommandParse(pathtoyaml);
  CommandParse();

  std::deque<Message2>  parseCommands(const auto& clientMessageQueue,  std::vector<Connection2> clients);


};
#endif /* commandparse_h */
