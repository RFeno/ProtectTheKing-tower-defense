#include "vEnnemy.h"
#include <SFML/Graphics.hpp>

#include "Ogre.h"
#include "Orc.h"
#include "ShadowMonster.h"
#include "KnightOfDeath.h"
#include "Gremlin.h"

#include "StateAttack.h"
#include "StateWalk.h"

#include <string>
#include <iostream>

using namespace sf;
using namespace std;

vEnnemy::vEnnemy()
{
    //ctor
    enemySprite = new Sprite();
    healthBarRedSprite.setScale(0.08f,0.08f);
    healthBarGreenSprite.setScale(0.08,0.08f);

}

vEnnemy::~vEnnemy()
{
    //dtor
    delete enemySprite;
}

vEnnemy::vEnnemy(const vEnnemy& other):enemySprite(other.enemySprite)
{
    //copy ctor
}

vEnnemy& vEnnemy::operator=(const vEnnemy& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

/**give texture to vEnemy and configure it */
void vEnnemy::chargeInformations(Enemies *enemy)
{
    //health bar
    healthBarGreenSprite.setTexture(*healthBarGreenTexture);
    healthBarRedSprite.setTexture(*healthBarRedTexture);

    //enemies
    if(dynamic_cast<Ogre*>(enemy))
    {
        healthBarRedSprite.setPosition(enemy->getX()+5,enemy->getY()-3);
        healthBarGreenSprite.setPosition(enemy->getX()+5,enemy->getY()-3);
        enemySprite->setTexture(*ogreTextureWalk);
        enemySprite->setTextureRect(IntRect(0,0,OGRE_WIDTH,OGRE_HEIGHT));
        enemySprite->setPosition(Vector2f(-40, 510));
        enemySprite->setScale(0.28,0.28f);
    }
    else
    {
        if(dynamic_cast<Orc*>(enemy))
        {
            healthBarRedSprite.setPosition(enemy->getX()+2,enemy->getY()-5);
            healthBarGreenSprite.setPosition(enemy->getX()+2,enemy->getY()-5);
            enemySprite->setTexture(*orcTextureWalk);
            enemySprite->setTextureRect(IntRect(0,0,ORC_WIDTH,ORC_HEIGHT));
            enemySprite->setPosition(Vector2f(-40, 520));
            enemySprite->setScale(0.28f,0.28f);
        }
        else
        {
            if(dynamic_cast<ShadowMonster*>(enemy))
            {
                healthBarRedSprite.setPosition(enemy->getX()+5,enemy->getY()-5);
                healthBarGreenSprite.setPosition(enemy->getX()+5,enemy->getY()-5);
                enemySprite->setTexture(*shadowMonsterTextureWalk);
                enemySprite->setTextureRect(IntRect(0,0,SHADOWMONSTER_WIDTH,SHADOWMONSTER_HEIGHT));
                enemySprite->setPosition(Vector2f(-40, 527));
                enemySprite->setScale(0.28f,0.28f);
            }
            else
            {
                if(dynamic_cast<KnightOfDeath*>(enemy))
                {
                    healthBarRedSprite.setPosition(enemy->getX()+5,enemy->getY()+12);
                    healthBarGreenSprite.setPosition(enemy->getX()+5,enemy->getY()+12);
                    enemySprite->setTexture(*knightOfDeathTextureWalk);
                    enemySprite->setTextureRect(IntRect(0,0,KNIGHTOFDEATH_WIDTH,KNIGHTOFDEATH_HEIGHT));
                    enemySprite->setPosition(Vector2f(-40, 493));
                    enemySprite->setScale(0.28f,0.28f);
                }
                else
                {
                    healthBarRedSprite.setPosition(enemy->getX()-4,enemy->getY()-10);
                    healthBarGreenSprite.setPosition(enemy->getX()-4,enemy->getY()-10);
                    enemySprite->setTexture(*gremlinTextureWalk);
                    enemySprite->setTextureRect(IntRect(0,0,GREMLIN_WIDTH,GREMLIN_HEIGHT));
                    enemySprite->setPosition(Vector2f(-40, 550));
                    enemySprite->setScale(0.28f,0.28f);
                }
            }
        }
    }

    //since we receive a clone, we delete it
    delete enemy;
}

/**update the texture of enemy in terms of his state and his type of enemy, his state of enemy and bind postion with model */
void vEnnemy::updateTexture(Enemies *enemy)
{
    //bind position of sprite to model position
    enemySprite->setPosition(enemy->getX(),enemy->getY());

    if(dynamic_cast<Ogre*>(enemy))
    {
        healthBarRedSprite.setPosition(enemy->getX()+5,enemy->getY()-3);
        healthBarGreenSprite.setPosition(enemy->getX()+5,enemy->getY()-3);

        if(dynamic_cast<StateWalk*>(enemy->getState()))
        {
            enemySprite->setTexture(*ogreTextureWalk);
        }
        else
        {
            enemySprite->setTexture(*ogreAttackTexture);
        }
    }
    else if(dynamic_cast<Orc*>(enemy))
    {
        healthBarRedSprite.setPosition(enemy->getX()+2,enemy->getY()-5);
        healthBarGreenSprite.setPosition(enemy->getX()+2,enemy->getY()-5);

        if(dynamic_cast<StateWalk*>(enemy->getState()))
        {
            enemySprite->setTexture(*orcTextureWalk);
        }
        else
        {
            enemySprite->setTexture(*orcAttackTexture);
        }
    }
    else if(dynamic_cast<ShadowMonster*>(enemy))
    {
        healthBarRedSprite.setPosition(enemy->getX()+5,enemy->getY()-5);
        healthBarGreenSprite.setPosition(enemy->getX()+5,enemy->getY()-5);

        if(dynamic_cast<StateWalk*>(enemy->getState()))
        {
            enemySprite->setTexture(*shadowMonsterTextureWalk);
        }
        else
        {
            enemySprite->setTexture(*shadowMonsterAttackTexture);
        }
    }
    else if(dynamic_cast<KnightOfDeath*>(enemy))
    {
        healthBarRedSprite.setPosition(enemy->getX()+5,enemy->getY()+12);
        healthBarGreenSprite.setPosition(enemy->getX()+5,enemy->getY()+12);

        if(dynamic_cast<StateWalk*>(enemy->getState()))
        {
            enemySprite->setTexture(*knightOfDeathTextureWalk);
        }
        else
        {
            enemySprite->setTexture(*knightOfDeathAttackTexture);
        }
    }
    else
    {
        healthBarRedSprite.setPosition(enemy->getX()-4,enemy->getY()-10);
        healthBarGreenSprite.setPosition(enemy->getX()-4,enemy->getY()-10);
        if(dynamic_cast<StateWalk*>(enemy->getState()))
        {
            enemySprite->setTexture(*gremlinTextureWalk);
        }
        else
        {
            enemySprite->setTexture(*gremlinAttackTexture);
        }
    }

    //since we receive a clone, we delete it
    delete enemy;
}

/**update the health bar of the sprite */
void vEnnemy::updateHealth(Enemies *enemy)
{
    double healthMax = enemy->getHealthMax();
    double healthReel = enemy->getHealth();
    double remainingHealth = ( healthReel  / healthMax );

    //0.08f is the widht per default for the health bar
    healthBarGreenSprite.setScale(Vector2f(0.08*remainingHealth,0.08));

    //since we receive a clone, we delete it
    delete enemy;
}





