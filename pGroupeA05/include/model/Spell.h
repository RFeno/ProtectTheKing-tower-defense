#ifndef SPELL_H
#define SPELL_H

#include <vector>
#include "Enemies.h"

enum TypeOfSpell : int
{
    fire = 300,
    acidCloud = 200,
    lightning = 100,
};

enum DamageOfSpell : int
{
    fireDamage = 500,
    cloudDamage = 300,
    lightningDamage = 100,
};

enum EffectDuration{
    fireDuration = 3,
    cloudDuration = 2,
    lightningDuration = 1,
};

enum SizeOfSpell : int
{
    ACID_CLOUD_HEIGHT = 2398,
    ACID_CLOUD_WIDTH = 909,
    FIRE_WIDTH = 2398,
    FIRE_HEIGHT = 909,
    LIGHTNING_WIDTH = 2398,
    LIGHTNING_HEIGHT = 909,
};

class Spell
{
    public:
        Spell(int damage=1,float effectduration=1.0,int price = 200);
        virtual ~Spell();
        Spell(const Spell& other);
        Spell& operator=(const Spell& other);
        Spell* clone()const;

    protected:

    private:
        int damage;
        float effectduration;
        int price;
};

#endif // SPELL_H
