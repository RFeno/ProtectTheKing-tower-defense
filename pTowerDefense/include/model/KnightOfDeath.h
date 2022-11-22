#ifndef KNIGHTOFDEATH_H
#define KNIGHTOFDEATH_H

#include <Enemies.h>


class KnightOfDeath : public Enemies
{
    public:
        KnightOfDeath(int health=100, int attackSpeed=1, int marketValue=100, int scoreValue=100, int damage=2, State *state=nullptr);
        virtual ~KnightOfDeath();
        KnightOfDeath(const KnightOfDeath& other);
        KnightOfDeath& operator=(const KnightOfDeath& other);
        KnightOfDeath* clone()const;

    protected:

    private:
        const int y = 493;
};

#endif // KNIGHTOFDEATH_H
