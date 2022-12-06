#include "AcidCloudSpell.h"

AcidCloudSpell::AcidCloudSpell(int damage,float effectduration): Spell(damage,effectduration)
{
    //ctor
}

AcidCloudSpell::~AcidCloudSpell()
{
    //dtor
}

AcidCloudSpell::AcidCloudSpell(const AcidCloudSpell& other):Spell(other)
{
    //copy ctor
}

AcidCloudSpell& AcidCloudSpell::operator=(const AcidCloudSpell& rhs)
{
    if (this == &rhs) return *this; // handle self assignment

    Spell::operator=(rhs);

    //assignment operator
    return *this;
}
