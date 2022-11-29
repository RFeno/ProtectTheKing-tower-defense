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

        //
        void launchView();
        void loadSprite();
        bool drawEntities();
        void updateGame();
        void loadFont();


        //laod images
        bool verifyImage();
        bool verifyImageTower();
        bool verifyImageMonsters();
        bool verifyImageMapEntities();
        bool verifyImageInformations();


        //events
        void InputHandler(Event event, RenderWindow *window);
        bool isSpriteClicked (Sprite &spr);

        //methods
        void launchGame();
        void updateVennemyForView();
        void updateHealthBarAllEnemies();
        void enemyAnimation();
        void animationEnemyWalk2(Sprite *enemy);
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

        sf::Clock animClock;
        sf::Clock spawnClock;
        sf::Clock attackClock;
        sf::Clock gameSpeedClook;

        Game game;
        RenderWindow *windowFromMain;

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

        Texture earthTowerTexture1;

        Texture earthAttack;

        Texture sandTowerTextureButton;

        Texture sandTowerTexture1;

        Texture sandAttack;

        Texture iceTowerTextureButton;

        Texture iceTowerTexture1;

        Texture iceAttack;

        Texture ironTowerTextureButton;

        Texture ironTowerTexture1;

        Texture ironAttack;

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
