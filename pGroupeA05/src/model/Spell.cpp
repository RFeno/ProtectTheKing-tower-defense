#include "Spell.h"

Spell::Spell()
{
    //ctor
}

Spell::~Spell()
{
    //dtor
}

Spell::Spell(const Spell& other)
{
    //copy ctor
}

Spell& Spell::operator=(const Spell& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}
