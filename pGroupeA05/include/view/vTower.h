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

        Tower *tower;
        sf::Clock* animAttackClock;
        sf::Clock bulletClock;
        int position;

        bool attackAnimation = false;


    public:

        vTower(int x,int y, Tower* tower, int position);
        virtual ~vTower();
        vTower(const vTower& other);
        vTower& operator=(const vTower& other);

        void chargeInformations();
        void animAttack();
        int calculateMiddlePosition();

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

        void setAttackAnimation(bool animation)
        {
            this->attackAnimation=animation;
        }

        bool isAttackAnimation()
        {
            return attackAnimation;
        }

        void setX(int x)
        {
            this->x=x;
        }

        void setY(int y)
        {
            this->y=y;
        }

        int getPosition()
        {
            return position;
        }

        void setPosition(int position)
        {
            this->position=position;
        }

    protected:
};

#endif // VTOWER_H
