#include <iostream>
#include "yaml-cpp/yaml.h"

using namespace std;

int main()
{
    YAML::Node config = YAML::LoadFile("shire.yml");
    return 0;
}
