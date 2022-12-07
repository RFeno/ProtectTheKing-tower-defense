#include "vResourceManager.h"

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Spell.h"

/**TOWERS*/
#include "TowerEarth.h"
#include "TowerIce.h"
#include "TowerIron.h"
#include "TowerSand.h"

using namespace std;
using namespace sf;

vResourceManager::vResourceManager()
{
    verifyImage();
    //ctor
    for(int i=0; i< 10; i++)
    {
        //create vEnemy with nullptr enemy
        vEnnemy *venemy = new vEnnemy();

        //set all textures of enemies
        venemy->gremlinAttackTexture =&gremlinAttackTexture;
        venemy->gremlinDeadTexture = &gremlinDeadTexture;
        venemy->gremlinTextureWalk = &gremlinTextureWalk;

        venemy->ogreAttackTexture = &ogreAttackTexture;
        venemy->ogreDeadTexture = &ogreDeadTexture;
        venemy->ogreTextureWalk = &ogreTextureWalk;

        venemy->orcAttackTexture = &orcAttackTexture;
        venemy->orcDeadTexture = &orcDeadTexture;
        venemy->orcTextureWalk = &orcTextureWalk;

        venemy->knightOfDeathAttackTexture = &knightOfDeathAttackTexture;
        venemy->knightOfDeathDeadTexture = &knightOfDeathDeadTexture;
        venemy->knightOfDeathTextureWalk = &knightOfDeathTextureWalk;

        venemy->shadowMonsterAttackTexture = &shadowMonsterAttackTexture;
        venemy->shadowMonsterDeadTexture = &shadowMonsterDeadTexture;
        venemy->shadowMonsterTextureWalk = &shadowMonsterTextureWalk;

        //health bar textures
        venemy->healthBarGreenTexture = &kingHealthGreenTexture;
        venemy->healthBarRedTexture = &kingHealthRedTexture;

        listOfvEnnemies.push_back(venemy);
    }

    ///spells sprites
    for(int i=0; i < NUMBER_ACID_SPELL; i++)
    {
        listOfAcideCloudSpell.push_back(new Sprite());
    }

    for(int i=0; i < NUMBER_FIRE_SPELL; i++)
    {
        listOfFireSpell.push_back(new Sprite());
    }

    for(int i=0; i < NUMBER_LIGHTNING_SPELL; i++)
    {
        listOfLigntningSpell.push_back(new Sprite());
    }
}

vResourceManager::~vResourceManager()
{
    //dtor
     ///ENEMIES
    for(vEnnemy *venemy: listOfvEnnemies)
    {
        delete venemy;
    }

    ///SPELLS
    for(Sprite *acide: listOfAcideCloudSpell)
    {
        delete acide;
    }

    for(Sprite *fire: listOfFireSpell)
    {
        delete fire;
    }

    for(Sprite *lightning: listOfLigntningSpell)
    {
        delete lightning;
    }

    ///TOWERS
    for(vTower *vTower: listOfvTower)
    {
        delete vTower;
    }

    ///INFORMATIONS AND DIGITS
    for(Sprite *gem: gemSprites)
    {
        delete gem;
    }

    for(Sprite *sign: signSprites)
    {
        delete sign;
    }

    for(Sprite *sword: swordSprites)
    {
        delete sword;
    }

    for(Sprite *one: oneSprites)
    {
        delete one;
    }

    for(Sprite *two: twoSprites)
    {
        delete two;
    }

    for(Sprite *three: threeSprites)
    {
        delete three;
    }

    for(Sprite *four: fourSprites)
    {
        delete four;
    }

    for(Sprite *five: fiveSprites)
    {
        delete five;
    }

    for(Sprite *six: sixSprites)
    {
        delete six;
    }

    for(Sprite *seven: sevenSprites)
    {
        delete seven;
    }
}

/** load and configure game speed entitites */
void vResourceManager::loadGameSpeedEntities()
{
    ///gameSpeed
    infoBulbleMessageSprite.setTexture(infoBulbleMessageTexture);
    pauseButtonSprite.setTexture(pauseButtonTexture);
    increaseSpeedButtonSprite.setTexture(increaseSpeedButtonTexture);
    decreaseSpeedButtonSprite.setTexture(decreaseSpeedButtonTexture);
    playGameButtonSprite.setTexture(playGameButtonTexture);
    gameSpeedEmptyTableSprite.setTexture(emptyButtonTexture);
    multiplierSprite.setTexture(multiplierTexture);
    gameSpeedOneSprite.setTexture(oneTexture);
    gameSpeedTwoSprite.setTexture(twoTexture);
    gameSPeedThreeSprite.setTexture(threeTexture);

    multiplierSprite.setRotation(80.0f);
    infoBulbleMessageSprite.setPosition(1233, 215);
    pauseButtonSprite.setPosition(660, 707);
    increaseSpeedButtonSprite.setPosition(760, 707);
    decreaseSpeedButtonSprite.setPosition(560, 707);
    playGameButtonSprite.setPosition(665, 712);
    gameSpeedEmptyTableSprite.setPosition(663,655);
    multiplierSprite.setPosition(702,668);

    gameSpeedOneSprite.setPosition(710,672);
    gameSpeedTwoSprite.setPosition(710,672);
    gameSPeedThreeSprite.setPosition(710,672);

    infoBulbleMessageSprite.setScale(Vector2f(0.25f,0.25f));
    pauseButtonSprite.setScale(Vector2f(0.5f,0.5f));
    increaseSpeedButtonSprite.setScale(Vector2f(0.5f,0.5f));
    decreaseSpeedButtonSprite.setScale(Vector2f(0.5f,0.5f));
    playGameButtonSprite.setScale(Vector2f(0.24f,0.24f));
    gameSpeedEmptyTableSprite.setScale(0.35f,0.35f);
    multiplierSprite.setScale(0.25f,0.25f);

    gameSpeedOneSprite.setScale(0.35f,0.35f);
    gameSpeedTwoSprite.setScale(0.35f,0.35f);
    gameSPeedThreeSprite.setScale(0.35f,0.35f);
}

/** load all entities for spell */
void vResourceManager::loadSpellEntities()
{
    /// buttons to active spells
    acideCloudSprite.setTexture(acideCloudActiveButtonTexture);
    fireSprite.setTexture(fireActiveButtonTexture);
    lightningSprite.setTexture(lightningActiveButtonTexture);

    acideCloudSprite.setScale(0.50f,0.50f);
    fireSprite.setScale(0.50f,0.50f);
    lightningSprite.setScale(0.50,0.50f);

    acideCloudSprite.setPosition(Vector2f(110, 5));
    fireSprite.setPosition(Vector2f(210, 5));
    lightningSprite.setPosition(Vector2f(10, 5));

    ///buttons to buy spells
    fireBuyButtonSprite.setTexture(emptyButtonTexture);
    acideCloudBuyButtonSprite.setTexture(emptyButtonTexture);
    lightningBuyButtonSprite.setTexture(emptyButtonTexture);

    fireBuyButtonSprite.setScale(0.35f,0.35f);
    acideCloudBuyButtonSprite.setScale(0.35f,0.35f);
    lightningBuyButtonSprite.setScale(0.35f,0.35f);

    acideCloudBuyButtonSprite.setPosition(110,100);
    fireBuyButtonSprite.setPosition(210,100);
    lightningBuyButtonSprite.setPosition(10,100);

    int x = 20;
    for(int i = 0; i < 3; i++)
    {
        gemSprites.push_back(new Sprite());
        createSprite(*gemSprites.back(), gemTexture, 0.20f,0.20f, x,115);
        x+=100;
    }
    createText(acidPriceText, Color::Yellow, Color::Black, to_string(TypeOfSpell::acidCloud), 0.65f,0.65f, 140,111);
    createText(firePriceText, Color::Yellow, Color::Black, to_string(TypeOfSpell::fire), 0.65f,0.65f, 240,111);
    createText(lightningPriceText, Color::Yellow, Color::Black, to_string(TypeOfSpell::lightning), 0.65f,0.65f, 40,111);

    /// Informations of spells
    x = 13;
    for(int i = 0; i < 3; i++)
    {
        signSprites.push_back(new Sprite());
        createSprite(*signSprites.back(), signTexture, 0.3f,0.2f, x,165);
        x+=100;
    }

    // Damage
    x =9;
    for(int i = 0; i < 3; i++)
    {
        swordSprites.push_back(new Sprite());
        createSprite(*swordSprites.back(), swordTexture, 0.1f,0.1f, x,165);
        x+=100;
    }
    createText(acidAttackNumberText, Color::Yellow, Color::Black, to_string(DamageOfSpell::cloudDamage), 0.55f,0.55f, 147,175);
    createText(fireAttackNumberText, Color::Yellow, Color::Black, to_string(DamageOfSpell::fireDamage), 0.55f,0.55f, 247,175);
    createText(lightningAttackNumberText, Color::Yellow, Color::Black, to_string(DamageOfSpell::lightningDamage), 0.55f,0.55f, 47,175);

    // Stock
    createText(acidStockText, grey, Color::Black, "Stock :", 0.4f,0.4f, 120,205);
    createText(fireStockText, grey, Color::Black, "Stock :", 0.4f,0.4f, 220,205);
    createText(lightningStockText, grey, Color::Black, "Stock :", 0.4f,0.4f, 20,205);
    createText(acidStockNumberText, Color::Yellow, Color::Black, "0", 0.5f,0.5f, 165,204);
    createText(fireStockNumberText, Color::Yellow, Color::Black, "0", 0.5f,0.5f, 265,204);
    createText(lightningStockNumberText, Color::Yellow, Color::Black, "0", 0.5f,0.5f, 65,204);

    ///Title
    Color grey(200,200,200);
    spellTitleText.setFont(font);
    spellTitleText.setFillColor(grey);
    spellTitleText.setString("Spells");
    spellTitleText.setScale(1.1f,1.1f);
    spellTitleText.setPosition(Vector2f(310,20));

    ///effects
    for(int i=0; i < NUMBER_ACID_SPELL ; i++)
    {
        listOfAcideCloudSpell[i]->setTexture(acideCloudEffectTexture);
        listOfAcideCloudSpell[i]->setTextureRect(IntRect(0,0,ACID_CLOUD_WIDTH,ACID_CLOUD_HEIGHT));
        listOfAcideCloudSpell[i]->setPosition(Vector2f(i*98, 240));
        listOfAcideCloudSpell[i]->setScale(0.17f,0.17f);
    }

    for(int i=0; i < NUMBER_FIRE_SPELL ; i++)
    {
        listOfFireSpell[i]->setTexture(fireEffectTexture);
        listOfFireSpell[i]->setTextureRect(IntRect(0,0,ACID_CLOUD_WIDTH,ACID_CLOUD_HEIGHT));
        listOfFireSpell[i]->setPosition(Vector2f(i*96, 280));
        listOfFireSpell[i]->setScale(0.165f,0.165f);
    }

    for(int i=0; i < NUMBER_LIGHTNING_SPELL ; i++)
    {
        listOfLigntningSpell[i]->setTexture(lightningEffectTexture);
        listOfLigntningSpell[i]->setTextureRect(IntRect(0,0,LIGHTNING_WIDTH,LIGHTNING_HEIGHT));
        listOfLigntningSpell[i]->setPosition(Vector2f(i*50, 278));
        listOfLigntningSpell[i]->setScale(0.165f,0.165f);
    }

}

/** load all entities for towers */
void vResourceManager::loadTowersEntities()
{
    ///Title
    Color grey(200,200,200);
    towerTitleText.setFont(font);
    towerTitleText.setFillColor(grey);
    towerTitleText.setString("Towers");
    towerTitleText.setScale(1.1f,1.1f);
    towerTitleText.setPosition(Vector2f(870,20));

    ///towers buttons
    earthTowerButtonSprite.setTexture(earthTowerTextureButton);
    iceTowerButtonSprite.setTexture(iceTowerTextureButton);
    sandTowerButtonSprite.setTexture(sandTowerTextureButton);
    ironTowerButtonSprite.setTexture(ironTowerTextureButton);

    earthTowerButtonSprite.setScale(0.50f,0.50f);
    iceTowerButtonSprite.setScale(0.50f,0.50f);
    sandTowerButtonSprite.setScale(0.50f,0.50f);
    ironTowerButtonSprite.setScale(0.50f,0.50f);

    sandTowerButtonSprite.setPosition(Vector2f(1006,5));
    earthTowerButtonSprite.setPosition(Vector2f(1106,5));
    iceTowerButtonSprite.setPosition(Vector2f(1206,5));
    ironTowerButtonSprite.setPosition(Vector2f(1306,5));

    ///informations of tower

    int x = 1010;
    for(int i = 0; i < 4; i++)
    {
        swordSprites.push_back(new Sprite());
        swordSprites[i]->setTexture(swordTexture);
        swordSprites[i]->setPosition(Vector2f(x, 89));
        swordSprites[i]->setScale(0.1f,0.1f);
        x+=100;
    }

    x = 1020;
    for(int i = 0; i < 4; i++)
    {
        gemSprites.push_back(new Sprite());
        gemSprites[i]->setTexture(gemTexture);
        gemSprites[i]->setPosition(Vector2f(x, 129));
        gemSprites[i]->setScale(0.20f,0.20f);
        x+=100;
    }

    x = 1010;
    for(int i = 0; i < 4; i++)
    {
        signSprites.push_back(new Sprite());
        signSprites[i]->setTexture(signTexture);
        signSprites[i]->setPosition(Vector2f(x, 89));
        signSprites[i]->setScale(0.3f,0.2f);
        x+=100;
    }

    createText(sandAttackText, Color::Yellow, Color::Black, to_string(TowerSand().getDamage()), 0.60f,0.60f, 1044,98);
    createText(sandPriceText, Color::Yellow, Color::Black, to_string(TowerSand().getPrice()), 0.60f,0.60f, 1044,125);
    createText(earthAttackText, Color::Yellow, Color::Black, to_string(TowerEarth().getDamage()), 0.60f,0.60f, 1144,98);
    createText(earthPriceText, Color::Yellow, Color::Black, to_string(TowerEarth().getPrice()), 0.60f,0.60f, 1144,125);
    createText(iceAttackText, Color::Yellow, Color::Black, to_string(TowerIce().getDamage()), 0.60f,0.60f, 1244,98);
    createText(icePriceText, Color::Yellow, Color::Black, to_string(TowerIce().getPrice()), 0.60f,0.60f, 1244,125);
    createText(ironAttackText, Color::Yellow, Color::Black, to_string(TowerIron().getDamage()), 0.60f,0.60f, 1344,98);
    createText(ironPriceText, Color::Yellow, Color::Black, to_string(TowerIron().getPrice()), 0.60f,0.60f, 1344,125);

    /// sell button
    sellButtonSprite.setTexture(emptyButtonTexture);
    sellButtonSprite.setScale(0.50f,0.50f);
    sellButtonSprite.setPosition(Vector2f(880,90));
    createText(sellText, grey, Color::Black, "Sell", 1.1f,1.1f, 905,104);
}

/**load all entities for map */
void vResourceManager::loadMapEntities()
{
    windowSmallSpellSprite.setTexture(windowSmallTexture);
    windowSmallTowerSprite.setTexture(windowSmallTexture);

    windowSmallSpellSprite.setPosition(300,12.5);
    windowSmallSpellSprite.setScale(1.05,1.05);

    windowSmallTowerSprite.setPosition(860,12.5);
    windowSmallTowerSprite.setScale(1.25,1.05);


    loadKingEntities();
}

void vResourceManager::loadKingEntities()
{
    ///king
    kingHealthGreenSprite.setTexture(kingHealthGreenTexture);
    kingHealthRedSprite.setTexture(kingHealthRedTexture);
    kingHealthGreenSprite.setScale(0.20f,0.20f);
    kingHealthRedSprite.setScale(0.20,0.20f);
    kingHealthGreenSprite.setPosition(1240,345);
    kingHealthRedSprite.setPosition(1240,345);
}

/** */
void vResourceManager::loadFailEntities()
{
    tableEmptyFailSprite.setTexture(tableEmptyTexture);
    tableEmptyFailSprite.setScale(0.75f,0.75f);
    tableEmptyFailSprite.setPosition(465,80);

    headerFailedSprite.setTexture(headerFailedTexture);
    headerFailedSprite.setScale(0.7f,0.7f);
    headerFailedSprite.setPosition(565,80);

    windowFailSprite.setTexture(signTexture);
    windowFailSprite.setPosition(575,220);

    backgroundSprite.setTexture(backgroundTexture);

    resetButtonFailSprite.setTexture(resetButtonTexture);
    resetButtonFailSprite.setPosition(620,600);

}

/** Configures a text that will be displayed on the screen afterwards*/
void vResourceManager::createText(Text& text, Color colorFill, Color colorOutline, string str, float xScale, float yScale, int xPosition, int yPosition)
{
    text.setFont(font);
    text.setFillColor(colorFill);
    text.setOutlineColor(colorOutline);
    text.setOutlineThickness(1.2f);
    text.setString(str);
    text.setScale(xScale,yScale);
    text.setPosition(xPosition,yPosition);
}

/** Configures a sprite that will be displayed on the screen afterwards*/
void vResourceManager::createSprite(sf::Sprite& sprite, sf::Texture& texture, float xScale, float yScale, int xPosition, int yPosition)
{
    sprite.setTexture(texture);
    sprite.setScale(xScale,yScale);
    sprite.setPosition(xPosition,yPosition);
}

void vResourceManager::loadChoosingNumberEntities()
{
    ///choose number
    signSprites.push_back(new Sprite());
    signSprites.back()->setTexture(bigTableTexture);
    signSprites.back()->setPosition(Vector2f(500, 220));
    signSprites.back()->setScale(0.4f,0.4f);

    headerShopSprite.setTexture(headerShopTexture);
    headerShopSprite.setPosition(595, 210);
    headerShopSprite.setScale(0.5f,0.5f);

    Color grey(200,200,200);
    createText(chooseNumberText, grey, Color::Black, "", 0.9f,0.9f, 532,292);

    oneSprites.push_back(new Sprite());
    oneSprites.back()->setTexture(oneTexture);
    oneSprites.back()->setPosition(530, 395);
    oneSprites.back()->setScale(0.5f,0.5f);

    twoSprites.push_back(new Sprite());
    twoSprites.back()->setTexture(twoTexture);
    twoSprites.back()->setPosition(580, 395);
    twoSprites.back()->setScale(0.5f,0.5f);

    threeSprites.push_back(new Sprite());
    threeSprites.back()->setTexture(threeTexture);
    threeSprites.back()->setPosition(630, 395);
    threeSprites.back()->setScale(0.5f,0.5f);

    fourSprites.push_back(new Sprite());
    fourSprites.back()->setTexture(fourTexture);
    fourSprites.back()->setPosition(680, 395);
    fourSprites.back()->setScale(0.5f,0.5f);

    fiveSprites.push_back(new Sprite());
    fiveSprites.back()->setTexture(fiveTexture);
    fiveSprites.back()->setPosition(730, 395);
    fiveSprites.back()->setScale(0.5f,0.5f);

    sixSprites.push_back(new Sprite());
    sixSprites.back()->setTexture(sixTexture);
    sixSprites.back()->setPosition(780, 395);
    sixSprites.back()->setScale(0.5f,0.5f);

    sevenSprites.push_back(new Sprite());
    sevenSprites.back()->setTexture(sevenTexture);
    sevenSprites.back()->setPosition(830, 395);
    sevenSprites.back()->setScale(0.5f,0.5f);

    closeButtonSprite.setTexture(closeButtonTexture);
    closeButtonSprite.setPosition(865, 210);
    closeButtonSprite.setScale(0.35f,0.35f);

    /// Numbers to display under tower while choosing emplacement for tower
    oneSprites.push_back(new Sprite());
    oneSprites.back()->setTexture(oneTexture);
    oneSprites.back()->setPosition(170, 505);
    oneSprites.back()->setScale(0.5f,0.5f);

    twoSprites.push_back(new Sprite());
    twoSprites.back()->setTexture(twoTexture);
    twoSprites.back()->setPosition(430, 505);
    twoSprites.back()->setScale(0.5f,0.5f);

    threeSprites.push_back(new Sprite());
    threeSprites.back()->setTexture(threeTexture);
    threeSprites.back()->setPosition(730, 505);
    threeSprites.back()->setScale(0.5f,0.5f);

    fourSprites.push_back(new Sprite());
    fourSprites.back()->setTexture(fourTexture);
    fourSprites.back()->setPosition(1060, 505);
    fourSprites.back()->setScale(0.5f,0.5f);

    fiveSprites.push_back(new Sprite());
    fiveSprites.back()->setTexture(fiveTexture);
    fiveSprites.back()->setPosition(100, 750);
    fiveSprites.back()->setScale(0.5f,0.5f);

    sixSprites.push_back(new Sprite());
    sixSprites.back()->setTexture(sixTexture);
    sixSprites.back()->setPosition(360, 750);
    sixSprites.back()->setScale(0.5f,0.5f);

    sevenSprites.push_back(new Sprite());
    sevenSprites.back()->setTexture(sevenTexture);
    sevenSprites.back()->setPosition(1050, 750);
    sevenSprites.back()->setScale(0.5f,0.5f);
}
void vResourceManager::loadStatsPlayerEntities()
{
    /// player gems
    signSprites.push_back(new Sprite());
    signSprites.back()->setTexture(bigTableTexture);
    signSprites.back()->setPosition(504, 10);
    signSprites.back()->setScale(0.3f,0.3f);

    gemSprites.push_back(new Sprite());
    gemSprites.back()->setTexture(gemTexture);
    gemSprites.back()->setPosition(595,34);
    gemSprites.back()->setScale(0.36f,0.36f);
    createText(playerGemsNumberText, Color::Yellow, Color::Black, "0", 1.f,1.f, 635,28);

    /// wave number
    createText(waveText, grey, Color::Black, "Wave number :", 0.7f,0.7f, 540, 70);
    createText(waveNumberText, Color::Yellow, Color::Black, "0", 0.9f,0.9f, 730,66);

    /// enemy killed
    createText(enemiesKilledText, grey, Color::Black, "Enemies killed : ", 0.7f,0.7f, 540, 115);
    createText(enemiesKilledNumberText, Color::Yellow, Color::Black, "0", 0.9f,0.9f, 730,111);

    /// score
    createText(scoreText, grey, Color::Black, "Score :", 0.7f,0.7f, 580, 156);
    createText(scoreNumberText, Color::Yellow, Color::Black, "0", 0.9f,0.9f, 680,151);
}


/** to load the sprites, adding texture to sprite */
void vResourceManager::loadSprite()
{
    ///map
    mapSprite.setTexture(mapTexture);
    mapSprite.setScale(0.73f,0.75f);

    loadMapEntities();
    loadGameSpeedEntities();

    loadTowersEntities();

    loadChoosingNumberEntities();
    loadStatsPlayerEntities();

    loadSpellEntities();
    loadFailEntities();

    /// message pop up
    messagePopUpText.setFont(font);
    messagePopUpText.setFillColor(Color::Black);
    messagePopUpText.setScale(0.5f,0.5f);
    messagePopUpText.setPosition(Vector2f(1243,223));
}

/**to verify if all images is accessible and charge in the texture*/
bool vResourceManager::verifyImage()
{
    //verify load images
    if (!mapTexture.loadFromFile("res/images/gameBoard/map.png"))
    {
        cerr << "ERROR to charge texture" << endl;
        return false;
    }

    if(verifyImageMonsters() && verifyImageTower() && verifyImageMapEntities() && verifyImageTowersInformations())
    {
        return true;
    }

    return false;
}

/** verify if the image of towers are accessibles and charge in the texture */
bool vResourceManager::verifyImageTower()
{
    if (!earthTowerTexture1.loadFromFile("res/images/towers/earth.png"))
    {
        cerr << "ERROR chargement texture" << endl;
        return false;
    }

    if (!iceTowerTexture1.loadFromFile("res/images/towers/ice.png"))
    {
        cerr << "ERROR chargement texture" << endl;
        return false;
    }

    if (!sandTowerTexture1.loadFromFile("res/images/towers/sand.png"))
    {
        cerr << "ERROR chargement texture" << endl;
        return false;
    }

    if (!ironTowerTexture1.loadFromFile("res/images/towers/iron.png"))
    {
        cerr << "ERROR chargement texture" << endl;
        return false;
    }

    if (!earthAttack.loadFromFile("res/images/towers/earthEffect.png"))
    {
        cerr << "ERROR chargement texture" << endl;
        return false;
    }

    if (!sandAttack.loadFromFile("res/images/towers/sandEffect.png"))
    {
        cerr << "ERROR chargement texture" << endl;
        return false;
    }

    if (!iceAttack.loadFromFile("res/images/towers/iceEffect.png"))
    {
        cerr << "ERROR chargement texture" << endl;
        return false;
    }

    if (!ironAttack.loadFromFile("res/images/towers/ironEffect.png"))
    {
        cerr << "ERROR chargement texture" << endl;
        return false;
    }
    return true;
}

/** verify if the image of monsters are accessibles and charge in the texture*/
bool vResourceManager::verifyImageMonsters()
{
    if (!ogreTextureWalk.loadFromFile("res/images/sprites/1/1_enemies_1_WALK_spritesheet.png"))
    {
        cerr << "ERROR chargement texture" << endl;
        return false;
    }

    if (!orcTextureWalk.loadFromFile("res/images/sprites/2/spritesheet_WALK.png"))
    {
        cerr << "ERROR chargement texture" << endl;
        return false;
    }

    if (!gremlinTextureWalk.loadFromFile("res/images/sprites/3/spritesheet_WALK.png"))
    {
        cerr << "ERROR chargement texture" << endl;
        return false;
    }

    if (!shadowMonsterTextureWalk.loadFromFile("res/images/sprites/5/spritesheet_WALK.png"))
    {
        cerr << "ERROR chargement texture" << endl;
        return false;
    }

    if (!knightOfDeathTextureWalk.loadFromFile("res/images/sprites/9/spritesheet_WALK.png"))
    {
        cerr << "ERROR chargement texture" << endl;
        return false;
    }

    if (!ogreAttackTexture.loadFromFile("res/images/sprites/1/1_enemies_1_ATTACK_spritesheet.png"))
    {
        cerr << "ERROR chargement texture" << endl;
        return false;
    }

    if (!orcAttackTexture.loadFromFile("res/images/sprites/2/spritesheet_ATTACK.png"))
    {
        cerr << "ERROR chargement texture" << endl;
        return false;
    }

    if (!gremlinAttackTexture.loadFromFile("res/images/sprites/3/spritesheet_ATTACK.png"))
    {
        cerr << "ERROR chargement texture" << endl;
        return false;
    }

    if (!shadowMonsterAttackTexture.loadFromFile("res/images/sprites/5/spritesheet_ATTACK.png"))
    {
        cerr << "ERROR chargement texture" << endl;
        return false;
    }

    if (!knightOfDeathAttackTexture.loadFromFile("res/images/sprites/9/spritesheet_ATTACK.png"))
    {
        cerr << "ERROR chargement texture" << endl;
        return false;
    }

    if (!ogreDeadTexture.loadFromFile("res/images/sprites/1/1_enemies_1_DIE_spritesheet.png"))
    {
        cerr << "ERROR chargement texture" << endl;
        return false;
    }

    if (!orcDeadTexture.loadFromFile("res/images/sprites/2/spritesheet_DIE.png"))
    {
        cerr << "ERROR chargement texture" << endl;
        return false;
    }

    if (!gremlinDeadTexture.loadFromFile("res/images/sprites/3/spritesheet_DIE.png"))
    {
        cerr << "ERROR chargement texture" << endl;
        return false;
    }

    if (!shadowMonsterDeadTexture.loadFromFile("res/images/sprites/5/spritesheet_DIE.png"))
    {
        cerr << "ERROR chargement texture" << endl;
        return false;
    }

    if (!knightOfDeathDeadTexture.loadFromFile("res/images/sprites/9/spritesheet_DIE.png"))
    {
        cerr << "ERROR chargement texture" << endl;
        return false;
    }
    return true;
}

/** verify if the image of map entities are accessibles and charge in the texture */
bool vResourceManager::verifyImageMapEntities()
{
    if(!emptyButtonTexture.loadFromFile("res/images/gameBoard/button_empty.png"))
    {
        cerr << "ERROR chargement texture" << endl;
        return false;
    }

    if(!closeButtonTexture.loadFromFile("res/images/gameBoard/button_close.png"))
    {
        cerr << "ERROR chargement texture" << endl;
        return false;
    }

    if(!lightningActiveButtonTexture.loadFromFile("res/images/gameBoard/lightning.png"))
    {
        cerr << "ERROR chargement texture" << endl;
        return false;
    }

    if(!fireActiveButtonTexture.loadFromFile("res/images/gameBoard/fire.png"))
    {
        cerr << "ERROR chargement texture" << endl;
        return false;
    }

    if(!acideCloudActiveButtonTexture.loadFromFile("res/images/gameBoard/cloud.png"))
    {
        cerr << "ERROR chargement texture" << endl;
        return false;
    }

    if(!earthTowerTextureButton.loadFromFile("res/images/gameBoard/earthTowerButton.png"))
    {
        cerr << "ERROR chargement texture" << endl;
        return false;
    }

    if(!iceTowerTextureButton.loadFromFile("res/images/gameBoard/iceTowerButton.png"))
    {
        cerr << "ERROR chargement texture" << endl;
        return false;
    }

    if(!ironTowerTextureButton.loadFromFile("res/images/gameBoard/ironTowerButton.png"))
    {
        cerr << "ERROR chargement texture" << endl;
        return false;
    }

    if(!sandTowerTextureButton.loadFromFile("res/images/gameBoard/sandTowerButton.png"))
    {
        cerr << "ERROR chargement texture" << endl;
        return false;
    }

    if(!acideCloudEffectTexture.loadFromFile("res/images/sprites/spells/acideCloud.png"))
    {
        cerr << "ERROR chargement texture" << endl;
        return false;
    }

    if(!fireEffectTexture.loadFromFile("res/images/sprites/spells/fire.png"))
    {
        cerr << "ERROR chargement texture" << endl;
        return false;
    }

    if(!lightningEffectTexture.loadFromFile("res/images/sprites/spells/lightning.png"))
    {
        cerr << "ERROR chargement texture" << endl;
        return false;
    }

    if(!kingHealthGreenTexture.loadFromFile("res/images/gameBoard/health_bar-green.png"))
    {
        cerr << "ERROR chargement texture" << endl;
        return false;
    }

    if(!kingHealthRedTexture.loadFromFile("res/images/gameBoard/health_bar-red.png"))
    {
        cerr << "ERROR chargement texture" << endl;
        return false;
    }

    if(!pauseButtonTexture.loadFromFile("res/images/gameBoard/button_pause.png"))
    {
        cerr << "ERROR chargement texture" << endl;
        return false;
    }

    if(!increaseSpeedButtonTexture.loadFromFile("res/images/gameBoard/button_quick.png"))
    {
        cerr << "ERROR chargement texture" << endl;
        return false;
    }

    if(!decreaseSpeedButtonTexture.loadFromFile("res/images/gameBoard/button_slow.png"))
    {
        cout << "ERROR chargement texture" << endl;
        return false;
    }

    if(!infoBulbleMessageTexture.loadFromFile("res/images/gameBoard/message.png"))
    {
        cerr << "ERROR chargement texture" << endl;
        return false;
    }

    if(!playGameButtonTexture.loadFromFile("res/images/gameBoard/button_play.png"))
    {
        cerr << "ERROR chargement texture" << endl;
        return false;
    }

    if(!playGameButtonTexture.loadFromFile("res/images/gameBoard/button_play.png"))
    {
        cerr << "ERROR chargement texture" << endl;
        return false;
    }

    if(!multiplierTexture.loadFromFile("res/images/gameBoard/button_close.png"))
    {
        cerr << "ERROR chargement texture" << endl;
        return false;
    }

    if(!headerFailedTexture.loadFromFile("res/images/gameBoard/header_failed.png"))
    {
        cerr << "ERROR chargement texture" << endl;
        return false;
    }

    if(!headerShopTexture.loadFromFile("res/images/gameBoard/header_shop.png"))
    {
        cerr << "ERROR chargement texture" << endl;
        return false;
    }

    if(!backgroundTexture.loadFromFile("res/images/menu/game_background_4.png"))
    {
        cout << "ERROR chargement texture" << endl;
        return false;
    }

    if(!resetButtonTexture.loadFromFile("res/images/gameBoard/button_reset.png"))
    {
        cout << "ERROR chargement texture" << endl;
        return false;
    }

    if(!windowSmallTexture.loadFromFile("res/images/gameBoard/window_2.png"))
    {
        cout << "ERROR chargement texture" << endl;
        return false;
    }

    return true;
}

/** verify if the image of informations of towers are accessibles and charge in the texture */
bool vResourceManager::verifyImageTowersInformations()
{
    if (!oneTexture.loadFromFile("res/images/gameBoard/num_1.png"))
    {
        cerr << "ERROR chargement texture" << endl;
        return false;
    }

    if (!twoTexture.loadFromFile("res/images/gameBoard/num_2.png"))
    {
        cerr << "ERROR chargement texture" << endl;
        return false;
    }

    if (!threeTexture.loadFromFile("res/images/gameBoard/num_3.png"))
    {
        cerr << "ERROR chargement texture" << endl;
        return false;
    }

    if (!fourTexture.loadFromFile("res/images/gameBoard/num_4.png"))
    {
        cerr << "ERROR chargement texture" << endl;
        return false;
    }

    if (!fiveTexture.loadFromFile("res/images/gameBoard/num_5.png"))
    {
        cerr << "ERROR chargement texture" << endl;
        return false;
    }

    if (!sixTexture.loadFromFile("res/images/gameBoard/num_6.png"))
    {
        cerr << "ERROR chargement texture" << endl;
        return false;
    }

    if (!sevenTexture.loadFromFile("res/images/gameBoard/num_7.png"))
    {
        cerr << "ERROR chargement texture" << endl;
        return false;
    }

    if (!gemTexture.loadFromFile("res/images/gameBoard/coinCrystal.png"))
    {
        cerr << "ERROR chargement texture" << endl;
        return false;
    }

    if (!swordTexture.loadFromFile("res/images/gameBoard/sword.png"))
    {
        cerr << "ERROR chargement texture" << endl;
        return false;
    }

    if (!signTexture.loadFromFile("res/images/gameBoard/window_1.png"))
    {
        cerr << "ERROR chargement texture" << endl;
        return false;
    }

    if (!tableEmptyTexture.loadFromFile("res/images/gameBoard/table.png"))
    {
        cerr << "ERROR chargement texture" << endl;
        return false;
    }

    if (!bigTableTexture.loadFromFile("res/images/gameBoard/big_table.png"))
    {
        cerr << "ERROR chargement texture" << endl;
        return false;
    }

    if (!font.loadFromFile("res/fonts/plump.ttf"))
    {
        cerr << "ERROR chargement font" << endl;
        return false;
    }

    return true;
}



