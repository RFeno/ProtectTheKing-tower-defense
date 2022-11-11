#ifndef KNIGHTOFDEATH_H
#define KNIGHTOFDEATH_H

#include <Enemies.h>


class KnightOfDeath : public Enemies
{
    public:
        KnightOfDeath(int health=40, int attackSpeed=1, int marketValue=40, int scoreValue=40, int damage=1);
        virtual ~KnightOfDeath();
        KnightOfDeath(const KnightOfDeath& other);
        KnightOfDeath& operator=(const KnightOfDeath& other);
        KnightOfDeath* clone()const;

    protected:

    private:
};

#endif // KNIGHTOFDEATH_H
