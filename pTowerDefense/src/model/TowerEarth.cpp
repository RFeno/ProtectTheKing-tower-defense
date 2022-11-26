#include "TowerEarth.h"

TowerEarth::TowerEarth(int x, int y, int damage,int level,int price):Tower(x,y,damage,level,price)
{
    this->type=earth;
    this->range=20;

    //to delete
    this->xTower=300;
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









