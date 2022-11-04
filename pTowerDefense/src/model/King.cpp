#include "King.h"

King::King()
{
    numberOfLives = 10;
    //ctor
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
