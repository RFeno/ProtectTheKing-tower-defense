#include "TowerIce.h"

TowerIce::TowerIce(int x, int y,int damage,int level,int price):Tower(damage,level,price)
{
    this->type=ice;
}

TowerIce::~TowerIce()
{
    //dtor
}

TowerIce::TowerIce(const TowerIce& other)
{
    //copy ctor
}

TowerIce& TowerIce::operator=(const TowerIce& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

