#include "KnightOfDeath.h"
#include <string>
using namespace std;
KnightOfDeath::KnightOfDeath(int health, int attackSpeed, int marketValue, int scoreValue, int damage):Enemies(health,attackSpeed,marketValue,scoreValue,damage)
{
    //ctor
}

KnightOfDeath::~KnightOfDeath()
{
    //dtor
}

KnightOfDeath::KnightOfDeath(const KnightOfDeath& other):Enemies(other)
{
    //copy ctor
}

KnightOfDeath& KnightOfDeath::operator=(const KnightOfDeath& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

KnightOfDeath* KnightOfDeath::clone()const
{
    return new KnightOfDeath(*this);
}

string KnightOfDeath::getInformations()const
{
    return "[id: "+ to_string(*id)+ "   KnightOfDeath x:"+ to_string(x) +"    health:" + to_string(health) + "    attackSpeed:" + to_string(attackSpeed) + "    market value:" + to_string(marketValue) + "    score value:" + to_string(scoreValue) + "]";
}
