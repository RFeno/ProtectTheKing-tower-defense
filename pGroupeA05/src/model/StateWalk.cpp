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

bool StateWalk::attackKing()
{
    return false;
}

void StateWalk::die()
{
    this->enemy->changeState(new StateDie);
}
