#include "ShadowMonster.h"

ShadowMonster::ShadowMonster(int health, int attackSpeed, int marketValue, int scoreValue, int damage):Enemies(health,attackSpeed,marketValue,scoreValue,damage)
{
    //ctor
}

ShadowMonster::~ShadowMonster()
{
    //dtor
}

ShadowMonster::ShadowMonster(const ShadowMonster& other):Enemies(other)
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
