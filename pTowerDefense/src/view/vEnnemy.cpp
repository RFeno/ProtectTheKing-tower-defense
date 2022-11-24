#include "vEnnemy.h"
#include <SFML/Graphics.hpp>

#include "Ogre.h"
#include "Orc.h"
#include "ShadowMonster.h"
#include "KnightOfDeath.h"
#include "Gremlin.h"

#include <string>
#include <iostream>

using namespace sf;
using namespace std;

vEnnemy::vEnnemy(Enemies *enemy, Sprite *enemySprite, bool walk, bool animated, bool spawn, bool attack, bool dead): enemy(enemy), enemySprite(enemySprite), walk(walk), animated(animated), spawn(spawn), attack(attack), dead(dead)
{
    //ctor
}

vEnnemy::~vEnnemy()
{
    //dtor
    //the map delete the enemy
    delete enemySprite;
    delete healthBarGreenSprite;
    delete healthBarRedSprite;
}

vEnnemy::vEnnemy(const vEnnemy& other): enemy(other.enemy), enemySprite(other.enemySprite), walk(other.walk), animated(other.animated), spawn(other.spawn), attack(other.attack), dead(other.dead)
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

/*void vEnnemy::loadImages()
{
    if(!ogreTextureWalk->loadFromFile("res/images/sprites/1/1_enemies_1_WALK_spritesheet.png"))
    {
        cout << "ERROR chargement texture" << endl;
    }

    if(!orcTextureWalk->loadFromFile("res/images/sprites/2/spritesheet_WALK.png"))
    {
        cout << "ERROR chargement texture" << endl;

    }

    if (!gremlinTextureWalk->loadFromFile("res/images/sprites/3/spritesheet_WALK.png"))
    {
        cout << "ERROR chargement texture" << endl;

    }

    if (!shadowMonsterTextureWalk->loadFromFile("res/images/sprites/5/spritesheet_WALK.png"))
    {
        cout << "ERROR chargement texture" << endl;

    }

    if (!knightOfDeathTextureWalk->loadFromFile("res/images/sprites/9/spritesheet_WALK.png"))
    {
        cout << "ERROR chargement texture" << endl;

    }

    if (!ogreAttackTexture->loadFromFile("res/images/sprites/1/1_enemies_1_ATTACK_spritesheet.png"))
    {
        cout << "ERROR chargement texture" << endl;
    }


    if (!orcAttackTexture->loadFromFile("res/images/sprites/2/spritesheet_ATTACK.png"))
    {
        cout << "ERROR chargement texture" << endl;
    }

    if (!gremlinAttackTexture->loadFromFile("res/images/sprites/3/spritesheet_ATTACK.png"))
    {
        cout << "ERROR chargement texture" << endl;
    }

    if (!shadowMonsterAttackTexture->loadFromFile("res/images/sprites/5/spritesheet_ATTACK.png"))
    {
        cout << "ERROR chargement texture" << endl;
    }

    if (!knightOfDeathAttackTexture->loadFromFile("res/images/sprites/9/spritesheet_ATTACK.png"))
    {
        cout << "ERROR chargement texture" << endl;
    }

    if (!ogreDeadTexture->loadFromFile("res/images/sprites/1/1_enemies_1_DIE_spritesheet.png"))
    {
        cout << "ERROR chargement texture" << endl;
    }

    if (!orcDeadTexture->loadFromFile("res/images/sprites/2/spritesheet_DIE.png"))
    {
        cout << "ERROR chargement texture" << endl;
    }

    if (!gremlinDeadTexture->loadFromFile("res/images/sprites/3/spritesheet_DIE.png"))
    {
        cout << "ERROR chargement texture" << endl;
    }

    if (!shadowMonsterDeadTexture->loadFromFile("res/images/sprites/5/spritesheet_DIE.png"))
    {
        cout << "ERROR chargement texture" << endl;
    }

    if (!knightOfDeathDeadTexture->loadFromFile("res/images/sprites/9/spritesheet_DIE.png"))
    {
        cout << "ERROR chargement texture" << endl;

    }
}*/


