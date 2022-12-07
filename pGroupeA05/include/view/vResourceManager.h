#ifndef VRESOURCEMANAGER_H
#define VRESOURCEMANAGER_H

#include <SFML/Graphics.hpp>
#include "vEnnemy.h"
#include "vTower.h"
#include "Game.h"

class vResourceManager
{
    public:
        vResourceManager();
        virtual ~vResourceManager();

        bool verifyImage();
        bool verifyImageTower();
        bool verifyImageMonsters();
        bool verifyImageMapEntities();
        bool verifyImageTowersInformations();

        ///IMAGES
        void loadSprite();
        void loadGameSpeedEntities();
        void loadSpellEntities();
        void loadTowersEntities();
        void loadMapEntities();
        void loadKingEntities();
        void loadFailEntities();
        void loadChoosingNumberEntities();
        void loadStatsPlayerEntities();

        void loadFont();

        void createText(sf::Text& text, sf::Color colorFill, sf::Color colorOutline, std::string str, float xScale, float yScale, int xPosition, int yPosition);
        void createSprite(sf::Sprite& sprite, sf::Texture& texture, float xScale, float yScale, int xPosition, int yPosition);


        sf::Font font;
        sf::Color grey = sf::Color(200,200,200);

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
        sf::Sprite windowSmallSpellSprite;
        sf::Sprite windowSmallTowerSprite;
        sf::Sprite headerShopSprite;

        ///Map and entitites textures
        sf::Texture mapTexture;
        sf::Texture pauseTexture;
        sf::Texture emptyButtonTexture;
        sf::Texture closeButtonTexture;
        sf::Texture headerShopTexture;
        sf::Texture windowSmallTexture;
        sf::Texture bigTableTexture;

        ///Map and entitites texts
        sf::Text playerGemsNumberText;
        sf::Text waveNumberText;
        sf::Text waveText;
        sf::Text scoreNumberText;
        sf::Text scoreText;
        sf::Text messagePopUpText;

        ///Spell textures
        sf::Texture acideCloudActiveButtonTexture;
        sf::Texture lightningActiveButtonTexture;
        sf::Texture fireActiveButtonTexture;
        sf::Texture acideCloudEffectTexture;
        sf::Texture fireEffectTexture;
        sf::Texture lightningEffectTexture;

        ///Spell sprites:
        sf::Sprite fireBuyButtonSprite;
        sf::Sprite acideCloudBuyButtonSprite;
        sf::Sprite lightningBuyButtonSprite;

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
        sf::Texture earthAttack;
        sf::Texture sandAttack;
        sf::Texture iceAttack;
        sf::Texture ironAttack;

        ///Towers buy buttons textures
        sf::Texture earthTowerTextureButton;
        sf::Texture sandTowerTextureButton;
        sf::Texture iceTowerTextureButton;
        sf::Texture ironTowerTextureButton;

        ///Towers textures
        sf::Texture sandTowerTexture1;
        sf::Texture iceTowerTexture1;
        sf::Texture ironTowerTexture1;
        sf::Texture earthTowerTexture1;

        ///Tower buttons sprites
        sf::Sprite earthTowerButtonSprite;
        sf::Sprite sandTowerButtonSprite;
        sf::Sprite iceTowerButtonSprite;
        sf::Sprite ironTowerButtonSprite;

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
        sf::Texture oneTexture;
        sf::Texture twoTexture;
        sf::Texture threeTexture;
        sf::Texture fourTexture;
        sf::Texture fiveTexture;
        sf::Texture sixTexture;
        sf::Texture sevenTexture;
        sf::Texture gemTexture;
        sf::Texture swordTexture;
        sf::Texture signTexture;

        ///Failed textures
        sf::Texture headerFailedTexture;
        sf::Texture resetButtonTexture;
        sf::Texture backgroundTexture;

        ///Failed Sprites
        sf::Sprite tableEmptyFailSprite;
        sf::Sprite windowFailSprite;
        sf::Sprite resetButtonFailSprite;
        sf::Sprite headerFailedSprite;
        sf::Sprite backgroundSprite;

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

        /**A déplacer */
        sf::Texture tableEmptyTexture;

        std::vector<vEnnemy*> listOfvEnnemies;
        std::vector<vTower*> listOfvTower;
        std::vector<sf::Sprite*> listOfAcideCloudSpell;
        std::vector<sf::Sprite*> listOfFireSpell;
        std::vector<sf::Sprite*> listOfLigntningSpell;

    protected:

    private:
        const int NUMBER_ACID_SPELL = 13;
        const int NUMBER_FIRE_SPELL = 13;
        const int NUMBER_LIGHTNING_SPELL = 24;
};

#endif // VRESOURCEMANAGER_H
