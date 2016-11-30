#ifndef FIGHT_H
#define FIGHT_H

#include "Combatant.h"


class Fight{

public:
  Fight(Combatant instigator, Combatant target, int roomID);

	// Combatant getInstigatorCombatant();
  // Combatant getTargetCombatant();
	Combatant instigatorCombatant;
  Combatant targetCombatant;
  bool targetOverrideFlag;
  bool instigatorOverrideFlag;
  int roomID;
  void setInstigatorOverrideFlag(bool);
  void setTargetOverrideFlag(bool);
};

#endif /* FIGHT_H */
