#ifndef VENNEMY_H
#define VENNEMY_H

#include <SFML/Graphics.hpp>
#include "Enemies.h"
//#include "vState.h"

class vEnnemy
{
    public:

        vEnnemy(Enemies *enemy, sf::Sprite *enemySprite, bool walk, bool animated, bool spawn, bool attack, bool dead);
        virtual ~vEnnemy();
        vEnnemy(const vEnnemy& other);
        vEnnemy& operator=(const vEnnemy& other);

        //static bool chargesEnemiesTextures();
        void chargeInformations();
        void updateTexture();
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

        //sprites
        sf::Sprite *enemySprite;
        sf::Sprite *healthBarGreenSprite;
        sf::Sprite *healthBarRedSprite;


        bool walk;
        bool animated;
        bool spawn;
        bool attack;
        bool dead;




};

#endif // VENNEMY_H
