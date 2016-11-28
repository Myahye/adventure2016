#include "Fight.h"

Fight::Fight(Combatant& instigator, Combatant& target):
        instigatorCombatant{instigator}, targetCombatant{target}{};

void Fight::setInstigatorOverrideFlag(bool val){
  this->instigatorOverrideFlag = val;
}
void Fight::setTargetOverrideFlag(bool val){
  this->targetOverrideFlag = val;
}
