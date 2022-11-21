#include "StateWalk.h"
#include <iostream>

using namespace std;

/*StateWalk::StateWalk()
{
    //ctor
}

StateWalk::~StateWalk()
{
    //dtor
}

StateWalk::StateWalk(const StateWalk& other)
{
    //copy ctor
}

StateWalk& StateWalk::operator=(const StateWalk& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}*/

void StateWalk::walk(int x)
{
    this->enemy->setX(x);
}

void StateWalk::attackKing(King &king)
{
    cout << "impossible a enemy canno't walk and attack at the same time";
}

void StateWalk::die()
{
    //TODO
}
