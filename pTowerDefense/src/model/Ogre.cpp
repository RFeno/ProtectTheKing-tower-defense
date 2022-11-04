#include "Ogre.h"

Ogre::Ogre()
{
    //ctor
}

Ogre::~Ogre()
{
    //dtor
}

Ogre::Ogre(const Ogre& other)
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
