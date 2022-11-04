#ifndef TOWERIRON_H
#define TOWERIRON_H

#include <Tower.h>


class TowerIron : public Tower
{
    public:
        TowerIron(int damage=80,int level=1,int price=400);
        virtual ~TowerIron();

    protected:

    private:
};

#endif // TOWERIRON_H
