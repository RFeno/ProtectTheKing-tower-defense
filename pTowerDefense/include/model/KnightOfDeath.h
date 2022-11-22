#ifndef KNIGHTOFDEATH_H
#define KNIGHTOFDEATH_H

#include <Enemies.h>


class KnightOfDeath : public Enemies
{
    public:
        KnightOfDeath(int health=1000, int attackSpeed=1, int marketValue=1000, int scoreValue=1000, int damage=2);
        virtual ~KnightOfDeath();
        KnightOfDeath(const KnightOfDeath& other);
        KnightOfDeath& operator=(const KnightOfDeath& other);
        KnightOfDeath* clone()const;
        std::string getInformations()const;

    protected:

    private:
        const int y = 493;
};

#endif // KNIGHTOFDEATH_H
