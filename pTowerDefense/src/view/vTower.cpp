#include "vTower.h"

#include <SFML/Graphics.hpp>

using namespace sf;

vTower::vTower(Vector2f* position, Sprite* sprite , Tower* tower, Texture* towerTexture): position(position), towerSprite(sprite), tower(tower), towerTexture(towerTexture)
{
    //ctor
    sprite->setTexture(*towerTexture);
}

vTower::~vTower()
{
    //dtor
    delete tower;
    delete towerSprite;
    delete position;
    //est ce neccessaire appel au constructeur de copy renvoie un nouveau pointeur ?
    //delete towerTexture;
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
