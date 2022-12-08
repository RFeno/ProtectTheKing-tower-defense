#ifndef STATEDIE_H
#define STATEDIE_H

#include <State.h>


class StateDie : public State
{
    public:
        void walk() override;
        void die() override;
        bool attackKing()override;

    protected:

    private:
};

#endif // STATEDIE_H
