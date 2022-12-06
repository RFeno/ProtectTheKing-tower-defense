#include "LightningSpell.h"


LightningSpell::LightningSpell(int damage, float effectduration,int price):Spell(damage,effectduration,price)
{
    //ctor
}

LightningSpell::~LightningSpell()
{
    //dtor
}

LightningSpell::LightningSpell(const LightningSpell& other):Spell(other)
{
    //copy ctor
}

LightningSpell& LightningSpell::operator=(const LightningSpell& rhs)
{
    if (this == &rhs) return *this; // handle self assignment

    Spell::operator=(rhs);

    //assignment operator
    return *this;
}
