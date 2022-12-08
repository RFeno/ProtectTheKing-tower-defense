#ifndef STATE_H
#define STATE_H

#include "Enemies.h"
#include "King.h"

class Enemies;

class State
{
    public:

        virtual ~State();

        void setEnemy(Enemies *enemy)
        {
            this->enemy=enemy;
        }

        virtual void walk() = 0;
        virtual void die() = 0;
        virtual bool attackKing() = 0;


    protected:
        Enemies *enemy;

    private:
};

#endif // STATE_H
