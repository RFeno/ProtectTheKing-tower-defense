#ifndef VGAMEBOARD_H
#define VGAMEBOARD_H

#include <SFML/Graphics.hpp>
#include "Enemies.h"
#include "Game.h"
#include "vEnnemy.h"
#include "vTower.h"

using namespace sf;

class vGameBoard
{
    public:

        //canonic
        vGameBoard(RenderWindow& window);
        virtual ~vGameBoard();
        vGameBoard(const vGameBoard& other);
        vGameBoard& operator=(const vGameBoard& other);

        void launchView();

        void loadSprite();

        void loadFont();

        //laod images
        bool verifyImage();
        bool verifyImageTower();
        bool verifyImageMonsters();
        bool verifyImageMapEntities();

        bool drawEntities();
        void InputHandler(Event event, RenderWindow *window);
        bool isSpriteClicked (Sprite &spr);

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
        void adaptAnimationSprite();





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

        const int NUMBER_ACIDE_SPELL = 14;

        const int WALK_SPEED = 3;

        int idSpawn = 0;
        int spawnTime = 3;

        //std::vector<Sprite*> enemiesSprite;
        std::vector<vEnnemy*> listOfvEnnemies;
        std::vector<vTower*> listOfvTower;
        std::vector<Sprite*> listOfAcideCloudSpell;
        std::vector<Sprite*> listOfFireSpell;
        std::vector<Sprite*> listOfLigntningSpell;

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

        int x_acide = 0;

        Clock animClock;
        Clock spawnClock;

        Game game;
        RenderWindow *windowFromMain;

        //enemies
        Texture gremlinTexture;
        Texture knightOfDeathTexture;
        Texture shadowMonsterTexture;
        Texture ogreTexture;
        Texture orcTexture;

        //map and entitites sprites
        Sprite mapSprite;
        Sprite pauseSprite;
        Sprite acideCloudSprite;
        Sprite lightningSprite;
        Sprite fireSprite;
        //map and entitites textures
        Texture mapTexture;
        Texture pauseTexture;
        Texture acideCloudTexture;
        Texture lightningTexture;
        Texture fireTexture;

        Texture acideCloudEffectTexture;

        //Towers textures
        /* without number = icon button*/
        Texture earthTowerTexture;

        Texture earthTowerTexture1;
        Texture earthTowerTexture2;
        Texture earthTowerTexture3;

        Texture sandTowerTexture;

        Texture sandTowerTexture1;
        Texture sandTowerTexture2;
        Texture sandTowerTexture3;

        Texture iceTowerTexture;

        Texture iceTowerTexture1;
        Texture iceTowerTexture2;
        Texture iceTowerTexture3;

        Texture ironTowerTexture;

        Texture ironTowerTexture1;
        Texture ironTowerTexture2;
        Texture ironTowerTexture3;

        //Tower sprites
        Sprite earthTowerSprite;
        Sprite sandTowerSprite;
        Sprite iceTowerSprite;
        Sprite ironTowerSprite;

};

#endif // VGAMEBOARD_H
