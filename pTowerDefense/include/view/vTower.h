#ifndef VTOWER_H
#define VTOWER_H

#include <SFML/Graphics.hpp>
#include "Tower.h"

class vTower
{
    private:
        int x;
        int y;
        sf::Sprite* towerSprite;
        sf::Sprite* attackSprite;
        Tower *tower;
        sf::Clock* animAttackClock;


    public:

        vTower(int x,int y, Tower* tower);
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

        int getX()
        {
            return x;
        }

        int getY()
        {
            return y;
        }

        void setX(int x)
        {
            this->x=x;
        }

        void setY(int y)
        {
            this->y=y;
        }


    protected:
};

#endif // VTOWER_H
