#include "StateDie.h"
#include <iostream>

using namespace std;
void StateDie::walk()
{
     cout << "impossible the enemy is die, he canno't walk" << endl;
}

void StateDie::attackKing(King &king)
{
    //TODO
    cout << "impossible the enemy is die, he canno't attack" << "ENNEMY => " << enemy->getInformations();
}

void StateDie::die()
{
    cout << "impossible the enemy is already die";
}

