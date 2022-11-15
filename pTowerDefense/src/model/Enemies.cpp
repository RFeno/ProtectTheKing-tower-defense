#include "Enemies.h"
#include <string>

using namespace std;

Enemies::Enemies(int health, int attackSpeed, int marketValue, int scoreValue, int damage): health(health),attackSpeed(attackSpeed),marketValue(marketValue),scoreValue(scoreValue),damage(damage)
{
    //ctor
    this->id = new int(++compteur);
}

Enemies::~Enemies()
{
    //dtor
    delete id;
}

Enemies::Enemies(const Enemies& other): health(other.health),attackSpeed(other.attackSpeed),marketValue(other.marketValue),scoreValue(other.scoreValue),damage(other.damage)
{
   //copy ctor
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
        //die();
    }
}

string Enemies::getInformations()const
{
    return "[Enemies => health:" + to_string(health) + " attackSpeed:" + to_string(attackSpeed) + " market value:" + to_string(marketValue) + " score value:" + to_string(scoreValue) + "]";
}

