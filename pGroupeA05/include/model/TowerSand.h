#ifndef TOWERSAND_H
#define TOWERSAND_H

#include <Tower.h>


class TowerSand : public Tower
{
    public:
        TowerSand(int xTower=0, int yTower=0, int position=-1, int damage=20,int level=1,int price=sand,int range=123);
        virtual ~TowerSand();
        TowerSand(const TowerSand& other);
        TowerSand& operator=(const TowerSand& other);

    protected:

    private:
};

#endif // TOWERSAND_H
