#ifndef GREMLIN_H
#define GREMLIN_H
#include "Enemies.h"
#include <string>


class Gremlin : public Enemies
{
    public:
        Gremlin(int health=200, int attackSpeed=1, int marketValue=200, int scoreValue=200, int damage=1);
        virtual ~Gremlin();
        Gremlin(const Gremlin& other);
        Gremlin& operator=(const Gremlin& other);
        Gremlin* clone()const;
        std::string getInformations()const;

    protected:

    private:
};

#endif // GREMLIN_H
