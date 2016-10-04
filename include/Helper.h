class Helper {
  std::vector<> Npcs;
public:
  Helper();
  Helper(std::vector<Npc>);

  boolean createNpc(int, string);
  Npc getNpc (int);
};
