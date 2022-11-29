#include "Ogre.h"
#include <string>

using namespace std;

Ogre::Ogre(int health, float attackSpeed, int marketValue, int scoreValue, int damage,float walkingSpeed):Enemies(health,attackSpeed,marketValue,scoreValue,damage,walkingSpeed)
{
    //ctor
    y=517;
}

Ogre::~Ogre()
{
    //dtor
}

Ogre::Ogre(const Ogre& other):Enemies(other)
{
    //copy ctor

}

Ogre& Ogre::operator=(const Ogre& rhs)
{
    if (this == &rhs) return *this; // handle self assignment

    Enemies::operator=(rhs);

    //assignment operator
    return *this;
}


string Ogre::getInformations()const
{
    return "[id: "+ to_string(*id)+"      |Ogre          x:"+ to_string(x) +"    health:" + to_string(health) + "    attackSpeed:" + to_string(attackSpeed) + "    market value:" + to_string(marketValue) + "     score value:" + to_string(scoreValue) + " walking speed:"+to_string(walkingSpeed) + " ]";
}

