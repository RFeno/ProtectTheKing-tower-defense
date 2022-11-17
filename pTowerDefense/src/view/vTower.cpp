#include "vTower.h"

#include <SFML/Graphics.hpp>

using namespace sf;

vTower::vTower(int x, int y, Sprite* sprite , Tower* tower): x(x), y(y), towerSprite(sprite), tower(tower)
{
    //ctor
}

vTower::~vTower()
{
    //dtor
    delete tower;
    delete towerSprite;
}

vTower::vTower(const vTower& other)
{
    //copy ctor
}

vTower& vTower::operator=(const vTower& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}
