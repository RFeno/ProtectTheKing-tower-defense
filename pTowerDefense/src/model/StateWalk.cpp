#include "StateWalk.h"
#include <iostream>
#include "StateDie.h"

using namespace std;

void StateWalk::walk()
{
    if(this->enemy->isSpawn())
    {
        this->enemy->setX(enemy->getX()+enemy->WALK_SPEED);
    }
}

void StateWalk::attackKing(King &king)
{
    //cout << "impossible a enemy canno't walk and attack at the same time" << endl;
}

void StateWalk::die()
{
    this->enemy->changeState(new StateDie);
}
