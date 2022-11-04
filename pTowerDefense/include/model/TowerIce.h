#ifndef TOWERICE_H
#define TOWERICE_H

#include <Tower.h>


class TowerIce : public Tower
{
    public:
        TowerIce(int damage=40,int level=1,int price=150);
        virtual ~TowerIce();
        TowerIce(const TowerIce& other);
        TowerIce& operator=(const TowerIce& other);

    protected:

    private:
};

#endif // TOWERICE_H
