#include "StateAttack.h"
#include "StateDie.h"

#include <iostream>

using namespace std;

void StateAttack::walk()
{
    //impossible the enemy is in attack mode, he canno't attack and walk at the same time
}
bool StateAttack::attackKing()
{
    return true;
}

void StateAttack::die()
{
    this->enemy->changeState(new StateDie());
}
