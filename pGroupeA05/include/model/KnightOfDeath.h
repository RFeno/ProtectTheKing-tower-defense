#ifndef KNIGHTOFDEATH_H
#define KNIGHTOFDEATH_H

#include <Enemies.h>


class KnightOfDeath : public Enemies
{
    public:
        KnightOfDeath(int health=550, int marketValue=20, int scoreValue=1000, int damage=2,float walkingSpeed=0.75);
        virtual ~KnightOfDeath();
        KnightOfDeath(const KnightOfDeath& other);
        KnightOfDeath& operator=(const KnightOfDeath& other);
        std::string getInformations()const;
        KnightOfDeath* clone() const;

    protected:

    private:
};

#endif // KNIGHTOFDEATH_H
