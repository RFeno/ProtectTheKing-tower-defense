#include "Gremlin.h"
#include "Enemies.h"
Gremlin::Gremlin(int health, int attackSpeed, int marketValue, int scoreValue, int damage):Enemies(health,attackSpeed,marketValue,scoreValue,damage)
{
    //ctor
}

Gremlin::~Gremlin()
{
    //dtor
}

Gremlin::Gremlin(const Gremlin& other):Enemies(other)
{
    //copy ctor
}

Gremlin& Gremlin::operator=(const Gremlin& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}
