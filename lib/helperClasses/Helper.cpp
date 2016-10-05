#include "Helper.h"

Helper::Helper() {}

Helper::Helper(std::vector<std::string> asdf){
  this.Npcs = asdf;
}
vector<string> Helper::Npcs;


//Need to add error codes
bool createNpc(int id, string shortdesc){
  for(NPC &npc : Npcs){
    if(npc.getId == id){
      return false;
    }
  }
  NPC npc (id, shortdesc);
  Npcs.push_back(npc);
  return true;
}
