#ifndef VGAMEBOARD_H
#define VGAMEBOARD_H

#include <SFML/Graphics.hpp>
#include "Enemies.h"
#include "Game.h"
#include "vEnnemy.h"

using namespace sf;

class vGameBoard
{
    public:

        vGameBoard(RenderWindow& window);
        virtual ~vGameBoard();
        vGameBoard(const vGameBoard& other);
        vGameBoard& operator=(const vGameBoard& other);

        void launchView();
        void loadSprite();
        void loadFont();
        bool verifyImage();
        bool drawEntities(RenderWindow& window);
        void InputHandler(Event event, RenderWindow *window);
        bool isSpriteClicked (Sprite &spr, RenderWindow &window);

        //methods
        void launchGame();
        void launchWave(int numberOfEnemies);
        void animationEnemyWalk();
        void animationEnemyWalk2(Sprite *enemy);
        void enemiesSpawn();
        void displayEnd();
        bool setTower(int y, int x, int type);
        bool setTower(int y, int x, Tower* t);
        void activeFireSpell();
        void activeLightningSpeel();
        void activeCloudSpell();





    protected:

    private:
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

        //std::vector<Sprite*> enemiesSprite;
        std::vector<vEnnemy*> listOfEnnemies;

        //x and y serve to reset the animation of sprites in fonction of diffrents size of sprite
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

        Clock animClock;
        Clock spawnClock;
        //bool animatedEnemmyWalk;
        Game game;
        RenderWindow *windowFromMain;

        const int WALK_SPEED = 3;

        int idSpawn = 0;
        int spawnTime = 3;

        std::vector<bool> isSpawn;

        //enemies
        Texture gremlinTexture;
        Texture knightOfDeathTexture;
        Texture shadowMonsterTexture;
        Texture ogreTexture;
        Texture orcTexture;

        //map and entitites
        Sprite mapSprite;
        Sprite pauseSprite;
        Sprite acideCloudSprite;
        Sprite lightningSprite;
        Sprite fireSprite;
        Texture mapTexture;
        Texture pauseTexture;
        Texture acideCloudTexture;
        Texture lightningTexture;
        Texture fireTexture;

        //Towers textures
        Texture earthTowerTexture;
        Texture sandTowerTexture;
        Texture iceTowerTexture;
        Texture ironTowerTexture;
        //Tower sprites
        Sprite earthTowerSprite;
        Sprite sandTowerSprite;
        Sprite iceTowerSprite;
        Sprite ironTowerSprite;

};

#endif // VGAMEBOARD_H
