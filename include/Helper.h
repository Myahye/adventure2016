#include "NPC.h"
#include <string>
#include <vector>
using namespace std;

class Helper {
  static vector<string> Npcs;

public:

  Helper();
  Helper(vector<NPC>);
  //bool createNpc();
  bool createNpc(int, string);
  NPC getNpc (int);
};
