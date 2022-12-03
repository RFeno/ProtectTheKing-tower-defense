#include "TowerSand.h"

TowerSand::TowerSand(int x, int y,int position, int damage,int level,int price,int range):Tower(x,y,damage,level,price,range,position)
{
    this->type=sand;
}

TowerSand::~TowerSand()
{
    //dtor
}

TowerSand::TowerSand(const TowerSand& other):Tower(other)
{
    //copy ctor
}

TowerSand& TowerSand::operator=(const TowerSand& rhs)
{
    if (this == &rhs) return *this; // handle self assignment

    Tower::operator=(rhs);

    //assignment operator
    return *this;
}

