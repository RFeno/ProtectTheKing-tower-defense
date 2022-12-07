#include "Orc.h"
#include <string>

using namespace std;

Orc::Orc(int health, int marketValue, int scoreValue, int damage, float walkingSpeed):Enemies(health,marketValue,scoreValue,damage,walkingSpeed)
{
    //ctor

    y=525;
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

    Enemies::operator=(rhs);

    //assignment operator
    return *this;
}

/**return the state of the enemy (informations) */
string Orc::getInformations()const
{
    return "[id: "+ to_string(*id)+"      |Orc           x:"+ to_string(x) +"    health:" + to_string(health) + "    market value:" + to_string(marketValue) + "     score value:" + to_string(scoreValue) +"  walking speed:"+to_string(walkingSpeed) + " ]";
}

Orc* Orc::clone() const
{
    return new Orc(*this);
}
