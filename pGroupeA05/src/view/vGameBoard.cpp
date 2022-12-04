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

#include "vGameBoard.h"
#include "StateDie.h"

using namespace sf;
using namespace std;

vGameBoard::vGameBoard(RenderWindow &window)
{
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

    for(int i=0; i < NUMBER_ACIDE_SPELL; i++)
    {
        listOfAcideCloudSpell.push_back(new Sprite());
    }
}

vGameBoard::~vGameBoard()
{
    //dtor
    for(vEnnemy *venemy: listOfvEnnemies)
    {
        delete venemy;
    }

    for(Sprite *acide: listOfAcideCloudSpell)
    {
        delete acide;
    }

    for(vTower *vTower: listOfvTower)
    {
        delete vTower;
    }

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

void vGameBoard::launchView()
{
    //vsynch activation
    windowFromMain->setVerticalSyncEnabled(true);

    // limit the window to 60 images per second
    windowFromMain->setFramerateLimit(60);

    if(verifyImage())
    {
        loadSprite();

        while (windowFromMain->isOpen())
        {
            Event event;

            while(windowFromMain->pollEvent(event))
            {
                InputHandler(event, windowFromMain);
            }

            if(!game.getGamePaused() && !game.isGameOver())
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
        cout << "There is no tower at this position." << endl;
    }
    return false;
}

/**to manage the events */
void vGameBoard::InputHandler(Event event, RenderWindow *window)
{
    // close the window
    if (event.type == Event::Closed)
    {
        window->close();
    }

    // detect mouse click
    if (event.type == Event::MouseButtonPressed)
    {
        cout << "model : " << game.getMap()->getTowers().size() <<endl;
        cout << "vue : " << listOfvTower.size() <<endl;
        if (event.mouseButton.button == Mouse::Left)
        {
            if(!isChoosingNumberForPositionTower)
            {
                // buy earth tower
                if(isSpriteClicked(earthTowerButtonSprite))
                {
                    cout << "button buy earthTower click" << endl;

                    if(game.getMap()->getTowers().size() <7)
                    {
                        //display error message
                        if(game.getPlayer()->getCoins() - earth >= 0 )
                        {
                            //dont forget to remove coins in player wallet

                            isChoosingNumberForPositionTower = true;
                            typeTowerChoosed = TypeOfTowerPrice::earth;
                        }
                        else
                        {
                            //display not enough coins message
                        }
                    }
                    else
                    {
                        //display all tower places are occupied
                    }

                }

                // buy sand tower
                if(isSpriteClicked(sandTowerButtonSprite))
                {
                    cout << "button buy sandTower click" << endl;

                    if(game.getMap()->getTowers().size() <7)
                    {
                        if(game.getPlayer()->getCoins() - sand >= 0 )
                        {
                            isChoosingNumberForPositionTower = true;
                            typeTowerChoosed = TypeOfTowerPrice::sand;
                        }
                    }
                }

                // buy ice tower
                if(isSpriteClicked(iceTowerButtonSprite))
                {
                    cout << "button buy iceTower click" << endl;

                    if(game.getMap()->getTowers().size() <7)
                    {
                        if(game.getPlayer()->getCoins() - ice >= 0 )
                        {
                            isChoosingNumberForPositionTower = true;
                            typeTowerChoosed = TypeOfTowerPrice::ice;

                        }
                    }
                }

                // buy iron tower
                if(isSpriteClicked(ironTowerButtonSprite))
                {
                    cout << "button buy ironTower click" << endl;

                    if(game.getMap()->getTowers().size() <7)
                    {
                        if(game.getPlayer()->getCoins() - iron >= 0 )
                        {
                            isChoosingNumberForPositionTower = true;
                            typeTowerChoosed = TypeOfTowerPrice::iron;
                        }
                    }
                }

                // sell tower
                if(isSpriteClicked(sellButtonSprite))
                {
                    isChoosingNumberForPositionTower = true;
                    isSellingTower = true;
                }
            }

            // close the sign to choose tower emplacement
            if(isSpriteClicked(closeButtonSprite))
            {
                cout<<"test"<<endl;
                isChoosingNumberForPositionTower = false;
                isSellingTower = false;
            }

            if(isSpriteClicked(pauseButtonSprite))
            {
                if(game.getGamePaused())
                {
                    game.setGamePaused(false);
                }
                else if(!game.getGamePaused())
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


        if (event.mouseButton.button == Mouse::Right)
        {
            cout << "right click"<< endl;

             if(isSpriteClicked(acideCloudSprite) == 1)
            {

            }
        }
    }


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
        gemSprites[i]->setPosition(Vector2f(x, 159));
        gemSprites[i]->setScale(0.20f,0.20f);
        x+=100;
    }

    x = 1010;
    for(int i = 0; i < 4; i++)
    {
        signSprites.push_back(new Sprite());
        signSprites[i]->setTexture(signTexture);
        signSprites[i]->setPosition(Vector2f(x, 89));
        signSprites[i]->setScale(0.3f,0.3f);
        x+=100;
    }

    twentySprite.setScale(0.30f,0.30f);
    twentySprite.setPosition(Vector2f(1045,100));

    fourtySprite.setScale(0.30f,0.30f);
    fourtySprite.setPosition(Vector2f(1145,100));

    sixtySprite.setScale(0.30f,0.30f);
    sixtySprite.setPosition(Vector2f(1245,100));

    eightySprite.setScale(0.30f,0.30f);
    eightySprite.setPosition(Vector2f(1345,100));

    oneHundredSprite.setScale(0.30f,0.30f);
    oneHundredSprite.setPosition(Vector2f(1045,158));

    oneHundredFiftySprite.setScale(0.30f,0.30f);
    oneHundredFiftySprite.setPosition(Vector2f(1145,158));

    twoHundredFiftySprite.setScale(0.30f,0.30f);
    twoHundredFiftySprite.setPosition(Vector2f(1245,158));

    fourHundredSprite.setScale(0.30f,0.30f);
    fourHundredSprite.setPosition(Vector2f(1345,158));

    sellButtonSprite.setTexture(emptyButtonTexture);
    sellButtonSprite.setScale(0.50f,0.50f);
    sellButtonSprite.setPosition(Vector2f(880,10));

    Color grey(200,200,200);
    sellText.setFont(font);
    sellText.setFillColor(grey);
    sellText.setOutlineColor(Color::Black);
    sellText.setOutlineThickness(1.2f);
    sellText.setString("Sell");
    sellText.setScale(1.1f,1.1f);
    sellText.setPosition(Vector2f(905,24));

    closeButtonSprite.setTexture(closeButtonTexture);
    closeButtonSprite.setRotation(45.f);
    closeButtonSprite.setScale(Vector2f(0.5f, 0.5f));
    closeButtonSprite.setPosition(880, 137);

    ///choose number
    signSprites.push_back(new Sprite());
    signSprites.back()->setTexture(signTexture);
    signSprites.back()->setPosition(Vector2f(500, 150));
    signSprites.back()->setScale(1.5f,0.5f);

    chooseNumberText.setFont(font);
    chooseNumberText.setFillColor(grey);
    chooseNumberText.setOutlineColor(Color::Black);
    chooseNumberText.setOutlineThickness(1.2f);
    chooseNumberText.setString("Choose the tower\n   emplacement");
    chooseNumberText.setScale(1.1f,1.1f);
    chooseNumberText.setPosition(Vector2f(540,162));

    oneSprites.push_back(new Sprite());
    oneSprites.back()->setTexture(oneTexture);
    oneSprites.back()->setPosition(530, 255);
    oneSprites.back()->setScale(0.5f,0.5f);

    twoSprites.push_back(new Sprite());
    twoSprites.back()->setTexture(twoTexture);
    twoSprites.back()->setPosition(580, 255);
    twoSprites.back()->setScale(0.5f,0.5f);

    threeSprites.push_back(new Sprite());
    threeSprites.back()->setTexture(threeTexture);
    threeSprites.back()->setPosition(630, 255);
    threeSprites.back()->setScale(0.5f,0.5f);

    fourSprites.push_back(new Sprite());
    fourSprites.back()->setTexture(fourTexture);
    fourSprites.back()->setPosition(680, 255);
    fourSprites.back()->setScale(0.5f,0.5f);

    fiveSprites.push_back(new Sprite());
    fiveSprites.back()->setTexture(fiveTexture);
    fiveSprites.back()->setPosition(730, 255);
    fiveSprites.back()->setScale(0.5f,0.5f);

    sixSprites.push_back(new Sprite());
    sixSprites.back()->setTexture(sixTexture);
    sixSprites.back()->setPosition(780, 255);
    sixSprites.back()->setScale(0.5f,0.5f);

    sevenSprites.push_back(new Sprite());
    sevenSprites.back()->setTexture(sevenTexture);
    sevenSprites.back()->setPosition(830, 255);
    sevenSprites.back()->setScale(0.5f,0.5f);

    /// Numbers to display under tower while choosing emplacement for tower
    oneSprites.push_back(new Sprite());
    oneSprites.back()->setTexture(oneTexture);
    oneSprites.back()->setPosition(1060, 505);
    oneSprites.back()->setScale(0.5f,0.5f);

    twoSprites.push_back(new Sprite());
    twoSprites.back()->setTexture(twoTexture);
    twoSprites.back()->setPosition(730, 505);
    twoSprites.back()->setScale(0.5f,0.5f);

    threeSprites.push_back(new Sprite());
    threeSprites.back()->setTexture(threeTexture);
    threeSprites.back()->setPosition(430, 505);
    threeSprites.back()->setScale(0.5f,0.5f);

    fourSprites.push_back(new Sprite());
    fourSprites.back()->setTexture(fourTexture);
    fourSprites.back()->setPosition(170, 505);
    fourSprites.back()->setScale(0.5f,0.5f);

    fiveSprites.push_back(new Sprite());
    fiveSprites.back()->setTexture(fiveTexture);
    fiveSprites.back()->setPosition(1050, 750);
    fiveSprites.back()->setScale(0.5f,0.5f);

    sixSprites.push_back(new Sprite());
    sixSprites.back()->setTexture(sixTexture);
    sixSprites.back()->setPosition(360, 750);
    sixSprites.back()->setScale(0.5f,0.5f);

    sevenSprites.push_back(new Sprite());
    sevenSprites.back()->setTexture(sevenTexture);
    sevenSprites.back()->setPosition(100, 750);
    sevenSprites.back()->setScale(0.5f,0.5f);

    /// player gems
    gemSprites.push_back(new Sprite());
    gemSprites.back()->setTexture(gemTexture);
    gemSprites.back()->setPosition(730,44);
    gemSprites.back()->setScale(0.30f,0.30f);

    //pas besoin de dire c'est implicite
    /*playerGemsText.setFont(font);
    playerGemsText.setFillColor(grey);
    playerGemsText.setOutlineColor(Color::Black);
    playerGemsText.setOutlineThickness(1.2f);
    playerGemsText.setString("Wallet : ");
    playerGemsText.setScale(0.8f,0.8f);
    playerGemsText.setPosition(540,40);*/

    playerGemsNumberText.setFont(font);
    playerGemsNumberText.setFillColor(Color::Yellow);
    playerGemsNumberText.setOutlineColor(Color::Black);
    playerGemsNumberText.setOutlineThickness(1.2f);
    playerGemsNumberText.setString(to_string(game.getPlayer()->getCoins()));
    playerGemsNumberText.setScale(0.8f,0.8f);
    playerGemsNumberText.setPosition(770,40);
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
    acideCloudSprite.setTexture(acideCloudTexture);
    fireSprite.setTexture(fireTexture);
    lightningSprite.setTexture(lightningTexture);

    acideCloudSprite.setScale(0.50f,0.50f);
    fireSprite.setScale(0.50f,0.50f);
    lightningSprite.setScale(0.50,0.50f);

    acideCloudSprite.setPosition(Vector2f(10, 55));
    fireSprite.setPosition(Vector2f(110, 55));
    lightningSprite.setPosition(Vector2f(210, 55));

    ///buttons to buy spells
    fireBuyButtonSprite.setTexture(emptyButtonTexture);
    acideCloudBuyButtonSprite.setTexture(emptyButtonTexture);
    lightningBuyButtonSprite.setTexture(emptyButtonTexture);

    fireBuyButtonSprite.setScale(0.35f,0.35f);
    acideCloudBuyButtonSprite.setScale(0.35f,0.35f);
    lightningBuyButtonSprite.setScale(0.35f,0.35f);

    fireBuyButtonSprite.setPosition(10,150);
    acideCloudBuyButtonSprite.setPosition(110,150);
    lightningBuyButtonSprite.setPosition(210,150);

    ///Title
    Color grey(200,200,200);
    spellTitleText.setFont(font);
    spellTitleText.setFillColor(grey);
    spellTitleText.setOutlineColor(Color::Black);
    spellTitleText.setOutlineThickness(1.2f);
    spellTitleText.setString("Spells");
    spellTitleText.setScale(1.1f,1.1f);
    spellTitleText.setPosition(Vector2f(10,10));

    ///effects
    for(int i=0; i < NUMBER_ACIDE_SPELL ; i++)
    {
        listOfAcideCloudSpell.push_back(new Sprite());
        listOfAcideCloudSpell[i]->setTexture(acideCloudEffectTexture);
        listOfAcideCloudSpell[i]->setTextureRect(IntRect(0,0,909,2398));
        listOfAcideCloudSpell[i]->setPosition(Vector2f(i*98, 240));
        listOfAcideCloudSpell[i]->setScale(0.17f,0.17f);
    }


}

/** load all entities for towers */
void vGameBoard::loadTowersEntities()
{
    ///towers buttons
    earthTowerButtonSprite.setTexture(earthTowerTextureButton);
    iceTowerButtonSprite.setTexture(iceTowerTextureButton);
    sandTowerButtonSprite.setTexture(sandTowerTextureButton);
    ironTowerButtonSprite.setTexture(ironTowerTextureButton);

    earthTowerButtonSprite.setScale(0.50f,0.50f);
    iceTowerButtonSprite.setScale(0.50f,0.50f);
    sandTowerButtonSprite.setScale(0.50f,0.50f);
    ironTowerButtonSprite.setScale(0.50f,0.50f);

    earthTowerButtonSprite.setPosition(Vector2f(1206,5));
    iceTowerButtonSprite.setPosition(Vector2f(1106,5));
    sandTowerButtonSprite.setPosition(Vector2f(1006,5));
    ironTowerButtonSprite.setPosition(Vector2f(1306,5));

    ///informations of tower
    twentySprite.setTexture(twentyTexture);
    fourtySprite.setTexture(fourtyTexture);
    sixtySprite.setTexture(sixtyTexture);
    eightySprite.setTexture(eightyTexture);
    oneHundredSprite.setTexture(oneHundredTexture);
    oneHundredFiftySprite.setTexture(oneHundredFiftyTexture);
    twoHundredFiftySprite.setTexture(twoHundredFiftyTexture);
    fourHundredSprite.setTexture(fourHundredTexture);
}

/**load all entities for map */
void vGameBoard::loadMapEntities()
{
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

/** to draw the entitties in the window */
void vGameBoard::drawEntities()
{
    ///map
    windowFromMain->draw(mapSprite);

    if(!game.isGameOver())
    {
        drawMapEntities();
        drawGameSpeedView();


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
        }

        drawEnemies();

        //Place here elemnets between the towers
        drawSpellEntities();


        ///towers 5 to 7
        for(int i = 0; i < (int)listOfvTower.size(); i++)
        {
            if(listOfvTower[i]->getTower()->getPosition() >= 5)
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

        // button to sell towers
        windowFromMain->draw(sellButtonSprite);
        windowFromMain->draw(sellText);

    }
}

void vGameBoard::drawSpellEntities()
{

    ///Acid spell
    /*for(int i=0; i < NUMBER_ACIDE_SPELL ; i++)
    {
        windowFromMain->draw(*listOfAcideCloudSpell[i]);
    }*/

    windowFromMain->draw(spellTitleText);
    windowFromMain->draw(fireBuyButtonSprite);
    windowFromMain->draw(acideCloudBuyButtonSprite);
    windowFromMain->draw(lightningBuyButtonSprite);
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

    ///reset wave is all enemies are dead
    if(game.IsEndOfWave())
    {
        //desactivate all animations for tower
        for(vTower *vtower:listOfvTower)
        {
            vtower->getTower()->setAttacking(false);
        }
        //delete and create and improve enemies
        game.refreshEnemies();
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
        if(attackTowerClock.getElapsedTime().asSeconds() > (0.06 / game.getGameSpeed()))
        {
            for(vTower *vtower: listOfvTower)
            {
                for(Enemies *enemy: game.getMap()->getEnemies())
                {
                    ///allow to attack only the first enemy in range and farthest
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
/** draw map entities */
void vGameBoard::drawMapEntities()
{
    drawMapButtons();

    ///king health and bubble message
    windowFromMain->draw(kingHealthRedSprite);
    windowFromMain->draw(kingHealthGreenSprite);
    windowFromMain->draw(infoBulbleMessageSprite);

    ///tower informations
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
    windowFromMain->draw(twentySprite);
    windowFromMain->draw(fourtySprite);
    windowFromMain->draw(sixtySprite);
    windowFromMain->draw(eightySprite);
    windowFromMain->draw(oneHundredSprite);
    windowFromMain->draw(oneHundredFiftySprite);
    windowFromMain->draw(twoHundredFiftySprite);
    windowFromMain->draw(fourHundredSprite);

    /// player gems
    windowFromMain->draw(playerGemsText);
    windowFromMain->draw(playerGemsNumberText);
    windowFromMain->draw(*gemSprites[4]);
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
    if(!game.getGamePaused())
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

/**update the sprites */
void vGameBoard::adaptAnimationSprite()
{
    adaptPartOfTexture();

    /*for(size_t i=0;i<listOfAcideCloudSpell.size();i++)
    {
        listOfAcideCloudSpell[i]->setTextureRect(IntRect(x_acide*909,0,909,2938));
    }*/

}

/**adapt which part of spreet sheet we need to display for animation */
void vGameBoard::adaptPartOfTexture()
{
    if(animClock.getElapsedTime().asSeconds() > 0.08f / game.getGameSpeed())
    {
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

         if(x_acide*909 >= (int)acideCloudEffectTexture.getSize().x - 909)
        {
            x_acide = 0;
        }
        else
        {
            x_acide++;
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
        game.setMessage("A tower is already at this position. You canno't buy a another tower at the same postion");
    }
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

    if(!closeButtonTexture.loadFromFile("res/images/gameBoard/button_plus.png"))
    {
        cerr << "ERROR chargement texture" << endl;
        return false;
    }

    if(!lightningTexture.loadFromFile("res/images/gameBoard/lightning.png"))
    {
        cerr << "ERROR chargement texture" << endl;
        return false;
    }

    if(!fireTexture.loadFromFile("res/images/gameBoard/fire.png"))
    {
        cerr << "ERROR chargement texture" << endl;
        return false;
    }

    if(!acideCloudTexture.loadFromFile("res/images/gameBoard/cloud.png"))
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

    if (!twentyTexture.loadFromFile("res/images/gameBoard/20.png"))
    {
        cerr << "ERROR chargement texture" << endl;
        return false;
    }

    if (!fourtyTexture.loadFromFile("res/images/gameBoard/40.png"))
    {
        cerr << "ERROR chargement texture" << endl;
        return false;
    }

    if (!sixtyTexture.loadFromFile("res/images/gameBoard/60.png"))
    {
        cerr << "ERROR chargement texture" << endl;
        return false;
    }

    if (!eightyTexture.loadFromFile("res/images/gameBoard/80.png"))
    {
        cerr << "ERROR chargement texture" << endl;
        return false;
    }

    if (!oneHundredTexture.loadFromFile("res/images/gameBoard/100.png"))
    {
        cerr << "ERROR chargement texture" << endl;
        return false;
    }

    if (!oneHundredFiftyTexture.loadFromFile("res/images/gameBoard/150.png"))
    {
        cerr << "ERROR chargement texture" << endl;
        return false;
    }

    if (!twoHundredFiftyTexture.loadFromFile("res/images/gameBoard/250.png"))
    {
        cerr << "ERROR chargement texture" << endl;
        return false;
    }

    if (!fourHundredTexture.loadFromFile("res/images/gameBoard/400.png"))
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

    if (!font.loadFromFile("res/fonts/plump.ttf"))
    {
        cerr << "ERROR chargement font" << endl;
        return false;
    }

    return true;
}


