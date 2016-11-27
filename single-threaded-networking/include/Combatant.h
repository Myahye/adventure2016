#ifndef COMBATANT_H
#define COMBATANT_H

class Combatant {
private:
  bool isNpc;
  networking::Connection connection;

public:
  Combatant(bool isNpc_, networking::Connection* connection_, Character* character_);

  bool isNpc();
  networking::message sendMessage(String message);
  void attack(int amount);

}

#endif /* COMBATANT_H */
