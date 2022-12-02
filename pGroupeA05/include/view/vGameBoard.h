#ifndef VGAMEBOARD_H
#define VGAMEBOARD_H

#include <SFML/Graphics.hpp>
#include "Enemies.h"
#include "Game.h"
#include "vEnnemy.h"
#include "vTower.h"


class vGameBoard
{
    public:

        ///canonic
        vGameBoard(sf::RenderWindow &window);
        virtual ~vGameBoard();
        vGameBoard(const vGameBoard& other);
        vGameBoard& operator=(const vGameBoard& other);

        ///DISPLAY
        void launchView();

        /**DRAW*/
        void drawEntities();

        void drawEnemies();

        void drawMapEntities();
        void drawMapButtons();

        void drawTowers();

        void drawGameSpeedView();

        void loadFont();

        ///IMAGES
        void loadSprite();
        void loadGameSpeedEntities();

        bool verifyImage();
        bool verifyImageTower();
        bool verifyImageMonsters();
        bool verifyImageMapEntities();
        bool verifyImageInformations();

        ///EVENTS
        void InputHandler(sf::Event event,sf::RenderWindow *window);
        bool isSpriteClicked (sf::Sprite &spr);

        void launchGame();

        ///UPDATE
        void updateGame();
        void updateVennemyForView();
        void updateHealthBarAllEnemies();
        void enemyAnimation();
        void displayEnd();


        ///TOWERS
        void buyTower(TypeOfTower type, int position);
        bool removeVTower(int position);
        int searchVTower(int position);
        bool removeVEnemy(vEnnemy& enemy);
        int searchVEnemy(vEnnemy& enemy);


        /**A DEPLACER DANS LE MODEL car traitements */
        /*these methods are used to calculate the positions of the towers*/
        void getPositionOfNewTower(TypeOfTower type, int &x, int &y, int position);
        void getPositionOfEarth(int &x, int &y, int position);
        void getPositionOfIron(int &x, int &y, int position);
        void getPositionOfIce(int &x, int &y, int position);
        void getPositionOfSand(int &x, int &y, int position);

        ///ADAPTE IMAGES
        void adaptAnimationSprite();
        void adaptAnimationTexture();
        void adaptPartOfTexture();
        void updateKingHealth();



    protected:

    private:

        const int OGRE_WIDTH = 377;
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
        bool gamePaused=false;


        std::vector<vEnnemy*> listOfvEnnemies;
        std::vector<vTower*> listOfvTower;
        std::vector<sf::Sprite*> listOfAcideCloudSpell;
        std::vector<sf::Sprite*> listOfFireSpell;
        std::vector<sf::Sprite*> listOfLigntningSpell;

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

        bool isChoosingNumberForPositionTower;
        bool isSellingTower;

        TypeOfTower typeTowerChoosed;

        sf::Clock animClock;
        sf::Clock spawnClock;
        sf::Clock attackClock;
        sf::Clock gameSpeedClook;
        sf::Clock attackTowerClock;

        Game game;
        sf::RenderWindow *windowFromMain;

        // texts
        sf::Font font;
        sf::Text sellText;
        sf::Text chooseNumberText;


        ///entities gameSpeed textures
        sf::Texture pauseButtonTexture;
        sf::Texture increaseSpeedButtonTexture;
        sf::Texture decreaseSpeedButtonTexture;
        sf::Texture infoBulbleMessageTexture;
        sf::Texture playGameButtonTexture;
        sf::Texture multiplierTexture;

        ///entities gameSpeed sprites
        sf::Sprite pauseButtonSprite;
        sf::Sprite increaseSpeedButtonSprite;
        sf::Sprite decreaseSpeedButtonSprite;
        sf::Sprite infoBulbleMessageSprite;
        sf::Sprite playGameButtonSprite;
        sf::Sprite gameSpeedEmptyTableSprite;
        sf::Sprite multiplierSprite;
        sf::Sprite gameSpeedOneSprite;
        sf::Sprite gameSpeedTwoSprite;
        sf::Sprite gameSPeedThreeSprite;

        ///King health
        sf::Texture kingHealthGreenTexture;
        sf::Texture kingHealthRedTexture;
        sf::Sprite kingHealthGreenSprite;
        sf::Sprite kingHealthRedSprite;

        ///enemies walk
        sf::Texture gremlinTextureWalk;
        sf::Texture knightOfDeathTextureWalk;
        sf::Texture shadowMonsterTextureWalk ;
        sf::Texture ogreTextureWalk;
        sf::Texture orcTextureWalk;

        ///enemies attack
        sf::Texture gremlinAttackTexture;
        sf::Texture knightOfDeathAttackTexture ;
        sf::Texture shadowMonsterAttackTexture;
        sf::Texture ogreAttackTexture ;
        sf::Texture orcAttackTexture ;

        ///enemies dead
        sf::Texture gremlinDeadTexture ;
        sf::Texture knightOfDeathDeadTexture ;
        sf::Texture shadowMonsterDeadTexture;
        sf::Texture ogreDeadTexture;
        sf::Texture orcDeadTexture ;

        ///map and entitites sprites
        sf::Sprite mapSprite;
        sf::Sprite pauseSprite;
        sf::Sprite acideCloudSprite;
        sf::Sprite lightningSprite;
        sf::Sprite fireSprite;
        sf::Sprite sellButtonSprite;
        sf::Sprite closeButtonSprite;

        ///Map and entitites textures
        sf::Texture mapTexture;
        sf::Texture pauseTexture;
        sf::Texture acideCloudTexture;
        sf::Texture lightningTexture;
        sf::Texture fireTexture;
        sf::Texture emptyButtonTexture;
        sf::Texture closeButtonTexture;
        sf::Texture headerUpgradeTexture;


        ///Speel textures
        sf::Texture acideCloudEffectTexture;

        ///Towers textures
        sf::Texture earthAttack;
        sf::Texture sandAttack;
        sf::Texture iceAttack;
        sf::Texture ironAttack;

        sf::Texture earthTowerTextureButton;
        sf::Texture sandTowerTextureButton;
        sf::Texture iceTowerTextureButton;
        sf::Texture ironTowerTextureButton;

        sf::Texture sandTowerTexture1;
        sf::Texture iceTowerTexture1;
        sf::Texture ironTowerTexture1;
        sf::Texture earthTowerTexture1;

        ///Tower sprites
        sf::Sprite earthTowerButtonSprite;
        sf::Sprite sandTowerButtonSprite;
        sf::Sprite iceTowerButtonSprite;
        sf::Sprite ironTowerButtonSprite;

        ///Informations tower textures
        sf::Texture oneTexture;
        sf::Texture twoTexture;
        sf::Texture threeTexture;
        sf::Texture fourTexture;
        sf::Texture fiveTexture;
        sf::Texture sixTexture;
        sf::Texture sevenTexture;
        sf::Texture twentyTexture;
        sf::Texture fourtyTexture;
        sf::Texture sixtyTexture;
        sf::Texture eightyTexture;
        sf::Texture oneHundredTexture;
        sf::Texture oneHundredFiftyTexture;
        sf::Texture twoHundredFiftyTexture;
        sf::Texture fourHundredTexture;
        sf::Texture crystalTexture;
        sf::Texture swordTexture;
        sf::Texture signTexture;


        ///informations sprite
        sf::Sprite oneSprite;
        sf::Sprite twoSprite;
        sf::Sprite threeSprite;
        sf::Sprite fourSprite;
        sf::Sprite fiveSprite;
        sf::Sprite sixSprite;
        sf::Sprite sevenSprite;
        sf::Sprite twentySprite;
        sf::Sprite fourtySprite;
        sf::Sprite sixtySprite;
        sf::Sprite eightySprite;
        sf::Sprite oneHundredSprite;
        sf::Sprite oneHundredFiftySprite;
        sf::Sprite twoHundredFiftySprite;
        sf::Sprite fourHundredSprite;

        std::vector<sf::Sprite*> swordSprites;
        std::vector<sf::Sprite*> crystalSprites;
        std::vector<sf::Sprite*> signSprites;

};

#endif // VGAMEBOARD_H
