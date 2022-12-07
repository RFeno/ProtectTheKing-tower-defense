#include "King.h"
#include <string>

using namespace std;

King::King(int health): health(health),kingHealthMax(health)
{
    //ctor
    this->kingHealthMax=health;
}

King::~King()
{
    //dtor
}

King::King(const King& other): health(other.health),kingHealthMax(other.health)
{
    //copy ctor
}

King& King::operator=(const King& rhs)
{
    if (this == &rhs) return *this; // handle self assignment

    this->health=rhs.health;
    this->kingHealthMax=rhs.kingHealthMax;

    //assignment operator
    return *this;
}

void King::setHealth(int health)
{
    this->health=health;

    if(this->health<0)
    {
        this->health=0;
    }
}

void King::receiveDamage(int damage)
{
    setHealth(health-damage);
}

/**return the health of the king */
string King::getInformations()const
{
    return "[King health:" + to_string(health) +"]";
}

King *King::clone()const
{
    return new King(*this);
}
