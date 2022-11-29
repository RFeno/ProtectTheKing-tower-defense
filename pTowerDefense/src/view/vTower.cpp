#include "vTower.h"
#include "TowerEarth.h"
#include "TowerSand.h"
#include "TowerIce.h"
#include "TowerIron.h"

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

vTower::vTower(int x,int y, Tower* tower,int position): x(x), y(y), tower(tower), position(position)
{
    //ctor
    this->towerSprite = new Sprite();
    this->attackSprite = new Sprite();
    this->animAttackClock = new Clock();
}

vTower::~vTower()
{
    //dtor
    delete towerSprite;
    delete attackSprite;
    delete animAttackClock;
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
    towerSprite->setTexture(*towerTexture);
    towerSprite->setScale(0.9f,0.9f);
    if(dynamic_cast<TowerEarth*>(tower))
    {
        attackSprite->setTexture(*attackTexture);
        attackSprite->setScale(0.5f,0.5f);
        attackSprite->setPosition(x+48, y-60);
    }
    else
    {
        if(dynamic_cast<TowerSand*>(tower))
        {
            attackSprite->setTexture(*attackTexture);
            attackSprite->setScale(0.5f,0.5f);
            attackSprite->setPosition(x + 50, y - 50);
        }
        else
        {
            if(dynamic_cast<TowerIce*>(tower))
            {
                attackSprite->setTexture(*attackTexture);
                attackSprite->setScale(0.5f,0.5f);
                attackSprite->setPosition(x + 60, y - 70);
            }
            else
            {
                if(dynamic_cast<TowerIron*>(tower))
                {
                    attackSprite->setTexture(*attackTexture);
                    attackSprite->setScale(0.5f,0.5f);
                    attackSprite->setPosition(x+55, y-35);
                }
            }
        }
    }
    towerSprite->setPosition(x, y);
}

int vTower::calculateMiddlePosition()
{
    return towerTexture->getSize().x / 2 ;
}
