#include "StateDie.h"
#include <iostream>

using namespace std;

void StateDie::walk()
{
    //impossible the enemy is die, he canno't walk
}

bool StateDie::attackKing()
{
    return false;
}

void StateDie::die()
{
    //cout << "impossible the enemy is already die";
}

