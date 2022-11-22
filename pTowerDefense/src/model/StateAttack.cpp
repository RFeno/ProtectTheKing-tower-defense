#include "StateAttack.h"
#include "StateDie.h"

#include <iostream>

using namespace std;

void StateAttack::walk()
{
     cout << "impossible a enemy canno't walk and attack at the same time";
}

void StateAttack::attackKing(King &king)
{
    //TODO
}

void StateAttack::die()
{
    this->enemy->changeState(new StateDie());
}
