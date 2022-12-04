/** States */
#include "State.h"
#include "StateWalk.h"
#include "StateAttack.h"
#include "Enemies.h"
#include "King.h"

#include <string>
#include <iostream>

class State;
class StateDie;

using namespace std;

Enemies::Enemies(int health, int marketValue, int scoreValue, int damage,float walkingSpeed)
: health(health),marketValue(marketValue),scoreValue(scoreValue),damage(damage), walkingSpeed(walkingSpeed)
{
    //ctor
    this->id = new int(++compteur);
    changeState(new StateWalk);
    counted=false;
    spawn=false;
    //enemies start at -50 to arrive naturally on the screen
    x=-50;
    y=0;
}

Enemies::~Enemies()
{
    //dtor
    delete id;
    delete state;
}

Enemies::Enemies(const Enemies& other): health(other.health),marketValue(other.marketValue),scoreValue(other.scoreValue),damage(other.damage),walkingSpeed(other.walkingSpeed),x(other.x),y(other.y)
{
   //copy ctor
   //est-ce correct d'avoir deux ennemis avec le même id ?
    this->id = new int(*other.id);
    this->counted=other.counted;
}

Enemies& Enemies::operator=(const Enemies& rhs)
{
    if (this == &rhs) return *this; // handle self assignment

    delete this->id;
    changeState(rhs.state);
    this->id=rhs.id;
    this->damage=rhs.damage;
    this->health=rhs.health;
    this->marketValue=rhs.marketValue;
    this->scoreValue=rhs.scoreValue;
    this->walkingSpeed=rhs.walkingSpeed;
    this->x=rhs.x;
    this->x=rhs.y;
    this->counted=rhs.counted;

    //assignment operator
    return *this;
}

/** this method decrease the health of the enemy if the health is lower of egal to 0 the enemy die */
void Enemies::receiveDamage(int damage)
{
    setHealth(health-damage);
}

/** this method changes the state of the enemy*/
void Enemies::changeState(State *state)
{
    if(this->state !=nullptr)
    {
        delete this->state;
    }

    this->state = state;
    this->state->setEnemy(this);
}

/** active walk of enemy, change his position x */
void Enemies::walk()
{
    this->state->walk();
}

/** the enemies attack the king*/
void Enemies::attackKing(King &king)
{
    this->state->attackKing(king);
}

/**change the health of enemy */
void Enemies::setHealth(int health)
{
    this->health=health;

    if(this->health<0)
    {
        this->health=0;
        die();
    }
}

/** changes de positions of enemy */
void Enemies::setX(float x)
{
    this->x = x;

    if(x >= King::xKing)
    {
        this->x = King::xKing;
        changeState(new StateAttack);
    }
}

/** change the state of enemies to dead */
void Enemies::die()
{
    this->state->die();
}

/** this method is called at the end of each wave and buffs the enemy to make it harder to kill */
void Enemies::improveStatistics(int numeroOfWave)
{
    this->setHealth(health*numeroOfWave*IMPROVE_LEVEL);
    healthMax=health;
}

/** changes the walking speed of enemy */
void Enemies::setWalkingSpeed(float speed)
{
    if(speed>0)
    {
        walkingSpeed = speed;
    }
}
