#include "vTower.h"
#include "TowerEarth.h"
#include "TowerSand.h"
#include "TowerIce.h"
#include "TowerIron.h"

#include <SFML/Graphics.hpp>

using namespace sf;

vTower::vTower(Vector2f* position, Sprite* sprite , Tower* tower): position(position), towerSprite(sprite), tower(tower)
{
    //ctor
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

void vTower::chargeInformations()
{
    if(dynamic_cast<TowerEarth*>(tower))
    {
        towerSprite->setTexture(*towerTexture);
    }
    else
    {
        if(dynamic_cast<TowerSand*>(tower))
        {
            towerSprite->setTexture(*towerTexture);
        }
        else
        {
            if(dynamic_cast<TowerIce*>(tower))
            {
                towerSprite->setTexture(*towerTexture);
            }
            else
            {
                if(dynamic_cast<TowerIron*>(tower))
                {
                    towerSprite->setTexture(*towerTexture);
                }
            }
        }
    }
}
