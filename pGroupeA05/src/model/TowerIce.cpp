#include "TowerIce.h"

TowerIce::TowerIce(int x, int y,int damage,int level,int price,int range):Tower(x,y,damage,level,price,range)
{
    this->type=ice;
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

