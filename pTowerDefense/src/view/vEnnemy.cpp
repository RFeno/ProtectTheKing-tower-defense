#include "vEnnemy.h"
#include <SFML/Graphics.hpp>

using namespace sf;

vEnnemy::vEnnemy(Enemies *enemy, Sprite *enemySprite, bool walk, bool animated, bool spawn): enemy(enemy), enemySprite(enemySprite), walk(walk), animated(animated), spawn(spawn)
{
    //ctor
    /*enemy=nullptr;
    enemySprite=nullptr;*/
    spawn=false;
    walk=false;
    animated=false;
}

vEnnemy::~vEnnemy()
{
    //dtor
}

vEnnemy::vEnnemy(const vEnnemy& other): enemy(other.enemy), enemySprite(other.enemySprite), walk(other.walk), animated(other.animated), spawn(other.spawn)
{
    //copy ctor
}

vEnnemy& vEnnemy::operator=(const vEnnemy& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}
