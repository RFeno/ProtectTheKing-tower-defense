#include "TowerEarth.h"

TowerEarth::TowerEarth(int damage,int level,int price):Tower(damage,level,price)
{
    //this->type=earth;
    setType(earth);
}

TowerEarth::~TowerEarth()
{
    //dtor
}

TowerEarth::TowerEarth(const TowerEarth& other)
{
    //copy ctor
}

TowerEarth& TowerEarth::operator=(const TowerEarth& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

// don't forget to delete
TowerEarth* TowerEarth::clone()const
{
    return new TowerEarth(*this);
}









