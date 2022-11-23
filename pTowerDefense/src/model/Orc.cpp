#include "Orc.h"
#include <string>

using namespace std;

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

string Orc::getInformations()const
{
    return "[id: "+ to_string(*id)+"   Orc           x:"+ to_string(x) +"    health:" + to_string(health) + "    attackSpeed:" + to_string(attackSpeed) + "    market value:" + to_string(marketValue) + "     score value:" + to_string(scoreValue) + " ]";
}
