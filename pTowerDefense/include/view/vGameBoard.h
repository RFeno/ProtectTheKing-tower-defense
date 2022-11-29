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

        //canonic
        vGameBoard(sf::RenderWindow &window);
        virtual ~vGameBoard();
        vGameBoard(const vGameBoard& other);
        vGameBoard& operator=(const vGameBoard& other);

        void launchView();
        void loadSprite();
        bool drawEntities();
        void updateGame();
        void loadFont();


        //load images
        bool verifyImage();
        bool verifyImageTower();
        bool verifyImageMonsters();
        bool verifyImageMapEntities();
        bool verifyImageInformations();

        //events
        void InputHandler(sf::Event event,sf::RenderWindow *window);
        bool isSpriteClicked (sf::Sprite &spr);

        //methods
        void launchGame();
        void updateVennemyForView();
        void updateHealthBarAllEnemies();
        void enemyAnimation();
        void animationEnemyWalk2(sf::Sprite *enemy);
        void enemiesSpawn();
        void displayEnd();
        void buyTower(TypeOfTower type, int position);
        bool removeVTower(int position);
        int searchVTower(int position);
        bool removeVEnemy(vEnnemy& enemy);
        int searchVEnemy(vEnnemy& enemy);

        /*these methods are used to calculate the positions of the towers*/
        void getPositionOfNewTower(TypeOfTower type, int &x, int &y, int position);
        void getPositionOfEarth(int &x, int &y, int position);
        void getPositionOfIron(int &x, int &y, int position);
        void getPositionOfIce(int &x, int &y, int position);
        void getPositionOfSand(int &x, int &y, int position);

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
        TypeOfTower typeTowerChoosed;

        sf::Clock animClock;
        sf::Clock spawnClock;
        sf::Clock attackClock;
        sf::Clock gameSpeedClook;

        Game game;
        sf::RenderWindow *windowFromMain;

        //King
        sf::Texture kingHealthGreenTexture;
        sf::Texture kingHealthRedTexture;
        sf::Sprite kingHealthGreenSprite;
        sf::Sprite kingHealthRedSprite;
        sf::RectangleShape KingHpBar;
        sf::RectangleShape KingHpBarBack;

        //walk
        sf::Texture gremlinTextureWalk;
        sf::Texture knightOfDeathTextureWalk;
        sf::Texture shadowMonsterTextureWalk ;
        sf::Texture ogreTextureWalk;
        sf::Texture orcTextureWalk;

        //attack
        sf::Texture gremlinAttackTexture;
        sf::Texture knightOfDeathAttackTexture ;
        sf::Texture shadowMonsterAttackTexture;
        sf::Texture ogreAttackTexture ;
        sf::Texture orcAttackTexture ;

        //dead
        sf::Texture gremlinDeadTexture ;
        sf::Texture knightOfDeathDeadTexture ;
        sf::Texture shadowMonsterDeadTexture;
        sf::Texture ogreDeadTexture;
        sf::Texture orcDeadTexture ;

        //map and entitites sprites
        sf::Sprite mapSprite;
        sf::Sprite pauseSprite;
        sf::Sprite acideCloudSprite;
        sf::Sprite lightningSprite;
        sf::Sprite fireSprite;

        //map and entitites textures
        sf::Texture mapTexture;
        sf::Texture pauseTexture;
        sf::Texture acideCloudTexture;
        sf::Texture lightningTexture;
        sf::Texture fireTexture;

        sf::Texture acideCloudEffectTexture;

        //Towers textures
        /* without number = icon button*/
        sf::Texture earthTowerTextureButton;

        sf::Texture earthTowerTexture1;

        sf::Texture earthAttack;

        sf::Texture sandTowerTextureButton;

        sf::Texture sandTowerTexture1;

        sf::Texture sandAttack;

        sf::Texture iceTowerTextureButton;

        sf::Texture iceTowerTexture1;

        sf::Texture iceAttack;

        sf::Texture ironTowerTextureButton;

        sf::Texture ironTowerTexture1;

        sf::Texture ironAttack;

        //Tower sprites
        sf::Sprite earthTowerSprite;
        sf::Sprite sandTowerSprite;
        sf::Sprite iceTowerSprite;
        sf::Sprite ironTowerSprite;

        //informations textures
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


        //informations sprite
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
