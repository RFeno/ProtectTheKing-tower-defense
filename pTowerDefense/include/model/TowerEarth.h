#ifndef TOWEREARTH_H
#define TOWEREARTH_H

#include <Tower.h>


class TowerEarth : public Tower
{
    public:
        TowerEarth(int xTower=0, int yTower=0, int damage=60,int level=1,int price=earth);
        virtual ~TowerEarth();
        TowerEarth(const TowerEarth& other);
        TowerEarth& operator=(const TowerEarth& other);

    protected:

    private:
};

#endif // TOWEREARTH_H
