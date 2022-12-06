#ifndef SPELL_H
#define SPELL_H

#include <vector>
#include "Enemies.h"

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

enum EffectDuration{
    fireDuration = 3,
    cloudDuration = 2,
    lightningDuration = 1,
};

class Spell
{
    public:
        Spell(int damage=1,float effectduration=1.0);
        virtual ~Spell();
        Spell(const Spell& other);
        Spell& operator=(const Spell& other);

        void attackEnemies(std::vector<Enemies*> listOfEnemies);

    protected:

    private:
        int damage;
        float effectduration;
};

#endif // SPELL_H
