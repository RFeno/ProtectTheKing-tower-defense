#include "TowerSand.h"

TowerSand::TowerSand(int x, int y,int damage,int level,int price,int range):Tower(x,y,damage,level,price,range)
{
    this->type=sand;
}

TowerSand::~TowerSand()
{
    //dtor
}

TowerSand::TowerSand(const TowerSand& other)
{
    //copy ctor
}

TowerSand& TowerSand::operator=(const TowerSand& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

