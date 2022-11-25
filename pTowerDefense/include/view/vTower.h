#ifndef VTOWER_H
#define VTOWER_H

#include <SFML/Graphics.hpp>
#include "Tower.h"

class vTower
{
    private:
        sf::Vector2f* position;
        sf::Sprite *towerSprite;
        Tower *tower;

    public:

        vTower(sf::Vector2f* position, sf::Sprite* sprite, Tower* tower);
        virtual ~vTower();
        vTower(const vTower& other);
        vTower& operator=(const vTower& other);

        void chargeInformations();

        sf::Texture *towerTexture = nullptr;

        sf::Sprite* getSprite()
        {
            return towerSprite;
        }

        sf::Vector2f* getPosition()
        {
            return position;
        }

    protected:
};

#endif // VTOWER_H
