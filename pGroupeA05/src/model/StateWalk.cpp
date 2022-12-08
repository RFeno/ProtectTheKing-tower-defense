#include "StateWalk.h"
#include <iostream>
#include "StateDie.h"

using namespace std;

void StateWalk::walk()
{
    if(this->enemy->isSpawn())
    {
        this->enemy->setX(enemy->getX()+enemy->getWalkingSpeed());
    }
}

void StateWalk::attackKing(King &king)
{
    //impossible a enemy canno't walk and attack at the same time
}

void StateWalk::die()
{
    this->enemy->changeState(new StateDie);
}
