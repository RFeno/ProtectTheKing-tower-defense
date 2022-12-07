#ifndef ACIDCLOUDSPELL_H
#define ACIDCLOUDSPELL_H

#include "Spell.h"

class AcidCloudSpell : public Spell
{
    public:
        AcidCloudSpell(int damage=cloudDamage,float effectduration=cloudDuration,int price=acidCloud);
        virtual ~AcidCloudSpell();
        AcidCloudSpell(const AcidCloudSpell& other);
        AcidCloudSpell& operator=(const AcidCloudSpell& other);

    protected:

    private:
};

#endif // ACIDCLOUDSPELL_H
