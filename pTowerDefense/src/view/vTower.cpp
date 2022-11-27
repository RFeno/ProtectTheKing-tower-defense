#include "vTower.h"
#include "TowerEarth.h"
#include "TowerSand.h"
#include "TowerIce.h"
#include "TowerIron.h"

#include <SFML/Graphics.hpp>

using namespace sf;

vTower::vTower(int x,int y, Tower* tower): x(x), y(y), tower(tower)
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
    /** gros pourquoi tu setScale si c'est une tour de terre
    j'ai mis le set postions en bas vu que c'est le même pour toutes les tours*/
    if(dynamic_cast<TowerEarth*>(tower))
    {
        towerSprite->setTexture(*towerTexture);
        attackSprite->setTexture(*attackTexture);
        attackSprite->setScale(0.5f,0.5f);
        attackSprite->setPosition(x + 175, y - 10);
        towerSprite->setScale(0.20f,0.20f);
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
    towerSprite->setPosition(x, y);

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
