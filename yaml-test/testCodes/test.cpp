#include "yaml-cpp/yaml.h"
#include <stdio>
int main()
{
   YAML::Emitter out;
   out << "Hello, World!";

   std::cout << "Here's the output YAML:\n" << out.c_str(); // prints "Hello, World!"
   return 0;
}
