#ifndef KNIGHTOFDEATH_H
#define KNIGHTOFDEATH_H

#include <Enemies.h>


class KnightOfDeath : public Enemies
{
    public:
        KnightOfDeath();
        virtual ~KnightOfDeath();
        KnightOfDeath(const KnightOfDeath& other);
        KnightOfDeath& operator=(const KnightOfDeath& other);
        KnightOfDeath* clone()const;

    protected:

    private:
};

#endif // KNIGHTOFDEATH_H
