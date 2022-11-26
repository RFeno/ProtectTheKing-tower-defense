#include "vTower.h"
#include "TowerEarth.h"
#include "TowerSand.h"
#include "TowerIce.h"
#include "TowerIron.h"

#include <SFML/Graphics.hpp>

using namespace sf;

vTower::vTower(Vector2i* position, Tower* tower): position(position), tower(tower)
{
    //ctor
    this->towerSprite = new Sprite();
    this->attackSprite = new Sprite();
    this->animAttackClock = new Clock();
}

vTower::~vTower()
{
    //dtor
    delete tower;
    delete towerSprite;
    delete attackSprite;
    delete position;
    delete towerTexture;
    delete attackTexture;
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
    if(dynamic_cast<TowerEarth*>(tower))
    {
        towerSprite->setTexture(*towerTexture);
        towerSprite->setScale(0.20f,0.20f);
        towerSprite->setPosition(position->x, position->y);
        attackSprite->setTexture(*attackTexture);
        attackSprite->setPosition(position->x + 175, position->y - 10);
        attackSprite->setScale(0.5f,0.5f);
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

//void vTower::animAttack()
//{
//    if(animAttackClock.getElapsedTime().asSeconds() > 1)
//    {
//        if(animAttackClock.getElapsedTime().asSeconds() < 0.3f)
//        {
//
//        }
//    }
//}
