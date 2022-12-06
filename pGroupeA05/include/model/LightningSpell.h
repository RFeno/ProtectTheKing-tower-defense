#ifndef LIGHTNINGSPELL_H
#define LIGHTNINGSPELL_H

#include <Spell.h>


class LightningSpell : public Spell
{
    public:
        LightningSpell(int damage=lightningDamage,float effectduration=lightningDuration);
        virtual ~LightningSpell();
        LightningSpell(const LightningSpell& other);
        LightningSpell& operator=(const LightningSpell& other);

    protected:

    private:
};

#endif // LIGHTNINGSPELL_H
