#ifndef TOWERIRON_H
#define TOWERIRON_H

#include <Tower.h>


class TowerIron : public Tower
{
    public:
        TowerIron(int xTower=0, int yTower=0,int position=-1, int damage=80,int level=1,int price=iron, int range =123);
        TowerIron(const TowerIron& other);
        TowerIron& operator=(const TowerIron& rhs);
        virtual ~TowerIron();


    protected:

    private:
};

#endif // TOWERIRON_H
