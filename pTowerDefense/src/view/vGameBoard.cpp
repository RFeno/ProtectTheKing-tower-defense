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

using namespace sf;
using namespace std;

vGameBoard::vGameBoard(RenderWindow& window)
{
    this->windowFromMain = &window;
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

            animationEnemyWalk();
            windowFromMain->clear();
            drawEntities();

            windowFromMain->display();
        }
    }
    else
        cout << "error" <<endl;
}

void vGameBoard::launchGame()
{
    launchWave(game.getNumberOfEnemies());
}

void vGameBoard::launchWave(int numberOfEnnemies)
{
    game.createWave(numberOfEnnemies);

    //bind enemy model and sprite
    for(int i=0; i< (int)game.getMap()->getEnemies().size(); i++)
    {
        //clone enemies because AI
        vEnnemy *venemy = new vEnnemy(game.getMap()->getEnemies()[i]->clone(),new Sprite(),false,false,false,false);
        listOfvEnnemies.push_back(venemy);
    }


    for(int i=0; i < 10; i++)
    {
        listOfAcideCloudSpell.push_back(new Sprite());
    }



    cout << game.getMap()->getEnemies().size() << endl;
    cout << game.getMap()->strEnemies() << endl;

    launchView();
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
            //animationEnemyWalk();
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
        if(dynamic_cast<Ogre*>(game.getMap()->getEnemies()[i]))
        {
            listOfvEnnemies[i]->getSprite()->setTexture(ogreTexture);
            listOfvEnnemies[i]->getSprite()->setTextureRect(IntRect(0,0,OGRE_WIDTH,OGRE_HEIGHT));
            listOfvEnnemies[i]->getSprite()->setPosition(Vector2f(-40, 510));
            listOfvEnnemies[i]->getSprite()->setScale(0.28,0.28f);
        }

         if(dynamic_cast<Orc*>(game.getMap()->getEnemies()[i]))
        {
            listOfvEnnemies[i]->getSprite()->setTexture(orcTexture);
            listOfvEnnemies[i]->getSprite()->setTextureRect(IntRect(0,0,ORC_WIDTH,ORC_HEIGHT));
            listOfvEnnemies[i]->getSprite()->setPosition(Vector2f(-40, 520));
            listOfvEnnemies[i]->getSprite()->setScale(0.28f,0.28f);
        }

        if(dynamic_cast<ShadowMonster*>(game.getMap()->getEnemies()[i]))
        {
             listOfvEnnemies[i]->getSprite()->setTexture(shadowMonsterTexture);
             listOfvEnnemies[i]->getSprite()->setTextureRect(IntRect(0,0,SHADOWMONSTER_WIDTH,SHADOWMONSTER_HEIGHT));
             listOfvEnnemies[i]->getSprite()->setPosition(Vector2f(-40, 527));
             listOfvEnnemies[i]->getSprite()->setScale(0.28f,0.28f);
        }

        if(dynamic_cast<KnightOfDeath*>(game.getMap()->getEnemies()[i]))
        {
             listOfvEnnemies[i]->getSprite()->setTexture(knightOfDeathTexture);
             listOfvEnnemies[i]->getSprite()->setTextureRect(IntRect(0,0,KNIGHTOFDEATH_WIDTH,KNIGHTOFDEATH_HEIGHT));
             listOfvEnnemies[i]->getSprite()->setPosition(Vector2f(-40, 493));
             listOfvEnnemies[i]->getSprite()->setScale(0.28f,0.28f);
        }

         if(dynamic_cast<Gremlin*>(game.getMap()->getEnemies()[i]))
        {
             listOfvEnnemies[i]->getSprite()->setTexture(gremlinTexture);
             listOfvEnnemies[i]->getSprite()->setTextureRect(IntRect(0,0,GREMLIN_WIDTH,GREMLIN_HEIGHT));
             listOfvEnnemies[i]->getSprite()->setPosition(Vector2f(-40, 550));
             listOfvEnnemies[i]->getSprite()->setScale(0.28f,0.28f);
        }
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

    //towers
    earthTowerSprite.setTexture(earthTowerTexture);
    iceTowerSprite.setTexture(iceTowerTexture);
    sandTowerSprite.setTexture(sandTowerTexture);
    ironTowerSprite.setTexture(ironTowerTexture);

    //spells
    acideCloudSprite.setTexture(acideCloudTexture);
    fireSprite.setTexture(fireTexture);
    lightningSprite.setTexture(lightningTexture);

    //size
    acideCloudSprite.setScale(0.50f,0.50f);
    fireSprite.setScale(0.50f,0.50f);
    lightningSprite.setScale(0.50,0.50f);

    earthTowerSprite.setScale(0.50f,0.50f);
    iceTowerSprite.setScale(0.50f,0.50f);
    sandTowerSprite.setScale(0.50f,0.50f);
    ironTowerSprite.setScale(0.50f,0.50f);
    mapSprite.setScale(0.73f,0.75f);


    //positions
    acideCloudSprite.setPosition(Vector2f(10, 5));
    fireSprite.setPosition(Vector2f(110, 5));
    lightningSprite.setPosition(Vector2f(210, 5));

    earthTowerSprite.setPosition(Vector2f(1006,5));
    iceTowerSprite.setPosition(Vector2f(1106,5));
    sandTowerSprite.setPosition(Vector2f(1206,5));
    ironTowerSprite.setPosition(Vector2f(1306,5));

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


    for(int i=0; i < NUMBER_ACIDE_SPELL ; i++)
    {
        windowFromMain->draw(*listOfAcideCloudSpell[i]);
    }


    // enemies spawn one per one
    if(spawnClock.getElapsedTime().asSeconds() > spawnTime && idSpawn < (int)listOfvEnnemies.size())
    {
        //window.draw(*enemiesSprite[idSpawn]);
        listOfvEnnemies[idSpawn]->setSpawn(true);
        idSpawn++;
        spawnClock.restart();
    }

    for(int i=0;i<(int)listOfvEnnemies.size();i++)
    {
        if(listOfvEnnemies[i]->isSpawn())
        {
            windowFromMain->draw(*listOfvEnnemies[i]->getSprite());
        }
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
		&& mousePos.x < spr.getPosition().x + spr.getTexture()->getSize().x
		&& mousePos.y > spr.getPosition().y && mousePos.y < spr.getPosition().y + spr.getTexture()->getSize().y
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

void vGameBoard::animationEnemyWalk()
{
    //methods adapte which parts of sprite sheet we need to display
    adaptAnimationSprite();

    if(animClock.getElapsedTime().asSeconds() > 0.08f)
    {


        if(x_Ogre*OGRE_WIDTH >= (int)ogreTexture.getSize().x - OGRE_WIDTH)
        {
            x_Ogre = 0;
        }
        else
        {
            x_Ogre++;
        }



        if(x_shadowMonster*SHADOWMONSTER_WIDTH >= (int)shadowMonsterTexture.getSize().x - SHADOWMONSTER_WIDTH)
        {
            x_shadowMonster = 0;
        }
        else
        {
            x_shadowMonster++;
        }



        if(x_Orc*ORC_WIDTH >= (int)orcTexture.getSize().x - ORC_WIDTH)
        {
            x_Orc = 0;
        }
        else
        {
            x_Orc++;
        }



        if(x_gremlin*GREMLIN_WIDTH >= (int)gremlinTexture.getSize().x - GREMLIN_WIDTH)
        {
            x_gremlin = 0;
        }
        else
        {
            x_gremlin++;
        }



        if(x_knight*KNIGHTOFDEATH_WIDTH >= (int)knightOfDeathTexture.getSize().x - KNIGHTOFDEATH_WIDTH)
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




        //for the deplacement
        for(int i=0;i< (int)listOfvEnnemies.size();i++)
        {
            if(listOfvEnnemies[i]->isSpawn())
            {
                listOfvEnnemies[i]->getSprite()->move(WALK_SPEED,0);
            }

            if((int)listOfvEnnemies[i]->getSprite()->getPosition().x % 100 == 0)
            {
                cout<<listOfvEnnemies[0]->getSprite()->getPosition().x<<endl;
            }

            if(listOfvEnnemies[i]->getSprite()->getPosition().x > 1200)
            {
                listOfvEnnemies[i]->setAttack(true);
            }

            if(listOfvEnnemies[i]->isAttacking())
            {
                animationEnemyAttack(listOfvEnnemies[i]);
                listOfvEnnemies[i]->setAttack(false);
            }
        }



        animClock.restart();
    }
}

void vGameBoard::animationEnemyWalk2(Sprite *enemy)
{
   //to implemented
}

void vGameBoard::animationEnemyAttack(vEnnemy* vEnnemy)
{
    // Change the texture
    if(dynamic_cast<Ogre*>(vEnnemy->getEnnemy()))
    {
        vEnnemy->getSprite()->setTexture(ogreAttackTexture);
        vEnnemy->getSprite()->setTextureRect(IntRect(0,0,OGRE_WIDTH,OGRE_HEIGHT));
    }

     if(dynamic_cast<Orc*>(vEnnemy->getEnnemy()))
    {
        vEnnemy->getSprite()->setTexture(orcAttackTexture);
        vEnnemy->getSprite()->setTextureRect(IntRect(0,0,ORC_WIDTH,ORC_HEIGHT));
    }

    if(dynamic_cast<ShadowMonster*>(vEnnemy->getEnnemy()))
    {
         vEnnemy->getSprite()->setTexture(shadowMonsterAttackTexture);
         vEnnemy->getSprite()->setTextureRect(IntRect(0,0,SHADOWMONSTER_WIDTH,SHADOWMONSTER_HEIGHT));
    }

    if(dynamic_cast<KnightOfDeath*>(vEnnemy->getEnnemy()))
    {
         vEnnemy->getSprite()->setTexture(knightOfDeathAttackTexture);
         vEnnemy->getSprite()->setTextureRect(IntRect(0,0,KNIGHTOFDEATH_WIDTH,KNIGHTOFDEATH_HEIGHT));
    }

     if(dynamic_cast<Gremlin*>(vEnnemy->getEnnemy()))
    {
         vEnnemy->getSprite()->setTexture(gremlinAttackTexture);
         vEnnemy->getSprite()->setTextureRect(IntRect(0,0,GREMLIN_WIDTH,GREMLIN_HEIGHT));
    }

}

/*methods adapte which parts of sprite sheet we need to display*/
void vGameBoard::adaptAnimationSprite()
{
    for(size_t i=0;i<listOfvEnnemies.size();i++)
     {
        if(dynamic_cast<Ogre*>(game.getMap()->getEnemies()[i]))
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
     }

     for(size_t i=0;i<listOfAcideCloudSpell.size();i++)
     {
        listOfAcideCloudSpell[i]->setTextureRect(IntRect(x_acide*909,0,909,2938));
     }



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


    if(verifyImageMonsters() && verifyImageTower() && verifyImageMapEntities())
    {
        return true;
    }

    return false;

}

bool vGameBoard::verifyImageTower()
{
    return true;
}

bool vGameBoard::verifyImageMonsters()
{
    if (!ogreTexture.loadFromFile("res/images/sprites/1/1_enemies_1_WALK_spritesheet.png"))
    {
         cout << "ERROR chargement texture" << endl;
         return false;
    }

    if (!orcTexture.loadFromFile("res/images/sprites/2/spritesheet_WALK.png"))
    {
         cout << "ERROR chargement texture" << endl;
         return false;
    }

    if (!gremlinTexture.loadFromFile("res/images/sprites/3/spritesheet_WALK.png"))
    {
         cout << "ERROR chargement texture" << endl;
         return false;
    }

    if (!shadowMonsterTexture.loadFromFile("res/images/sprites/5/spritesheet_WALK.png"))
    {
         cout << "ERROR chargement texture" << endl;
         return false;
    }

    if (!knightOfDeathTexture.loadFromFile("res/images/sprites/9/spritesheet_WALK.png"))
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


