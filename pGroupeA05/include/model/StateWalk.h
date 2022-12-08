#ifndef STATEWALK_H
#define STATEWALK_H
#include "State.h"

class StateWalk: public State
{
    public:
        void walk() override;
        void die() override;
        bool attackKing()override;

    protected:

    private:
};

#endif // STATEWALK_H
