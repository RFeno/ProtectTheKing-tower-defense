#ifndef STATEATTACK_H
#define STATEATTACK_H
#include "State.h"

class StateAttack: public State
{
    public:
        StateAttack();
        virtual ~StateAttack();

        void walk(int x) override;
        void die() override;
        void attackKing(King &king)override;


    protected:

    private:
};

#endif // STATEATTACK_H
