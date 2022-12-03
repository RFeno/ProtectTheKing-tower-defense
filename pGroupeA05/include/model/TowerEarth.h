#ifndef TOWEREARTH_H
#define TOWEREARTH_H

#include <Tower.h>


class TowerEarth : public Tower
{
    public:
        TowerEarth(int xTower=0, int yTower=0,int position=-1, int damage=40,int level=1,int price=earth,int range=123);
        virtual ~TowerEarth();
        TowerEarth(const TowerEarth& other);
        TowerEarth& operator=(const TowerEarth& other);

    protected:

    private:
};

#endif // TOWEREARTH_H
