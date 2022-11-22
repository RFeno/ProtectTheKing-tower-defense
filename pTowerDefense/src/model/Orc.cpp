#include "Orc.h"

Orc::Orc(int health, int attackSpeed, int marketValue, int scoreValue, int damage):Enemies(health,attackSpeed,marketValue,scoreValue,damage)
{
    //ctor
}

Orc::~Orc()
{
    //dtor

}

Orc::Orc(const Orc& other):Enemies(other)
{
    //copy ctor
}

Orc& Orc::operator=(const Orc& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

Orc* Orc::clone()const
{
    return new Orc(*this);
}
