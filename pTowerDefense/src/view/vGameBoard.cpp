#include "vGameBoard.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <unistd.h>

#include "Ogre.h"
#include "Orc.h"
#include "ShadowMonster.h"
#include "KnightOfDeath.h"
#include "Gremlin.h"
#include "vEnnemy.h"

#include "TowerEarth.h"
#include "TowerIce.h"
#include "TowerIron.h"
#include "TowerSand.h"

#include "StateDie.h"

using namespace sf;
using namespace std;

vGameBoard::vGameBoard(RenderWindow& window)
{
    this->windowFromMain = &window;
    //to delete
    //game.getMap()->addTower(new TowerEarth());
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

    for(Sprite *crystal: crystalSprites)
    {
        delete crystal;
    }

    for(Sprite *sign: signSprites)
    {
        delete sign;
    }

    for(Sprite *sword: swordSprites)
    {
        delete sword;
    }
}

vGameBoard::vGameBoard(const vGameBoard& other)
{
    //copy ctor
}

vGameBoard& vGameBoard::operator=(const vGameBoard& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
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

            while (windowFromMain->pollEvent(event))
            {
                InputHandler(event, windowFromMain);
            }

            updateGame();

            windowFromMain->clear();

            drawEntities();

            windowFromMain->display();
        }
    }
    else
        cout << "error" <<endl;
}

void vGameBoard::updateVennemyForView()
{
    //bind enemy model and sprite

    /** VEILLER A SUPP LES VENNEMIES MORTS */
    /*for(int i=0; i<(int)listOfvEnnemies.size(); i++)
    {
        if(dynamic_cast<StateDie*>(listOfvEnnemies[i]->getEnemy()->getState()))
        {
            cout << " suppression " << endl;
            removeVEnemy(*listOfvEnnemies[i]);
        }
    }*/


    for(int i=0; i< (int)game.getMap()->getEnemies().size(); i++)
    {
        //clone enemies because AI
        vEnnemy *venemy = new vEnnemy(game.getMap()->getEnemies()[i]);

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

        venemy->chargeInformations();


        listOfvEnnemies.push_back(venemy);
    }


//    for(int i=0; i < NUMBER_ACIDE_SPELL; i++)
//    {
//        listOfAcideCloudSpell.push_back(new Sprite());
//    }

    Vector2i* position = getPositionOfNewTower(earth);
    cout << "position x :"<< position->x << endl;

    if(game.getMap()->getTowers().size() > 0)
    {
        cout << "x de 1er tour : "<< game.getMap()->getTowers()[0]->getX() << endl;
    }

    cout << game.getMap()->getEnemies().size() << endl;
    cout << game.getMap()->strEnemies() << endl;
}

int vGameBoard::searchVEnemy(vEnnemy& enemy)
{
    int result = -1;

    for(size_t i=0;i<listOfvEnnemies.size();i++)
    {
        if(listOfvEnnemies[i]==&enemy)
        {
            result=i;
            break;
        }
    }
    return result;
}

bool vGameBoard::removeVEnemy(vEnnemy& enemy)
{
    int index = searchVEnemy(enemy);

    if(index!=-1)
    {
        vEnnemy *tmp = *(listOfvEnnemies.begin() + index);
        listOfvEnnemies.erase(listOfvEnnemies.begin()+index);
        delete tmp;

        return true;
    }
    else
    {
        cout << "this enemy is not in the list of vEnnmy" << endl;
    }
    return false;
}

/*to manage the events */
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
        if (event.mouseButton.button == Mouse::Left)
        {
            // buy earth tower
            if(isSpriteClicked(earthTowerSprite))
            {
                cout << "button buy earthTower click" << endl;

                if(game.getMap()->getTowers().size() <7)
                {
                    //display error message
                    if(game.getPlayer()->getCoins() - earth >= 0 )
                    {
                        //dont forget to remove coins in player wallet
                        buyTower(earth);
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
            if(isSpriteClicked(sandTowerSprite))
            {
                cout << "button buy sandTower click" << endl;

                if(game.getMap()->getTowers().size() <7)
                {
                    if(game.getPlayer()->getCoins() - sand >= 0 )
                    {
                        buyTower(sand);
                    }
                }
            }

            // buy earth tower
            if(isSpriteClicked(iceTowerSprite))
            {
                cout << "button buy iceTower click" << endl;

                if(game.getMap()->getTowers().size() <7)
                {
                    if(game.getPlayer()->getCoins() - ice >= 0 )
                    {
                        buyTower(ice);
                    }
                }
            }

            // buy iron tower
            if(isSpriteClicked(ironTowerSprite))
            {
                cout << "button buy ironTower click" << endl;

                if(game.getMap()->getTowers().size() <7)
                {
                    if(game.getPlayer()->getCoins() - iron >= 0 )
                    {
                        buyTower(iron);
                    }
                }
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

}

/* to load the sprites, adding texture to sprite */
void vGameBoard::loadSprite()
{
    // un sprite = 377 , 404
    // Les 2 premiers argument = position d'origine
    // Les 2 d'après, taille d'un sprite
    // Donc si tu veux prendre le deuxième sprite -> + 377 au premier argument et ansi de suite


    //in function of the type of enemy set positions and +
    for(size_t i=0;i<listOfvEnnemies.size();i++)
    {
       //
    }

    for(int i=0; i < NUMBER_ACIDE_SPELL ; i++)
    {
        listOfAcideCloudSpell.push_back(new Sprite());
        listOfAcideCloudSpell[i]->setTexture(acideCloudEffectTexture);
        listOfAcideCloudSpell[i]->setTextureRect(IntRect(0,0,909,2398));
        listOfAcideCloudSpell[i]->setPosition(Vector2f(i*98, 240));
        listOfAcideCloudSpell[i]->setScale(0.17f,0.17f);
    }


    mapSprite.setTexture(mapTexture);

    mapSprite.setScale(0.73f,0.75f);

    //towers buttons
    earthTowerSprite.setTexture(earthTowerTexture);
    iceTowerSprite.setTexture(iceTowerTexture);
    sandTowerSprite.setTexture(sandTowerTexture);
    ironTowerSprite.setTexture(ironTowerTexture);

    earthTowerSprite.setScale(0.50f,0.50f);
    iceTowerSprite.setScale(0.50f,0.50f);
    sandTowerSprite.setScale(0.50f,0.50f);
    ironTowerSprite.setScale(0.50f,0.50f);

    earthTowerSprite.setPosition(Vector2f(1006,5));
    iceTowerSprite.setPosition(Vector2f(1106,5));
    sandTowerSprite.setPosition(Vector2f(1206,5));
    ironTowerSprite.setPosition(Vector2f(1306,5));

    //informations of tower
    twentySprite.setTexture(twentyTexture);
    fourtySprite.setTexture(fourtyTexture);
    sixtySprite.setTexture(sixtyTexture);
    eightySprite.setTexture(eightyTexture);
    oneHundredSprite.setTexture(oneHundredTexture);
    oneHundredFiftySprite.setTexture(oneHundredFiftyTexture);
    twoHundredFiftySprite.setTexture(twoHundredFiftyTexture);
    fourHundredSprite.setTexture(fourHundredTexture);

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
        crystalSprites.push_back(new Sprite());
        crystalSprites[i]->setTexture(crystalTexture);
        crystalSprites[i]->setPosition(Vector2f(x, 159));
        crystalSprites[i]->setScale(0.20f,0.20f);
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

    //spells buttons
    acideCloudSprite.setTexture(acideCloudTexture);
    fireSprite.setTexture(fireTexture);
    lightningSprite.setTexture(lightningTexture);

    acideCloudSprite.setScale(0.50f,0.50f);
    fireSprite.setScale(0.50f,0.50f);
    lightningSprite.setScale(0.50,0.50f);

    acideCloudSprite.setPosition(Vector2f(10, 5));
    fireSprite.setPosition(Vector2f(110, 5));
    lightningSprite.setPosition(Vector2f(210, 5));
}


/* to draw the entitties in the window */
bool vGameBoard::drawEntities()
{
    //map
    windowFromMain->draw(mapSprite);

    //spell buttons
    windowFromMain->draw(lightningSprite);
    windowFromMain->draw(fireSprite);
    windowFromMain->draw(acideCloudSprite);

    //towers buttons
    windowFromMain->draw(ironTowerSprite);
    windowFromMain->draw(iceTowerSprite);
    windowFromMain->draw(sandTowerSprite);
    windowFromMain->draw(earthTowerSprite);

    //tower informations
    for(int i=0; i < 4 ; i++)
    {
        windowFromMain->draw(*signSprites[i]);
    }

    windowFromMain->draw(twentySprite);
    windowFromMain->draw(fourtySprite);
    windowFromMain->draw(sixtySprite);
    windowFromMain->draw(eightySprite);
    windowFromMain->draw(oneHundredSprite);
    windowFromMain->draw(oneHundredFiftySprite);
    windowFromMain->draw(twoHundredFiftySprite);
    windowFromMain->draw(fourHundredSprite);

    for(int i=0; i < 4 ; i++)
    {
        windowFromMain->draw(*swordSprites[i]);
    }

    /*for(int i=0; i < 4 ; i++)
    {
        windowFromMain->draw(*crystalSprites[i]);
    }*/

    /**A DEPLACER */
    // enemies spawn one per one
    if(spawnClock.getElapsedTime().asSeconds() > spawnTime && idSpawn < (int)listOfvEnnemies.size())
    {
        //window.draw(*enemiesSprite[idSpawn]);

        listOfvEnnemies[idSpawn]->setSpawn(true);
        listOfvEnnemies[idSpawn]->getEnemy()->setSpawn(true);
        idSpawn++;
        spawnClock.restart();
    }

    //ennemies
    for(int i=0;i<(int)listOfvEnnemies.size();i++)
    {
        if(listOfvEnnemies[i]->isSpawn())
        {
            windowFromMain->draw(*listOfvEnnemies[i]->getSprite());
        }
    }

    /** towers 1 to 4 */
    for(int i = 0; i < (int)listOfvTower.size(); i++)
    {
        if(i < 4)
        {
          windowFromMain->draw(*(listOfvTower[i]->getSprite()));
        }
    }

    /**
        Place here elemnets between the towers
    */

    // Acid spell
    for(int i=0; i < NUMBER_ACIDE_SPELL ; i++)
    {
        windowFromMain->draw(*listOfAcideCloudSpell[i]);
    }

    /** towers 5 to 7 */
    for(int i = 0; i < (int)listOfvTower.size(); i++)
    {
        if(i >= 4)
        {
          windowFromMain->draw(*(listOfvTower[i]->getSprite()));
        }
    }

    // attack animations of towers
    for(int i = 0; i < (int)listOfvTower.size(); i++)
    {
        if(listOfvTower[i]->getAttackClock()->getElapsedTime().asSeconds() > 2)
        {
            windowFromMain->draw(*(listOfvTower[i]->getAttackSprite()));
            if(listOfvTower[i]->getAttackClock()->getElapsedTime().asSeconds() > 3)
            {
                listOfvTower[i]->getAttackClock()->restart();
            }
        }
        cout<< "clock attaque : "<< listOfvTower[i]->getAttackClock()->getElapsedTime().asSeconds() << endl;
    }

    return true;
}

//fonction for actionEvent on Buttons Sprite
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

void vGameBoard::enemyAnimation()
{
    //method adapts which texture we need to display
    adaptAnimationTexture();


    //method adapts which parts of Texture (sprite sheet) we need to display
    adaptAnimationSprite();

    //for the deplacement
    /** à mettre dans un clock, peut etre dans vEnnmy */
    for(int i=0;i< (int)listOfvEnnemies.size();i++)
    {
//        if(listOfvEnnemies[i]->isSpawn())
//        {
            listOfvEnnemies[i]->getSprite()->setPosition(listOfvEnnemies[i]->getEnemy()->getX(),listOfvEnnemies[i]->getEnemy()->getY());
        //}
    }
}

void vGameBoard::updateGame()
{
    game.play();
    updateVennemyForView();
    enemyAnimation();

}

/*methods adapte which parts of sprite sheet we need to display*/
void vGameBoard::adaptAnimationSprite()
{
    adaptPartOfTexture();

    /*for(size_t i=0;i<listOfvEnnemies.size();i++)
    {
        if(dynamic_cast<Ogre*>(listOfvEnnemies[i]->getEnemy()))
        {
            listOfvEnnemies[i]->getSprite()->setTextureRect(IntRect(x_Ogre*OGRE_WIDTH,y_Ogre*OGRE_HEIGHT,OGRE_WIDTH,OGRE_HEIGHT));
        }

         if(dynamic_cast<Orc*>(game.getMap()->getEnemies()[i]))
        {
            listOfvEnnemies[i]->getSprite()->setTextureRect(IntRect(x_Orc*ORC_WIDTH,y_Orc*ORC_HEIGHT,ORC_WIDTH,ORC_HEIGHT));
        }

        if(dynamic_cast<ShadowMonster*>(game.getMap()->getEnemies()[i]))
        {
            listOfvEnnemies[i]->getSprite()->setTextureRect(IntRect(x_shadowMonster*SHADOWMONSTER_WIDTH,y_shadowMonster*SHADOWMONSTER_HEIGHT,SHADOWMONSTER_WIDTH,SHADOWMONSTER_HEIGHT));
        }

        if(dynamic_cast<KnightOfDeath*>(game.getMap()->getEnemies()[i]))
        {
            listOfvEnnemies[i]->getSprite()->setTextureRect(IntRect(x_knight*KNIGHTOFDEATH_WIDTH,y_knight*KNIGHTOFDEATH_HEIGHT,KNIGHTOFDEATH_WIDTH,KNIGHTOFDEATH_HEIGHT));
        }

        if(dynamic_cast<Gremlin*>(game.getMap()->getEnemies()[i]))
        {
            listOfvEnnemies[i]->getSprite()->setTextureRect(IntRect(x_gremlin*GREMLIN_WIDTH,y_gremlin*GREMLIN_HEIGHT,GREMLIN_WIDTH,GREMLIN_HEIGHT));
        }
    }*/

    for(size_t i=0;i<listOfAcideCloudSpell.size();i++)
    {
        listOfAcideCloudSpell[i]->setTextureRect(IntRect(x_acide*909,0,909,2938));
    }

}

void vGameBoard::adaptPartOfTexture()
{
    /*if(animClock.getElapsedTime().asSeconds() > 0.08f)
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

         if(x_acide*909 >= (int)acideCloudEffectTexture.getSize().x - 909)
        {
            x_acide = 0;
        }
        else
        {
            x_acide++;
        }
        animClock.restart();
    }*/
}
/**
*call the method updateTexture who in terms of the state of ennemy set the good texture to sprite
*/
void vGameBoard::adaptAnimationTexture()
{
    for(int i=0;i < (int)listOfvEnnemies.size();i++)
    {

        if(listOfvEnnemies[i]->getEnemy()!=nullptr)
        {
            listOfvEnnemies[i]->updateTexture();
        }
        else
        {
            removeVEnemy(*listOfvEnnemies[i]);
        }
    }
}

void vGameBoard::buyTower(TypeOfTower type)
{
    switch(type)
    {
        case earth:
        {
            Vector2i* position = getPositionOfNewTower(earth);

            TowerEarth* tower = new TowerEarth;
            game.getMap()->addTower(tower);


            //back = last element
            vTower *vtower = new vTower(position, game.getMap()->getTowers().back());
            vtower->towerTexture = &earthTowerTexture1;
            vtower->attackTexture = &earthAttack;
            vtower->chargeInformations();


            /** Ca ne marche pas je comprend pas pourquoi */
            //vtower->getTower()->setX(position->x);

            listOfvTower.push_back(vtower);


            delete tower;
            break;
        }

        case ice:
        {
            TowerIce* tower = new TowerIce;
            game.getMap()->addTower(tower);

            Vector2i* position = getPositionOfNewTower(ice);

            //back = last element
            vTower *vtower = new vTower(position, game.getMap()->getTowers().back());
            vtower->towerTexture = &iceTowerTexture1;
            vtower->chargeInformations();
            vtower->getSprite()->setPosition(position->x, position->y);

            listOfvTower.push_back(vtower);

            delete tower;
            break;
        }


        case iron:
        {
            TowerIron* tower = new TowerIron;
            game.getMap()->addTower(tower);

            Vector2i* position = getPositionOfNewTower(iron);

            //back = last element
            vTower *vtower = new vTower(position, game.getMap()->getTowers().back());
            vtower->towerTexture = &ironTowerTexture1;
            vtower->chargeInformations();
            vtower->getSprite()->setPosition(position->x, position->y);

            listOfvTower.push_back(vtower);

            delete tower;
            break;
        }

        case sand:
        {
            TowerSand* tower = new TowerSand;
            game.getMap()->addTower(tower);

            Vector2i* position = getPositionOfNewTower(sand);

            //back = last element
            vTower *vtower = new vTower(position, game.getMap()->getTowers().back());
            vtower->towerTexture = &sandTowerTexture1;
            vtower->chargeInformations();
            vtower->getSprite()->setPosition(position->x, position->y);

            listOfvTower.push_back(vtower);

            delete tower;
            break;
        }
    }
}

/**
*depending on the type of tower the player wants to buy
*this method will call the correct method which will return an x and y position
*/
Vector2i* vGameBoard::getPositionOfNewTower(TypeOfTower type)
{
    switch(type)
    {
        case earth:

            return getPositionOfEarth();
            break;

        case iron:

            return getPositionOfIron();
            break;

        case ice:

            return getPositionOfIce();
            break;

        case sand:

            return getPositionOfSand();
            break;
    }
    //impossible to get here
    return nullptr;
}
/*
this method defines a position in x and y to display the tower in the right place on the map
*/
Vector2i* vGameBoard::getPositionOfEarth()
{
    int x;
    int y;

    switch((int)listOfvTower.size())
    {
        case 3:
            {
                x=100-110;
                y=370-75;
                break;
            }
        case 2:
            {
                x=350-110;
                y=370-75;
                break;
            }
        case 1:
            {
                x=650-110;
                y=370-75;
                break;
            }
        case 0:
            {
                x=990-110;
                y=370-75;
                break;
            }
        case 6:
            {
                x=40-120;
                y=600-75;
                break;
            }
        case 5:
            {
                x=300-120;
                y=600-75;
                break;
            }
        case 4:
            {
                x=970-110;
                y=600-75;
                break;
            }
    }
    //dont forget to delete
    return new Vector2i(x,y);
}

/*
this method defines a position in x and y to display the tower in the right place on the map
*/
Vector2i* vGameBoard::getPositionOfIce()
{
    int x;
    int y;

    switch((int)listOfvTower.size())
    {
        case 3:
            {
                x=100;
                y=385;
                break;
            }
        case 2:
            {
                x=350;
                y=395;
                break;
            }
        case 1:
            {
                x=650;
                y=385;
                break;
            }
        case 0:
            {
                x=990;
                y=390;
                break;
            }
        case 6:
            {
                x=40;
                y=630;
                break;
            }
        case 5:
            {
                x=300;
                y=630;
                break;
            }
        case 4:
            {
                x=970;
                y=625;
                break;
            }
    }
    return new Vector2i(x,y);
}

/*
this method defines a position in x and y to display the tower in the right place on the map
*/
Vector2i* vGameBoard::getPositionOfIron()
{
    int x;
    int y;

    switch((int)listOfvTower.size())
    {
        case 3:
            {
                x=100;
                y=330;
                break;
            }
        case 2:
            {
                x=355;
                y=330;
                break;
            }
        case 1:
            {
                x=655;
                y=330;
                break;
            }
        case 0:
            {
                x=990;
                y=330;
                break;
            }
        case 6:
            {
                x=38;
                y=575;
                break;
            }
        case 5:
            {
                x=297;
                y=575;
                break;
            }
        case 4:
            {
                x=970;
                y=575;
                break;
            }
    }
    return new Vector2i(x,y);
}

/*
this method defines a position in x and y to display the tower in the right place on the map
*/
Vector2i* vGameBoard::getPositionOfSand()
{
    int x;
    int y;

    switch((int)listOfvTower.size())
    {
        case 3:
            {
                x=100;
                y=340;
                break;
            }
        case 2:
            {
                x=350;
                y=340;
                break;
            }
        case 1:
            {
                x=650;
                y=340;
                break;
            }
        case 0:
            {
                x=990;
                y=340;
                break;
            }
        case 6:
            {
                x=40;
                y=575;
                break;
            }
        case 5:
            {
                x=300;
                y=575;
                break;
            }
        case 4:
            {
                x=970;
                y=575;
                break;
            }
    }
    return new Vector2i(x,y);
}

/* to verify if all images is accessible and charge in the texture */
bool vGameBoard::verifyImage()
{
    //verify load images
    if (!mapTexture.loadFromFile("res/images/gameBoard/map.png"))
    {
         cout << "ERROR to charge texture" << endl;
         return false;
    }


    if(verifyImageMonsters() && verifyImageTower() && verifyImageMapEntities() && verifyImageInformations())
    {
        return true;
    }

    return false;

}

bool vGameBoard::verifyImageTower()
{

    if (!earthTowerTexture1.loadFromFile("res/images/towers/earth.png"))
    {
         cout << "ERROR chargement texture" << endl;
         return false;
    }

    if (!iceTowerTexture1.loadFromFile("res/images/towers/ice1.png"))
    {
         cout << "ERROR chargement texture" << endl;
         return false;
    }

    if (!sandTowerTexture1.loadFromFile("res/images/towers/sand1.png"))
    {
         cout << "ERROR chargement texture" << endl;
         return false;
    }

    if (!ironTowerTexture1.loadFromFile("res/images/towers/iron1.png"))
    {
         cout << "ERROR chargement texture" << endl;
         return false;
    }

    if (!earthAttack.loadFromFile("res/images/towers/earthEffect.png"))
    {
         cout << "ERROR chargement texture" << endl;
         return false;
    }
    return true;
}

bool vGameBoard::verifyImageMonsters()
{
    if (!ogreTextureWalk.loadFromFile("res/images/sprites/1/1_enemies_1_WALK_spritesheet.png"))
    {
        cout << "ERROR chargement texture" << endl;
        return false;
    }

    if (!orcTextureWalk.loadFromFile("res/images/sprites/2/spritesheet_WALK.png"))
    {
         cout << "ERROR chargement texture" << endl;
         return false;
    }

    if (!gremlinTextureWalk.loadFromFile("res/images/sprites/3/spritesheet_WALK.png"))
    {
         cout << "ERROR chargement texture" << endl;
         return false;
    }

    if (!shadowMonsterTextureWalk.loadFromFile("res/images/sprites/5/spritesheet_WALK.png"))
    {
         cout << "ERROR chargement texture" << endl;
         return false;
    }

    if (!knightOfDeathTextureWalk.loadFromFile("res/images/sprites/9/spritesheet_WALK.png"))
    {
         cout << "ERROR chargement texture" << endl;
         return false;
    }

    if (!ogreAttackTexture.loadFromFile("res/images/sprites/1/1_enemies_1_ATTACK_spritesheet.png"))
    {
         cout << "ERROR chargement texture" << endl;
         return false;
    }

    if (!orcAttackTexture.loadFromFile("res/images/sprites/2/spritesheet_ATTACK.png"))
    {
         cout << "ERROR chargement texture" << endl;
         return false;
    }

    if (!gremlinAttackTexture.loadFromFile("res/images/sprites/3/spritesheet_ATTACK.png"))
    {
         cout << "ERROR chargement texture" << endl;
         return false;
    }

    if (!shadowMonsterAttackTexture.loadFromFile("res/images/sprites/5/spritesheet_ATTACK.png"))
    {
         cout << "ERROR chargement texture" << endl;
         return false;
    }

    if (!knightOfDeathAttackTexture.loadFromFile("res/images/sprites/9/spritesheet_ATTACK.png"))
    {
         cout << "ERROR chargement texture" << endl;
         return false;
    }

    if (!ogreDeadTexture.loadFromFile("res/images/sprites/1/1_enemies_1_DIE_spritesheet.png"))
    {
         cout << "ERROR chargement texture" << endl;
         return false;
    }

    if (!orcDeadTexture.loadFromFile("res/images/sprites/2/spritesheet_DIE.png"))
    {
         cout << "ERROR chargement texture" << endl;
         return false;
    }

    if (!gremlinDeadTexture.loadFromFile("res/images/sprites/3/spritesheet_DIE.png"))
    {
         cout << "ERROR chargement texture" << endl;
         return false;
    }

    if (!shadowMonsterDeadTexture.loadFromFile("res/images/sprites/5/spritesheet_DIE.png"))
    {
        cout << "ERROR chargement texture" << endl;
        return false;
    }

    if (!knightOfDeathDeadTexture.loadFromFile("res/images/sprites/9/spritesheet_DIE.png"))
    {
         cout << "ERROR chargement texture" << endl;
         return false;
    }
    return true;
}

bool vGameBoard::verifyImageMapEntities()
{
    if (!lightningTexture.loadFromFile("res/images/gameBoard/lightning.png"))
    {
         cout << "ERROR chargement texture" << endl;
         return false;
    }

    if (!fireTexture.loadFromFile("res/images/gameBoard/fire.png"))
    {
         cout << "ERROR chargement texture" << endl;
         return false;
    }

    if (!acideCloudTexture.loadFromFile("res/images/gameBoard/cloud.png"))
    {
         cout << "ERROR chargement texture" << endl;
         return false;
    }

    if (!earthTowerTexture.loadFromFile("res/images/gameBoard/earthTowerButton.png"))
    {
         cout << "ERROR chargement texture" << endl;
         return false;
    }

    if (!iceTowerTexture.loadFromFile("res/images/gameBoard/iceTowerButton.png"))
    {
         cout << "ERROR chargement texture" << endl;
         return false;
    }

    if (!ironTowerTexture.loadFromFile("res/images/gameBoard/ironTowerButton.png"))
    {
         cout << "ERROR chargement texture" << endl;
         return false;
    }

    if (!sandTowerTexture.loadFromFile("res/images/gameBoard/sandTowerButton.png"))
    {
         cout << "ERROR chargement texture" << endl;
         return false;
    }

    if (!acideCloudEffectTexture.loadFromFile("res/images/sprites/spells/acideCloud.png"))
    {
         cout << "ERROR chargement texture" << endl;
         return false;
    }
    return true;
}

bool vGameBoard::verifyImageInformations()
{
    if (!twentyTexture.loadFromFile("res/images/gameBoard/20.png"))
    {
         cout << "ERROR chargement texture" << endl;
         return false;
    }

    if (!fourtyTexture.loadFromFile("res/images/gameBoard/40.png"))
    {
         cout << "ERROR chargement texture" << endl;
         return false;
    }

    if (!sixtyTexture.loadFromFile("res/images/gameBoard/60.png"))
    {
         cout << "ERROR chargement texture" << endl;
         return false;
    }

    if (!eightyTexture.loadFromFile("res/images/gameBoard/80.png"))
    {
         cout << "ERROR chargement texture" << endl;
         return false;
    }

    if (!oneHundredTexture.loadFromFile("res/images/gameBoard/100.png"))
    {
         cout << "ERROR chargement texture" << endl;
         return false;
    }

    if (!oneHundredFiftyTexture.loadFromFile("res/images/gameBoard/150.png"))
    {
         cout << "ERROR chargement texture" << endl;
         return false;
    }

    if (!twoHundredFiftyTexture.loadFromFile("res/images/gameBoard/250.png"))
    {
         cout << "ERROR chargement texture" << endl;
         return false;
    }

    if (!fourHundredTexture.loadFromFile("res/images/gameBoard/400.png"))
    {
         cout << "ERROR chargement texture" << endl;
         return false;
    }

    if (!crystalTexture.loadFromFile("res/images/gameBoard/coinCrystal.png"))
    {
         cout << "ERROR chargement texture" << endl;
         return false;
    }

    if (!swordTexture.loadFromFile("res/images/gameBoard/sword.png"))
    {
         cout << "ERROR chargement texture" << endl;
         return false;
    }

    if (!signTexture.loadFromFile("res/images/gameBoard/window_1.png"))
    {
         cout << "ERROR chargement texture" << endl;
         return false;
    }

    return true;
}


