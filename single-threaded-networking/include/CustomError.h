#ifndef custom_errors_h
#define custom_errors_h

#include <exception>

namespace custom_errors {

  struct NoSuchDoorException : public exception
  {
    const char * what () const throw ()
    {
      return "There is no passage leading in that direction.";
    }
  };

}

#endif /*custom_errors_h*/
