#include "TowerIce.h"

TowerIce::TowerIce(int x, int y,int position,int damage,int level,int price,int range):Tower(x,y,damage,level,price,range,position)
{
    this->type=ice;
    this->attackActivated=false;
}

TowerIce::~TowerIce()
{
    //dtor
}

TowerIce::TowerIce(const TowerIce& other):Tower(other)
{
    //copy ctor
}

TowerIce& TowerIce::operator=(const TowerIce& rhs)
{
    if (this == &rhs) return *this; // handle self assignment

    Tower::operator=(rhs);

    //assignment operator
    return *this;
}

/** clone the tower */
TowerIce* TowerIce::clone()const
{
    return new TowerIce(*this);
}

