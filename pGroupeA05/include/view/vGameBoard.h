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

        vGameBoard(sf::RenderWindow &window);
        virtual ~vGameBoard();

        ///DISPLAY
        void launchView();

        /**DRAW*/
        void drawEntities();

        void drawEnemies();
        void drawOneEnemy(vEnnemy *enemy);

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
        bool verifyImageTowersInformations();

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



        ///ADAPT IMAGES
        void adaptAnimationSprite();
        void adaptAnimationTexture();
        void adaptPartOfTexture();
        void updateKingHealth();



    protected:

    private:

        const int NUMBER_ACIDE_SPELL = 13;


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

        bool isChoosingNumberForPositionTower = false;
        bool isSellingTower = false;

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

        ///enemies walk textures
        sf::Texture gremlinTextureWalk;
        sf::Texture knightOfDeathTextureWalk;
        sf::Texture shadowMonsterTextureWalk ;
        sf::Texture ogreTextureWalk;
        sf::Texture orcTextureWalk;

        ///enemies attack textures
        sf::Texture gremlinAttackTexture;
        sf::Texture knightOfDeathAttackTexture ;
        sf::Texture shadowMonsterAttackTexture;
        sf::Texture ogreAttackTexture ;
        sf::Texture orcAttackTexture ;

        ///enemies dead textures
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
        std::vector<sf::Sprite*> oneSprites;
        std::vector<sf::Sprite*> twoSprites;
        std::vector<sf::Sprite*> threeSprites;
        std::vector<sf::Sprite*> fourSprites;
        std::vector<sf::Sprite*> fiveSprites;
        std::vector<sf::Sprite*> sixSprites;
        std::vector<sf::Sprite*> sevenSprites;

        /**A déplacer */
        sf::Texture tableEmptyTexture;
        sf::Texture headerFailedTexture;
        sf::Texture resetButtonTexture;

};

#endif // VGAMEBOARD_H