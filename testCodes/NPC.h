#include <string>
#include <fstream>
#include "yaml-cpp/yaml.h"

class NPC
{
public:
  NPC(std::string NPC_Info);

  int getArmor();
  std::string getDamage();
  std::string getDescription();
  int getExperience();
  int getGold();
  std::string getHit();
  int getId();
  std::string getKeywords();
  int getLevel();
  std::string getLongdesc();
  std::string getShortdesc();
  int getThac0();

private:
  int armor;
  std::string damage;
  std::string description;
  int experience;
  int gold;
  std::string hit;
  int id;
  std::string keywords;
  int level;
  std::string longdesc;
  std:string shortdesc;
  int thac0;
}
