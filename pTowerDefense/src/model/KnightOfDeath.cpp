#include "KnightOfDeath.h"

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
