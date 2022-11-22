#ifndef STATEWALK_H
#define STATEWALK_H
#include "State.h"

class StateWalk: public State
{
    public:
        /*StateWalk();
        virtual ~StateWalk();
        StateWalk(const StateWalk& other);
        StateWalk& operator=(const StateWalk& other);*/

        void walk() override;
        void die() override;
        void attackKing(King &king)override;

    protected:

    private:
};

#endif // STATEWALK_H
