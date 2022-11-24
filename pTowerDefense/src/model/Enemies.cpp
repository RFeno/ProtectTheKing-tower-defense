#include "Enemies.h"
#include <string>
#include "State.h"
#include "StateDie.h"
#include "StateWalk.h"
#include "StateAttack.h"
#include "King.h"

class State;
class StateDie;

using namespace std;

Enemies::Enemies(int health, int attackSpeed, int marketValue, int scoreValue, int damage)
: health(health),attackSpeed(attackSpeed),marketValue(marketValue),scoreValue(scoreValue),damage(damage)
{
    //ctor
    this->id = new int(++compteur);
    this->state=nullptr;
    changeState(new StateWalk);
}

Enemies::~Enemies()
{
    //dtor
    delete id;
    delete state;

}

Enemies::Enemies(const Enemies& other): health(other.health),attackSpeed(other.attackSpeed),marketValue(other.marketValue),scoreValue(other.scoreValue),damage(other.damage)
{
   //copy ctor
    this->id = new int(*other.id);
}

Enemies& Enemies::operator=(const Enemies& rhs)
{
    if (this == &rhs) return *this; // handle self assignment

    this->attackSpeed=rhs.attackSpeed;
    this->damage=rhs.damage;
    this->health=rhs.health;
    this->marketValue=rhs.marketValue;
    this->scoreValue=rhs.scoreValue;

    //assignment operator
    return *this;
}

/*
* this method decrease the health of the enemy
* if the health is lower of egal to 0 the enemy die
*/
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
void Enemies::setX(int x)
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
    if(!dynamic_cast<StateDie*>(state))
    {
        changeState(new StateDie);
    }
}

