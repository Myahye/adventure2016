#include <iostream>
#include "yaml-cpp/yaml.h"

using namespace std;

int main()
{
    YAML::Node config = YAML::LoadFile("shire.yaml");
    return 0;
}
