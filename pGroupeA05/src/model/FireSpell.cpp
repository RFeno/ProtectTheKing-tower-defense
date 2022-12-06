#include "FireSpell.h"

FireSpell::FireSpell(int damage, float effectduration,int price): Spell(damage,effectduration,price)
{
    //ctor
}

FireSpell::~FireSpell()
{
    //dtor
}

FireSpell::FireSpell(const FireSpell& other):Spell(other)
{
    //copy ctor
}

FireSpell& FireSpell::operator=(const FireSpell& rhs)
{
    if (this == &rhs) return *this; // handle self assignment

    Spell::operator=(rhs);

    //assignment operator
    return *this;
}
