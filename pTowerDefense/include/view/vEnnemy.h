#ifndef VENNEMY_H
#define VENNEMY_H

#include <SFML/Graphics.hpp>
#include "Enemies.h"
//#include "vState.h"

class vEnnemy
{
    public:

        vEnnemy(Enemies *enemy);
        virtual ~vEnnemy();
        vEnnemy(const vEnnemy& other);
        vEnnemy& operator=(const vEnnemy& other);

        //static bool chargesEnemiesTextures();
        void chargeInformations();
        void updateTexture();
        void updatePartOfTexture();
        void animationClock();

        void launchDead();
        void animation();

        //getters and setters
        Enemies* getEnemy()
        {
            return enemy;
        }

        bool isSpawn()const
        {
            return spawn;
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

        void setDead(bool dead)
        {
            this->dead=dead;
        }

        //texture of health
        sf::Texture *healthBarGreenTexture = nullptr;
        sf::Texture *healthBarRedTexture = nullptr;

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


    protected:

    private:
        //model
        Enemies* enemy;

        const int OGRE_WIDTH = 377 ;
        const int OGRE_HEIGHT = 404;
        const int ORC_WIDTH = 339;
        const int ORC_HEIGHT = 353 ;
        const int GREMLIN_WIDTH = 238;
        const int GREMLIN_HEIGHT = 227;
        const int SHADOWMONSTER_WIDTH = 326;
        const int SHADOWMONSTER_HEIGHT = 302;
        const int KNIGHTOFDEATH_WIDTH = 445;
        const int KNIGHTOFDEATH_HEIGHT = 469;

        int x_Ogre = 0;
        int y_Ogre = 0;

        int x_Orc = 0;
        int y_Orc = 0;

        int x_gremlin = 0;
        int y_gremlin = 0;

        int x_shadowMonster = 0;
        int y_shadowMonster = 0;

        int x_knight = 0;
        int y_knight = 0;

        sf::Clock animClock;

        //sprites
        sf::Sprite *enemySprite;
        sf::Sprite *healthBarGreenSprite;
        sf::Sprite *healthBarRedSprite;


        bool animated = false;
        bool spawn = false;
        bool dead = false;




};

#endif // VENNEMY_H
