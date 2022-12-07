#ifndef VENNEMY_H
#define VENNEMY_H

#include <SFML/Graphics.hpp>
#include <Enemies.h>

class vEnnemy
{
    public:

        vEnnemy();
        virtual ~vEnnemy();
        vEnnemy(const vEnnemy& other);
        vEnnemy& operator=(const vEnnemy& other);

        void chargeInformations(Enemies *enemy);
        void updateTexture(Enemies *enemy);
        void updatePartOfTexture(Enemies *enemy);
        void animationClock();
        void updateHealth(Enemies *enemy);

        //getters and setters
        sf::Sprite *getSprite()
        {
            return enemySprite;
        }

        void setSprite(sf::Sprite *enemySprite)
        {
            this->enemySprite=enemySprite;
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
        //sprites
        sf::Sprite *enemySprite;

};

#endif // VENNEMY_H
