#ifndef STATE_H
#define STATE_H

#include "Enemies.h"
#include "King.h"

class State
{
    public:

        virtual ~State();
        /*State(const State& other);
        State& operator=(const State& other);*/

        void setEnemy(Enemies *enemy)
        {
            this->enemy=enemy;
        }

        virtual void walk(int x) = 0;
        virtual void die() = 0;
        virtual void attackKing(King &king) = 0;
        //virtual void update() = 0;


    protected:
        Enemies *enemy;

    private:
};

#endif // STATE_H