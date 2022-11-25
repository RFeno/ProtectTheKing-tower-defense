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

        void updateGame();

        void loadFont();


        //laod images
        bool verifyImage();
        bool verifyImageTower();
        bool verifyImageMonsters();
        bool verifyImageMapEntities();
        bool verifyImageInformations();
        bool chargesEnemiesTextures();

        //events
        bool drawEntities();
        void InputHandler(Event event, RenderWindow *window);
        bool isSpriteClicked (Sprite &spr);

        //methods
        void launchGame();
        void updateVennemyForView();
        void enemyAnimation();
        void animationEnemyWalk2(Sprite *enemy);
        void enemiesSpawn();
        void displayEnd();
        void buyTower(TypeOfTower type);
        bool removeVEnemy(vEnnemy& enemy);
        int searchVEnemy(vEnnemy& enemy);

        /*these methods are used to calculate the positions of the towers*/
        sf::Vector2f* getPositionOfNewTower(TypeOfTower type);
        sf::Vector2f* getPositionOfEarth();
        sf::Vector2f* getPositionOfIron();
        sf::Vector2f* getPositionOfIce();
        sf::Vector2f* getPositionOfSand();


        bool setTower(int x, int y, int type);
        //bool setTower(int y, int x, Tower* t);


        void activeFireSpell();
        void activeLightningSpeel();
        void activeCloudSpell();
        void adaptAnimationSprite();
        void adaptAnimationTexture();
        void adaptPartOfTexture();


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


        const int NUMBER_ACIDE_SPELL = 13;



        int idSpawn = 0;
        int spawnTime = 3;

        //std::vector<Sprite*> enemiesSprite;
        std::vector<vEnnemy*> listOfvEnnemies;
        std::vector<vTower*> listOfvTower;
        std::vector<Sprite*> listOfAcideCloudSpell;
        std::vector<Sprite*> listOfFireSpell;
        std::vector<Sprite*> listOfLigntningSpell;


        //x and y serve to reset the animation of sprites in fonction of diffrents size of sprite


        int x_acide = 0;

        Clock animClock;
        Clock spawnClock;
        Clock attackClock;

        Game game;
        RenderWindow *windowFromMain;

        //walk
        Texture gremlinTextureWalk;
        Texture knightOfDeathTextureWalk;
        Texture shadowMonsterTextureWalk ;
        Texture ogreTextureWalk;
        Texture orcTextureWalk;

        //attack
        Texture gremlinAttackTexture;
        Texture knightOfDeathAttackTexture ;
        Texture shadowMonsterAttackTexture;
        Texture ogreAttackTexture ;
        Texture orcAttackTexture ;

        //dead
        Texture gremlinDeadTexture ;
        Texture knightOfDeathDeadTexture ;
        Texture shadowMonsterDeadTexture;
        Texture ogreDeadTexture;
        Texture orcDeadTexture ;

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

        //informations textures
        Texture twentyTexture;
        Texture fourtyTexture;
        Texture sixtyTexture;
        Texture eightyTexture;
        Texture oneHundredTexture;
        Texture oneHundredFiftyTexture;
        Texture twoHundredFiftyTexture;
        Texture fourHundredTexture;
        Texture crystalTexture;
        Texture swordTexture;
        Texture signTexture;


        //informations sprite
        Sprite twentySprite;
        Sprite fourtySprite;
        Sprite sixtySprite;
        Sprite eightySprite;
        Sprite oneHundredSprite;
        Sprite oneHundredFiftySprite;
        Sprite twoHundredFiftySprite;
        Sprite fourHundredSprite;
        std::vector<Sprite*> swordSprites;
        std::vector<Sprite*> crystalSprites;
        std::vector<Sprite*> signSprites;

};

#endif // VGAMEBOARD_H
