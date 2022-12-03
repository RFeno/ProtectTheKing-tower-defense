#include "TowerIron.h"

TowerIron::TowerIron(int x, int y,int position,int damage,int level,int price,int range):Tower(x,y,damage,level,price,range,position)
{
    this->type=iron;
}


TowerIron::~TowerIron()
{
    //dtor
}

TowerIron::TowerIron(const TowerIron& other): Tower(other)
{
    //copy ctor
}

TowerIron& TowerIron::operator=(const TowerIron& rhs)
{
    if (this == &rhs) return *this; // handle self assignment

    Tower::operator=(rhs);

    //assignment operator
    return *this;
}


