#include "Ogre.h"

Ogre::Ogre(int health, int attackSpeed, int marketValue, int scoreValue, int damage):Enemies(health,attackSpeed,marketValue,scoreValue,damage)
{
    //ctor
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
    //assignment operator
    return *this;
}

Ogre* Ogre::clone()const
{
    return new Ogre(*this);
}
