#ifndef GREMLIN_H
#define GREMLIN_H
#include "Enemies.h"
#include <string>


class Gremlin : public Enemies
{
    public:
        Gremlin(int health=200, float attackSpeed=1.5, int marketValue=200, int scoreValue=200, int damage=1,float walkingSpeed=1.5);
        virtual ~Gremlin();
        Gremlin(const Gremlin& other);
        Gremlin& operator=(const Gremlin& other);
        std::string getInformations()const;



    protected:

    private:


};

#endif // GREMLIN_H
