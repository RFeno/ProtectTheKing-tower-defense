#include "Gremlin.h"
#include "Enemies.h"
#include <string.h>

using namespace std;

Gremlin::Gremlin(int health, int attackSpeed, int marketValue, int scoreValue, int damage):Enemies(health,attackSpeed,marketValue,scoreValue,damage)
{
    //ctor
    y=555;
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

Gremlin* Gremlin::clone()const
{
    return new Gremlin(*this);
}

string Gremlin::getInformations()const
{
    return "[id: "+ to_string(*id)+ "   Gremlin       x:"+ to_string(x) +"    health:" + to_string(health) + "    attackSpeed:" + to_string(attackSpeed) + "    market value:" + to_string(marketValue) + "     score value:" + to_string(scoreValue) + " ]";
}
