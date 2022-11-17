#ifndef VENNEMY_H
#define VENNEMY_H

#include <SFML/Graphics.hpp>
#include "Enemies.h"


class vEnnemy
{
    public:

        vEnnemy(Enemies *enemy, sf::Sprite *enemySprite, bool walk, bool animated, bool spawn, bool attack, bool dead);
        virtual ~vEnnemy();
        vEnnemy(const vEnnemy& other);
        vEnnemy& operator=(const vEnnemy& other);

        //getters and setters
        Enemies* getEnnemy()
        {
            return enemy;
        }

        bool isSpawn()const
        {
            return spawn;
        }

        bool isWalking()const
        {
            return walk;
        }
        bool isDead()const
        {
            return dead;
        }

        bool getAnimated()const
        {
            return animated;
        }

        sf::Sprite *getSprite()
        {
            return enemySprite;
        }

        bool isAttacking()
        {
            return attack;
        }

        void setSprite(sf::Sprite *enemySprite)
        {
            this->enemySprite=enemySprite;
        }

        void setEnemy(Enemies* enemy)
        {
            this->enemy=enemy;
        }

        void setSpawn(bool spawn)
        {
            this->spawn=spawn;
        }

        void setAttack(bool attack)
        {
            this->attack=attack;
        }


        void setWalk(bool walk)
        {
            this->walk=walk;
        }


        void setDead(bool dead)
        {
            this->dead=dead;
        }


    protected:

    private:
        Enemies* enemy;
        sf::Sprite *enemySprite;
        bool walk;
        bool animated;
        bool spawn;
        bool attack;
        bool dead;




};

#endif // VENNEMY_H
