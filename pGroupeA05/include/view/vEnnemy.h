#ifndef VENNEMY_H
#define VENNEMY_H

#include <SFML/Graphics.hpp>
#include "Enemies.h"
//#include "vState.h"

class vEnnemy
{
    public:

        vEnnemy(Enemies *enemy=nullptr);
        virtual ~vEnnemy();
        vEnnemy(const vEnnemy& other);
        vEnnemy& operator=(const vEnnemy& other);

        void chargeInformations();
        void updateTexture();
        void updatePartOfTexture();
        void animationClock();
        void updateHealth();

        //getters and setters
        Enemies* getEnemy()
        {
            return enemy;
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

        //all textures of walk
        sf::Texture *ogreTextureWalk = nullptr;

        sf::Texture *orcTextureWalk = nullptr;
        sf::Texture *shadowMonsterTextureWalk = nullptr;
        sf::Texture *knightOfDeathTextureWalk = nullptr;
        sf::Texture *gremlinTextureWalk = nullptr;

        //all textures of dead
        sf::Texture *ogreDeadTexture = nullptr;
        sf::Texture *orcDeadTexture = nullptr;
        sf::Texture *shadowMonsterDeadTexture = nullptr;
        sf::Texture *knightOfDeathDeadTexture = nullptr;
        sf::Texture *gremlinDeadTexture = nullptr;

        //all textures of attack
        sf::Texture *ogreAttackTexture = nullptr;
        sf::Texture *shadowMonsterAttackTexture = nullptr;
        sf::Texture *knightOfDeathAttackTexture = nullptr;
        sf::Texture *gremlinAttackTexture = nullptr;
        sf::Texture *orcAttackTexture = nullptr ;

        //texture of health
        sf::Texture *healthBarGreenTexture = nullptr;
        sf::Texture *healthBarRedTexture = nullptr;

        sf::Sprite healthBarRedSprite;
        sf::Sprite healthBarGreenSprite;

    protected:

    private:
        //model
        Enemies* enemy;

        //sprites
        sf::Sprite *enemySprite;

};

#endif // VENNEMY_H
