#include "Observable.h"

Observable::Observable()
{
    //ctor
}

Observable::~Observable()
{
    //dtor
}

Observable::Observable(const Observable& other)
{
    //copy ctor
}

Observable& Observable::operator=(const Observable& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}
