#include "TowerIron.h"

TowerIron::TowerIron(int x, int y,int damage,int level,int price):Tower(damage,level,price)
{
    this->type=iron;
}


TowerIron::~TowerIron()
{
    //dtor
}

TowerIron::TowerIron(const TowerIron& other)
{
    //copy ctor
}

TowerIron& TowerIron::operator=(const TowerIron& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}


