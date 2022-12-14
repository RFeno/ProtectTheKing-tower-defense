#ifndef GREMLIN_H
#define GREMLIN_H
#include "Enemies.h"
#include <string>


class Gremlin : public Enemies
{
    public:
        Gremlin(int health=250, int marketValue=5, int scoreValue=200, int damage=1,float walkingSpeed=1.5);
        virtual ~Gremlin();
        Gremlin(const Gremlin& other);
        Gremlin& operator=(const Gremlin& other);
        std::string getInformations()const;
        Gremlin* clone() const;


    protected:

    private:


};

#endif // GREMLIN_H
