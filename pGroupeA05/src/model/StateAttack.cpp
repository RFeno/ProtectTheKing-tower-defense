#include "StateAttack.h"
#include "StateDie.h"

#include <iostream>

using namespace std;

void StateAttack::walk()
{
    //impossible the enemy is in attack mode, he canno't attack and walk at the same time
}
void StateAttack::attackKing(King &king)
{
    //TODO
    king.receiveDamage(this->enemy->getDamage());
}

void StateAttack::die()
{
    this->enemy->changeState(new StateDie());
}
