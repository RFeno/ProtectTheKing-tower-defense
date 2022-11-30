#include "Enemies.h"
#include "King.h"

/** States */
#include "State.h"
#include "StateDie.h"
#include "StateWalk.h"
#include "StateAttack.h"

#include <string>

class State;
class StateDie;

using namespace std;

Enemies::Enemies(int health, int marketValue, int scoreValue, int damage,float walkingSpeed)
: health(health),marketValue(marketValue),scoreValue(scoreValue),damage(damage), walkingSpeed(walkingSpeed)
{
    //ctor
    this->id = new int(++compteur);
    changeState(new StateWalk);
}

Enemies::~Enemies()
{
    //dtor
    delete id;
    delete state;

}

Enemies::Enemies(const Enemies& other): health(other.health),marketValue(other.marketValue),scoreValue(other.scoreValue),damage(other.damage),walkingSpeed(other.walkingSpeed)
{
   //copy ctor
    this->id = new int(*other.id);
}

Enemies& Enemies::operator=(const Enemies& rhs)
{
    if (this == &rhs) return *this; // handle self assignment

    this->damage=rhs.damage;
    this->health=rhs.health;
    this->marketValue=rhs.marketValue;
    this->scoreValue=rhs.scoreValue;
    this->walkingSpeed=rhs.walkingSpeed;

    //assignment operator
    return *this;
}

/*this method decrease the health of the enemy if the health is lower of egal to 0 the enemy die*/
void Enemies::receiveDamage(int damage)
{
    setHealth(getHealth()-damage);

    if(this->health<=0)
    {
        health=0;
        changeState(new StateDie);
    }
}

/* this method changes the state of the enemy*/
void Enemies::changeState(State *state)
{
    if(this->state !=nullptr)
    {
        delete this->state;
    }

    this->state = state;

    this->state->setEnemy(this);
}

/* active walk of enemy, change his position x */
void Enemies::walk()
{
    this->state->walk();
}

/*the enemies attack the king*/
void Enemies::attackKing(King &king)
{
    this->state->attackKing(king);
}

/*change the health of enemy */
void Enemies::setHealth(int health)
{
    this->health=health;

    if(health<0)
    {
        health=0;
        die();
    }
}

/*changes de positions of enemy */
void Enemies::setX(float x)
{
    this->x = x;

    if(x >= King::xKing)
    {
        this->x = King::xKing;
        changeState(new StateAttack);
    }
}

/*change the state of enemies to dead*/
void Enemies::die()
{
    this->state->die();
}

/*this method is called at the end of each wave and buffs the enemy to make it harder to kill*/
void Enemies::improveStatistics(int numeroOfWave)
{
    this->setHealth(health*numeroOfWave*0.35);
    healthMax=health;
}

/*changes the walking speed of enemy */
void Enemies::setWalkingSpeed(float speed)
{
    if(speed>0)
    {
        walkingSpeed = speed;
    }
}
