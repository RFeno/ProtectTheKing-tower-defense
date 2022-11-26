#ifndef TOWERICE_H
#define TOWERICE_H

#include <Tower.h>


class TowerIce : public Tower
{
    public:
        TowerIce(int xTower=0, int yTower=0,int damage=40,int level=1,int price=ice);
        virtual ~TowerIce();
        TowerIce(const TowerIce& other);
        TowerIce& operator=(const TowerIce& other);

    protected:

    private:
};

#endif // TOWERICE_H
