#ifndef VENNEMY_H
#define VENNEMY_H

#include <SFML/Graphics.hpp>
#include "Enemies.h"


class vEnnemy
{
    public:

        vEnnemy(Enemies *enemy, sf::Sprite *enemySprite, bool walk, bool animated, bool spawn);
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

        bool getWalk()const
        {
            return walk;
        }

        bool getAnimated()const
        {
            return animated;
        }

        sf::Sprite *getSprite()
        {
            return enemySprite;
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


    protected:

    private:
        Enemies* enemy;
        sf::Sprite *enemySprite;
        bool walk;
        bool animated;
        bool spawn;




};

#endif // VENNEMY_H
