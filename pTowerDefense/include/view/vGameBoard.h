#ifndef VGAMEBOARD_H
#define VGAMEBOARD_H

#include <SFML/Graphics.hpp>
#include "Enemies.h"
#include "Game.h"

using namespace sf;

class vGameBoard
{
    public:

        const int WALK_SPEED = 2;
        int distanceMove =1;

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
        bool animatedEnemmyWalk;
        Game game;
        RenderWindow *windowFromMain;

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


        //view
        Texture mapTexture;
        Texture pauseTexture;
        Texture acideCloudTexture;
        Texture lightningTexture;
        Texture fireTexture;
        std::vector<Sprite*> enemiesSprite;

        Texture gremlinTexture;
        Texture knightOfDeathTexture;
        Texture shadowMonsterTexture;
        Texture ogreTexture;
        Texture orcTexture;

        Sprite mapSprite;
        Sprite pauseSprite;
        //Sprite musiqueOnSprite;
        Sprite acideCloudSprite;
        Sprite lightningSprite;
        Sprite fireSprite;




};

#endif // VGAMEBOARD_H
