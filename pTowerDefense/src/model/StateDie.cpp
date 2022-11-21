#include "StateDie.h"
#include <iostream>

using namespace std;
void StateDie::walk(int x)
{
     cout << "impossible the enemy is die, he canno't walk";
}

void StateDie::attackKing(King &king)
{
    //TODO
    cout << "impossible the enemy is die, he canno't attack";
}

void StateDie::die()
{
    cout << "impossible the enemy is already die";
}

