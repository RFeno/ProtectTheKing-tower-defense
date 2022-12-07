#include <SFML/Graphics.hpp>
#include <iostream>

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

/**SPELLS */
#include "AcidCloudSpell.h"
#include "FireSpell.h"
#include "LightningSpell.h"

#include "vGameBoard.h"
#include "StateDie.h"

using namespace sf;
using namespace std;

vGameBoard::vGameBoard(RenderWindow &window)
{
    this->windowFromMain = &window;

    isChoosingNumberForPositionTower=false;
    isSellingTower = false;
}

vGameBoard::~vGameBoard()
{
    //dtor
}

/** allow to run and launch view game */
void vGameBoard::launchView()
{
    //vsynch activation
    windowFromMain->setVerticalSyncEnabled(true);

    // limit the window to 60 images per second
    windowFromMain->setFramerateLimit(60);

    if(verifyImage())
    {
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
    //bind because AIP
    for(int i=0;i<(int)game.getMap()->getEnemies().size();i++)
    {
        listOfvEnnemies[i]->chargeInformations(game.getMap()->getEnemies()[i]->clone());
    }
}

/** remove a vtower of gameboard*/
int vGameBoard::searchVTower(int position)
{
    int result = -1;

    for(size_t i=0;i<listOfvTower.size();i++)
    {
        if(game.getMap()->getTowers()[i]->getPosition() == position)
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

/**sell a tower of gameboard */
void vGameBoard::sellTower(int position)
{
    isChoosingNumberForPositionTower = false;

    for(int i=0;i<(int)game.getMap()->getTowers().size();i++)
    {
        if(game.getMap()->getTowers()[i]->getPosition() == position)
        {
            game.creditPlayerWallet(game.getMap()->getTowers()[i]->getType() * 0.5f);
            playerGemsNumberText.setString(to_string(game.getPlayer()->getCoins()));
            removeVTower(position);
            game.getMap()->removeTower(*game.getMap()->getTowers()[i]);
        }
    }
    isSellingTower = false;
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
                if(isSpriteClicked(*sellButtonSprite))
                {
                    isChoosingNumberForPositionTower = true;
                    isSellingTower = true;
                    chooseNumberText.setString("Choose the location of\n     the tower to sell");
                }
            }

            // close the sign to choose tower emplacement
            if(isSpriteClicked(*closeButtonSprite))
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

            //detect button reset
            if(game.isGameOver() && isSpriteClicked(*resetButtonFailSprite))
            {
                game.resetGame();
                resetGameView();
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
                    sellTower(position);
                }
                if(isSpriteClicked(*twoSprites[0]))
                {
                    position = 2;
                    sellTower(position);
                }
                if(isSpriteClicked(*threeSprites[0]))
                {
                    position = 3;
                    sellTower(position);
                }
                if(isSpriteClicked(*fourSprites[0]))
                {
                    position = 4;
                    sellTower(position);
                }
                if(isSpriteClicked(*fiveSprites[0]))
                {
                    position = 5;
                    sellTower(position);
                }
                if(isSpriteClicked(*sixSprites[0]))
                {
                    position = 6;
                    sellTower(position);
                }
                if(isSpriteClicked(*sevenSprites[0]))
                {
                    position = 7;
                    sellTower(position);
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
    if(isSpriteClicked(*pauseButtonSprite))
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

    if(isSpriteClicked(*decreaseSpeedButtonSprite))
    {
        game.decreaseGameSpeed();
    }

    if(isSpriteClicked(*increaseSpeedButtonSprite))
    {
        game.increaseGameSpeed();
    }
}

/** allow to set choice of tower  */
void vGameBoard::eventsChoiceTowers()
{
    chooseNumberText.setString("Choose the location of\n     the tower to buy");
    if(isSpriteClicked(*earthTowerButtonSprite))
    {
        cout << "button buy earthTower click" << endl;
        eventsActiveTowersChoice(earth);
    }

    // buy sand tower
    if(isSpriteClicked(*sandTowerButtonSprite))
    {
        cout << "button buy sandTower click" << endl;
        eventsActiveTowersChoice(sand);
    }

    // buy ice tower
    if(isSpriteClicked(*iceTowerButtonSprite))
    {
        cout << "button buy iceTower click" << endl;
        eventsActiveTowersChoice(ice);
    }

    // buy iron tower
    if(isSpriteClicked(*ironTowerButtonSprite))
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
        activeMessagePopUp("All slots are\noccupied. Please\nsell a tower.");
    }
}

/** events to active spells */
void vGameBoard::eventsSpells()
{
    //button to buy
    if(isSpriteClicked(*acideCloudBuyButtonSprite))
    {
        cout <<  "acide cloud buy button click" << endl;
        eventsActiveSpell(acidCloud);
    }
    else if(isSpriteClicked(*fireBuyButtonSprite))
    {
        cout <<  "fire buy button click" << endl;
        eventsActiveSpell(fire);
    }
    else if(isSpriteClicked(*lightningBuyButtonSprite))
    {
        cout <<  "lightning buy button click" << endl;
        eventsActiveSpell(lightning);
    }

    //button to active
    if(isSpriteClicked(*acideCloudSprite))
    {
        cout <<  "acide cloud spell active button click" << endl;
        if(game.getPlayer()->activeSpell(acidCloud,game.getMap()->getEnemies()))
        {
            game.setAcidCloudActive(true);
        }
    }
    else if(isSpriteClicked(*fireSprite))
    {
        cout <<  "fire spell active button click" << endl;
        if(game.getPlayer()->activeSpell(fire,game.getMap()->getEnemies()))
        {
            game.setFireActive(true);
        }
    }
    else if(isSpriteClicked(*lightningSprite))
    {
        cout <<  "lightning spell active button click" << endl;
        if(game.getPlayer()->activeSpell(lightning,game.getMap()->getEnemies()))
        {
            game.setLightningActive(true);
        }
    }

    // calculation of spell number of th eplayer
    game.getPlayer()->updateSpellsNumber();
    // update stock of spells
    acidStockNumberText.setString(to_string(game.getPlayer()->getAcidNumber()));
    fireStockNumberText.setString(to_string(game.getPlayer()->getFireNumber()));
    lightningStockNumberText.setString(to_string(game.getPlayer()->getLightningNumber()));
}

/***/
void vGameBoard::eventsActiveSpell(TypeOfSpell type)
{
    //type == (type and price)
    if((game.getPlayer()->getCoins()) - type >=0 )
    {
        game.getPlayer()->buySpell(type);
        game.debitPlayerWallet(type);
    }
    else
    {
        activeMessagePopUp("You have not\nenough gems to\nbuy this spell.");
    }
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
    ///update player stats when enemy dies
    game.increasePlayerStatsWhenEnemyKilled();
    playerGemsNumberText.setString(to_string(game.getPlayer()->getCoins()));
    scoreNumberText.setString(to_string(game.getPlayer()->getScore()));
    enemiesKilledNumberText.setString(to_string(game.getPlayer()->getNumberOfEnemyKilled()));

    ///reset wave is all enemies are dead
    if(game.isEndOfWave())
    {
        //desactivate all animations for tower
        for(Tower *tower:game.getMap()->getTowers())
        {
            tower->setAttacking(false);
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
        game.getMap()->getEnemies()[game.getNumberOfEnemiesSpawned()]->setSpawn(true);

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
            game.getMap()->confrontationTowersEnemies();
            attackTowerClock.restart();
        }

        ///attack of enemies
        if(attackClock.getElapsedTime().asSeconds() > (0.5f / game.getGameSpeed()))
        {
            //update King Health
            updateKingHealth();

            game.getMap()->confrontationEnemiesKing();

            updateKingHealth();



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
    kingHealthGreenSprite->setScale(Vector2f(0.20*remainingHealth,0.20));
}

/**update health bar of all enemies who are not dead **/
void vGameBoard::updateHealthBarAllEnemies()
{
    for(int i=0;i<(int)game.getMap()->getEnemies().size();i++)
    {
        listOfvEnnemies[i]->updateHealth(game.getMap()->getEnemies()[i]->clone());
    }
}

/** to draw the entitties in the window */
void vGameBoard::drawEntities()
{
    ///map
    windowFromMain->draw(*mapSprite);

    if(!game.isGameOver())
    {
        drawMapEntities();
        drawGameSpeedView();

        // button to sell towers
        windowFromMain->draw(*sellButtonSprite);
        windowFromMain->draw(sellText);

        ///towers 1 to 4
        for(int i = 0; i < (int)listOfvTower.size(); i++)
        {
            if(game.getMap()->getTowers()[i]->getPosition() -1 < 4)
            {
                windowFromMain->draw(*(listOfvTower[i]->getSprite()));
            }
        }

        drawEnemies();

        //Place here elemnets between the towers
        drawSpellEntities();

        ///towers 5 to 7
        for(int i = 0; i < (int)listOfvTower.size(); i++)
        {
            if(game.getMap()->getTowers()[i]->getPosition() -1 >= 4)
            {
                windowFromMain->draw(*(listOfvTower[i]->getSprite()));
            }
        }

        /// attack animations of towers
        for(int i = 0; i < (int)listOfvTower.size(); i++)
        {
            if(game.getMap()->getTowers()[i]->isAttacking())
            {
                windowFromMain->draw(*(listOfvTower[i]->getAttackSprite()));
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
            windowFromMain->draw(*closeButtonSprite);
            windowFromMain->draw(*headerShopSprite);
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
    windowFromMain->draw(*fireBuyButtonSprite);
    windowFromMain->draw(*acideCloudBuyButtonSprite);
    windowFromMain->draw(*lightningBuyButtonSprite);

    ///informations of spells
    for(int i = 6; i < 9; i++)
    {
        windowFromMain->draw(*signSprites[i]);
    }

    for(int i = 5; i < 8; i++)
    {
        windowFromMain->draw(*gemSprites[i]);
    }

    for(int i = 4; i < 7; i++)
    {
        windowFromMain->draw(*swordSprites[i]);
    }
    windowFromMain->draw(acidStockText);
    windowFromMain->draw(acidStockNumberText);
    windowFromMain->draw(acidAttackNumberText);
    windowFromMain->draw(acidPriceText);
    windowFromMain->draw(fireStockText);
    windowFromMain->draw(fireStockNumberText);
    windowFromMain->draw(fireAttackNumberText);
    windowFromMain->draw(firePriceText);
    windowFromMain->draw(lightningStockText);
    windowFromMain->draw(lightningStockNumberText);
    windowFromMain->draw(lightningAttackNumberText);
    windowFromMain->draw(lightningPriceText);
}

/** draw map entities */
void vGameBoard::drawMapEntities()
{
    drawMapButtons();

    ///king health and bubble message
    windowFromMain->draw(*kingHealthRedSprite);
    windowFromMain->draw(*kingHealthGreenSprite);

    /// message pop up said by the king
    if(isMessagePopUp)
    {
        if(messageClock.getElapsedTime().asSeconds() < 5)
        {
            windowFromMain->draw(*infoBulbleMessageSprite);
            windowFromMain->draw(messagePopUpText);
        }
        else
        {
            messageClock.restart();
            isMessagePopUp = false;
        }
    }

    ///tower informations
    windowFromMain->draw(*windowSmallTowerSprite);
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
    windowFromMain->draw(*windowSmallSpellSprite);


}

/** draw map buttons */
void vGameBoard::drawMapButtons()
{
    ///spell buttons
    windowFromMain->draw(*lightningSprite);
    windowFromMain->draw(*fireSprite);
    windowFromMain->draw(*acideCloudSprite);

    ///towers buttons
    windowFromMain->draw(*ironTowerButtonSprite);
    windowFromMain->draw(*iceTowerButtonSprite);
    windowFromMain->draw(*sandTowerButtonSprite);
    windowFromMain->draw(*earthTowerButtonSprite);
}

/** draw enemies*/
void vGameBoard::drawEnemies()
{
    //allows you to draw some enemies before others
    for(int i=0;i<Enemies::NUMBER_OF_ENEMY_TYPES;i++)
    {
        for(int j=0;j<(int)game.getMap()->getEnemies().size();j++)
        {
            if(game.getMap()->getEnemies()[j]->isSpawn() && !dynamic_cast<StateDie*>(game.getMap()->getEnemies()[j]->getState()))
            {
                switch(i)
                {
                    case 0:
                    {
                        if(dynamic_cast<Orc*>(game.getMap()->getEnemies()[j]))
                        {
                           drawOneEnemy(listOfvEnnemies[j]);
                        }
                        break;
                    }
                    case 1:
                    {
                        if(dynamic_cast<Gremlin*>(game.getMap()->getEnemies()[j]))
                        {
                            drawOneEnemy(listOfvEnnemies[j]);
                        }
                        break;
                    }
                    case 2:
                    {
                        if(dynamic_cast<ShadowMonster*>(game.getMap()->getEnemies()[j]))
                        {
                           drawOneEnemy(listOfvEnnemies[j]);
                        }
                        break;
                    }
                    case 3:
                    {
                        if(dynamic_cast<Ogre*>(game.getMap()->getEnemies()[j]))
                        {
                           drawOneEnemy(listOfvEnnemies[j]);
                        }
                        break;
                    }
                    case 4:
                    {
                        if(dynamic_cast<KnightOfDeath*>(game.getMap()->getEnemies()[j]))
                        {
                            drawOneEnemy(listOfvEnnemies[j]);
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
        windowFromMain->draw(*pauseButtonSprite);
    }
    else
    {
        windowFromMain->draw(*playGameButtonSprite);
    }

    windowFromMain->draw(*increaseSpeedButtonSprite);
    windowFromMain->draw(*decreaseSpeedButtonSprite);
    windowFromMain->draw(*gameSpeedEmptyTableSprite);
    windowFromMain->draw(*multiplierSprite);

    switch(game.getGameSpeed())
    {
        case 1:
        {
            windowFromMain->draw(*gameSpeedOneSprite);
            break;
        }
        case 2:
        {
            windowFromMain->draw(*gameSpeedTwoSprite);
            break;
        }
        case 3:
        {
            windowFromMain->draw(*gameSPeedThreeSprite);
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
        windowFromMain->draw(*backgroundSprite);
        windowFromMain->draw(*tableEmptyFailSprite);
        windowFromMain->draw(*windowFailSprite);
        windowFromMain->draw(*headerFailedSprite);
        windowFromMain->draw(*resetButtonFailSprite);
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
        if(dynamic_cast<Ogre*>(game.getMap()->getEnemies()[i]))
        {
            listOfvEnnemies[i]->getSprite()->setTextureRect(IntRect(x_Ogre*OGRE_WIDTH,y_Ogre*OGRE_HEIGHT,OGRE_WIDTH,OGRE_HEIGHT));
        }
        else if(dynamic_cast<Orc*>(game.getMap()->getEnemies()[i]))
        {
            listOfvEnnemies[i]->getSprite()->setTextureRect(IntRect(x_Orc*ORC_WIDTH,y_Orc*ORC_HEIGHT,ORC_WIDTH,ORC_HEIGHT));
        }
        else if(dynamic_cast<ShadowMonster*>(game.getMap()->getEnemies()[i]))
        {
            listOfvEnnemies[i]->getSprite()->setTextureRect(IntRect(x_shadowMonster*SHADOWMONSTER_WIDTH,y_shadowMonster*SHADOWMONSTER_HEIGHT,SHADOWMONSTER_WIDTH,SHADOWMONSTER_HEIGHT));
        }
        else if(dynamic_cast<KnightOfDeath*>(game.getMap()->getEnemies()[i]))
        {
            listOfvEnnemies[i]->getSprite()->setTextureRect(IntRect(x_knight*KNIGHTOFDEATH_WIDTH,y_knight*KNIGHTOFDEATH_HEIGHT,KNIGHTOFDEATH_WIDTH,KNIGHTOFDEATH_HEIGHT));
        }
        else if(dynamic_cast<Gremlin*>(game.getMap()->getEnemies()[i]))
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
        if(x_Ogre*OGRE_WIDTH >= (int)ogreTextureWalk->getSize().x - OGRE_WIDTH)
        {
            x_Ogre = 0;
        }
        else
        {
            x_Ogre++;
        }

        if(x_shadowMonster*SHADOWMONSTER_WIDTH >= (int)shadowMonsterTextureWalk->getSize().x - SHADOWMONSTER_WIDTH)
        {
            x_shadowMonster = 0;
        }
        else
        {
            x_shadowMonster++;
        }


        if(x_Orc*ORC_WIDTH >= (int)orcTextureWalk->getSize().x - ORC_WIDTH)
        {
            x_Orc = 0;
        }
        else
        {
            x_Orc++;
        }


        if(x_gremlin*GREMLIN_WIDTH >= (int)gremlinTextureWalk->getSize().x - GREMLIN_WIDTH)
        {
            x_gremlin = 0;
        }
        else
        {
            x_gremlin++;
        }


        if(x_knight*KNIGHTOFDEATH_WIDTH >= (int)knightOfDeathTextureWalk->getSize().x - KNIGHTOFDEATH_WIDTH)
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
            if(x_acide*909 >= (int)acideCloudEffectTexture->getSize().x - 909)
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
            if(x_fire*FIRE_HEIGHT>= (int)fireEffectTexture->getSize().x - FIRE_HEIGHT)
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
            if(x_lightning*LIGHTNING_HEIGHT>= (int)lightningEffectTexture->getSize().x - LIGHTNING_HEIGHT)
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
        if(!dynamic_cast<StateDie*>(game.getMap()->getEnemies()[i]->getState()))
        {
            listOfvEnnemies[i]->updateTexture(game.getMap()->getEnemies()[i]->clone());
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


    /**clone when add because AIP */
    if(!positionAlreadyUsed)
    {
        switch(type)
        {
            case earth:
            {
                game.getMap()->addTower(earth,position);
                vTower *vtower = new vTower(game.getMap()->getXOftheNextTower(),game.getMap()->getYOftheNextTower());
                vtower->towerTexture = &resourceManager.earthTowerTexture1;
                vtower->attackTexture = &resourceManager.earthAttack;
                vtower->chargeInformations(game.getMap()->getTowers().back()->clone());
                listOfvTower.push_back(vtower);
                break;
            }
            case ice:
            {
                game.getMap()->addTower(ice,position);
                vTower *vtower = new vTower(game.getMap()->getXOftheNextTower(),game.getMap()->getYOftheNextTower());
                vtower->towerTexture = &resourceManager.iceTowerTexture1;
                vtower->attackTexture = &resourceManager.iceAttack;
                vtower->chargeInformations(game.getMap()->getTowers().back()->clone());
                listOfvTower.push_back(vtower);
                break;
            }
            case iron:
            {
                game.getMap()->addTower(iron,position);
                vTower *vtower = new vTower(game.getMap()->getXOftheNextTower(),game.getMap()->getYOftheNextTower());
                vtower->towerTexture = &resourceManager.ironTowerTexture1;
                vtower->attackTexture = &resourceManager.ironAttack;
                vtower->chargeInformations(game.getMap()->getTowers().back()->clone());
                listOfvTower.push_back(vtower);
                break;
            }
            case sand:
            {
                game.getMap()->addTower(sand,position);
                vTower *vtower = new vTower(game.getMap()->getXOftheNextTower(),game.getMap()->getYOftheNextTower());
                vtower->towerTexture = &resourceManager.sandTowerTexture1;
                vtower->attackTexture = &resourceManager.sandAttack;
                vtower->chargeInformations(game.getMap()->getTowers().back()->clone());
                listOfvTower.push_back(vtower);

                break;
            }
        }
        //type = price of tower
        game.debitPlayerWallet(type);
        playerGemsNumberText.setString(to_string(game.getPlayer()->getCoins()));
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
    // reset spells stock
    acidStockNumberText.setString(to_string(game.getPlayer()->getAcidNumber()));
    fireStockNumberText.setString(to_string(game.getPlayer()->getFireNumber()));
    lightningStockNumberText.setString(to_string(game.getPlayer()->getLightningNumber()));
}

bool vGameBoard::verifyImage()
{
    resourceManager.verifyImage();
    resourceManager.loadSprite();
    sf::Font font = resourceManager.font;

    ///entities gameSpeed textures
    pauseButtonTexture = &resourceManager.pauseButtonTexture;
    increaseSpeedButtonTexture =&resourceManager.increaseSpeedButtonTexture;
    decreaseSpeedButtonTexture = &resourceManager.decreaseSpeedButtonTexture;
    infoBulbleMessageTexture = &resourceManager.infoBulbleMessageTexture;
    playGameButtonTexture = &resourceManager.playGameButtonTexture;
    multiplierTexture = &resourceManager.multiplierTexture;

    ///entities gameSpeed sprites
    pauseButtonSprite = &resourceManager.pauseButtonSprite;
    increaseSpeedButtonSprite = &resourceManager.increaseSpeedButtonSprite;
    decreaseSpeedButtonSprite = &resourceManager.decreaseSpeedButtonSprite;
    infoBulbleMessageSprite = &resourceManager.infoBulbleMessageSprite;
    playGameButtonSprite = &resourceManager.playGameButtonSprite;
    gameSpeedEmptyTableSprite = &resourceManager.gameSpeedEmptyTableSprite;
    multiplierSprite = &resourceManager.multiplierSprite;
    gameSpeedOneSprite = &resourceManager.gameSpeedOneSprite;
    gameSpeedTwoSprite = &resourceManager.gameSpeedTwoSprite;
    gameSPeedThreeSprite = &resourceManager.gameSPeedThreeSprite;

    ///King health
    kingHealthGreenTexture = &resourceManager.kingHealthGreenTexture;
    kingHealthRedTexture = &resourceManager.kingHealthRedTexture;
    kingHealthGreenSprite = &resourceManager.kingHealthGreenSprite;
    kingHealthRedSprite = &resourceManager.kingHealthRedSprite;

    ///enemies walk textures
    gremlinTextureWalk = &resourceManager.gremlinTextureWalk;
    knightOfDeathTextureWalk = &resourceManager.knightOfDeathTextureWalk;
    shadowMonsterTextureWalk = &resourceManager.shadowMonsterTextureWalk ;
    ogreTextureWalk = &resourceManager.ogreTextureWalk;
    orcTextureWalk = &resourceManager.orcTextureWalk;

    ///enemies attack textures
    gremlinAttackTexture = &resourceManager.gremlinAttackTexture;
    knightOfDeathAttackTexture = &resourceManager.knightOfDeathAttackTexture ;
    shadowMonsterAttackTexture = &resourceManager.shadowMonsterAttackTexture;
    ogreAttackTexture = &resourceManager.ogreAttackTexture;
    orcAttackTexture = &resourceManager.orcAttackTexture;

    ///enemies dead textures
    gremlinDeadTexture = &resourceManager.gremlinDeadTexture ;
    knightOfDeathDeadTexture = &resourceManager.knightOfDeathDeadTexture;
    shadowMonsterDeadTexture = &resourceManager.shadowMonsterDeadTexture;
    ogreDeadTexture = &resourceManager.ogreDeadTexture;
    orcDeadTexture = &resourceManager.orcDeadTexture;

    ///map and entitites sprites
    mapSprite = &resourceManager.mapSprite;
    pauseSprite = &resourceManager.pauseSprite;
    acideCloudSprite = &resourceManager.acideCloudSprite;
    lightningSprite = &resourceManager.lightningSprite;
    fireSprite = &resourceManager.fireSprite;
    sellButtonSprite = &resourceManager.sellButtonSprite;
    closeButtonSprite = &resourceManager.closeButtonSprite;
    windowSmallSpellSprite = &resourceManager.windowSmallSpellSprite;
    windowSmallTowerSprite = &resourceManager.windowSmallTowerSprite;
    headerShopSprite = &resourceManager.headerShopSprite;

    ///Map and entitites textures
    mapTexture = &resourceManager.mapTexture;
    pauseTexture = &resourceManager.pauseTexture;
    emptyButtonTexture = &resourceManager.emptyButtonTexture;
    closeButtonTexture = &resourceManager.closeButtonTexture;
    headerShopTexture = &resourceManager.headerShopTexture;
    windowSmallTexture = &resourceManager.windowSmallTexture;
    bigTableTexture = &resourceManager.bigTableTexture;

    ///Map and entitites texts
    playerGemsNumberText = resourceManager.playerGemsNumberText;
    waveNumberText = resourceManager.waveNumberText;
    waveText = resourceManager.waveText;
    scoreNumberText = resourceManager.scoreNumberText;
    scoreText = resourceManager.scoreText;
    messagePopUpText = resourceManager.messagePopUpText;

    ///Spell textures
    acideCloudActiveButtonTexture = &resourceManager.acideCloudActiveButtonTexture;
    lightningActiveButtonTexture = &resourceManager.lightningActiveButtonTexture;
    fireActiveButtonTexture = &resourceManager.fireActiveButtonTexture;
    acideCloudEffectTexture = &resourceManager.acideCloudEffectTexture;
    fireEffectTexture = &resourceManager.fireEffectTexture;
    lightningEffectTexture = &resourceManager.lightningEffectTexture;

    ///Spell sprites:
    fireBuyButtonSprite = &resourceManager.fireBuyButtonSprite;
    acideCloudBuyButtonSprite = &resourceManager.acideCloudBuyButtonSprite;
    lightningBuyButtonSprite = &resourceManager.lightningBuyButtonSprite;

    ///Spell texts
    spellTitleText = resourceManager.spellTitleText;
    acidStockText = resourceManager.acidStockText;
    fireStockText = resourceManager.fireStockText;
    lightningStockText = resourceManager.lightningStockText;
    acidStockNumberText = resourceManager.acidStockNumberText;
    fireStockNumberText = resourceManager.fireStockNumberText;
    lightningStockNumberText = resourceManager.lightningStockNumberText;
    acidAttackNumberText = resourceManager.acidAttackNumberText;
    fireAttackNumberText = resourceManager.fireAttackNumberText;
    lightningAttackNumberText = resourceManager.lightningAttackNumberText;
    acidPriceText = resourceManager.acidPriceText;
    firePriceText = resourceManager.firePriceText;
    lightningPriceText = resourceManager.lightningPriceText;

    ///Towers attacks textures
    earthAttack = &resourceManager.earthAttack ;
    sandAttack = &resourceManager.sandAttack;
    iceAttack = &resourceManager.iceAttack;
    ironAttack = &resourceManager.ironAttack;

    ///Towers buy buttons textures
    earthTowerTextureButton = &resourceManager.earthTowerTextureButton;
    sandTowerTextureButton = &resourceManager.sandTowerTextureButton;
    iceTowerTextureButton = &resourceManager.iceTowerTextureButton;
    ironTowerTextureButton = &resourceManager.ironTowerTextureButton;

    ///Towers textures
    sandTowerTexture1 = &resourceManager.sandTowerTexture1;
    iceTowerTexture1 = &resourceManager.iceTowerTexture1;
    ironTowerTexture1 = &resourceManager.iceTowerTexture1;
    earthTowerTexture1 = &resourceManager.earthTowerTexture1;

    ///Tower buttons sprites
    earthTowerButtonSprite = &resourceManager.earthTowerButtonSprite;
    sandTowerButtonSprite = &resourceManager.sandTowerButtonSprite;
    iceTowerButtonSprite = &resourceManager.iceTowerButtonSprite;
    ironTowerButtonSprite = &resourceManager.ironTowerButtonSprite;

    ///Informations tower texts
    towerTitleText = resourceManager.towerTitleText;
    sellText = resourceManager.sellText;
    chooseNumberText = resourceManager.chooseNumberText;
    earthAttackText = resourceManager.earthAttackText;
    earthPriceText = resourceManager.earthPriceText;
    iceAttackText = resourceManager.iceAttackText;
    icePriceText = resourceManager.icePriceText;
    sandAttackText = resourceManager.sandAttackText;
    sandPriceText = resourceManager.sandPriceText;
    ironAttackText = resourceManager.ironAttackText;
    ironPriceText = resourceManager.ironPriceText;

    ///Informations tower textures
    oneTexture = &resourceManager.oneTexture;
    twoTexture = &resourceManager.twoTexture;
    threeTexture = &resourceManager.threeTexture;
    fourTexture = &resourceManager.fourTexture;
    fiveTexture = &resourceManager.fiveTexture;
    sixTexture = &resourceManager.sixTexture;
    sevenTexture = &resourceManager.sevenTexture;
    gemTexture = &resourceManager.gemTexture;
    swordTexture = &resourceManager.swordTexture;
    signTexture = &resourceManager.signTexture;

    ///Failed textures
    headerFailedTexture = &resourceManager.headerFailedTexture;
    resetButtonTexture = &resourceManager.resetButtonTexture;
    backgroundTexture = &resourceManager.backgroundTexture;

    ///Failed Sprites
    tableEmptyFailSprite = &resourceManager.tableEmptyFailSprite;
    windowFailSprite = &resourceManager.windowFailSprite;
    resetButtonFailSprite = &resourceManager.resetButtonFailSprite;
    headerFailedSprite = &resourceManager.headerFailedSprite;
    backgroundSprite = &resourceManager.backgroundSprite;

    ///Failed texts
    enemiesKilledText = resourceManager.enemiesKilledText;
    enemiesKilledNumberText = resourceManager.enemiesKilledNumberText;

    swordSprites = resourceManager.swordSprites;
    gemSprites = resourceManager.gemSprites;
    signSprites = resourceManager.signSprites;
    oneSprites = resourceManager.oneSprites;
    twoSprites = resourceManager.twoSprites;
    threeSprites = resourceManager.threeSprites;
    fourSprites = resourceManager.fourSprites;
    fiveSprites = resourceManager.fiveSprites;
    sixSprites = resourceManager.sixSprites;
    sevenSprites = resourceManager.sevenSprites;

    tableEmptyTexture = &resourceManager.tableEmptyTexture;

    swordSprites = resourceManager.swordSprites;
    gemSprites = resourceManager.gemSprites;
    signSprites = resourceManager.signSprites;
    oneSprites = resourceManager.oneSprites;
    twoSprites = resourceManager.twoSprites;
    threeSprites = resourceManager.threeSprites;
    fourSprites = resourceManager.fourSprites;
    fiveSprites = resourceManager.fiveSprites;
    sixSprites = resourceManager.sixSprites;
    sevenSprites = resourceManager.sevenSprites;

    listOfvEnnemies = resourceManager.listOfvEnnemies;
    listOfvTower = resourceManager.listOfvTower;
    listOfAcideCloudSpell = resourceManager.listOfAcideCloudSpell;
    listOfFireSpell = resourceManager.listOfFireSpell;
    listOfLigntningSpell = resourceManager.listOfLigntningSpell;

    return true;
}

