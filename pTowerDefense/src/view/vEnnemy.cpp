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

vEnnemy::vEnnemy(Enemies *enemy): enemy(enemy)
{
    //ctor
    enemySprite = new Sprite();
}

vEnnemy::~vEnnemy()
{
    //dtor
    //the map delete the enemy
    delete enemySprite;
    delete healthBarGreenSprite;
    delete healthBarRedSprite;
}

vEnnemy::vEnnemy(const vEnnemy& other): enemy(other.enemy), enemySprite(other.enemySprite)
{
    //copy ctor
}

vEnnemy& vEnnemy::operator=(const vEnnemy& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

void vEnnemy::chargeInformations()
{
    if(dynamic_cast<Ogre*>(enemy))
    {
        enemySprite->setTexture(*ogreTextureWalk);
        enemySprite->setTextureRect(IntRect(0,0,OGRE_WIDTH,OGRE_HEIGHT));
        enemySprite->setPosition(Vector2f(-40, 510));
        enemySprite->setScale(0.28,0.28f);
    }
    else
    {
        if(dynamic_cast<Orc*>(enemy))
        {
            enemySprite->setTexture(*orcTextureWalk);
            enemySprite->setTextureRect(IntRect(0,0,ORC_WIDTH,ORC_HEIGHT));
            enemySprite->setPosition(Vector2f(-40, 520));
            enemySprite->setScale(0.28f,0.28f);
        }
        else
        {
            if(dynamic_cast<ShadowMonster*>(enemy))
            {
                enemySprite->setTexture(*shadowMonsterTextureWalk);
                enemySprite->setTextureRect(IntRect(0,0,SHADOWMONSTER_WIDTH,SHADOWMONSTER_HEIGHT));
                enemySprite->setPosition(Vector2f(-40, 527));
                enemySprite->setScale(0.28f,0.28f);
            }
            else
            {
                if(dynamic_cast<KnightOfDeath*>(enemy))
                {
                    enemySprite->setTexture(*knightOfDeathTextureWalk);
                    enemySprite->setTextureRect(IntRect(0,0,KNIGHTOFDEATH_WIDTH,KNIGHTOFDEATH_HEIGHT));
                    enemySprite->setPosition(Vector2f(-40, 493));
                    enemySprite->setScale(0.28f,0.28f);
                }
                else
                {
                    if(dynamic_cast<Gremlin*>(enemy))
                    {
                        enemySprite->setTexture(*gremlinTextureWalk);
                        enemySprite->setTextureRect(IntRect(0,0,GREMLIN_WIDTH,GREMLIN_HEIGHT));
                        enemySprite->setPosition(Vector2f(-40, 550));
                        enemySprite->setScale(0.28f,0.28f);
                    }
                }
            }
        }
    }
}

/*update the texture of enemy in terms of his state and his type of enemy */
void vEnnemy::updateTexture()
{
    if(dynamic_cast<Ogre*>(enemy))
    {

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
        if(dynamic_cast<StateWalk*>(enemy->getState()))
        {
            enemySprite->setTexture(*knightOfDeathTextureWalk);
        }
        else
        {
            enemySprite->setTexture(*knightOfDeathAttackTexture);
        }
    }
    else //if(dynamic_cast<Gremlin*>(enemy))
    {
        if(dynamic_cast<StateWalk*>(enemy->getState()))
        {
            enemySprite->setTexture(*gremlinTextureWalk);
        }
        else
        {
            enemySprite->setTexture(*gremlinAttackTexture);
        }
    }
}





