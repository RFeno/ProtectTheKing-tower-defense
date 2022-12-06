#ifndef FIRESPELL_H
#define FIRESPELL_H


class FireSpell : public Spell
{
    public:
        FireSpell(int damage=fireDamage,float effectduration=fireDuration);
        virtual ~FireSpell();
        FireSpell(const FireSpell& other);
        FireSpell& operator=(const FireSpell& rhs);

    protected:

    private:
};

#endif // FIRESPELL_H
