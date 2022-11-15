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

    //while player doesn't loose relaunch wave
    launchGame();

    cout << game.getMap()->getEnemies().size() << endl;
    cout << game.getMap()->strEnemies() << endl;

}

vGameBoard::~vGameBoard()
{
    //dtor
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
            drawEntities(*windowFromMain);

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

    for(int i=0; i< (int)game.getMap()->getEnemies().size(); i++)
    {
        //bind enemy model and sprite
        cout << "create vEnnemy" << endl;
        vEnnemy *venemy = new vEnnemy(game.getMap()->getEnemies()[i],new Sprite(),false,false,false);
        listOfEnnemies.push_back(venemy);
    }

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

    for(size_t i=0;i<listOfEnnemies.size();i++)
    {
        if(dynamic_cast<Ogre*>(game.getMap()->getEnemies()[i]))
        {
            listOfEnnemies[i]->getSprite()->setTexture(ogreTexture);
            listOfEnnemies[i]->getSprite()->setTextureRect(IntRect(0,0,OGRE_WIDTH,OGRE_HEIGHT));
            listOfEnnemies[i]->getSprite()->setPosition(Vector2f(10, 535));
            listOfEnnemies[i]->getSprite()->setScale(0.28,0.28f);
        }

         if(dynamic_cast<Orc*>(game.getMap()->getEnemies()[i]))
        {
            listOfEnnemies[i]->getSprite()->setTexture(orcTexture);
            listOfEnnemies[i]->getSprite()->setTextureRect(IntRect(0,0,ORC_WIDTH,ORC_HEIGHT));
            listOfEnnemies[i]->getSprite()->setPosition(Vector2f(10, 545));
             listOfEnnemies[i]->getSprite()->setScale(0.28f,0.28f);
        }

        if(dynamic_cast<ShadowMonster*>(game.getMap()->getEnemies()[i]))
        {
             listOfEnnemies[i]->getSprite()->setTexture(shadowMonsterTexture);
             listOfEnnemies[i]->getSprite()->setTextureRect(IntRect(0,0,SHADOWMONSTER_WIDTH,SHADOWMONSTER_HEIGHT));
             listOfEnnemies[i]->getSprite()->setPosition(Vector2f(10, 553));
             listOfEnnemies[i]->getSprite()->setScale(0.28f,0.28f);
        }

        if(dynamic_cast<KnightOfDeath*>(game.getMap()->getEnemies()[i]))
        {
             listOfEnnemies[i]->getSprite()->setTexture(knightOfDeathTexture);
             listOfEnnemies[i]->getSprite()->setTextureRect(IntRect(0,0,KNIGHTOFDEATH_WIDTH,KNIGHTOFDEATH_HEIGHT));
             listOfEnnemies[i]->getSprite()->setPosition(Vector2f(10, 518));
             listOfEnnemies[i]->getSprite()->setScale(0.28f,0.28f);
        }

         if(dynamic_cast<Gremlin*>(game.getMap()->getEnemies()[i]))
        {
             listOfEnnemies[i]->getSprite()->setTexture(gremlinTexture);
             listOfEnnemies[i]->getSprite()->setTextureRect(IntRect(0,0,GREMLIN_WIDTH,GREMLIN_HEIGHT));
             listOfEnnemies[i]->getSprite()->setPosition(Vector2f(10, 575));
             listOfEnnemies[i]->getSprite()->setScale(0.28f,0.28f);
        }
    }

    mapSprite.setScale(0.73f,0.75f);
    mapSprite.setTexture(mapTexture);

    //spell
    acideCloudSprite.setTexture(acideCloudTexture);
    fireSprite.setTexture(fireTexture);
    lightningSprite.setTexture(lightningTexture);

    //size
    acideCloudSprite.setScale(0.50f,0.50f);
    fireSprite.setScale(0.50f,0.50f);
    lightningSprite.setScale(0.50,0.50f);

    //positions
    acideCloudSprite.setPosition(Vector2f(10, 5));
    fireSprite.setPosition(Vector2f(110, 5));
    lightningSprite.setPosition(Vector2f(210, 5));

}

/* to verify if all images is accessible and charge in the texture */
bool vGameBoard::verifyImage()
{
    //verify load images
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

    if (!mapTexture.loadFromFile("res/images/gameBoard/map.png"))
    {
         cout << "ERROR chargement texture" << endl;
         return false;
    }

    //1_enemies_1_ATTACK_spritesheet.png
    if (!ogreTexture.loadFromFile("res/images/sprites/1/1_enemies_1_JUMP_spritesheet.png"))
    {
         cout << "ERROR chargement texture" << endl;
         return false;
    }

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

    if (!acideCloudTexture.loadFromFile("res/images/gameBoard/cloud.png"))
    {
         cout << "ERROR chargement texture" << endl;
         return false;
    }

    if (!acideCloudTexture.loadFromFile("res/images/gameBoard/cloud.png"))
    {
         cout << "ERROR chargement texture" << endl;
         return false;
    }

    return true;
}
/* to draw the entitties in the window */
bool vGameBoard::drawEntities(RenderWindow& window)
{
    //display elements
    window.draw(mapSprite);
    window.draw(lightningSprite);
    window.draw(fireSprite);
    window.draw(acideCloudSprite);

    // enemies spawn one per one
    if(spawnClock.getElapsedTime().asSeconds() > spawnTime && idSpawn < (int)listOfEnnemies.size())
    {
        //window.draw(*enemiesSprite[idSpawn]);
        listOfEnnemies[idSpawn]->setSpawn(true);
        idSpawn++;
        spawnClock.restart();
    }

    for(int i=0;i<(int)listOfEnnemies.size();i++)
    {
        if(listOfEnnemies[i]->isSpawn())
        {
            window.draw(*listOfEnnemies[i]->getSprite());
        }
    }

    return true;

}

//fonction for actionEvent on Buttons Sprite
bool vGameBoard::isSpriteClicked (Sprite &spr, RenderWindow &window )
{
    //take the position of the mouse
    Vector2i mousePos = Mouse::getPosition(window);

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
    if(animClock.getElapsedTime().asSeconds() > 0.08f)
    {
         for(size_t i=0;i<listOfEnnemies.size();i++)
         {
            if(dynamic_cast<Ogre*>(game.getMap()->getEnemies()[i]))
            {
                 listOfEnnemies[i]->getSprite()->setTextureRect(IntRect(x_Ogre*OGRE_WIDTH,y_Ogre*OGRE_HEIGHT,OGRE_WIDTH,OGRE_HEIGHT));
            }

             if(dynamic_cast<Orc*>(game.getMap()->getEnemies()[i]))
            {
                 listOfEnnemies[i]->getSprite()->setTextureRect(IntRect(x_Orc*ORC_WIDTH,y_Orc*ORC_HEIGHT,ORC_WIDTH,ORC_HEIGHT));
            }

            if(dynamic_cast<ShadowMonster*>(game.getMap()->getEnemies()[i]))
            {
                 listOfEnnemies[i]->getSprite()->setTextureRect(IntRect(x_shadowMonster*SHADOWMONSTER_WIDTH,y_shadowMonster*SHADOWMONSTER_HEIGHT,SHADOWMONSTER_WIDTH,SHADOWMONSTER_HEIGHT));
            }

            if(dynamic_cast<KnightOfDeath*>(game.getMap()->getEnemies()[i]))
            {
                 listOfEnnemies[i]->getSprite()->setTextureRect(IntRect(x_knight*KNIGHTOFDEATH_WIDTH,y_knight*KNIGHTOFDEATH_HEIGHT,KNIGHTOFDEATH_WIDTH,KNIGHTOFDEATH_HEIGHT));
            }

            if(dynamic_cast<Gremlin*>(game.getMap()->getEnemies()[i]))
            {
                 listOfEnnemies[i]->getSprite()->setTextureRect(IntRect(x_gremlin*GREMLIN_WIDTH,y_gremlin*GREMLIN_HEIGHT,GREMLIN_WIDTH,GREMLIN_HEIGHT));
            }
         }

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

        //for the deplacement

        for(int i=0;i< (int)listOfEnnemies.size();i++)
        {
            if(listOfEnnemies[i]->isSpawn())
            {
                 listOfEnnemies[i]->getSprite()->move(WALK_SPEED,0);
            }
        }

        animClock.restart();
    }
}

void vGameBoard::animationEnemyWalk2(Sprite *enemy)
{
   //to implemented
}


