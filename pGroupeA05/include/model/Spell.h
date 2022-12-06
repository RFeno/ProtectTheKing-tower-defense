#ifndef SPELL_H
#define SPELL_H


class Spell
{
    public:
        Spell(int damage=1,effectduration=1);
        virtual ~Spell();
        Spell(const Spell& other);
        Spell& operator=(const Spell& other);

    protected:

    private:
        int damage;
        float effectduration;
};

#endif // SPELL_H
