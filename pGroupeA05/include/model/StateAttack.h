#ifndef STATEATTACK_H
#define STATEATTACK_H
#include "State.h"

class StateAttack: public State
{
    public:
        void walk() override;
        void die() override;
        bool attackKing()override;


    protected:

    private:
};

#endif // STATEATTACK_H
