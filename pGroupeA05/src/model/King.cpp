#include "King.h"
#include <string>

using namespace std;

King::King(int health): health(health),kingHealthMax(health)
{
    //ctor
    //this->kingHealthMax=health;
}

King::~King()
{
    //dtor
}

King::King(const King& other)
{
    //copy ctor
}

King& King::operator=(const King& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
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

string King::getInformations()const
{
    return "[King health:" + to_string(health) +"]";
}
