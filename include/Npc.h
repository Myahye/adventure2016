class Npc {
  int armor, exp, gold, id, level, thac0;
  string damage, hit, shortdesc;
  std::vector<string> description, keywords, longdesc;
public:
  Npc (int,string);
  int getId () {return (id);}

};
