#include "StateAttack.h"
#include "StateDie.h"

#include <iostream>

using namespace std;

void StateAttack::walk()
{
     cout << "impossible is in attack mode, he canno't attack and walk at the same time" << endl;
}
void StateAttack::attackKing(King &king)
{
    //TODO
}

void StateAttack::die()
{
    this->enemy->changeState(new StateDie());
}
