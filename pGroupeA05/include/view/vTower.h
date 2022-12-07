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
        sf::Sprite bulletSprite;
        sf::Clock bulletClock;

    public:

        vTower(int x,int y);
        virtual ~vTower();
        vTower(const vTower& other);
        vTower& operator=(const vTower& other);

        void chargeInformations(Tower *tower);
        void animAttack();
        int calculateMiddlePosition();

        sf::Texture *towerTexture = nullptr;
        sf::Texture *attackTexture = nullptr;

        sf::Sprite* getSprite()const
        {
            return towerSprite;
        }

        sf::Sprite* getAttackSprite()const
        {
            return attackSprite;
        }

        int getX()const
        {
            return x;
        }

        int getY()const
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
