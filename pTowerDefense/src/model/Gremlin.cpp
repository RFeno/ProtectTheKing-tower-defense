#include "Gremlin.h"

Gremlin::Gremlin()
{
    //ctor
}

Gremlin::~Gremlin()
{
    //dtor
}

Gremlin::Gremlin(const Gremlin& other)
{
    //copy ctor
}

Gremlin& Gremlin::operator=(const Gremlin& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}
