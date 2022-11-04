#include "ShadowMonster.h"

ShadowMonster::ShadowMonster()
{
    //ctor
}

ShadowMonster::~ShadowMonster()
{
    //dtor
}

ShadowMonster::ShadowMonster(const ShadowMonster& other)
{
    //copy ctor
}

ShadowMonster& ShadowMonster::operator=(const ShadowMonster& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

ShadowMonster* ShadowMonster::clone()const
{
    return new ShadowMonster(*this);
}
