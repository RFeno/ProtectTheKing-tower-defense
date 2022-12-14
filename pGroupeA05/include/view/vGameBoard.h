#ifndef VGAMEBOARD_H
#define VGAMEBOARD_H

#include <SFML/Graphics.hpp>
#include "Enemies.h"
#include "Game.h"
#include "vEnnemy.h"
#include "vTower.h"
#include "vResourceManager.h"

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
        void drawSpellEntities();
        void drawFailEntities();


        //void createText(sf::Text& text, sf::Color colorFill, sf::Color colorOutline, std::string str, float xScale, float yScale, int xPosition, int yPosition);

        bool verifyImage();


        ///EVENTS
        void InputHandler(sf::Event event);
        void eventsTowers();
        void eventsGameSpeed();
        void eventsChoiceTowers();
        void eventsActiveTowersChoice(TypeOfTowerPrice type);
        void eventsSpells();
        void eventsActiveSpell(TypeOfSpell type);
        bool isSpriteClicked (sf::Sprite &spr);
        void activeMessagePopUp(std::string message);

        void launchGame();

        ///UPDATE
        void updateGame();
        void updateVennemyForView();
        void updateHealthBarAllEnemies();
        void enemyAnimation();
        void displayEnd();
        void changeStatsPosition();


        ///TOWERS
        void buyTower(TypeOfTowerPrice type, int position);
        bool removeVTower(int position);
        int searchVTower(int position);
        bool removeVEnemy(vEnnemy& enemy);
        int searchVEnemy(vEnnemy& enemy);
        void sellTower(int position);

        ///ADAPT IMAGES
        void adaptAnimationSprite();
        void adaptAnimationTexture();
        void adaptPartOfTexture();
        void updateKingHealth();


        void resetGameView();



    protected:

    private:

        const int NUMBER_ACID_SPELL = 13;
        const int NUMBER_FIRE_SPELL = 13;
        const int NUMBER_LIGHTNING_SPELL = 24;

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
        int x_fire = 0;
        int x_lightning =0;

        bool isChoosingNumberForPositionTower = false;
        bool isSellingTower = false;
        bool isMessagePopUp = false;

        TypeOfTowerPrice typeTowerChoosed;

        sf::Clock animClock;
        sf::Clock spawnClock;
        sf::Clock attackClock;
        sf::Clock gameSpeedClook;
        sf::Clock attackTowerClock;
        sf::Clock messageClock;
        sf::Clock acidCloudSpellClock;
        sf::Clock fireSpellClock;
        sf::Clock lightningSpellClock;

        Game game;
        vResourceManager resourceManager;
        sf::RenderWindow *windowFromMain;

        sf::Font *font;

        ///entities gameSpeed textures
        sf::Texture *pauseButtonTexture;
        sf::Texture *increaseSpeedButtonTexture;
        sf::Texture *decreaseSpeedButtonTexture;
        sf::Texture *infoBulbleMessageTexture;
        sf::Texture *playGameButtonTexture;
        sf::Texture *multiplierTexture;

        ///entities gameSpeed sprites
        sf::Sprite *pauseButtonSprite;
        sf::Sprite *increaseSpeedButtonSprite;
        sf::Sprite *decreaseSpeedButtonSprite;
        sf::Sprite *infoBulbleMessageSprite;
        sf::Sprite *playGameButtonSprite;
        sf::Sprite *gameSpeedEmptyTableSprite;
        sf::Sprite *multiplierSprite;
        sf::Sprite *gameSpeedOneSprite;
        sf::Sprite *gameSpeedTwoSprite;
        sf::Sprite *gameSPeedThreeSprite;

        ///King health
        sf::Texture *kingHealthGreenTexture;
        sf::Texture *kingHealthRedTexture;
        sf::Sprite *kingHealthGreenSprite;
        sf::Sprite *kingHealthRedSprite;

        ///enemies walk textures
        sf::Texture *gremlinTextureWalk;
        sf::Texture *knightOfDeathTextureWalk;
        sf::Texture *shadowMonsterTextureWalk ;
        sf::Texture *ogreTextureWalk;
        sf::Texture *orcTextureWalk;

        ///enemies attack textures
        sf::Texture *gremlinAttackTexture;
        sf::Texture *knightOfDeathAttackTexture ;
        sf::Texture *shadowMonsterAttackTexture;
        sf::Texture *ogreAttackTexture ;
        sf::Texture *orcAttackTexture ;

        ///enemies dead textures
        sf::Texture *gremlinDeadTexture ;
        sf::Texture *knightOfDeathDeadTexture ;
        sf::Texture *shadowMonsterDeadTexture;
        sf::Texture *ogreDeadTexture;
        sf::Texture *orcDeadTexture ;

        ///map and entitites sprites
        sf::Sprite *mapSprite;
        sf::Sprite *pauseSprite;
        sf::Sprite *acideCloudSprite;
        sf::Sprite *lightningSprite;
        sf::Sprite *fireSprite;
        sf::Sprite *sellButtonSprite;
        sf::Sprite *closeButtonSprite;
        sf::Sprite *windowSmallSpellSprite;
        sf::Sprite *windowSmallTowerSprite;
        sf::Sprite *headerShopSprite;

        ///Map and entitites textures
        sf::Texture *mapTexture;
        sf::Texture *pauseTexture;
        sf::Texture *emptyButtonTexture;
        sf::Texture *closeButtonTexture;
        sf::Texture *headerShopTexture;
        sf::Texture *windowSmallTexture;
        sf::Texture *bigTableTexture;

        ///Map and entitites texts
        sf::Text playerGemsNumberText;
        sf::Text waveNumberText;
        sf::Text waveText;
        sf::Text scoreNumberText;
        sf::Text scoreText;
        sf::Text messagePopUpText;

        ///Spell textures
        sf::Texture *acideCloudActiveButtonTexture;
        sf::Texture *lightningActiveButtonTexture;
        sf::Texture *fireActiveButtonTexture;
        sf::Texture *acideCloudEffectTexture;
        sf::Texture *fireEffectTexture;
        sf::Texture *lightningEffectTexture;

        ///Spell sprites:
        sf::Sprite *fireBuyButtonSprite;
        sf::Sprite *acideCloudBuyButtonSprite;
        sf::Sprite *lightningBuyButtonSprite;

        ///Spell texts
        sf::Text spellTitleText;
        sf::Text acidStockText;
        sf::Text fireStockText;
        sf::Text lightningStockText;
        sf::Text acidStockNumberText;
        sf::Text fireStockNumberText;
        sf::Text lightningStockNumberText;
        sf::Text acidAttackNumberText;
        sf::Text fireAttackNumberText;
        sf::Text lightningAttackNumberText;
        sf::Text acidPriceText;
        sf::Text firePriceText;
        sf::Text lightningPriceText;

        ///Towers attacks textures
        sf::Texture *earthAttack;
        sf::Texture *sandAttack;
        sf::Texture *iceAttack;
        sf::Texture *ironAttack;

        ///Towers buy buttons textures
        sf::Texture *earthTowerTextureButton;
        sf::Texture *sandTowerTextureButton;
        sf::Texture *iceTowerTextureButton;
        sf::Texture *ironTowerTextureButton;

        ///Towers textures
        sf::Texture *sandTowerTexture1;
        sf::Texture *iceTowerTexture1;
        sf::Texture *ironTowerTexture1;
        sf::Texture *earthTowerTexture1;

        ///Tower buttons sprites
        sf::Sprite *earthTowerButtonSprite;
        sf::Sprite *sandTowerButtonSprite;
        sf::Sprite *iceTowerButtonSprite;
        sf::Sprite *ironTowerButtonSprite;

        ///Informations tower texts
        sf::Text towerTitleText;
        sf::Text sellText;
        sf::Text chooseNumberText;
        sf::Text earthAttackText;
        sf::Text earthPriceText;
        sf::Text iceAttackText;
        sf::Text icePriceText;
        sf::Text sandAttackText;
        sf::Text sandPriceText;
        sf::Text ironAttackText;
        sf::Text ironPriceText;

        ///Informations tower textures
        sf::Texture *oneTexture;
        sf::Texture *twoTexture;
        sf::Texture *threeTexture;
        sf::Texture *fourTexture;
        sf::Texture *fiveTexture;
        sf::Texture *sixTexture;
        sf::Texture *sevenTexture;
        sf::Texture *gemTexture;
        sf::Texture *swordTexture;
        sf::Texture *signTexture;

        ///Failed textures
        sf::Texture *headerFailedTexture;
        sf::Texture *resetButtonTexture;
        sf::Texture *backgroundTexture;

        ///Failed Sprites
        sf::Sprite *tableEmptyFailSprite;
        sf::Sprite *windowFailSprite;
        sf::Sprite *resetButtonFailSprite;
        sf::Sprite *headerFailedSprite;
        sf::Sprite *backgroundSprite;

        ///Failed texts
        sf::Text enemiesKilledText;
        sf::Text enemiesKilledNumberText;

        std::vector<sf::Sprite*> swordSprites;
        std::vector<sf::Sprite*> gemSprites;
        std::vector<sf::Sprite*> signSprites;
        std::vector<sf::Sprite*> oneSprites;
        std::vector<sf::Sprite*> twoSprites;
        std::vector<sf::Sprite*> threeSprites;
        std::vector<sf::Sprite*> fourSprites;
        std::vector<sf::Sprite*> fiveSprites;
        std::vector<sf::Sprite*> sixSprites;
        std::vector<sf::Sprite*> sevenSprites;

        /**utils */
        sf::Texture *tableEmptyTexture;
};

#endif // VGAMEBOARD_H
