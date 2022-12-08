#include "Spell.h"

#include "Enemies.h"
#include <vector>

using namespace std;

Spell::Spell(int damage,float effectduration,int price): damage(damage), effectduration(effectduration), price(price)
{
    //ctor
}

Spell::~Spell()
{
    //dtor
}

Spell::Spell(const Spell& other): damage(other.damage), effectduration(other.effectduration), price(other.price)
{
    //copy ctor
}

Spell& Spell::operator=(const Spell& rhs)
{
    if (this == &rhs) return *this; // handle self assignment

    this->damage=rhs.damage;
    this->effectduration=rhs.effectduration;
    this->price=rhs.price;

    //assignment operator
    return *this;
}

/** attack all enemies in the map received as argument*/
void Spell::attackEnemies(vector<Enemies*> listOfEnemies)
{
    for(Enemies *enemy:listOfEnemies)
    {
        if(enemy->isSpawn())
        {
            enemy->receiveDamage(damage);
        }
    }
}

/** clone the spell */
void Spell::clone()const
{
    return Spell(*this);
}
