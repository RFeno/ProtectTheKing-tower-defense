#include <SFML/Graphics.hpp>
#include <iostream>
#include <unistd.h>

/**ENEMIES*/
#include "Ogre.h"
#include "Orc.h"
#include "ShadowMonster.h"
#include "KnightOfDeath.h"
#include "Gremlin.h"
#include "vEnnemy.h"

/**TOWERS*/
#include "TowerEarth.h"
#include "TowerIce.h"
#include "TowerIron.h"
#include "TowerSand.h"
#include "AcidCloudSpell.h"

#include "vGameBoard.h"
#include "StateDie.h"

using namespace sf;
using namespace std;

vGameBoard::vGameBoard(RenderWindow &window)
{
    /**TO DELETE */

    game.getPlayer()->buySpell(lightning);
    game.getPlayer()->buySpell(lightning);
    game.getPlayer()->buySpell(lightning);
    game.getPlayer()->buySpell(lightning);
    game.getPlayer()->buySpell(lightning);

    game.getPlayer()->buySpell(cloud);
    game.getPlayer()->buySpell(cloud);
    game.getPlayer()->buySpell(cloud);
    game.getPlayer()->buySpell(cloud);
    game.getPlayer()->buySpell(cloud);
    game.getPlayer()->buySpell(cloud);
    game.getPlayer()->buySpell(cloud);
    game.getPlayer()->buySpell(cloud);
    game.getPlayer()->buySpell(cloud);
    game.getPlayer()->buySpell(cloud);
    game.getPlayer()->buySpell(cloud);
    game.getPlayer()->buySpell(cloud);
    game.getPlayer()->buySpell(cloud);
    game.getPlayer()->buySpell(cloud);
    game.getPlayer()->buySpell(cloud);

    game.getPlayer()->buySpell(fire);
    game.getPlayer()->buySpell(fire);
    game.getPlayer()->buySpell(fire);
    game.getPlayer()->buySpell(fire);
    game.getPlayer()->buySpell(fire);
    game.getPlayer()->buySpell(fire);
    game.getPlayer()->buySpell(fire);
    game.getPlayer()->buySpell(fire);




    this->windowFromMain = &window;

    isChoosingNumberForPositionTower=false;
    isSellingTower = false;

    for(int i=0; i< game.getNumberOfEnemies(); i++)
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

vGameBoard::~vGameBoard()
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

/** allow to run and launch view game */
void vGameBoard::launchView()
{
    //vsynch activation
    windowFromMain->setVerticalSyncEnabled(true);

    // limit the window to 60 images per second
    windowFromMain->setFramerateLimit(60);

    /** if we have success to charge all images and load sprites, display screen */
    if(verifyImage())
    {
        loadSprite();

        while (windowFromMain->isOpen())
        {
            Event event;

            while(windowFromMain->pollEvent(event))
            {
                InputHandler(event);
            }

            if(!game.isGamePaused() && !game.isGameOver())
            {
                updateGame();
            }

            windowFromMain->clear();

            drawEntities();

            windowFromMain->display();
        }
    }
}

/** bind the enemy to the vEnemy  */
void vGameBoard::updateVennemyForView()
{
    //bind enemy on model to sprite on screen
    for(int i=0;i<(int)game.getMap()->getEnemies().size();i++)
    {
        listOfvEnnemies[i]->setEnemy(game.getMap()->getEnemies()[i]);
        listOfvEnnemies[i]->chargeInformations();
    }
}

/** remove a vtower of gameboard*/
int vGameBoard::searchVTower(int position)
{
    int result = -1;

    for(size_t i=0;i<listOfvTower.size();i++)
    {
        if(listOfvTower[i]->getTower()->getPosition() == position)
        {
            result=i;
            break;
        }
    }
    return result;
}

/**remove a vtower of gameboard*/
bool vGameBoard::removeVTower(int position)
{
    int index = searchVTower(position);

    if(index!=-1)
    {
        vTower *tmp = *(listOfvTower.begin() + index);
        listOfvTower.erase(listOfvTower.begin() + index);
        delete tmp;

        return true;
    }
    else
    {
        activeMessagePopUp("There is no\ntower at\nthis position.");
    }
    return false;
}

/**to manage the events */
void vGameBoard::InputHandler(Event event)
{
    // close the window
    if (event.type == Event::Closed)
    {
        windowFromMain->close();
    }

    // detect mouse click
    if (event.type == Event::MouseButtonPressed)
    {
        if (event.mouseButton.button == Mouse::Left)
        {
            if(!isChoosingNumberForPositionTower)
            {
                //detect events type of towers choice to buy or sell
                eventsChoiceTowers();

                // sell tower
                if(isSpriteClicked(sellButtonSprite))
                {
                    isChoosingNumberForPositionTower = true;
                    isSellingTower = true;
                    chooseNumberText.setString("Choose the location of\n     the tower to sell");
                }
            }

            // close the sign to choose tower emplacement
            if(isSpriteClicked(closeButtonSprite))
            {
                isChoosingNumberForPositionTower = false;
                isSellingTower = false;
            }

            //detect pause, increase and decrease events
            eventsGameSpeed();

            //detect spells buttons
            if(!game.isGamePaused())
            {
                eventsSpells();
            }


            if(game.isGameOver() && isSpriteClicked(resetButtonFailSprite))
            {
                game.resetGame();
                resetGameView();
            }
        }


        if (event.mouseButton.button == Mouse::Right)
        {
            cout << "right click"<< endl;

             if(isSpriteClicked(acideCloudSprite) == 1)
            {

            }
        }
    }


    /** verify after the pannel is showing if the player have choice a number */
    if(isChoosingNumberForPositionTower)
    {
        if (event.mouseButton.button == Mouse::Left)
        {
            int position = 0;
            // for sell tower
            if(isSellingTower)
            {
                if(isSpriteClicked(*oneSprites[0]))
                {
                    position = 1;
                    isChoosingNumberForPositionTower = false;
                    for(vTower* vt : listOfvTower)
                    {
                        if(vt->getTower()->getPosition() == position)
                        {
                            game.getMap()->removeTower(*vt->getTower());
                        }
                    }
                    removeVTower(position);
                    isSellingTower = false;
                }
                if(isSpriteClicked(*twoSprites[0]))
                {
                    position = 2;
                    isChoosingNumberForPositionTower = false;
                    for(vTower* vt : listOfvTower)
                    {
                        if(vt->getTower()->getPosition() == position)
                        {
                            game.getMap()->removeTower(*vt->getTower());
                        }
                    }
                    removeVTower(position);
                    isSellingTower = false;
                }
                if(isSpriteClicked(*threeSprites[0]))
                {
                    position = 3;
                    isChoosingNumberForPositionTower = false;
                    for(vTower* vt : listOfvTower)
                    {
                        if(vt->getTower()->getPosition() == position)
                        {
                            game.getMap()->removeTower(*vt->getTower());
                        }
                    }
                    removeVTower(position);
                    isSellingTower = false;
                }
                if(isSpriteClicked(*fourSprites[0]))
                {
                    position = 4;
                    isChoosingNumberForPositionTower = false;
                    for(vTower* vt : listOfvTower)
                    {
                        if(vt->getTower()->getPosition() == position)
                        {
                            game.getMap()->removeTower(*vt->getTower());
                        }
                    }
                    removeVTower(position);
                    isSellingTower = false;
                }
                if(isSpriteClicked(*fiveSprites[0]))
                {
                    position = 5;
                    isChoosingNumberForPositionTower = false;
                    for(vTower* vt : listOfvTower)
                    {
                        if(vt->getTower()->getPosition() == position)
                        {
                            game.getMap()->removeTower(*vt->getTower());
                        }
                    }
                    removeVTower(position);
                    isSellingTower = false;
                }
                if(isSpriteClicked(*sixSprites[0]))
                {
                    position = 6;
                    isChoosingNumberForPositionTower = false;
                    for(vTower* vt : listOfvTower)
                    {
                        if(vt->getTower()->getPosition() == position)
                        {
                            game.getMap()->removeTower(*vt->getTower());
                        }
                    }
                    removeVTower(position);
                    isSellingTower = false;
                }
                if(isSpriteClicked(*sevenSprites[0]))
                {
                    position = 7;
                    isChoosingNumberForPositionTower = false;
                    for(vTower* vt : listOfvTower)
                    {
                        if(vt->getTower()->getPosition() == position)
                        {
                            game.getMap()->removeTower(*vt->getTower());
                        }
                    }
                    removeVTower(position);
                    isSellingTower = false;
                }
            }
            // for buy a tower
            else
            {
                if(isSpriteClicked(*oneSprites[0]))
                {
                    position = 1;
                    isChoosingNumberForPositionTower = false;
                    buyTower(typeTowerChoosed, position);
                }
                if(isSpriteClicked(*twoSprites[0]))
                {
                    position = 2;
                    isChoosingNumberForPositionTower = false;
                    buyTower(typeTowerChoosed, position);
                }
                if(isSpriteClicked(*threeSprites[0]))
                {
                    position = 3;
                    isChoosingNumberForPositionTower = false;
                    buyTower(typeTowerChoosed, position);
                }
                if(isSpriteClicked(*fourSprites[0]))
                {
                    position = 4;
                    isChoosingNumberForPositionTower = false;
                    buyTower(typeTowerChoosed, position);
                }
                if(isSpriteClicked(*fiveSprites[0]))
                {
                    position = 5;
                    isChoosingNumberForPositionTower = false;
                    buyTower(typeTowerChoosed, position);
                }
                if(isSpriteClicked(*sixSprites[0]))
                {
                    position = 6;
                    isChoosingNumberForPositionTower = false;
                    buyTower(typeTowerChoosed, position);
                }
                if(isSpriteClicked(*sevenSprites[0]))
                {
                    position = 7;
                    isChoosingNumberForPositionTower = false;
                    buyTower(typeTowerChoosed, position);
                }
            }
        }
    }
}

void vGameBoard::eventsGameSpeed()
{
    if(isSpriteClicked(pauseButtonSprite))
    {
        if(game.isGamePaused())
        {
            game.setGamePaused(false);
        }
        else
        {
            game.setGamePaused(true);
        }
    }

    if(isSpriteClicked(decreaseSpeedButtonSprite))
    {
        game.decreaseGameSpeed();
    }

    if(isSpriteClicked(increaseSpeedButtonSprite))
    {
        game.increaseGameSpeed();
    }
}

/** allow to set choice of tower  */
void vGameBoard::eventsChoiceTowers()
{
    chooseNumberText.setString("Choose the location of\n     the tower to buy");
    if(isSpriteClicked(earthTowerButtonSprite))
    {
        cout << "button buy earthTower click" << endl;
        eventsActiveTowersChoice(earth);
    }

    // buy sand tower
    if(isSpriteClicked(sandTowerButtonSprite))
    {
        cout << "button buy sandTower click" << endl;
        eventsActiveTowersChoice(sand);
    }

    // buy ice tower
    if(isSpriteClicked(iceTowerButtonSprite))
    {
        cout << "button buy iceTower click" << endl;
        eventsActiveTowersChoice(ice);
    }

    // buy iron tower
    if(isSpriteClicked(ironTowerButtonSprite))
    {
        cout << "button buy ironTower click" << endl;
        eventsActiveTowersChoice(iron);
    }
}

void vGameBoard::eventsActiveTowersChoice(TypeOfTowerPrice type)
{
    if(!game.getMap()->isAllPlacesOccupied())
    {
        if(game.getPlayer()->getCoins() - type >= 0 )
        {
            isChoosingNumberForPositionTower = true;
            typeTowerChoosed = type;
        }
        else
        {
            activeMessagePopUp("You have not\nenough gems to\nbuy this tower.");
        }
    }
    else
    {
        activeMessagePopUp("All places of\ntowers are\noccupied\nplease sell");
    }
}

/** events to active spells */
void vGameBoard::eventsSpells()
{
    //button to buy
    if(isSpriteClicked(acideCloudBuyButtonSprite))
    {
        cout <<  "acide cloud buy button click" << endl;
    }

    //button to active
    if(isSpriteClicked(acideCloudSprite))
    {
        cout <<  "acide cloud spell active button click" << endl;
        if(game.getPlayer()->activeSpell(cloud,game.getMap()->getEnemies()))
        {
            game.setAcidCloudActive(true);
        }
    }

    //button to active
    if(isSpriteClicked(fireSprite))
    {
        cout <<  "fire spell active button click" << endl;
        if(game.getPlayer()->activeSpell(fire,game.getMap()->getEnemies()))
        {
            game.setFireActive(true);
        }
    }

     //button to active
    if(isSpriteClicked(lightningSprite))
    {
        cout <<  "lightning spell active button click" << endl;
        if(game.getPlayer()->activeSpell(lightning,game.getMap()->getEnemies()))
        {
            game.setLightningActive(true);
        }
    }



}

/** to load the sprites, adding texture to sprite */
void vGameBoard::loadSprite()
{
    ///map
    mapSprite.setTexture(mapTexture);
    mapSprite.setScale(0.73f,0.75f);

    loadMapEntities();
    loadGameSpeedEntities();

    loadSpellEntities();
    loadTowersEntities();

    loadFailEntities();

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

    /// player gems
    signSprites.push_back(new Sprite());
    signSprites.back()->setTexture(bigTableTexture);
    signSprites.back()->setPosition(504, 10);
    signSprites.back()->setScale(0.3f,0.3f);

    gemSprites.push_back(new Sprite());
    gemSprites.back()->setTexture(gemTexture);
    gemSprites.back()->setPosition(595,34);
    gemSprites.back()->setScale(0.36f,0.36f);
    createText(playerGemsNumberText, Color::Yellow, Color::Black, to_string(game.getPlayer()->getCoins()), 1.f,1.f, 635,28);

    /// wave number
    createText(waveText, grey, Color::Black, "Wave number :", 0.7f,0.7f, 540, 70);
    createText(waveNumberText, Color::Yellow, Color::Black, to_string(game.getNumeroOfWave()), 0.9f,0.9f, 730,66);

    /// enemy killed
    createText(enemiesKilledText, grey, Color::Black, "Enemies killed : ", 0.7f,0.7f, 540, 115);
    createText(enemiesKilledNumberText, Color::Yellow, Color::Black, to_string(game.getPlayer()->getNumberOfEnemyKilled()), 0.9f,0.9f, 730,111);

    /// score
    createText(scoreText, grey, Color::Black, "Score :", 0.7f,0.7f, 580, 156);
    createText(scoreNumberText, Color::Yellow, Color::Black, to_string(game.getPlayer()->getScore()), 0.9f,0.9f, 680,151);

    /// message pop up
    messagePopUpText.setFont(font);
    messagePopUpText.setFillColor(Color::Black);
    messagePopUpText.setScale(0.5f,0.5f);
    messagePopUpText.setPosition(Vector2f(1243,223));
}

/** load and configure game speed entitites */
void vGameBoard::loadGameSpeedEntities()
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
void vGameBoard::loadSpellEntities()
{
    /// buttons to active spells
    acideCloudSprite.setTexture(acideCloudActiveButtonTexture);
    fireSprite.setTexture(fireActiveButtonTexture);
    lightningSprite.setTexture(lightningActiveButtonTexture);

    acideCloudSprite.setScale(0.50f,0.50f);
    fireSprite.setScale(0.50f,0.50f);
    lightningSprite.setScale(0.50,0.50f);

    acideCloudSprite.setPosition(Vector2f(10, 5));
    fireSprite.setPosition(Vector2f(110, 5));
    lightningSprite.setPosition(Vector2f(210, 5));

    ///buttons to buy spells
    fireBuyButtonSprite.setTexture(emptyButtonTexture);
    acideCloudBuyButtonSprite.setTexture(emptyButtonTexture);
    lightningBuyButtonSprite.setTexture(emptyButtonTexture);

    fireBuyButtonSprite.setScale(0.35f,0.35f);
    acideCloudBuyButtonSprite.setScale(0.35f,0.35f);
    lightningBuyButtonSprite.setScale(0.35f,0.35f);

    fireBuyButtonSprite.setPosition(10,100);
    acideCloudBuyButtonSprite.setPosition(110,100);
    lightningBuyButtonSprite.setPosition(210,100);

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
void vGameBoard::loadTowersEntities()
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
void vGameBoard::loadMapEntities()
{
    windowSmallSpellSprite.setTexture(windowSmallTexture);
    windowSmallTowerSprite.setTexture(windowSmallTexture);

    windowSmallSpellSprite.setPosition(300,12.5);
    windowSmallSpellSprite.setScale(1.05,1.05);

    windowSmallTowerSprite.setPosition(860,12.5);
    windowSmallTowerSprite.setScale(1.25,1.05);


    loadKingEntities();
}

void vGameBoard::loadKingEntities()
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
void vGameBoard::loadFailEntities()
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

/**Detect events when buttons are pressed*/
bool vGameBoard::isSpriteClicked (Sprite &spr)
{
    //take the position of the mouse
    Vector2i mousePos = Mouse::getPosition(*windowFromMain);

    //condition if it is in the sprite
	if(mousePos.x > spr.getPosition().x
		&& mousePos.x < spr.getPosition().x + (spr.getTexture()->getSize().x * spr.getScale().x)
		&& mousePos.y > spr.getPosition().y && mousePos.y < spr.getPosition().y + (spr.getTexture()->getSize().y * spr.getScale().y)
		&& Mouse::isButtonPressed(Mouse::Left)
	)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/** animate enemy at the screen */
void vGameBoard::enemyAnimation()
{
    //method adapts which texture we need to display
    adaptAnimationTexture();

    //method adapts which parts of Texture (sprite sheet) we need to display
    adaptAnimationSprite();
}

/** play once, update model of game */
void vGameBoard::updateGame()
{
//    cout << game.getMap()->strEnemies() << endl;
//    cout << game.getMap()->getKing().getInformations() << endl;
//    cout << game.getMap()->strTowers() <<endl;

    ///update player stats when enemy dies
    game.increasePlayerStatsWhenEnemyKilled();
    playerGemsNumberText.setString(to_string(game.getPlayer()->getCoins()));
    scoreNumberText.setString(to_string(game.getPlayer()->getScore()));
    enemiesKilledNumberText.setString(to_string(game.getPlayer()->getNumberOfEnemyKilled()));

    ///reset wave is all enemies are dead
    if(game.isEndOfWave())
    {
        //desactivate all animations for tower
        for(vTower *vtower:listOfvTower)
        {
            vtower->getTower()->setAttacking(false);
        }
        //delete and create and improve enemies
        game.refreshEnemies();

        //set the wave number in the view
        waveNumberText.setString(to_string(game.getNumeroOfWave()));

        //bind model and view
        updateVennemyForView();
    }

    ///enemies spawn one per one
    if(spawnClock.getElapsedTime().asSeconds() > (Game::spawnTime / game.getGameSpeed()) && game.getNumberOfEnemiesSpawned() < (int)listOfvEnnemies.size())
    {
        listOfvEnnemies[game.getNumberOfEnemiesSpawned()]->getEnemy()->setSpawn(true);

        game.increaseNumberOfEnemiesSpawned();

        spawnClock.restart();
    }


    ///game speed
    if(gameSpeedClook.getElapsedTime().asSeconds() > (0.013f / game.getGameSpeed()))
    {
        updateHealthBarAllEnemies();

        ///walks of enemies
        for(int i=0;i<game.getGameSpeed();i++)
        {
            game.ennemiesWalk();
        }

        ///attack of towers
        if(attackTowerClock.getElapsedTime().asSeconds() > (0.06f / game.getGameSpeed()))
        {
            for(vTower *vtower: listOfvTower)
            {
                for(Enemies *enemy: game.getMap()->getEnemies())
                {

                    ///allow to change tower mode of attacking only is the enemy is in range
                    if(vtower->getTower()->isInRange(enemy->getX(),vtower->calculateMiddlePosition()))
                    {

                        ///allow to attack only if the enemy is the first and the farthest
                        if(game.getMap()->getFirstEnemyNotDead(*vtower->getTower(),vtower->calculateMiddlePosition()) == game.getMap()->searchEnemy(*enemy))
                        {
                            vtower->getTower()->setAttacking(true);
                            vtower->getTower()->attackEnemy(*enemy);
                        }
                        else
                        {
                            vtower->getTower()->setAttacking(false);
                        }

                    }
                }
            }
            attackTowerClock.restart();
        }

        /** GERER ICI LE TEMPS ENTRE 2 ATTACK DES ENNEMIS SUR LE ROI */
        if(attackClock.getElapsedTime().asSeconds() > (0.5f / game.getGameSpeed()))
        {
            for(Enemies *enemy: game.getMap()->getEnemies())
            {
                enemy->attackKing(game.getMap()->getKing());

                //update King Health
                updateKingHealth();
            }
            attackClock.restart();
        }

        enemyAnimation();

        gameSpeedClook.restart();
    }

}

/** Update the health bar of king */
void vGameBoard::updateKingHealth()
{
    double kingHealthMax = game.getMap()->getKing().getKingHealthMax();
    double kingHealthReel = game.getMap()->getKing().getHealth();
    double remainingHealth = (kingHealthReel  / kingHealthMax );
    //0.20 is the widht per default for the health bar
    kingHealthGreenSprite.setScale(Vector2f(0.20*remainingHealth,0.20));
}

/**update health bar of all enemies who are not dead **/
void vGameBoard::updateHealthBarAllEnemies()
{
    for(vEnnemy *venemy:listOfvEnnemies)
    {
        if(!dynamic_cast<StateDie*>(venemy->getEnemy()->getState()))
        {
            venemy->updateHealth();
        }
    }
}

/** to draw the entitties in the window */
void vGameBoard::drawEntities()
{
    ///map
    windowFromMain->draw(mapSprite);

    if(!game.isGameOver())
    {
        drawMapEntities();
        drawGameSpeedView();

        // button to sell towers
        windowFromMain->draw(sellButtonSprite);
        windowFromMain->draw(sellText);

        ///towers 1 to 4
        for(int i = 0; i < (int)listOfvTower.size(); i++)
        {
            if(listOfvTower[i]->getTower()->getPosition() < 4)
            {
                windowFromMain->draw(*(listOfvTower[i]->getSprite()));
            }
        }

        // When the player must choose the emplacement of tower
        if(isChoosingNumberForPositionTower)
        {
            windowFromMain->draw(*signSprites[4]);
            for(int i = 0; i<2; i++)
            {
                windowFromMain->draw(*oneSprites[i]);
                windowFromMain->draw(*twoSprites[i]);
                windowFromMain->draw(*threeSprites[i]);
                windowFromMain->draw(*fourSprites[i]);
                windowFromMain->draw(*fiveSprites[i]);
                windowFromMain->draw(*sixSprites[i]);
                windowFromMain->draw(*sevenSprites[i]);
            }
            windowFromMain->draw(chooseNumberText);
            windowFromMain->draw(closeButtonSprite);
            windowFromMain->draw(headerShopSprite);
        }

        drawEnemies();

        //Place here elemnets between the towers
        drawSpellEntities();


        ///towers 5 to 7
        for(int i = 0; i < (int)listOfvTower.size(); i++)
        {
            if(listOfvTower[i]->getTower()->getPosition() >= 4)
            {
                windowFromMain->draw(*(listOfvTower[i]->getSprite()));
            }
        }

        /// attack animations of towers
        for(int i = 0; i < (int)listOfvTower.size(); i++)
        {
            if(listOfvTower[i]->getTower()->isAttacking() == true)
            {
                windowFromMain->draw(*(listOfvTower[i]->getAttackSprite()));
            }
        }

    }
    else
    {
        drawFailEntities();
    }
}

/** draw entities for spells*/
void vGameBoard::drawSpellEntities()
{
    ///Acid spell effect
    if(game.isAcidCloudSpellActive())
    {
        for(int i=0; i < NUMBER_ACID_SPELL ; i++)
        {
            windowFromMain->draw(*listOfAcideCloudSpell[i]);
        }
    }

    ///Fire spell effect
    if(game.isFireSpellActive())
    {
        for(int i=0; i < NUMBER_FIRE_SPELL ; i++)
        {
            windowFromMain->draw(*listOfFireSpell[i]);
        }
    }

    ///Lightning spell effect
    if(game.isLightNingSpellActive())
    {
        for(int i=0; i < NUMBER_LIGHTNING_SPELL ; i++)
        {
            windowFromMain->draw(*listOfLigntningSpell[i]);
        }
    }

    ///buttons and title
    windowFromMain->draw(spellTitleText);
    windowFromMain->draw(fireBuyButtonSprite);
    windowFromMain->draw(acideCloudBuyButtonSprite);
    windowFromMain->draw(lightningBuyButtonSprite);
}

/** draw map entities */
void vGameBoard::drawMapEntities()
{
    drawMapButtons();

    ///king health and bubble message
    windowFromMain->draw(kingHealthRedSprite);
    windowFromMain->draw(kingHealthGreenSprite);

    /// message pop up said by the king
    if(isMessagePopUp)
    {
        if(messageClock.getElapsedTime().asSeconds() < 5)
        {
            windowFromMain->draw(infoBulbleMessageSprite);
            windowFromMain->draw(messagePopUpText);
        }
        else
        {
            messageClock.restart();
            isMessagePopUp = false;
        }
    }

    ///tower informations
    windowFromMain->draw(windowSmallTowerSprite);
    windowFromMain->draw(towerTitleText);
    for(int i=0; i < 4 ; i++)
    {
        windowFromMain->draw(*signSprites[i]);
    }

    for(int i=0; i < 4 ; i++)
    {
        windowFromMain->draw(*swordSprites[i]);
    }

    for(int i=0; i < 4 ; i++)
    {
        windowFromMain->draw(*gemSprites[i]);
    }

    ///prices of towers
    windowFromMain->draw(earthAttackText);
    windowFromMain->draw(earthPriceText);
    windowFromMain->draw(sandAttackText);
    windowFromMain->draw(sandPriceText);
    windowFromMain->draw(iceAttackText);
    windowFromMain->draw(icePriceText);
    windowFromMain->draw(ironAttackText);
    windowFromMain->draw(ironPriceText);

    /// player gems
    windowFromMain->draw(*signSprites[5]);
    windowFromMain->draw(playerGemsNumberText);
    windowFromMain->draw(*gemSprites[4]);
    /// wave number
    windowFromMain->draw(waveText);
    windowFromMain->draw(waveNumberText);
    /// score
    windowFromMain->draw(scoreText);
    windowFromMain->draw(scoreNumberText);
    /// enemies killed
    windowFromMain->draw(enemiesKilledText);
    windowFromMain->draw(enemiesKilledNumberText);

    ///
    windowFromMain->draw(windowSmallSpellSprite);


}

/** draw map buttons */
void vGameBoard::drawMapButtons()
{
    ///spell buttons
    windowFromMain->draw(lightningSprite);
    windowFromMain->draw(fireSprite);
    windowFromMain->draw(acideCloudSprite);

    ///towers buttons
    windowFromMain->draw(ironTowerButtonSprite);
    windowFromMain->draw(iceTowerButtonSprite);
    windowFromMain->draw(sandTowerButtonSprite);
    windowFromMain->draw(earthTowerButtonSprite);
}

/** draw enemies*/
void vGameBoard::drawEnemies()
{
    //allows you to draw some enemies before others
    for(int i=0;i<Enemies::NUMBER_OF_ENEMY_TYPES;i++)
    {
        for(vEnnemy* enemy: listOfvEnnemies)
        {
            if(enemy->getEnemy()->isSpawn() && !dynamic_cast<StateDie*>(enemy->getEnemy()->getState()))
            {
                switch(i)
                {
                    case 0:
                    {
                        if(dynamic_cast<Orc*>(enemy->getEnemy()))
                        {
                           drawOneEnemy(enemy);
                        }
                        break;
                    }
                    case 1:
                    {
                        if(dynamic_cast<Gremlin*>(enemy->getEnemy()))
                        {
                            drawOneEnemy(enemy);
                        }
                        break;
                    }
                    case 2:
                    {
                        if(dynamic_cast<ShadowMonster*>(enemy->getEnemy()))
                        {
                           drawOneEnemy(enemy);
                        }
                        break;
                    }
                    case 3:
                    {
                        if(dynamic_cast<Ogre*>(enemy->getEnemy()))
                        {
                           drawOneEnemy(enemy);
                        }
                        break;
                    }
                    case 4:
                    {
                        if(dynamic_cast<KnightOfDeath*>(enemy->getEnemy()))
                        {
                            drawOneEnemy(enemy);
                        }
                        break;
                    }
                }
            }
        }
    }
}

/** draws on the screen the enemy received as an argument */
void vGameBoard::drawOneEnemy(vEnnemy *enemy)
{
    windowFromMain->draw(*enemy->getSprite());
    windowFromMain->draw(enemy->healthBarRedSprite);
    windowFromMain->draw(enemy->healthBarGreenSprite);
}

/**draw all entities for game speed */
void vGameBoard::drawGameSpeedView()
{
    if(!game.isGamePaused())
    {
        windowFromMain->draw(pauseButtonSprite);
    }
    else
    {
        windowFromMain->draw(playGameButtonSprite);
    }

    windowFromMain->draw(increaseSpeedButtonSprite);
    windowFromMain->draw(decreaseSpeedButtonSprite);
    windowFromMain->draw(gameSpeedEmptyTableSprite);
    windowFromMain->draw(multiplierSprite);

    switch(game.getGameSpeed())
    {
        case 1:
        {
            windowFromMain->draw(gameSpeedOneSprite);
            break;
        }
        case 2:
        {
            windowFromMain->draw(gameSpeedTwoSprite);
            break;
        }
        case 3:
        {
            windowFromMain->draw(gameSPeedThreeSprite);
            break;
        }
    }
}

/** draw the menu of fail */
void vGameBoard::drawFailEntities()
{
    changeStatsPosition(game.isGameOver());
    if(game.isGameOver())
    {
        windowFromMain->draw(backgroundSprite);
        windowFromMain->draw(tableEmptyFailSprite);
        windowFromMain->draw(windowFailSprite);
        windowFromMain->draw(headerFailedSprite);
        windowFromMain->draw(resetButtonFailSprite);
        windowFromMain->draw(*gemSprites[4]);
        windowFromMain->draw(playerGemsNumberText);
        windowFromMain->draw(waveText);
        windowFromMain->draw(waveNumberText);
        windowFromMain->draw(enemiesKilledText);
        windowFromMain->draw(enemiesKilledNumberText);
        windowFromMain->draw(scoreText);
        windowFromMain->draw(scoreNumberText);
    }
}

void vGameBoard::changeStatsPosition(bool isGameOver)
{
    if(isGameOver)
    {
        gemSprites[4]->setPosition(650, 275);
        playerGemsNumberText.setPosition(690,270);
        waveText.setPosition(600,350);
        waveNumberText.setPosition(780,347);
        enemiesKilledText.setPosition(600,425);
        enemiesKilledNumberText.setPosition(780,422);
        scoreText.setPosition(600,500);
        scoreNumberText.setPosition(690,497);
    }
    else
    {
        gemSprites[4]->setPosition(595,34);
        playerGemsNumberText.setPosition(635,28);
        waveText.setPosition(540, 70);
        waveNumberText.setPosition(730,66);
        enemiesKilledText.setPosition(540, 115);
        enemiesKilledNumberText.setPosition(730,111);
        scoreText.setPosition(580, 156);
        scoreNumberText.setPosition(680,151);
    }
}

/**update the sprites */
void vGameBoard::adaptAnimationSprite()
{
    /** change value in enum after */
    for(size_t i=0;i<listOfAcideCloudSpell.size();i++)
    {
        listOfAcideCloudSpell[i]->setTextureRect(IntRect(x_acide*909,0,909,2938));
    }

    for(size_t i=0;i<listOfFireSpell.size();i++)
    {
        listOfFireSpell[i]->setTextureRect(IntRect(x_fire*FIRE_HEIGHT,0,FIRE_HEIGHT,FIRE_WIDTH));
    }

    for(size_t i=0;i<listOfLigntningSpell.size();i++)
    {
        listOfLigntningSpell[i]->setTextureRect(IntRect(x_lightning*FIRE_HEIGHT,0,FIRE_HEIGHT,FIRE_WIDTH));
    }

    ///ENEMIES
    for(int i = 0; i<(int)listOfvEnnemies.size();i++)
    {
        if(dynamic_cast<Ogre*>(listOfvEnnemies[i]->getEnemy()))
        {
            listOfvEnnemies[i]->getSprite()->setTextureRect(IntRect(x_Ogre*OGRE_WIDTH,y_Ogre*OGRE_HEIGHT,OGRE_WIDTH,OGRE_HEIGHT));
        }
        else if(dynamic_cast<Orc*>(listOfvEnnemies[i]->getEnemy()))
        {
            listOfvEnnemies[i]->getSprite()->setTextureRect(IntRect(x_Orc*ORC_WIDTH,y_Orc*ORC_HEIGHT,ORC_WIDTH,ORC_HEIGHT));
        }
        else if(dynamic_cast<ShadowMonster*>(listOfvEnnemies[i]->getEnemy()))
        {
            listOfvEnnemies[i]->getSprite()->setTextureRect(IntRect(x_shadowMonster*SHADOWMONSTER_WIDTH,y_shadowMonster*SHADOWMONSTER_HEIGHT,SHADOWMONSTER_WIDTH,SHADOWMONSTER_HEIGHT));
        }
        else if(dynamic_cast<KnightOfDeath*>(listOfvEnnemies[i]->getEnemy()))
        {
            listOfvEnnemies[i]->getSprite()->setTextureRect(IntRect(x_knight*KNIGHTOFDEATH_WIDTH,y_knight*KNIGHTOFDEATH_HEIGHT,KNIGHTOFDEATH_WIDTH,KNIGHTOFDEATH_HEIGHT));
        }
        else if(dynamic_cast<Gremlin*>(listOfvEnnemies[i]->getEnemy()))
        {
            listOfvEnnemies[i]->getSprite()->setTextureRect(IntRect(x_gremlin*GREMLIN_WIDTH,y_gremlin*GREMLIN_HEIGHT,GREMLIN_WIDTH,GREMLIN_HEIGHT));
        }
    }

    adaptPartOfTexture();
}

/**adapt which part of spreet sheet we need to display for animation */
void vGameBoard::adaptPartOfTexture()
{
    if(animClock.getElapsedTime().asSeconds() > 0.08f / game.getGameSpeed())
    {
        if(x_Ogre*OGRE_WIDTH >= (int)ogreTextureWalk.getSize().x - OGRE_WIDTH)
        {
            x_Ogre = 0;
        }
        else
        {
            x_Ogre++;
        }

        if(x_shadowMonster*SHADOWMONSTER_WIDTH >= (int)shadowMonsterTextureWalk.getSize().x - SHADOWMONSTER_WIDTH)
        {
            x_shadowMonster = 0;
        }
        else
        {
            x_shadowMonster++;
        }


        if(x_Orc*ORC_WIDTH >= (int)orcTextureWalk.getSize().x - ORC_WIDTH)
        {
            x_Orc = 0;
        }
        else
        {
            x_Orc++;
        }


        if(x_gremlin*GREMLIN_WIDTH >= (int)gremlinTextureWalk.getSize().x - GREMLIN_WIDTH)
        {
            x_gremlin = 0;
        }
        else
        {
            x_gremlin++;
        }


        if(x_knight*KNIGHTOFDEATH_WIDTH >= (int)knightOfDeathTextureWalk.getSize().x - KNIGHTOFDEATH_WIDTH)
        {
            x_knight = 0;
        }
        else
        {
            x_knight++;
        }

        ///if the animation is at the end
        if(game.isAcidCloudSpellActive())
        {
            if(x_acide*909 >= (int)acideCloudEffectTexture.getSize().x - 909)
            {
                game.setAcidCloudActive(false);
                x_acide = 0;
            }
            else
            {
                x_acide++;
            }
        }

        ///if the animation is at the end
        if(game.isFireSpellActive())
        {
            if(x_fire*FIRE_HEIGHT>= (int)fireEffectTexture.getSize().x - FIRE_HEIGHT)
            {
                game.setFireActive(false);
                x_fire = 0;
            }
            else
            {
                x_fire++;
            }
        }

        ///if the animation is at the end
        if(game.isLightNingSpellActive())
        {
            if(x_lightning*LIGHTNING_HEIGHT>= (int)lightningEffectTexture.getSize().x - LIGHTNING_HEIGHT)
            {
                game.setLightningActive(false);
                x_lightning = 0;
            }
            else
            {
                x_lightning++;
            }
        }



        animClock.restart();
    }
}

/**call the method updateTexture who in terms of the state of ennemy set the good texture to sprite and adapt him */
void vGameBoard::adaptAnimationTexture()
{
    //adapt the texture of only dead enemies to save resources
    for(int i=0;i < (int)listOfvEnnemies.size();i++)
    {
        if(!dynamic_cast<StateDie*>(listOfvEnnemies[i]->getEnemy()->getState()))
        {
            listOfvEnnemies[i]->updateTexture();
        }
    }
}

/** launch a pop up with a message said by the king */
void vGameBoard::activeMessagePopUp(std::string message)
{
    messagePopUpText.setString(message);
    isMessagePopUp = true;
    messageClock.restart();
}

/** buy the tower*/
void vGameBoard::buyTower(TypeOfTowerPrice type, int position)
{
    bool positionAlreadyUsed = game.getMap()->isTowerPositonAlreadyUsed(position);

    if(!positionAlreadyUsed)
    {
        switch(type)
        {
            case earth:
            {
                game.getMap()->addTower(earth,position);
                vTower *vtower = new vTower(game.getMap()->getXOftheNextTower(),game.getMap()->getYOftheNextTower(),game.getMap()->getTowers().back());
                vtower->towerTexture = &earthTowerTexture1;
                vtower->attackTexture = &earthAttack;
                vtower->chargeInformations();
                listOfvTower.push_back(vtower);
                break;
            }
            case ice:
            {
                game.getMap()->addTower(ice,position);
                vTower *vtower = new vTower(game.getMap()->getXOftheNextTower(),game.getMap()->getYOftheNextTower(),game.getMap()->getTowers().back());
                vtower->towerTexture = &iceTowerTexture1;
                vtower->attackTexture = &iceAttack;
                vtower->chargeInformations();
                listOfvTower.push_back(vtower);
                break;
            }
            case iron:
            {
                game.getMap()->addTower(iron,position);
                vTower *vtower = new vTower(game.getMap()->getXOftheNextTower(),game.getMap()->getYOftheNextTower(),game.getMap()->getTowers().back());
                vtower->towerTexture = &ironTowerTexture1;
                vtower->attackTexture = &ironAttack;
                vtower->chargeInformations();
                listOfvTower.push_back(vtower);
                break;
            }
            case sand:
            {
                game.getMap()->addTower(sand,position);
                vTower *vtower = new vTower(game.getMap()->getXOftheNextTower(),game.getMap()->getYOftheNextTower(),game.getMap()->getTowers().back());
                vtower->towerTexture = &sandTowerTexture1;
                vtower->attackTexture = &sandAttack;
                vtower->chargeInformations();
                listOfvTower.push_back(vtower);

                break;
            }
        }
        //type = price of tower
        game.debitPlayerWallet(type);
        playerGemsNumberText.setString(to_string(game.getPlayer()->getCoins()));
        cout<<game.getPlayer()->getCoins()<<endl;
    }
    else
    {
        activeMessagePopUp("A tower is\nalready at this\nposition.");
    }
}

/**Reset view (towers) */
void vGameBoard::resetGameView()
{
    for(vTower *tower:listOfvTower)
    {
        delete tower;
    }

    listOfvTower.clear();
    isChoosingNumberForPositionTower = false;
    changeStatsPosition(game.isGameOver());
}

/** configure a text who that will after showing on screnn*/
void vGameBoard::createText(Text& text, Color colorFill, Color colorOutline, string str, float xScale, float yScale, int xPosition, int yPosition)
{
    text.setFont(font);
    text.setFillColor(colorFill);
    text.setOutlineColor(colorOutline);
    text.setOutlineThickness(1.2f);
    text.setString(str);
    text.setScale(xScale,yScale);
    text.setPosition(xPosition,yPosition);
}

/**to verify if all images is accessible and charge in the texture*/
bool vGameBoard::verifyImage()
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
bool vGameBoard::verifyImageTower()
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
bool vGameBoard::verifyImageMonsters()
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
bool vGameBoard::verifyImageMapEntities()
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
bool vGameBoard::verifyImageTowersInformations()
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


