#include "vTower.h"
#include "TowerEarth.h"
#include "TowerSand.h"
#include "TowerIce.h"
#include "TowerIron.h"

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

vTower::vTower(int x,int y): x(x), y(y)
{
    //ctor
    this->towerSprite = new Sprite();
    this->attackSprite = new Sprite();
}

vTower::~vTower()
{
    //dtor
    delete towerSprite;
    delete attackSprite;
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

void vTower::chargeInformations(Tower *tower)
{
    towerSprite->setTexture(*towerTexture);
    bulletSprite.setTexture(*attackTexture);
    attackSprite->setTexture(*attackTexture);
    towerSprite->setScale(0.9f,0.9f);

    if(dynamic_cast<TowerEarth*>(tower))
    {
        attackSprite->setScale(0.5f,0.5f);
        attackSprite->setPosition(x+48, y-60);
    }
    else
    {
        if(dynamic_cast<TowerSand*>(tower))
        {
            attackSprite->setScale(0.5f,0.5f);
            attackSprite->setPosition(x + 50, y - 50);
        }
        else
        {
            if(dynamic_cast<TowerIce*>(tower))
            {
                attackSprite->setScale(0.5f,0.5f);
                attackSprite->setPosition(x + 60, y - 70);
            }
            else
            {
                if(dynamic_cast<TowerIron*>(tower))
                {
                    attackSprite->setScale(0.5f,0.5f);
                    attackSprite->setPosition(x+55, y-35);
                }
            }
        }
    }

    towerSprite->setPosition(x, y);

    //because it's a clone
    delete tower;
}

int vTower::calculateMiddlePosition()
{
    return towerTexture->getSize().x / 2 ;
}

