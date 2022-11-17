#include "vEnnemy.h"
#include <SFML/Graphics.hpp>

using namespace sf;

vEnnemy::vEnnemy(Enemies *enemy, Sprite *enemySprite, bool walk, bool animated, bool spawn, bool attack): enemy(enemy), enemySprite(enemySprite), walk(walk), animated(animated), spawn(spawn), attack(attack)
{
    //ctor
}

vEnnemy::~vEnnemy()
{
    //dtor
    //the map delete the enemy
    delete enemySprite;
}

vEnnemy::vEnnemy(const vEnnemy& other): enemy(other.enemy), enemySprite(other.enemySprite), walk(other.walk), animated(other.animated), spawn(other.spawn), attack(other.attack)
{
    //copy ctor
}

vEnnemy& vEnnemy::operator=(const vEnnemy& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}
