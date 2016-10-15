#ifndef commandparse_h
#define commandparse_h
//include "model.h"
#include <boost/algorithm/string/predicate.hpp>

#include "Server.h"



class CommandParse {

private:



public:

  //CommandParse(pathtoyaml);
  CommandParse();

  std::deque<networking::Message>  parseCommands(const std::deque<networking::Message>& clientMessageQueue,  std::vector<networking::Connection>& clients);


};
#endif /* commandparse_h */
