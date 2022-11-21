#ifndef GREMLIN_H
#define GREMLIN_H
#include "Enemies.h"

class Gremlin : public Enemies
{
    public:
        Gremlin(int health=20, int attackSpeed=1, int marketValue=20, int scoreValue=20, int damage=1, State *state=nullptr);
        virtual ~Gremlin();
        Gremlin(const Gremlin& other);
        Gremlin& operator=(const Gremlin& other);
        Gremlin* clone()const;

    protected:

    private:
};

#endif // GREMLIN_H
