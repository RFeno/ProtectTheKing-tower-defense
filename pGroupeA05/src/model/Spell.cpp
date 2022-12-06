#include "Spell.h"


enum TypeOfSpell : int
{
    fire = 0,
    cloud = 1,
    lightning = 2,
};

enum DamageOfSpell : int
{
    fireDamage = 5,
    cloudDamage = 3,
    lightningDamage = 1,
};

enum EffectDuration: float
{
    fireDuration = 3,
    cloudDuration = 2,
    lightningDuration = 1,
};


Spell::Spell(int damage,int effectduration): damage(damage), effectduration(effectduration)
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
