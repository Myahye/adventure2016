#ifndef FIGHT_H
#define FIGHT_H

#include "Combatant.h"


class Fight{

private:
  bool targetOverrideFlag = false;
  bool instigatorOverrideFlag = false;


public:
  Fight(Combatant instigator, Combatant target, int roomID);

	// Combatant getInstigatorCombatant();
  // Combatant getTargetCombatant();
	Combatant instigatorCombatant;
  Combatant targetCombatant;

  int roomID;
  void setInstigatorOverrideFlag(bool);
  bool getInstigatorOverrideFlag() const;


  void setTargetOverrideFlag(bool);
  bool getTargetOverrideFlag() const;

};

#endif /* FIGHT_H */
