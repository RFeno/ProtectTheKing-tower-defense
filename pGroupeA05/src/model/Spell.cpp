#include "Spell.h"

#include "Enemies.h"
#include <vector>

using namespace std;

Spell::Spell(int damage,float effectduration): damage(damage), effectduration(effectduration)
{
    //ctor
}

Spell::~Spell()
{
    //dtor
}

Spell::Spell(const Spell& other): damage(other.damage), effectduration(other.effectduration)
{
    //copy ctor
}

Spell& Spell::operator=(const Spell& rhs)
{
    if (this == &rhs) return *this; // handle self assignment

    this->damage=rhs.damage;
    this->effectduration=rhs.effectduration;

    //assignment operator
    return *this;
}

void Spell::attackEnemies(vector<Enemies*> listOfEnemies)
{
    for(Enemies *enemy:listOfEnemies)
    {
        enemy->receiveDamage(damage);
    }
}
