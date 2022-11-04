#include "KnightOfDeath.h"

KnightOfDeath::KnightOfDeath()
{
    //ctor
}

KnightOfDeath::~KnightOfDeath()
{
    //dtor
}

KnightOfDeath::KnightOfDeath(const KnightOfDeath& other)
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
