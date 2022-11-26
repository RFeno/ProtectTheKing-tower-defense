#ifndef VTOWER_H
#define VTOWER_H

#include <SFML/Graphics.hpp>
#include "Tower.h"

class vTower
{
    private:
        sf::Vector2i* position;
        sf::Sprite* towerSprite;
        sf::Sprite* attackSprite;
        Tower *tower;

        sf::Clock* animAttackClock;

    public:

        vTower(sf::Vector2i* position, Tower* tower);
        virtual ~vTower();
        vTower(const vTower& other);
        vTower& operator=(const vTower& other);

        void chargeInformations();
        void animAttack();

        sf::Texture *towerTexture = nullptr;
        sf::Texture *attackTexture = nullptr;

        sf::Sprite* getSprite()
        {
            return towerSprite;
        }

        sf::Vector2i* getPosition()
        {
            return position;
        }

        Tower* getTower()
        {
            return tower;
        }

        sf::Clock* getAttackClock()
        {
            return animAttackClock;
        }

        sf::Sprite* getAttackSprite()
        {
            return attackSprite;
        }

    protected:
};

#endif // VTOWER_H
