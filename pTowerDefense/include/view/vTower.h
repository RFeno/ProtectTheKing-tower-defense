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
        sf::Texture* towerTexture;

    public:
        vTower(int x, int y, sf::Sprite* sprite, Tower* tower, sf::Texture* towerTexture);
        virtual ~vTower();
        vTower(const vTower& other);
        vTower& operator=(const vTower& other);

        sf::Sprite* getSprite()
        {
            return towerSprite;
        }

    protected:
};

#endif // VTOWER_H
