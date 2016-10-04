#include "Helper.h"
#include<cstring>
#include <vector>

using namespace std;

Helper::Helper(){

}

Helper::Helper(vector<string> Npcs){
  this.Npcs = Npcs;
}

//Need to add error codes
boolean createNpc(int id, string shortdesc){
  for(Npc &npc : Npcs){
    if(npc.getId == id){
      return false;
    }
  }
  Npc npc (id, shortdesc);
  Npcs.push_back(npc);
  return true;
}
