#include "Fight.h"

Fight::Fight(Combatant instigator_, Combatant target_, int roomID_):
        instigatorCombatant{instigator_}, targetCombatant{target_}, roomID{roomID_}{};

void Fight::setInstigatorOverrideFlag(bool val){
  this->instigatorOverrideFlag = val;
}
bool Fight::getInstigatorOverrideFlag() const {
  return this->instigatorOverrideFlag;
}

void Fight::setTargetOverrideFlag(bool val){
  this->targetOverrideFlag = val;
}

bool Fight::getTargetOverrideFlag() const {
  return this->targetOverrideFlag;
}
