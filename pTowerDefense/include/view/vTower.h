#ifndef VTOWER_H
#define VTOWER_H

#include <SFML/Graphics.hpp>
#include "Tower.h"

class vTower
{
    private:
        int x;
        int y;
        sf::Sprite *towerSprite;
        Tower *tower;

    public:
        vTower(int x, int y, sf::Sprite* sprite, Tower* tower);
        virtual ~vTower();
        vTower(const vTower& other);
        vTower& operator=(const vTower& other);


    protected:
};

#endif // VTOWER_H
