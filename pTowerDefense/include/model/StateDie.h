#ifndef STATEDIE_H
#define STATEDIE_H

#include <State.h>


class StateDie : public State
{
    public:
        void walk(int x) override;
        void die() override;
        void attackKing(King &king)override;

    protected:

    private:
};

#endif // STATEDIE_H
