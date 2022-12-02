#ifndef STATEWALK_H
#define STATEWALK_H
#include "State.h"

class StateWalk: public State
{
    public:
        void walk() override;
        void die() override;
        void attackKing(King &king)override;

    protected:

    private:
};

#endif // STATEWALK_H
