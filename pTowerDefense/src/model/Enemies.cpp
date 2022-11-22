#include "Enemies.h"

#include <string>
#include "King.h"
#include "State.h"
#include "StateDie.h"

class State;
class StateDie;

using namespace std;

Enemies::Enemies(int health, int attackSpeed, int marketValue, int scoreValue, int damage, State *state)
: health(health),attackSpeed(attackSpeed),marketValue(marketValue),scoreValue(scoreValue),damage(damage),state(state)
{
    //ctor
    this->id = new int(++compteur);
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

void Enemies::walk(int x)
{
    this->state->walk(x);
}

void Enemies::attackKing(King &king)
{
    this->state->attackKing(king);
}

void Enemies::setHealth(int health)
{
    this->health=health;

    if(health<0)
    {
        health=0;
    }
}

void Enemies::die()
{
    changeState(new StateDie);
}


/* return the enemy informations / attributes */
string Enemies::getInformations()const
{
    return "[Enemies => health:" + to_string(health) + " attackSpeed:" + to_string(attackSpeed) + " market value:" + to_string(marketValue) + " score value:" + to_string(scoreValue) + "]";
}

