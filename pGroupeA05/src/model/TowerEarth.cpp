#include "TowerEarth.h"
#include <iostream>

TowerEarth::TowerEarth(int x, int y,int position, int damage,int level,int price,int range):Tower(x,y,damage,level,price,range,position)
{
    this->type=earth;
}

TowerEarth::~TowerEarth()
{
    //dtor
}

TowerEarth::TowerEarth(const TowerEarth& other):Tower(other)
{
    //copy ctor

}

TowerEarth& TowerEarth::operator=(const TowerEarth& rhs)
{
    if (this == &rhs) return *this; // handle self assignment

    Tower::operator=(rhs);

    //assignment operator
    return *this;
}

/** clone the tower */
TowerEarth* TowerEarth::clone()const
{
    return new TowerEarth(*this);
}









