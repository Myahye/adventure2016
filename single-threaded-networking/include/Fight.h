#ifndef FIGHT_H
#define FIGHT_H

class Fight{

public:
  Fight(Combatant instigator, Combatant target);
  Combatant instigatorCombatant;
  Combatant targetCombatant;
  bool targetOverrideFlag
  bool instigatorOverrideFlag
  void setInstigatorOverrideFlag(bool);
  void setTargetOverrideFlag(bool);
}

#endif /* FIGHT_H */
